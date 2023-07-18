#include "linuxplugin.h"

#include <iostream>

namespace Engine {

    void LinuxPlugin::init() {
        std::cout << "LinuxPlugin::init()" << std::endl;
    }

    void LinuxPlugin::shutdown() {
        std::cout << "LinuxPlugin::shutdown()" << std::endl;
    }

    void LinuxPlugin::update() {
        std::cout << "LinuxPlugin::update()" << std::endl;
    }

}