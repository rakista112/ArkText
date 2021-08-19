#include "ArkAPI.hpp"

namespace ArkText
{
    sf::RenderWindow& get_window()
    {
        static sf::RenderWindow window;
        return window;
    }

   
}
