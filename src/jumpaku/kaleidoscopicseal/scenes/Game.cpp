//
//  Game.cpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#include "Game.hpp"

using namespace jumpaku::kaleidoscopicseal::core;
using namespace jumpaku::kaleidoscopicseal::scenes;

Game::Game(const InitData& init)
    : IScene(init),
    kaleidoscope(Kaleidoscope(Window::Center(), 10, 360)),
    strokeBuilder(StrokeBuilder(kaleidoscope.originalTriangle.asPolygon(), 3.0)){}

void Game::update()
{
    if (MouseL.pressed()) {
        strokeBuilder.update(TimePoint { Time::GetNanosec()*1.0e-9, Cursor::Pos() });
    }
    else {
        strokeBuilder.reset();
    }
}

void Game::draw() const
{
    kaleidoscope.originalTriangle.draw(Palette::Blue);
    kaleidoscope.reflectedTriangles.each([](auto t){ t.draw(Palette::Aliceblue); });
    if(strokeBuilder.currentState() == StrokeState::Ready) return;
    
    auto s = strokeBuilder.currentPatternStroke();
    s.lines.each([](auto l){ l.draw(4, Palette::Orange); });
    for(auto i : Range(1, kaleidoscope.division - 1)) {
        auto m = kaleidoscope.reflection(i);
        s.lines.each([m](auto l) {
            Line(m.transform(l.begin), m.transform(l.end)).draw(Palette::Orange);
        });
    }
}
