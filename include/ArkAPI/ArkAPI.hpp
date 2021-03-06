// my_class.h
#ifndef ARKAPI_H // include guard
#define ARKAPI_H

#include <Ark/Ark.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <Small/Graphics/Node.hpp>
#include <memory>

namespace ArkText
{
    sf::RenderWindow& get_window();
    Ark::Value make_circle(std::vector<Ark::Value> &n, Ark::VM *vm);
    Ark::Value make_rect(std::vector<Ark::Value> &n, Ark::VM *vm);
    void draw_circles();
    void draw_rects();
}

#endif
