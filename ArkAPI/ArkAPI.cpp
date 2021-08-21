#include "ArkAPI.hpp"
#include <algorithm>
namespace ArkText
{
    sf::RenderWindow &get_window()
    {
        static sf::RenderWindow window;
        return window;
    }

    std::vector<std::unique_ptr<sf::CircleShape>>& get_circle_obj()
    {
        static std::vector<std::unique_ptr<sf::CircleShape>> circleObj;
        return circleObj;
    }

    void draw_circles()
    {
        std::vector<std::unique_ptr<sf::CircleShape>>& circles = get_circle_obj();
        for(std::size_t i=0; i < circles.size(); ++i)
        {
            get_window().draw(*circles[i]);
        };
    }
    
    Ark::UserType::ControlFuncs* get_cfs()
    {
        static Ark::UserType::ControlFuncs cfs;
        cfs.ostream_func = [](std::ostream& os, const Ark::UserType& a) -> std::ostream& {
            auto pos = a.as<sf::CircleShape>().getPosition();
            os << "Circle: " << pos.x << ", " << pos.y;
            return os;
        };
        cfs.deleter = [](void* data) {
            std::vector<std::unique_ptr<sf::CircleShape>>& circles = get_circle_obj();
            auto it = std::find_if(circles.begin(), circles.end(), [data](const auto& val) -> bool {
                return val.get() == static_cast<sf::CircleShape*>(data);
            });
            if (it != circles.end())
                circles.erase(it);
        };
        return &cfs;
    }

    Ark::Value make_circle(std::vector<Ark::Value> &n, Ark::VM *vm)
    {
        if (n.size() != 3)
            throw std::runtime_error("draw_circle needs 3 arguments: center, radius and color");
        if (n[0].valueType() != Ark::ValueType::List)
            throw Ark::TypeError("draw_circle: center must be a 2-element List");
        if (n[1].valueType() != Ark::ValueType::Number)
            throw Ark::TypeError("draw_circle: radius must be a Number");
        if (n[2].valueType() != Ark::ValueType::String)
            throw Ark::TypeError("draw_circle: color must be a String");

        auto vec = n[0].list();
        sf::Vector2f vec2((float)vec[0].number(), (float)vec[1].number());
        sf::CircleShape *shape = get_circle_obj().emplace_back(
            std::make_unique<sf::CircleShape>((float)n[1].number())
        ).get();
        shape->setRadius((float)n[1].number());
        shape->setPosition(vec2);
        shape->setFillColor(sf::Color(100, 250, 50));
        Ark::Value v = Ark::Value(Ark::UserType(shape));
        v.usertypeRef().setControlFuncs(get_cfs());
        return v;
    }


}
