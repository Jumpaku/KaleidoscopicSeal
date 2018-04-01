//
//  Buttons.cpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#include "Button.hpp"

using namespace jumpaku::commons::buttons;

void Button::setState(State state)
{
    state = state;
}

void Button::fireOnClicked()
{
    onClicked();
}

void Button::transition()
{
    switch (getState()) {
    case State::Left:
        if (getShape().mouseOver() && !getShape().leftPressed()) {
            setState(State::MouseOver);
        }
        break;
    case State::MouseOver:
        if (getShape().leftPressed()) {
            setState(State::Pressed);
        }
        else if (!getShape().mouseOver()) {
            setState(State::Left);
        }
        break;
    case State::Pressed:
        if (!getShape().mouseOver()) {
            setState(State::Left);
        }
        else if (getShape().leftReleased()) {
            setState(State::Released);
        }
        break;
    case State::Released:
        setState(State::MouseOver);
        break;
    }
}

ButtonBuilder Button::builder()
{
    return ButtonBuilder();
}

void Button::draw() const
{
    if (view) {
        switch (getState()) {
        case ButtonInterface::State::Left:
            view->drawLeft();
            break;
        case ButtonInterface::State::MouseOver:
            view->drawMouseOver();
            break;
        case ButtonInterface::State::Pressed:
            view->drawPressed();
            break;
        case ButtonInterface::State::Released:
            view->drawReleased();
            break;
        default:
            break;
        }
    }
}

ButtonInterface::State Button::getState() const
{
    return state;
}

Polygon const &Button::getShape() const
{
    return polygon;
}
