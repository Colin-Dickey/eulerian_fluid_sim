//
 // @ Author: Colin Dickey
 // @ Create Time: 2025-06-18 12:41:15
 // @ Modified by: Colin Dickey
 // @ Modified time: 2025-06-18 12:50:13
 // @ Description: File containing random engine information
//

#ifndef RANDOM_H
#define RANDOM_H

#include<random>

float random_float(float min, float max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}


#endif