//
//  Story.cpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#include "Story.hpp"

using namespace jumpaku::kaleidoscopicseal::scenes;

Story::Story(const InitData& init): IScene(init){}

void Story::update()
{
    if (MouseL.down())
    {
        changeScene(U"Game", 2s);
    }
}

void Story::draw() const
{
    getData().font(U"Story").drawAt(Window::Center());
}
