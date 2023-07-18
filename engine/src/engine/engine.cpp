#include "engine.h"

#include <iostream>
#include <dlfcn.h>

namespace Engine
{
    using CreatePlugin = Plugin* (*)();
    using DestroyPlugin = void (*)(Plugin*);

    void Engine::run()
    {
        std::cout << "Running engine" << std::endl;

        std::cout << "Loaded plugins: " << std::endl;
        for(auto& plugin : plugins)
        {
            std::cout << "\tRunning plugin: " << plugin->getPluginName() << std::endl;
        }
    }

    void Engine::loadPlugin(const std::string &path)
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
        plugins.push_back(std::shared_ptr<Plugin>(plugin, destroyPlugin));

        std::cout << "Loaded plugin: " << plugin->getPluginName() << std::endl;
    }
}