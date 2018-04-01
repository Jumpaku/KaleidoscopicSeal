//
//  ButtonInterface.hpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#ifndef ButtonInterface_hpp
#define ButtonInterface_hpp

#include <stdio.h>

namespace jumpaku::buttons
{
    struct ButtonInterface
    {
        enum class State
        {
            MouseOver, Pressed, Released, Left,
        };
    protected:
        virtual void fireOnClicked() = 0;
        virtual void transition() = 0;
    public:
        virtual void update()
        {
            transition();
            if (getState() == State::Released) fireOnClicked();
        }
        virtual void draw()const = 0;
        virtual State getState()const = 0;
        virtual ~ButtonInterface() = default;
    };
}

#endif /* ButtonInterface_hpp */
