//
//  Kaleidoscope.cpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/01.
//

#include "Kaleidoscope.hpp"

using namespace jumpaku::kaleidoscopicseal::core;

Kaleidoscope::Kaleidoscope(Vec2 center, int division, double radius)
:   center(center),
    division(division),
    originalTriangle(makeOriginalTriangle(center, division, radius)),
    reflectedTriangles(reflectTriangles(center, division, originalTriangle))
{}

Triangle Kaleidoscope::makeOriginalTriangle(Vec2 center, int division, double radius)
{
    return Triangle(
                    Vec2(),
                    radius*Vec2(Cos((1.0/division + 0.5)*Math::Pi), Sin((1.0/division + 0.5)*Math::Pi)),
                    radius*Vec2(Cos((-1.0/division + 0.5)*Math::Pi), Sin((-1.0/division + 0.5)*Math::Pi)))
    .movedBy(center);
}

Array<Triangle> Kaleidoscope::reflectTriangles(Vec2 center, int division, Triangle originalTriangle)
{
    return Range(1, division - 1).map([=](auto i){
        return originalTriangle.rotatedAt(center, i*2*Math::Pi/division);
    }).asArray();
}

Array<Array<Vec2>> Kaleidoscope::reflect(Array<Vec2> const &points) const
{
    return Range(1, division-1).map([points, this](int i){
        return points.map([i, this](auto p) {
            auto v = (p - center).rotated(i*2.0*Math::Pi/division);
            return (IsOdd(i) ? Vec2(v.x, -v.y) : v) + center;
        });
    }).asArray();
}
