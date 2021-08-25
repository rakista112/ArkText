#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <ArkAPI/ShapeBase.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace ArkText
{
    class Circle : public sf::CircleShape, public ShapeBase
    {
        void setRadius (float radius);
        float getRadius () const;
    };
}

#endif