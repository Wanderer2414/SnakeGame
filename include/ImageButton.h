#pragma once
#include "Button.h"
#include <raylib.h>
#include <string>

class ImageButton:public Button {
public:
    ImageButton(const int& index = -1);
    void        draw() override,
                setSize(const float& width, const float& height),
                setImage(const std::string& image),
                unsetImage();
    ~ImageButton();
private:
    Texture2D   m_image;
};