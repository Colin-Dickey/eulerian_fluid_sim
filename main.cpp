//
 // @ Author: Colin Dickey
 // @ Create Time: 2025-06-15 16:35:46
 // @ Modified by: Colin Dickey
 // @ Modified time: 2025-06-17 17:43:31
 // @ Description: Main file for the eulerian fluid simulator.
//
#include<iostream>
#include<SFML/Graphics.hpp>
#include<string>
#include<sstream>
#include<iomanip>
#include<cmath>
#include"cell.h"

int main()
{
    int screen_width = 1600;
    int screen_height = 1000;
    int cell_size = 40;
    const float fixed_time_step = 1/30.f;
    const float gravity = 9.81;

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arial.ttf");

    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "FluidSim");

    //Creates grid of line cells
    std::vector<Cell> cells;
    for(int y = 0; y < screen_height / cell_size; y ++)
    {
        for(int x = 0; x < screen_width / cell_size; x ++)
        {
            cells.emplace_back(sf::Vector2i(x,y), cell_size, sf::Vector2f(0, 0));
        }
    }

    sf::Clock clock;

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

        //Velocity Updater
        if(clock.getElapsedTime().asSeconds() >= fixed_time_step)
        {
            for(auto& cell : cells)
            {
                std::cout<<fixed_time_step<<" "<<gravity<<"\n";
                cell.update_velocity(fixed_time_step, gravity);
            }
            clock.restart();
        }

        window.clear();

        //Renders Scene
        for(const auto& cell : cells)
        {
            window.draw(cell);
        }

        window.display();

    }

    return 0;
}