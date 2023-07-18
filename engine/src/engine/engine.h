#pragma once

#include "pluginmanager.h"

namespace Engine
{
    class Engine
    {
    public:
        Engine(int argc, char** argv);
        void loadPlugins();
        void run();
        PluginManager &pluginManager() { return m_pluginManager; }

    private:
        PluginManager m_pluginManager;
    };
}
