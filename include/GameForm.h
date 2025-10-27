#pragma once
#include "BoardGame.h"
#include "Clock.h"
#include "ImageButton.h"
#include "Form.h"
#include "Configuration.h"
#include "LinearMotion.h"
#include "Menu.h"
#include "DynamicBox.h"
#include "NoticeRound.h"
#include "../raylib/src/raylib.h"

#define Playground_width 700
#define Playground_height 500
#define Playground_x SCREEN_WIDTH/2
#define Playground_y (SCREEN_HEIGHT+30)/2
#define HomeButton_Width 400
#define HomeButton_Height 40
#define HomeButton_x (SCREEN_WIDTH-HomeButton_Width)/2
#define HomeButton_y 10

#define playground_color {100, 100, 200, 240}
#define playground_bound_color {250, 100, 100, 200}
#define playground_bound_thick 5
#define playground_roundness 0.05
#define Home_Normal_Color {150,100,100, 200}
#define Home_Hover_Color {255, 0, 0, 200}

class GameForm:public Form {
public:
    GameForm();
    void            init()      override,
                    loadAsset() override,
                    draw()      override,
                    close()     override;
    int             run()       override;
    ~GameForm();
private:
    bool            isStart = false,
                    isReturn = false,
                    isClose  = false;
    int             return_index = 0;
    Color           time_color = WHITE;
    Clock           clock;
    NoticeRound     notice;
    Texture2D       BACKGROUND_IMAGE;
    RoundedButton   HomeButton;
    BoardGame       board;
    ExpandRRectangleBox playground;
    LinearMotion    Home_Motion;
};