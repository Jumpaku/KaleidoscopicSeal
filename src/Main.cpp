# include <Siv3D.hpp>

#include"jumpaku/kaleidoscopicseal/core/Kaleidoscope.hpp"

using namespace jumpaku::kaleidoscopicseal::core;

void Main()
{
    Graphics::SetFullScreen(false, { 1280, 720 });
    Window::Centering();
    Image image(Window::Size(), Palette::White);
    
    auto center = Window::Center();
    auto division = 8;
    auto radius = 360.0;
    
    Array<Vec2> points;
    auto k = Kaleidoscope(center, division, radius);

    while (System::Update())
    {
        if (MouseL.pressed()) {
            points.push_back(Cursor::Pos());
        }
        else {
            points.clear();
        }
        k.originalTriangle.draw(Palette::Blue);
        k.reflectedTriangles.each([](auto t){ t.draw(Palette::Aliceblue); });
        
        LineString(points).draw(4, Palette::Orange);
        k.reflect(points).each([](auto ps){ LineString(ps).draw(Palette::Orange); });
    }
}
