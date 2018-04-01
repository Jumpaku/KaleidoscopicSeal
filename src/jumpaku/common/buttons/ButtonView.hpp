//
//  ButtonView.hpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#ifndef ButtonView_hpp
#define ButtonView_hpp

namespace jumpaku::commons::buttons
{
    struct ButtonView
    {
        virtual void drawMouseOver()const = 0;
        virtual void drawPressed()const = 0;
        virtual void drawReleased()const = 0;
        virtual void drawLeft()const = 0;
    };
}

#endif /* ButtonView_hpp */
