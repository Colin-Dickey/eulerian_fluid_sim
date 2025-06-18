//
 // @ Author: Colin Dickey
 // @ Create Time: 2025-06-15 16:35:46
 // @ Modified by: Colin Dickey
 // @ Modified time: 2025-06-18 15:21:10
 // @ Description: Main file for the eulerian fluid simulator.
//
#include<iostream>
#include<SFML/Graphics.hpp>
#include<string>
#include<sstream>
#include<iomanip>
#include<cmath>
#include"cell.h"
#include"functions.h"

int main()
{
    int screen_width = 1000;
    int screen_height = 1000;
    float cell_size = 2.f;
    const float fixed_time_step = 1/30.f;
    const float gravity = 9.81;
    const float diffusion_rate = 0.00002f;
    int grid_size = screen_width / cell_size - 2;

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arial.ttf");

    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "FluidSim");

    // Set coordinate system with +Y up
    sf::View view(sf::FloatRect(0, 0, screen_width, screen_height));
    view.setCenter(screen_width / 2.f, screen_height / 2.f);
    view.setSize(screen_width, -screen_height);  // This flips Y

    window.setView(view);

    //Creates grid of line cells
    std::vector<Cell> cells = cells_setup(screen_height, screen_width, cell_size);

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

        //physics_update(cells, diffusion_rate, fixed_time_step);
        if(clock.getElapsedTime().asSeconds() >= fixed_time_step)
        {
            physics_update(cells, diffusion_rate, fixed_time_step, grid_size);
            render(cells, window);
        }

    }

    return 0;
}