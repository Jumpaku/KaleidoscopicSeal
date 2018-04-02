//
//  Title.cpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#include "Title.hpp"

using namespace jumpaku::kaleidoscopicseal::scenes;

Title::Title(const InitData& init): IScene(init){}

void Title::update()
{
    if (MouseL.down())
    {
        changeScene(U"Story", 2s);
    }
}

void Title::draw() const
{
    getData().font(U"Title").drawAt(Window::Center());
}
