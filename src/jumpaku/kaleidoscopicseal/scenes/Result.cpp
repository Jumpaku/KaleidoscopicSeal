//
//  Result.cpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#include "Result.hpp"

using namespace jumpaku::kaleidoscopicseal::scenes;

Result::Result(const InitData& init): IScene(init){}

void Result::update()
{
    if (MouseL.down())
    {
        changeScene(U"Title", 2s);
    }
}

void Result::draw() const
{
    getData().font(U"Result").drawAt(Window::Center());
}
