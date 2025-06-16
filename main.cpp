//
 // @ Author: Colin Dickey
 // @ Create Time: 2025-06-15 16:35:46
 // @ Modified by: Colin Dickey
 // @ Modified time: 2025-06-16 15:59:57
 // @ Description: Main file for the eulerian fluid simulator.
//
#include<iostream>
#include<SFML/Graphics.hpp>
#include<string>
#include<sstream>
#include<iomanip>

int main()
{
    float fps_max = 60.f;
    int screen_width = 1600;
    int screen_height = 1000;
    float fixed_dt = 1 / fps_max;

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arial.ttf");

    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "FluidSim");

    sf::Text text_stats;
    text_stats.setFont(font);
    text_stats.setCharacterSize(14);
    text_stats.setFillColor(sf::Color::Cyan);
    text_stats.setPosition(10.f,10.f);

    sf::Clock clock;
    sf::Clock clock_fps;
    int frame_counter = 0;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        frame_counter++;
        //Updates FPS every second
        if(clock_fps.getElapsedTime().asSeconds() >= 1)
        {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(1)
                << "FPS: " << (frame_counter) << "\n";
            
            text_stats.setString(oss.str());
            window.draw(text_stats);
            
            clock_fps.restart();
            frame_counter = 0;
        }

        window.clear();
        //Renders Scene

        window.draw(text_stats);
        window.display();


    }

    return 0;
}