//
//  StrokeBuilder.hpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#ifndef StrokeBuilder_hpp
#define StrokeBuilder_hpp

#include <stdio.h>
#include <Siv3D.hpp>
#include "Stroke.hpp"

#endif /* StrokeBuilder_hpp */

namespace jumpaku::kaleidoscopicseal::core {

    struct TimePoint
    {
        double const time;
        Vec2 const point;
    };
    
    enum class StrokeState : int
    {
        Ready, Stroke, Timeout,
    };
    
    class StrokeBuilder
    {
        Array<TimePoint> points;
        
        StrokeState state = StrokeState::Ready;
    public:
        StrokeBuilder(Polygon area, double interval);
        
        Polygon const area;
        
        double const interval;
        
        void reset();
        
        StrokeState currentState()const;
        
        Stroke currentPatternStroke()const;
        
        void add(TimePoint timePoint);
    };
}
