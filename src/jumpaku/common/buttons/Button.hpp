//
//  Buttons.hpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#ifndef Buttons_hpp
#define Buttons_hpp

#include <functional>
#include <Siv3D.hpp>
#include "ButtonInterface.hpp"
#include "ButtonView.hpp"

namespace jumpaku::commons::buttons
{
    class ButtonBuilder;
    
    class Button: public ButtonInterface
    {
        std::function<void(void)> onClicked;
        State state;
        Polygon polygon;
        std::shared_ptr<ButtonView> view;
    protected:
        void setState(State state);
        virtual void fireOnClicked()override;
        virtual void transition()override;
    public:
        static ButtonBuilder builder();
        Button(std::shared_ptr<ButtonView> view, Polygon const &shape, std::function<void(void)> const &onClicked)
        :view(view),
        polygon(shape),
        onClicked(onClicked),
        state(State::Left)
        {}
        virtual ~Button() = default;
        virtual void draw()const override;
        virtual State getState()const override;
        virtual Polygon const &getShape()const;
    };
    
    class ButtonBuilder
    {
        std::function<void(void)> onClicked_;
        std::shared_ptr<ButtonView> view_;
        Polygon polygon_;
    public:
        ButtonBuilder &onClicked(std::function<void(void)> onClicked)
        {
            onClicked_ = onClicked;
            return *this;
        }
        
        template<typename View, typename ...Args>
        ButtonBuilder &view(Args ...args)
        {
            static_assert(std::is_base_of<ButtonView, View>::value, "View is not base of ButtonView");
            view_ = std::make_shared<View>(args...);
            return *this;
        }
        
        ButtonBuilder &polygon(Polygon const &polygon)
        {
            polygon_ = polygon;
            return *this;
        }
        
        std::shared_ptr<ButtonInterface> build()
        {
            return std::make_shared<Button>(view_, polygon_, onClicked_);
        }
    };
}

#endif /* Buttons_hpp */
