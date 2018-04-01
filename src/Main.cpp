#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "jumpaku/kaleidoscopicseal/core/Kaleidoscope.hpp"
#include "jumpaku/kaleidoscopicseal/core/StrokeBuilder.hpp"
#include "jumpaku/kaleidoscopicseal/scenes/Game.hpp"
#include "jumpaku/kaleidoscopicseal/scenes/Title.hpp"
#include "jumpaku/kaleidoscopicseal/scenes/Result.hpp"

using namespace jumpaku::kaleidoscopicseal::core;
using namespace jumpaku::kaleidoscopicseal::scenes;

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
