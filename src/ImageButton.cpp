#include "../include/ImageButton.h"

ImageButton::ImageButton(const int& index):Button(index) {

}
void ImageButton::setSize(const float& width, const float& height) {
    m_bound.width = m_image.width = width;
    m_bound.height = m_image.height = height;
    m_text_bound.x = m_bound.x + m_bound.width/2 - m_text_bound.width/2;
    m_text_bound.y = m_bound.y + m_bound.height/2 - m_text_bound.height/2;
}
void ImageButton::setImage(const std::string& image) {
    unsetImage();
    m_image = LoadTexture(image.c_str());
    m_image.width = m_bound.width;
    m_image.height = m_bound.height;
}
void ImageButton::unsetImage() {
    UnloadTexture(m_image);
}
void ImageButton::draw() {
    if (isHovered) {
        DrawTexture(m_image, m_bound.x, m_bound.y, hover_color);
        DrawText(m_text.c_str(), m_text_bound.x, m_text_bound.y, font_size, text_hover_color);
    }
    else {
        DrawTexture(m_image, m_bound.x, m_bound.y, normal_color);
        DrawText(m_text.c_str(), m_text_bound.x, m_text_bound.y, font_size, text_normal_color);
    }
}
ImageButton::~ImageButton() {
    unsetImage();
}