#include <ArkAPI/ShapeBase.hpp>

namespace ArkText 
{
    void ShapeBase::onRender(sf::RenderTarget& target, const sf::Transform& transform)
    {
        target.draw(*this);
    }
}