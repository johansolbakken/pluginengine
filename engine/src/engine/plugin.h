#pragma once

#include <string>
#include <functional>

namespace Engine
{
    class Plugin
    {
    public:
        using EventCallback = std::function<void()>;

        virtual ~Plugin() = default;
        virtual std::string getPluginName() = 0;
        virtual void init() {}
        virtual void shutdown() {}
        virtual void update() {}
        virtual void setEventCallback(const EventCallback &callback) {}
    };
}
