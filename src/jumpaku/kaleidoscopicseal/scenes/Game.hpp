//
//  Game.hpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Scenes.hpp"
#include "../core/Kaleidoscope.hpp"
#include "../core/StrokeBuilder.hpp"
#include "../core/TestHits.hpp"

namespace jumpaku::kaleidoscopicseal::scenes
{
    struct Game : MyApp::Scene
    {
        jumpaku::kaleidoscopicseal::core::Kaleidoscope kaleidoscope;
        
        jumpaku::kaleidoscopicseal::core::StrokeBuilder strokeBuilder;
        
        Array<Circle> targets;
        
        Game(const InitData& init);
        
        void update() override;
        
        void draw() const override;
    };
}

#endif /* Game_hpp */
