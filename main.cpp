//
 // @ Author: Colin Dickey
 // @ Create Time: 2025-06-15 16:35:46
 // @ Modified by: Colin Dickey
 // @ Modified time: 2025-06-15 17:14:40
 // @ Description: Main file for the eulerian fluid simulator.
//
#include<iostream>
#include<SFML/Graphics.hpp>
#include<string>
#include<sstream>
#include<iomanip>

int main()
{
    int screen_width = 1600;
    int screen_height = 1000;
    float fixed_dt = 0.0167f;

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arial.ttf");

    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "FluidSim");

    sf::Text text_stats;
    text_stats.setFont(font);
    text_stats.setCharacterSize(14);
    text_stats.setFillColor(sf::Color::Cyan);
    text_stats.setPosition(10.f,10.f);

    sf::Clock clock;
    float accumulator = .0f;
    float dt = .0f;
  
    sf::Clock fps_clock;
    float fps = .0f;
    int frame_count = 0;

    while(window.isOpen())
    {
        sf::Event event;
        dt = clock.restart().asSeconds();
        accumulator += dt;

        frame_count++;
        if(fps_clock.getElapsedTime().asSeconds() >= 1.f)
        {
            fps = frame_count / fps_clock.restart().asSeconds();
            frame_count = 0;
        }

        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1)
            << "FPS: " << fps << "\n";
            text_stats.setString(oss.str());

        window.clear();
        window.draw(text_stats);
        window.display();

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }

    return 0;
}