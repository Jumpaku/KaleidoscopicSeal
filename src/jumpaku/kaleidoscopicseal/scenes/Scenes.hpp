//
//  Scenes.hpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#ifndef Scenes_hpp
#define Scenes_hpp

#include <stdio.h>


namespace jumpaku::kaleidoscopicseal::scenes
{
    struct GameData
    {
        Font font = Font(50);
        
        int32 score = 0;
    };

    using MyApp = SceneManager<String, GameData>;
}

#endif /* Scenes_hpp */
