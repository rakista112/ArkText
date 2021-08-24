#ifndef SHAPEBASE_HPP
#define SHAPEBASE_HPP

#include <SFML/Graphics/Shape.hpp>
#include <Small/Graphics/Node.hpp>

namespace ArkText 
{
    class ShapeBase : public sf::Shape, public sgl::Graphics::Node
    {
        public:
            ShapeBase();

            virtual ~ShapeBase();

            void onRender(sf::RenderTarget& target, const sf::Transform& transform);

            // Circle Methods
            void setRadius (float radius) { }
            float getRadius () const { }

    };
}

#endif