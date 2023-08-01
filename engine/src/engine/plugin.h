#pragma once

#include <string>
#include <functional>

namespace Engine
{
    template <typename PluginType>
    concept PluginConcept = requires(PluginType p) {
        { p.getPluginName() } -> std::convertible_to<std::string>;
        { p.init() } -> std::same_as<void>;
        { p.shutdown() } -> std::same_as<void>;
        { p.update() } -> std::same_as<void>;
        { p.setEventCallback(std::declval<typename PluginType::EventCallback>()) } -> std::same_as<void>;
    };

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
