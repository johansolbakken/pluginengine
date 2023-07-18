#pragma once

#include "plugin.h"

#include <memory>
#include <vector>

namespace Engine
{
    class PluginManager
    {
    public:
        void loadPlugin(const std::string &path);
        void loadPlugins(const std::string &path);
        void loadPlugins(const std::string &path, const std::vector<std::string> &plugins);

        auto &plugins() { return m_plugins; }

    private:
        std::vector<std::shared_ptr<Plugin>> m_plugins;
    };
}