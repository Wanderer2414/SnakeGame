#pragma once
#include "Clock.h"
#include "Controller.h"
#include "Configuration.h"
#include <raylib.h>
#include <utility>
#include <vector>

#define snake_side 30
#define time_rect {10,10,100,40}
#define time_rect_roundness 0.2
#define time_rect_point_count 30
#define time_rect_color {100, 100, 250, 200}
#define time_pos_x 30
#define time_pos_y 20
#define time_font_color BLACK
#define time_font_size 30
#define warning_time_remain 50
#define warning_color RED
#define snake_color BLUE
#define snake_eat_color RED
#define snake_eat_side 40
#define apple_size 30
#define time_make_apple 2000
#define score_apple_x SCREEN_WIDTH-140
#define score_apple_y 8
#define score_x score_apple_x+apple_score_size
#define score_y 20
#define score_size 40
#define apple_score_size 50
class BoardGame:public Controller {
public:
    BoardGame(const int& index = -1);
    bool        isComplete(),
                isWin();
    void        setPosition(const float& x, const float& y) override,
                loadAssets(),
                setSize(const float& width, const float& height),
                init(),
                handle()    override,
                draw()      override,
                setAppleAndTime(const int& apple, const int& time),
                close();
    ~BoardGame();
private:
    bool        isStart = false,
                m_isComplete = false,
                m_isWin = false;
    Rectangle   m_bound = {0,0,0,0};
    int         score = 0,
                max_score = 0,
                max_time = 60,
                time_remain = max_time;
    float       speed = 5;
    void        SnakeUpdate();
    size_t      start_clock = 0;
    Clock       clock;
    Texture2D   apple,
                AppleScore;
    Vector2     dir;
    std::vector<std::pair<Rectangle,Color>> snake;
    std::vector<Vector2> apples;
};