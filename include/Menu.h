#include "RoundedButton.h"
#include "Form.h"
#include "DynamicBox.h"
#include "Configuration.h"
#include <raylib.h>
#pragma once
#define Main_button_width 300.0f
#define Main_button_height 50.0f
class Menu : public Form {
public:
    Menu();
    void        init()      override,
                loadAsset() override,
                draw()      override,
                close()     override,
                return_index(const int& index);
    int         run()       override;
    ~Menu();
private:
    const Color     main_box_color = {50, 50, 255, 150},
                    main_button_normal_color = {200, 200, 0, 200},
                    main_button_hover_color = {255, 255, 0, 255};

    bool            isReturned = false,
                    isChosen = false;
    int             difficult = 0;
    OpenVerticalRRectangleBox main_box;
    RoundedButton   start_button,
                    difficult_button,
                    quit_button;
    Texture2D       BACKGROUND_IMAGE;
};