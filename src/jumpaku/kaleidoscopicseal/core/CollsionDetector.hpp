//
//  CollsionDetector.hpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#ifndef CollsionDetector_hpp
#define CollsionDetector_hpp

#include <Siv3D.hpp>
#include "Stroke.hpp"

namespace jumpaku::kaleidoscopicseal::core
{
    struct HitResult
    {
        Polygon const target;
        bool const isHit;
    };
    
    Array<HitResult> TestHit(Array<Stroke> stroke, Array<Polygon> targets);
}

#endif /* CollsionDetector_hpp */
