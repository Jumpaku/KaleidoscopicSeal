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
    kaleidoscope(Kaleidoscope(Window::Center(), 6, 360)),
    strokeBuilder(StrokeBuilder(kaleidoscope.originalTriangle.asPolygon(), 3.0)),
    targets(Array<Circle>(5, Arg::generator=[](){ return Circle(RandomVec2(Circle(Window::Center(), 360*Cos(Math::Pi/6))), 10); })){}

void Game::update()
{
    if (MouseL.pressed()) {
        strokeBuilder.update(TimePoint { Time::GetNanosec()*1.0e-9, Cursor::Pos() });
    }
    else if(strokeBuilder.currentState() == StrokeState::Timeout) {
        changeScene(U"Result", 2s);
    }
    else {
        strokeBuilder.reset();
    }
}

void Game::draw() const
{
    kaleidoscope.originalTriangle.draw(Palette::Blue);
    kaleidoscope.reflectedTriangles.each([](auto t){ t.draw(Palette::Aliceblue); });

    if(strokeBuilder.currentState() == StrokeState::Ready) {
        targets.each([](auto t){ t.draw(Palette::Green); });
    }
    else{
        auto s = strokeBuilder.currentPatternStroke();
        auto lines = s.lines;
        for(auto i : Range(1, kaleidoscope.division - 1)) {
            auto m = kaleidoscope.reflection(i);
            s.lines.each([&lines, m](auto l) {
                lines.push_back(Line(m.transform(l.begin), m.transform(l.end)));
            });
        }
        auto hits = TestHits(lines, targets);
        hits.each([](auto hit){ hit.target.draw(hit.isHit ? Palette::Red : Palette::Green); });

        lines.each([](auto l){ l.draw(Palette::Orange); });
    }
}
