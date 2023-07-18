#pragma once

#include <string>
#include <vector>
#include <memory>

#include "plugin.h"

namespace Engine
{
    class Engine
    {
    public:
        void run();

        void loadPlugin(const std::string& path);

    private:
        std::vector<std::shared_ptr<Plugin>> plugins;
    };
}