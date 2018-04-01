#include<Siv3D.hpp>
 # include <HamFramework.hpp>
#include"jumpaku/kaleidoscopicseal/core/Kaleidoscope.hpp"
#include"jumpaku/kaleidoscopicseal/core/StrokeBuilder.hpp"

using namespace jumpaku::kaleidoscopicseal::core;

struct GameData
{
    Font font = Font(50);
    
    int32 score = 0;
};

using MyApp = SceneManager<String, GameData>;

struct Title : MyApp::Scene
{
    Title(const InitData& init): IScene(init){}
    
    void update() override
    {
        if (MouseL.down())
        {
            changeScene(U"Game", 2s);
        }
    }
    
    void draw() const override
    {
        getData().font(U"Title").drawAt(Window::BaseCenter());
    }
};

struct Game : MyApp::Scene
{
    Kaleidoscope kaleidoscope = Kaleidoscope(Window::Center(), 10, 360);
    
    StrokeBuilder strokeBuilder = StrokeBuilder(kaleidoscope.originalTriangle.asPolygon(), 3.0);
    
    Game(const InitData& init): IScene(init){}
    
    void update() override
    {
        if (MouseL.pressed()) {
            strokeBuilder.add(TimePoint { Time::GetNanosec()*1.0e-9, Cursor::Pos() });
        }
        else {
            strokeBuilder.reset();
        }
    }
    
    void draw() const override
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
};

struct Result : MyApp::Scene
{
    Result(const InitData& init): IScene(init){}
    
    void update() override
    {
        if (MouseL.down())
        {
            changeScene(U"Title", 2000);
        }
    }
    
    void draw() const override
    {
        getData().font(U"Result").drawAt(Window::BaseCenter());
        
        getData().font(getData().score).drawAt(Window::BaseCenter().movedBy(0, 60));
    }
};


void Main()
{
    Graphics::SetFullScreen(false, { 1280, 720 });
    Window::Centering();
    
    const auto p = MakeShared<GameData>();
    
    MyApp manager;
    manager.add<Title>(U"Title").add<Game>(U"Game").add<Result>(U"Result");
    
    while (System::Update())
    {
        if (!manager.update())
        {
            break;
        }
    }
}
