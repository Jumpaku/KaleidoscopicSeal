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

Mat3x2 Kaleidoscope::reflection(int rectangleIndex) const
{
    if(IsOdd(rectangleIndex)){
        return Mat3x2::Identity()
        .translated(-center)
        .rotated(rectangleIndex*2.0*Math::Pi/division)
        .scaled(-1, 1)
        .translated(center);
    }
    else {
        return Mat3x2::Identity()
        .translated(-center)
        .rotated(rectangleIndex*2.0*Math::Pi/division)
        .translated(center);
    }
}
