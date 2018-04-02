//
//  Stroke.hpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#ifndef Stroke_hpp
#define Stroke_hpp

#include <stdio.h>
#include <Siv3D.hpp>

namespace jumpaku::kaleidoscopicseal::core
{
    struct Stroke
    {
        Stroke(Array<Line> const &lines): lines(lines){}
        Array<Line> const lines;
    };
}

#endif /* Stroke_hpp */
