//
//  Title.hpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#ifndef Title_hpp
#define Title_hpp

#include <stdio.h>
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Scenes.hpp"

namespace jumpaku::kaleidoscopicseal::scenes
{
    struct Title : MyApp::Scene
    {
        Title(const InitData& init);
        
        void update() override;
        
        void draw() const override;
    };
}

#endif /* Title_hpp */
