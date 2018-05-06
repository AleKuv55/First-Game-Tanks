//
//  GameObject.cpp
//  Game
//
//  Created by Alexandr Kuznetsov on 03.05.2018.
//  Copyright © 2018 Alexandr Kuznetsov. All rights reserved.
//

#include "GameObject.hpp"

GameObject::GameObject()
{}

GameObject::GameObject(double x, double y, sf::Sprite spr, sf::RectangleShape rect):
position_(x, y),
spr_(spr),
rect_(rect)
{}
