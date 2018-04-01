//
//  ButtonManager.cpp
//  KaleidoscopicSeal
//
//  Created by Jumpaku on 2018/04/02.
//

#include "ButtonManager.hpp"
#include <algorithm>

using namespace std;
using namespace jumpaku::commons::buttons;

ButtonManager::ButtonManager(initializer_list<shared_ptr<ButtonInterface>> buttons):buttons(buttons.begin(), buttons.end()){}

void ButtonManager::add(shared_ptr<ButtonInterface> button)
{
    buttons.push_back(button);
}

void ButtonManager::update()
{
    for_each(buttons.begin(), buttons.end(), [](shared_ptr<ButtonInterface> const &button) {
        if (button) button->update();
    });
}

void ButtonManager::draw()const
{
    for_each(buttons.begin(), buttons.end(), [](shared_ptr<ButtonInterface> const &button) {
        if (button) button->draw();
    });
}
