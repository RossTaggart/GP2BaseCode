//
//  Keyboard.cpp
//  GP2BaseCode
//
//  Created by Brian on 23/10/2014.
//  Copyright (c) 2014 Glasgow Caledonian University. All rights reserved.
//

#include "Input/Keyboard.h"

Keyboard::Keyboard()
{
    for(int i=0;i<MAX_NO_KEYS;i++)
    {
        keysDown[i]=false;
        keysUp[i]=false;
    }
}

Keyboard::~Keyboard()
{
    
}

void Keyboard::setKeyDown(short index)
{
    keysDown[index]=true;
    keysUp[index]=false;
}

void Keyboard::setKeyUp(short index)
{
    keysDown[index]=false;
    keysUp[index]=true;
}

bool Keyboard::isKeyDown(short index)
{
    return keysDown[index];
}

bool Keyboard::isKeyUp(short index)
{
    return keysUp[index];
}