//
 // @ Author: Colin Dickey
 // @ Create Time: 2025-06-16 16:02:05
 // @ Modified by: Colin Dickey
 // @ Modified time: 2025-06-17 15:47:28
 // @ Description: This is a header file for an object "cell" which should contain a velocity vector or a unit velocity vector and a speed
//

#ifndef CELL_H
#define CELL_H

#include<SFML/Graphics.hpp>
#include<cmath>

class Cell : public sf::Drawable
{
    public:
    sf::Vector2i index;
    sf::VertexArray line;

    int cell_size;

    Cell(sf::Vector2i index, int cell_size)
    : index(index), line(sf::Lines, 2), cell_size(cell_size)
    {
        line[0].position = sf::Vector2f(cell_size * (index.x + 0.5), cell_size * (index.y + 0.5));
        line[1].position = sf::Vector2f(line[0].position.x, line[0].position.y);

        line[0].color = sf::Color::White;
        line[1].color = sf::Color::White;

    }

    void update_direction(const sf::Vector2f& target)
    {
        sf::Vector2f center = line[0].position;
        sf::Vector2f direction = target - center;

        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        length = static_cast<float>(std::pow(length,1.6));
        direction = direction * 10.f / length;

        line[1].position = center + sf::Vector2f(direction.x * cell_size / 2, direction.y * cell_size / 2);
    }

    private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(line, states);
    }

};

#endif
