#include <tuple>

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <Ark/Ark.hpp>
#include "ArkAPI.hpp"
int main()
{
    
    Ark::State state;
    // init all ark functions
    std::vector<std::tuple<std::string, Ark::Value::ProcType>> functions;
    functions.emplace_back(std::make_tuple("make_circle", ArkText::make_circle));
    functions.emplace_back(std::make_tuple("make_rect", ArkText::make_rect));
    for(auto& x : functions)
    {
        state.loadFunction(std::get<0>(x), std::get<1>(x));
    }

    Ark::VM vm(&state);
    ArkText::get_window().create(sf::VideoMode(1024, 768), "");
    ArkText::get_window().setVerticalSyncEnabled(true);
    ImGui::SFML::Init(ArkText::get_window());
    sf::Color bgColor;

    float color[3] = { 0.f, 0.f, 0.f };

    // let's use char array as buffer, see next part
    // for instructions on using std::string with ImGui
    char windowTitle[4096] = "ArkText";

    ArkText::get_window().setTitle(windowTitle);
    ArkText::get_window().resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
    sf::Clock deltaClock;
    while (ArkText::get_window().isOpen()) {
        sf::Event event;
        while (ArkText::get_window().pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                ArkText::get_window().close();
            }
        }

        ImGui::SFML::Update(ArkText::get_window(), deltaClock.restart());

        ImGui::Begin("Sketch Editor"); // begin window

        // Window title text edit
        ImGui::InputTextMultiline("", windowTitle, 4096, ImVec2(640, 480));
 
        if (ImGui::Button("Run Sketch")) {
           // state.reset();
            state.doString(windowTitle);
            vm.run();
            state.reset();
            for(auto& x : functions)
            {
                state.loadFunction(std::get<0>(x), std::get<1>(x));
            }
        }
        ImGui::End(); // end window

        ArkText::get_window().clear(bgColor); // fill background with color
        ArkText::draw_circles();
        ArkText::draw_rects();
        ImGui::SFML::Render(ArkText::get_window());
        ArkText::get_window().display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
