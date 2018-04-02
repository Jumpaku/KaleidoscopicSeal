//
//  CollsionDetector.cpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#include "TestHits.hpp"

namespace jumpaku::kaleidoscopicseal::core
{
    Array<HitResult> TestHits(Array<Line> lines, Array<Circle> targets)
    {
        auto results = Array<HitResult>();
        for(auto t : targets){
            bool intersects = false;
            for(auto l : lines){
                if (l.intersects(t)) {
                    intersects = true;
                    break;
                }
            }
            results.push_back(HitResult { t, intersects });
        }
        return results;
    }
}
