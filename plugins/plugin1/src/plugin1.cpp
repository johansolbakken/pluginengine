
#include <engine/plugin.h>

#include <iostream>

namespace Engine
{
    class Plugin1 : public Plugin
    {
    public:
        ~Plugin1() override = default;

        std::string getPluginName() override
        {
            return "Plugin1";
        }
    };

    extern "C" Plugin *createPlugin()
    {
        return new Plugin1();
    }

    extern "C" void destroyPlugin(Plugin *plugin)
    {
        std::cout << "I was plugin1 and I am destroyed" << std::endl;
        delete plugin;
    }
}