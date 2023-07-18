#pragma once

#include <string>

namespace Engine
{
    class Plugin
    {
    public:
        virtual ~Plugin() = default;
        virtual std::string getPluginName() = 0;
        virtual void init() {}
        virtual void shutdown() {}
        virtual void update() {}
    };
}
