#pragma once

#include <engine/plugin.h>

namespace Engine
{
    class MacPlugin : public Plugin
    {
    public:
        ~MacPlugin() override = default;

        std::string getPluginName() override
        {
            return "MacPlugin";
        }

        void init() override;
        void shutdown() override;
        void update() override;
        void setEventCallback(const EventCallback &callback) override { m_eventCallback = callback; }

    private:
        int m_time = 0;
        int m_counter = 0;
        EventCallback m_eventCallback;
    };

    extern "C" Plugin *createPlugin()
    {
        return new MacPlugin();
    }

    extern "C" void destroyPlugin(Plugin *plugin)
    {
        delete plugin;
    }
}
