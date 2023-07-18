#pragma once

#include "plugin.h"

#include <memory>
#include <vector>
#include <filesystem>

namespace Engine
{
    class PluginManager
    {
    public:
        void setPath(const std::string &path);

        void loadPlugin(const std::filesystem::path &path);
        void loadAllPlugins();
        void loadPlugins(const std::vector<std::string> &plugins);

        auto &plugins() { return m_plugins; }

    private:
        std::vector<std::shared_ptr<Plugin>> m_plugins;
        std::filesystem::path m_path;
    };
}