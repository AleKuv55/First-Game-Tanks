//
//  Vector.hpp
//  Game
//
//  Created by Alexandr Kuznetsov on 03.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

using namespace std;

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <cmath>
#include "ResourcePath.hpp"
#include <cstdlib>
#include <functional>
#include <tgmath.h>
#include <deque>
#include <list>
#include <vector>
#include <unistd.h>
#include <stdio.h>
class Vector
{
public:
    double x_;
    double y_;
    
    Vector()
    {
    }
    
    Vector(double x, double y)
    {
        x_ = x;
        y_ = y;
    }
    
};
#endif /* Vector_hpp */
