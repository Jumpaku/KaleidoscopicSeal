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
    state = StrokeState::Ready;
}

StrokeState StrokeBuilder::currentState()const
{
    return state;
}

Stroke StrokeBuilder::currentPatternStroke()const
{
    if(points.size() == 1) return Stroke(Array<Line> { Line(points[0].point, points[0].point) });
    auto lines = Array<Line>();
    for(auto i : Range(1, points.size() - 1)){
        lines.push_back(Line(points[i - 1].point, points[i].point));
    }
    return Stroke(lines);
}

void StrokeBuilder::update(TimePoint timePoint)
{
    switch (state) {
    case StrokeState::Ready:
        if(area.intersects(timePoint.point)) {
            state = StrokeState::Stroke;
            points.push_back(timePoint);
        }
        break;
    case StrokeState::Stroke:
        if(area.intersects(timePoint.point)){
            points.push_back(timePoint);
        }
        if(timePoint.time - points[0].time > interval){
            state = StrokeState::Timeout;
        }
        break;
    default:
        break;
    }
}
