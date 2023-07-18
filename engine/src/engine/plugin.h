#pragma once

#include <string>

namespace Engine
{
    class Plugin
    {
    public:
        virtual ~Plugin() = default;
        virtual std::string getPluginName() = 0;
    };
}