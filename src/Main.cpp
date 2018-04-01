# include <Siv3D.hpp>



void Main()
{
    Graphics::SetFullScreen(false, { 1280, 720 });
    Window::Centering();
    Image image(Window::Size(), Palette::White);
    
    auto center = Window::Center();
    auto division = 6;
    auto theta = 2.0*Math::Pi/division;
    auto radius = 360.0;
    auto baseTriangle = Triangle(center, center + radius*Vec2(Cos(theta), Sin(theta)), center + radius*Vec2(Cos(2*theta), Sin(2*theta)));
    
    Array<Vec2> points;

    while (System::Update())
    {
        if (MouseL.pressed()) {
            points.push_back(Cursor::Pos());
        }
        else {
            points.clear();
        }
        
        baseTriangle.draw(Palette::Blue);
        LineString(points).draw(4, Palette::Orange);
        for(auto i : Range(1, 5)){
            baseTriangle.rotatedAt(center, i*theta).draw(Palette::Aqua);
            LineString(points.map([=](auto p) {
                if(IsOdd(i)){
                    auto v = (p - center).rotated(2*i*theta);
                    return Vec2(v.x, -v.y) + center;
                }
                else {
                    return (p - center).rotated(i*theta) + center;
                }
            })).draw(2, Palette::Beige);
        }
    }
}
