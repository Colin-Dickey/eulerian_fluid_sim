//
 // @ Author: Colin Dickey
 // @ Create Time: 2025-06-16 16:02:05
 // @ Modified by: Colin Dickey
 // @ Modified time: 2025-06-18 12:33:11
 // @ Description: This is a header file for an object "cell" which should contain a velocity vector or a unit velocity vector and a speed
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<SFML/Graphics.hpp>
#include<cmath>
#include<iostream>
#include"cell.h"

void render(std::vector<Cell>& cells, sf::RenderWindow& window);

std::vector<Cell> cells_setup(float screen_height, float screen_width, int cell_size);

void physics_update(std::vector<Cell>& cells, float diff, float dt);

#endif