//
//  ButtonManager.hpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#ifndef ButtonManager_hpp
#define ButtonManager_hpp

#include <memory>
#include <list>
#include <initializer_list>
#include "ButtonInterface.hpp"

namespace jumpaku::commons::buttons
{
    class ButtonManager
    {
        std::list<std::shared_ptr<ButtonInterface>> buttons;
    public:
        ButtonManager() = default;
        ButtonManager(std::initializer_list<std::shared_ptr<ButtonInterface>> buttons);
        ~ButtonManager() = default;
        void add(std::shared_ptr<ButtonInterface> button);
        void update();
        void draw()const;
    };
}

#endif /* ButtonManager_hpp */
