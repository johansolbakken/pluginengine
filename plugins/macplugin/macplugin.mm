#include "macplugin.h"

#include <iostream>

#include <engine/engine.h>

#include <Foundation/Foundation.h>

namespace Engine {

    int getTime() {
        int time = 0;
        @autoreleasepool {
            NSDate *date = [NSDate date];
            time = (int) [date timeIntervalSince1970];
        }
        return time;
    }

    void MacPlugin::init() {
        m_time = getTime();
        m_counter = getTime();
    }

    void MacPlugin::shutdown() {
    }

    void MacPlugin::update() {
        int time = getTime();
        if (time - m_counter >= 1) {
            m_counter = time;
            std::cout << "Time: " << time - m_time << std::endl;
        }
        if (time - m_time >= 5) {
            m_eventCallback();
        }
    }
}
