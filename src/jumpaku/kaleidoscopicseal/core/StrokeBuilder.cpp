//
//  StrokeBuilder.cpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#include "StrokeBuilder.hpp"

using namespace jumpaku::kaleidoscopicseal::core;

StrokeBuilder::StrokeBuilder(Polygon area, double interval)
    :area(area),interval(interval)
{}

void StrokeBuilder::reset()
{
    points.clear();
}

StrokeState StrokeBuilder::currentState()const {
    return state;
}

Stroke StrokeBuilder::currentPatternStroke()const
{
    auto lines = Array<Line>();
    for(auto i : Range(1, points.size() - 1)){
        lines.push_back(Line(points[i - 1].point, points[i].point));
    }
    return Stroke(lines);
}

void StrokeBuilder::add(TimePoint timePoint)
{
    if(points.size() == 0)
        state = StrokeState::Stroke;
    
    if(points.size() > 0 && timePoint.time - points[0].time > interval)
        state = StrokeState::Timeout;
    
    if(state == StrokeState::Stroke && area.intersects(timePoint.point))
        points.push_back(timePoint);
}
