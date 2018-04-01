#include<Siv3D.hpp>
#include<list>
#include"jumpaku/kaleidoscopicseal/core/Kaleidoscope.hpp"
#include"jumpaku/kaleidoscopicseal/core/StrokeBuilder.hpp"

using namespace jumpaku::kaleidoscopicseal::core;



void Main()
{
    Graphics::SetFullScreen(false, { 1280, 720 });
    Window::Centering();
    
    auto k = Kaleidoscope(Window::Center(), 10, 360);
    auto builder = StrokeBuilder(k.originalTriangle.asPolygon(), 3.0);

    while (System::Update())
    {
        k.originalTriangle.draw(Palette::Blue);
        k.reflectedTriangles.each([](auto t){ t.draw(Palette::Aliceblue); });
        if (MouseL.pressed()) {
            builder.add(TimePoint { Time::GetNanosec()*1.0e-9, Cursor::Pos() });
            auto s = builder.currentPatternStroke();
            s.lines.each([](auto l){ l.draw(4, Palette::Orange); });
            for(auto i : Range(1, k.division - 1)) {
                auto m = k.reflection(i);
                s.lines.each([m](auto l) {
                    Line(m.transform(l.begin), m.transform(l.end)).draw(Palette::Orange);
                });
            }
        }
        else {
            builder.reset();
        }
    }
}
