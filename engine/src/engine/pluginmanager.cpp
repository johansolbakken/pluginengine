#include "pluginmanager.h"

#include <dlfcn.h>
#include <filesystem>
#include <iostream>
#include <string>

namespace Engine
{
    using CreatePlugin = Plugin *(*)();
    using DestroyPlugin = void (*)(Plugin *);

#ifdef __APPLE__
    std::string pluginExtension = ".dylib";
    std::string pluginPrefix = "lib";
#endif
#ifdef __linux__
    std::string pluginExtension = ".so";
    std::string pluginPrefix = "lib";
#endif

    void PluginManager::setPath(const std::string &path)
    {
        m_path = path;
    }

    void PluginManager::loadPlugin(const std::filesystem::path &path)
    {
        std::cout << "\033[90m";
        std::cout << "Loading plugin: " << path << std::endl;
        std::cout << "\033[0m";

        void *handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!handle)
        {
            std::cerr << "\033[31m";
            std::cerr << "Cannot open library: " << dlerror() << std::endl;
            std::cerr << "\033[0m";
            return;
        }

        dlerror();

        CreatePlugin createPlugin = reinterpret_cast<CreatePlugin>(dlsym(handle, "createPlugin"));
        const char *dlsym_error = dlerror();
        if (dlsym_error)
        {
            std::cerr << "\033[31m";
            std::cerr << "Cannot load symbol createPlugin: " << dlsym_error << std::endl;
            std::cerr << "\033[0m";
            dlclose(handle);
            return;
        }

        DestroyPlugin destroyPlugin = (DestroyPlugin)dlsym(handle, "destroyPlugin");
        dlsym_error = dlerror();
        if (dlsym_error)
        {
            std::cerr << "\033[31m";
            std::cerr << "Cannot load symbol destroyPlugin: " << dlsym_error << std::endl;
            std::cerr << "\033[0m";
            dlclose(handle);
            return;
        }

        Plugin *plugin = createPlugin();
        m_plugins.push_back(std::shared_ptr<Plugin>(plugin, destroyPlugin));

        std::cout << "\033[90m";
        std::cout << "Loaded plugin: " << plugin->getPluginName() << std::endl;
        std::cout << "\033[0m";
    }

    void PluginManager::loadAllPlugins()
    {
        std::function<void(std::string)> search;
        search = [&search, this](std::string path)
        {
            for (auto &p : std::filesystem::directory_iterator(path))
            {
                if (p.is_directory())
                {
                    search(p.path().string());
                }
                else if (p.path().extension() == pluginExtension)
                {
                    std::string pluginName = p.path().stem().string().substr(3);
                    loadPlugin(p.path().string());
                }
            }
        };

        search(m_path);
    }

    void PluginManager::loadPlugins(const std::vector<std::string> &plugins)
    {
        std::vector<std::string> foundPlugins;
        std::function<void(std::string)> search;
        search = [&search, this, &plugins, &foundPlugins](std::string path)
        {
            for (auto &p : std::filesystem::directory_iterator(path))
            {
                if (p.is_directory())
                {
                    search(p.path().string());
                }
                else if (p.path().extension() == pluginExtension)
                {
                    std::string pluginName = p.path().stem().string().substr(3);
                    for (auto &plugin : plugins)
                    {
                        if (pluginName == plugin)
                        {
                            loadPlugin(p.path().string());
                            foundPlugins.push_back(plugin);
                        }
                    }
                }
            }
        };

        search(m_path);

        for (auto &plugin : plugins)
        {
            bool found = false;
            for (auto &foundPlugin : foundPlugins)
            {
                if (plugin == foundPlugin)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                std::cerr << "\033[33m";
                std::cerr << "Warning: Plugin " << plugin << " not found" << std::endl;
                std::cerr << "\033[0m";
            }
        }
    }
}