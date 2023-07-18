#include "linuxplugin.h"

#include <iostream>

#include <engine/engine.h>

#include <sys/time.h>

namespace Engine {

    void LinuxPlugin::init() {
        std::cout << "I am LinuxPlugin and will now count to 5" << std::endl;
        // set m_time to current time
        struct timeval tv;
        gettimeofday(&tv, NULL);
        m_time = tv.tv_sec;
        m_counter = tv.tv_sec;
    }

    void LinuxPlugin::shutdown() {
        std::cout << "I am LinuxPlugin and I am shutting down" << std::endl;
    }

    void LinuxPlugin::update() {
        // get current time
        struct timeval tv;
        gettimeofday(&tv, NULL);
        int time = tv.tv_sec;
        if (time - m_counter >= 1) {
            std::cout << " - I am LinuxPlugin and I have counted to " << int(abs(time - m_time)) << std::endl;
            m_counter = time;
        }
        // if 5 seconds have passed, call the event callback
        if (time - m_time >= 5) {
            m_eventCallback();
        } 
    }
}
