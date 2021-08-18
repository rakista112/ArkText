#include "ArkAPI.hpp"

namespace ArkText
{
    std::unique_ptr<sf::RenderWindow> &get_window()
    {
        static std::unique_ptr<sf::RenderWindow> window;
        return window;
    }

    Ark::Value init_window(std::vector<Ark::Value> &n, Ark::VM *vm)
    {
        /**
         * Shamelessly copied from @SuperFola's 
         * https://github.com/SuperFola/arksfml/blob/master/src/window.cpp
         */
        if (n.size() != 3)
            throw std::runtime_error("sf:window:init needs 3 arguments: width, height and title");
        if (n[0].valueType() != Ark::ValueType::Number)
            throw Ark::TypeError("sf:window:init: width must be a Number");
        if (n[1].valueType() != Ark::ValueType::Number)
            throw Ark::TypeError("sf:window:init: height must be a Number");
        if (n[2].valueType() != Ark::ValueType::String)
            throw Ark::TypeError("sf:window:init: title must be a String");

        if (!get_window())
        {
            get_window()->create(sf::VideoMode(static_cast<long>(n[0].number()), static_cast<long>(n[1].number())), n[2].string().toString());
        }
        else
            throw std::runtime_error("init_window: can't call the function twice");

        return Ark::Nil;
    }
}