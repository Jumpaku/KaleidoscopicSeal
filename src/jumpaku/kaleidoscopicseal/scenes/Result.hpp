//
//  Result.hpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#ifndef Result_hpp
#define Result_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Scenes.hpp"

namespace jumpaku::kaleidoscopicseal::scenes
{
    struct Result : MyApp::Scene
    {
        Result(const InitData& init);
        
        void update() override;
        
        void draw() const override;
    };
}


#endif /* Result_hpp */
