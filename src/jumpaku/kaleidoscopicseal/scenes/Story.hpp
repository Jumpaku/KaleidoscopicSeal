//
//  Story.hpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#ifndef StoryScene_hpp
#define StoryScene_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Scenes.hpp"

namespace jumpaku::kaleidoscopicseal::scenes
{
    struct Story : MyApp::Scene
    {
        Story(const InitData& init);
        
        void update() override;
        
        void draw() const override;
    };
}

#endif /* StoryScene_hpp */
