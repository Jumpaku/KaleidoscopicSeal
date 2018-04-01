//
//  CollsionDetector.cpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#include "CollsionDetector.hpp"

namespace jumpaku::kaleidoscopicseal::core
{
    Array<HitResult> TestHit(Array<Stroke> stroke, Array<Polygon> targets)
    {
        Array<Line> lines = Array<Line>();
        for (auto s : stroke){
            lines.append(s.lines);
        }
        return targets.map([lines](auto target){
            auto isHit = lines.includes_if([target](auto l){
                return l.intersects(target);
            });
            return HitResult { target, isHit };
        });
    }
}
