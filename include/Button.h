#pragma once

#include "Controller.h"
#include "General.h"
#include "../raylib/src/raylib.h"
#include <string>

#define Default_Color BLUE
#define Default_text_color BLACK
class Button: public Controller {
public: 
    Button(const int& index = -1);
    bool            isClicked() const;
    void            handle()   override,
                    setPosition(const float& x, const float& y) override,
                    setText(const std::string& text),
                    setTextFillColor(const Color& color),
                    setFontSize(const float& size);
    virtual void    draw() override = 0;
    unsigned int    getPointCount() const;
    Vector2         getPosition() const,
                    getSize() const;
    Color           normal_color = Default_Color,
                    hover_color  = Default_Color,
                    text_normal_color = Default_text_color,
                    text_hover_color = Default_text_color;
protected:
    bool            isHovered;
    float           font_size = 30;
    
    std::string     m_text;
    Rectangle       m_bound = {0, 0, 0, 0},
                    m_text_bound = {0,0,0,font_size};
};