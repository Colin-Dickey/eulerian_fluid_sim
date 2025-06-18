//
 // @ Author: Colin Dickey
 // @ Create Time: 2025-06-16 16:02:05
 // @ Modified by: Colin Dickey
 // @ Modified time: 2025-06-18 15:19:23
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
    float density;

    sf::VertexArray line;
    sf::RectangleShape square;

    int cell_size;

    Cell(sf::Vector2i index, int cell_size, sf::Vector2f velocity, float density)
    : index(index), line(sf::Lines, 2), cell_size(cell_size), velocity(velocity), density(density)
    {
        line[0].position = sf::Vector2f(cell_size * (index.x + 0.5), cell_size * (index.y + 0.5));
        line[1].position = line[0].position + velocity;

        line[0].color = sf::Color::Red;
        line[1].color = sf::Color::Cyan;

        square.setSize(sf::Vector2f(cell_size, cell_size));
        square.setPosition(sf::Vector2f(cell_size * index.x, cell_size * index.y));
        square.setFillColor(sf::Color(50, 50, 50));
        square.setOutlineThickness(1);
        square.setOutlineColor(sf::Color(50, 50, 50));
    }

    private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(square, states);
        target.draw(line, states);
    }

};

#endif
