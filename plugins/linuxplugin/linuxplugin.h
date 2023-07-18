#pragma once

#include <engine/plugin.h>

namespace Engine
{
    class LinuxPlugin : public Plugin
    {
    public:
        ~LinuxPlugin() override = default;

        std::string getPluginName() override
        {
            return "LinuxPlugin";
        }

        void init() override;
        void shutdown() override;
        void update() override;
    };

    extern "C" Plugin *createPlugin()
    {
        return new LinuxPlugin();
    }

    extern "C" void destroyPlugin(Plugin *plugin)
    {
        delete plugin;
    }
}
