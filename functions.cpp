//
 // @ Author: Colin Dickey
 // @ Create Time: 2025-06-18 12:08:27
 // @ Modified by: Colin Dickey
 // @ Modified time: 2025-06-18 13:02:17
 // @ Description: Functions to debloat main
//

#include"functions.h"
#include<SFML/Graphics.hpp>
#include"random.h"
#include"cell.h"

void render(std::vector<Cell>& cells, sf::RenderWindow& window)
{
    window.clear();

    for(auto& cell : cells)
    {
        int intensity = static_cast<int>(cell.density * 255);

        cell.square.setFillColor(sf::Color(intensity, intensity, intensity));
        window.draw(cell.square);
    }

    for(auto& cell : cells)
    {
        window.draw(cell.line);
    }

    window.display();
}

std::vector<Cell> cells_setup(float screen_height, float screen_width, int cell_size)
{
    std::vector<Cell> cells;
    for(int y = 0; y < screen_height / cell_size; y ++)
    {
        for(int x = 0; x < screen_width / cell_size; x ++)
        {
            float density = random_float(0.f, 1.f);
            cells.emplace_back(sf::Vector2i(x, y), cell_size, sf::Vector2f(y - screen_height / 2 / cell_size, -1 * (x - screen_width / 2 / cell_size)), density);
        }
    }

    return cells;
}

void physics_update(std::vector<Cell>& cells, float diff, float dt)
{
    
}
