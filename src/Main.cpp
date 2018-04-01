#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "jumpaku/kaleidoscopicseal/core/Kaleidoscope.hpp"
#include "jumpaku/kaleidoscopicseal/core/StrokeBuilder.hpp"
#include "jumpaku/kaleidoscopicseal/scenes/Game.hpp"

using namespace jumpaku::kaleidoscopicseal::core;
using namespace jumpaku::kaleidoscopicseal::scenes;

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
        getData().font(U"Title").drawAt(Window::Center());
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
        getData().font(U"Title").drawAt(Window::Center());
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
