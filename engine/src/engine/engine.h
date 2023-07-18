#pragma once

#include "pluginmanager.h"

namespace Engine
{
    class Engine
    {
    public:
        void loadPlugins();
        void run();
        PluginManager &pluginManager() { return m_pluginManager; }

    private:
        PluginManager m_pluginManager;
    };
}