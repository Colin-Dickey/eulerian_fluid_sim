//
 // @ Author: Colin Dickey
 // @ Create Time: 2025-06-16 16:02:05
 // @ Modified by: Colin Dickey
 // @ Modified time: 2025-06-17 17:43:33
 // @ Description: This is a header file for an object "cell" which should contain a velocity vector or a unit velocity vector and a speed
//

#ifndef CELL_H
#define CELL_H

#include<SFML/Graphics.hpp>
#include<cmath>
#include<iostream>

class Cell : public sf::Drawable
{
    public:
    sf::Vector2i index;
    sf::Vector2f velocity;
    sf::VertexArray line;

    int cell_size;

    Cell(sf::Vector2i index, int cell_size, sf::Vector2f velocity)
    : index(index), line(sf::Lines, 2), cell_size(cell_size), velocity(velocity)
    {
        line[0].position = sf::Vector2f(cell_size * (index.x + 0.5), cell_size * (index.y + 0.5));
        line[1].position = line[0].position + velocity;

        line[0].color = sf::Color::White;
        line[1].color = sf::Color::White;

    }

    void update_velocity(const float fixed_time_step, const float gravity)
    {
        velocity.y += gravity * fixed_time_step;
        line[1].position += sf::Vector2f(0, velocity.y);

    }

    private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(line, states);
    }

};

#endif
