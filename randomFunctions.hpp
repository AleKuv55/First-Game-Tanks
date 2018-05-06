//
//  randomFunctions.hpp
//  Game
//
//  Created by Alexandr Kuznetsov on 05.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#ifndef randomFunctions_hpp
#define randomFunctions_hpp

#include <stdio.h>
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
using namespace std;

int generateRandom(int max);
int generateRandom0(int max);
bool generateRandomBool();
#endif /* randomFunctions_hpp */
