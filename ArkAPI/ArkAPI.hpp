// my_class.h
#ifndef ARKAPI_H // include guard
#define ARKAPI_H

#include <Ark/Ark.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

namespace ArkText
{
    std::unique_ptr<sf::RenderWindow>& get_window();
    Ark::Value init_window(std::vector<Ark::Value> &n, Ark::VM *vm);
}

#endif
