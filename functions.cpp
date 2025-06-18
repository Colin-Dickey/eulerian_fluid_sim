//
 // @ Author: Colin Dickey
 // @ Create Time: 2025-06-18 12:08:27
 // @ Modified by: Colin Dickey
 // @ Modified time: 2025-06-18 15:19:57
 // @ Description: Functions to debloat main
//

#include"functions.h"
#include<SFML/Graphics.hpp>
#include"random.h"
#include"cell.h"

#define IX(i, j) ((i) + (n + 2) * (j))

void render(std::vector<Cell>& cells, sf::RenderWindow& window)
{
    window.clear();

    for(auto& cell : cells)
    {
        int intensity = static_cast<int>(cell.density * 255);

        cell.square.setFillColor(sf::Color(intensity, intensity, intensity));
        cell.square.setOutlineColor(sf::Color(intensity, intensity, intensity));
        window.draw(cell.square);
    }

    for(auto& cell : cells)
    {
        //window.draw(cell.line);
        continue;
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
            if(x == 0 || y == 0 || x == screen_width / cell_size - 1 || y == screen_height / cell_size - 1)
            {
                float density = 0.f;
                cells.emplace_back(sf::Vector2i(x, y), cell_size, sf::Vector2f(y - screen_height / 2 / cell_size, -1 * (x - screen_width / 2 / cell_size)), density);
            }
            else
            {
                float density = random_float(0.f, 1.f);
                cells.emplace_back(sf::Vector2i(x, y), cell_size, sf::Vector2f(y - screen_height / 2 / cell_size, -1 * (x - screen_width / 2 / cell_size)), density);
            }
        }
    }

    return cells;
}

void diffuse(std::vector<Cell>& cells, float diff, float dt, int grid_size)
{
    int i, j, k;
    int n = grid_size;
    float a = dt * diff * n * n;

    std::vector<float> old_density(cells.size());
    for(size_t i = 0; i < cells.size(); i++)
    {
        old_density[i] = cells[i].density;
    } 

    for(j = 1; j <= n; j++)
    {
        for(i = 1; i <= n; i++)
        {
            if(i == 1 && j == 1)
            {
                cells[IX(i, j)].density = old_density[IX(i, j)] + a * (old_density[IX(i + 1, j)] + old_density[IX(i, j + 1)] - 2 * old_density[IX(i, j)]);
            }
            else if(i == 1 && j == n )
            {
                cells[IX(i, j)].density = old_density[IX(i, j)] + a * (old_density[IX(i + 1, j)] + old_density[IX(i, j - 1)] - 2 * old_density[IX(i, j)]);
            }
            else if(i == n  && j == 1)
            {
                cells[IX(i, j)].density = old_density[IX(i, j)] + a * (old_density[IX(i - 1, j)] + old_density[IX(i, j + 1)] - 2 * old_density[IX(i, j)]);
            }
            else if(i == n  && j == n)
            {
                cells[IX(i, j)].density = old_density[IX(i, j)] + a * (old_density[IX(i - 1, j)] + old_density[IX(i, j - 1)] - 2 * old_density[IX(i, j)]);
            }
            else if(i == 1)
            {
                cells[IX(i, j)].density = old_density[IX(i, j)] + a * (old_density[IX(i + 1, j)] + old_density[IX(i, j - 1)] + old_density[IX(i, j + 1)] - 3 * old_density[IX(i, j)]);
            }
            else if(j == 1)
            {
                cells[IX(i, j)].density = old_density[IX(i, j)] + a * (old_density[IX(i - 1, j)] + old_density[IX(i + 1, j)] + old_density[IX(i, j + 1)] - 3 * old_density[IX(i, j)]);
            }
            else if(i == n)
            {
                cells[IX(i, j)].density = old_density[IX(i, j)] + a * (old_density[IX(i - 1, j)] + old_density[IX(i, j - 1)] + old_density[IX(i, j + 1)] - 3 * old_density[IX(i, j)]);
            }
            else if(j == n)
            {
                cells[IX(i, j)].density = old_density[IX(i, j)] + a * (old_density[IX(i - 1, j)] + old_density[IX(i + 1, j)] + old_density[IX(i, j - 1)] - 3 * old_density[IX(i, j)]);
            }
            else
            {
                cells[IX(i, j)].density = old_density[IX(i, j)] + a * (old_density[IX(i - 1, j)] + old_density[IX(i + 1, j)] + old_density[IX(i, j - 1)] + old_density[IX(i, j + 1)] - 4 * old_density[IX(i, j)]);                
            }
        }
    }
}

void physics_update(std::vector<Cell>& cells, float diff, float dt, int grid_size)
{
    //Diffuse densities
    diffuse(cells, diff, dt, grid_size);
}
