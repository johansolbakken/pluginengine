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

    void PluginManager::loadPlugin(const std::string &path)
    {
        std::cout << "Loading plugin: " << path << std::endl;

        void *handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!handle)
        {
            std::cerr << "Cannot open library: " << dlerror() << std::endl;
            return;
        }

        dlerror();

        CreatePlugin createPlugin = reinterpret_cast<CreatePlugin>(dlsym(handle, "createPlugin"));
        const char *dlsym_error = dlerror();
        if (dlsym_error)
        {
            std::cerr << "Cannot load symbol createPlugin: " << dlsym_error << std::endl;
            dlclose(handle);
            return;
        }

        DestroyPlugin destroyPlugin = (DestroyPlugin)dlsym(handle, "destroyPlugin");
        dlsym_error = dlerror();
        if (dlsym_error)
        {
            std::cerr << "Cannot load symbol destroyPlugin: " << dlsym_error << std::endl;
            dlclose(handle);
            return;
        }

        Plugin *plugin = createPlugin();
        m_plugins.push_back(std::shared_ptr<Plugin>(plugin, destroyPlugin));

        std::cout << "Loaded plugin: " << plugin->getPluginName() << std::endl;
    }

    void PluginManager::loadPlugins(const std::string &path)
    {
        std::vector<std::string> plugins;
        /*
                // Recursively search for plugins
                std::function<void(std::string)> search;
                search = [&search, &plugins, &pluginExtension](std::string path)
                {
                    for (auto &p : std::filesystem::directory_iterator(path))
                    {
                        if (p.is_directory())
                        {
                            search(p.path().string());
                        }
                        else if (p.path().extension() == pluginExtension)
                        {
                            plugins.push_back(p.path().string());
                        }
                    }
                };

                search(path);

                for (auto &plugin : plugins)
                {
                    loadPlugin(plugin);
                }*/
    }

    void PluginManager::loadPlugins(const std::string &path, const std::vector<std::string> &plugins)
    {

        std::vector<std::string> pluginsPaths;
        /*
                // Recursively search for plugins
                std::function<void(std::string)> search;
                search = [&search, &plugins, &pluginExtension, &pluginsPaths](std::string path)
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
                            if (std::find(plugins.begin(), plugins.end(), pluginName) != plugins.end())
                            {
                                pluginsPaths.push_back(p.path().string());
                            }
                        }
                    }
                };

                search(path);

                for (auto &plugin : pluginsPaths)
                {
                    loadPlugin(plugin);
                }*/
    }
}