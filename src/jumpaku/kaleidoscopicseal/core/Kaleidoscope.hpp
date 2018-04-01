//
//  Kaleidoscope.hpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/01.
//

#ifndef Kaleidoscope_hpp
#define Kaleidoscope_hpp

#include <stdio.h>
#include <Siv3D.hpp>

#endif /* Kaleidoscope_hpp */

namespace jumpaku::kaleidoscopicseal::core {
    
    struct Kaleidoscope
    {
        Kaleidoscope(Vec2 center, int division, double radius);
        
        static Triangle makeOriginalTriangle(Vec2 center, int division, double radius);
        
        static Array<Triangle> reflectTriangles(Vec2 center, int division, Triangle originalTriangle);
        
        Vec2 const center;
        
        int const division;
        
        Triangle const originalTriangle;
        
        Array<Triangle> const reflectedTriangles;
        
        Mat3x2 reflection(int rectangleIndex) const;
    };
}
