#include "../include/BoardGame.h"
#include <cmath>
#include <ctime>
#include "../raylib/src/raylib.h"
#include <string>

BoardGame::BoardGame(const int& index):Controller(index) {

}
void BoardGame::setPosition(const float& x, const float& y) {
    m_bound.x = x;
    m_bound.y = y;
    for (auto& i:snake) {
        i.first.y = m_bound.y + 10;
        i.first.x = m_bound.x + 10;
        i.first.width = i.first.height = snake_side;
    }
}
void BoardGame::setAppleAndTime(const int& apple, const int& time) {
    max_score  = apple;
    max_time = time;
}
void BoardGame::setSize(const float& width, const float& height) {
    m_bound.width = width;
    m_bound.height = height;
}
void BoardGame::loadAssets() {
    apple = LoadTexture(apple_image);
    apple.width = apple.height = apple_size;
    AppleScore = LoadTexture(apple_image);
    AppleScore.width = AppleScore.height = apple_score_size;
}
void BoardGame::init() {
    for (int i = 0; i<2; i++) snake.push_back({{m_bound.x + 10, m_bound.y + 10}, snake_color});
    loadAssets();
    srand(time(0));
    start_clock = clock.getTime();
    score = 0;
    isStart = false;
    time_remain = max_time;
    dir = {0,0};
}
float distance(const Vector2& vec) {
    return std::sqrt(vec.x*vec.x + vec.y*vec.y);
}
void BoardGame::SnakeUpdate() {
    for (int i = snake.size()-1; i>0; i--) {
        if (Vector2 vec = {snake[i-1].first.x-snake[i].first.x, snake[i-1].first.y - snake[i].first.y}; distance(vec)>snake_side/2) {
            float dis = distance(vec);
            snake[i].first.x += vec.x/dis*(dis-snake_side/2);
            snake[i].first.y += vec.y/dis*(dis-snake_side/2);
            snake[i].first.width = snake[i].first.height = snake_side;
        }
        snake[i].second = snake[i-1].second;
        if (snake[i-1].first.width > snake_side) snake[i].first.width = snake[i].first.height = snake[i-1].first.width;
    }
    isStart = true;
}
void BoardGame::handle() {
    if (score==max_score) {
        m_isComplete = true;
        m_isWin = true;
        return ;
    } else  if (time_remain<=0) {
        m_isComplete = true;
        m_isWin = false;
        return;
    }
    speed = 5;
    if (IsKeyDown(KEY_SPACE)) speed = 10;
    if (IsKeyDown(KEY_LEFT_CONTROL)) speed = 2;
    if (IsKeyDown(KEY_RIGHT)) {
        dir = {1, 0};
    }
    else if (IsKeyDown(KEY_LEFT)) {
        dir = {-1, 0};
    }
    else if (IsKeyDown(KEY_DOWN)) {
        dir = {0, 1};
    }
    else if (IsKeyDown(KEY_UP)) {
        dir = {0, -1};
    };
    if ((snake[0].first.x+snake_side    > m_bound.x+m_bound.width-5     && dir.x>0  ) ||
        (snake[0].first.x               < m_bound.x              +5     && dir.x<0  ) ||
        (snake[0].first.y + snake_side  > m_bound.y + m_bound.height -5 && dir.y>0  ) ||
        (snake[0].first.y               < m_bound.y                  +5 && dir.y<0)) 
            dir = {0,0};
    if (dir.x || dir.y) SnakeUpdate();
    snake[0].first.x += dir.x*speed;
    snake[0].first.y += dir.y*speed;
    for (int i = apples.size()-1; i>=0; i--) {
        Vector2 dis = {snake.front().first.x-apples[i].x, snake.front().first.y-apples[i].y};
        if (distance(dis)<apple_size*2/3) {
            apples.erase(apples.begin()+i); 
            score++;
            snake.push_back({{snake.back().first.x, snake.back().first.y}, snake_color});
            snake[1].second = snake_eat_color;
            snake[1].first.width = snake[1].first.height = snake_eat_side;
        }
    }
    if (isStart && clock.getTime()-start_clock>time_make_apple) {
        float x = rand()%(int)std::round(m_bound.width-apple_size) + m_bound.x;
        float y = rand()%(int)std::round(m_bound.height-apple_size) + m_bound.y;
        apples.push_back({x,y});
        start_clock = clock.getTime();
    }
    if (isStart) {
        time_remain = max_time - clock.getTime()/1000;
    } else clock.start();
}
void BoardGame::draw() {
    for (auto& i:apples) DrawTexture(apple, i.x, i.y, WHITE);
    for (int i = snake.size()-1; i>=0; i--)  {
        DrawRectangle(snake[i].first.x, snake[i].first.y, snake[i].first.width,snake[i].first.height, snake[i].second);
        DrawRectangleLinesEx(snake[i].first, 5.0f, BLACK);
    }
    DrawRectangleRounded(time_rect, time_rect_roundness, time_rect_point_count, time_rect_color);
    if (time_remain > warning_time_remain) {
        DrawText((std::to_string(time_remain/60)+":"+std::to_string(time_remain%60)).c_str(),time_pos_x, time_pos_y, time_font_size, time_font_color);
    } else {
        auto tmp = clock.getTime()/400%2;
        if (tmp) 
            DrawText((std::to_string(time_remain/60)+":"+std::to_string(time_remain%60)).c_str(),time_pos_x, time_pos_y, time_font_size, warning_color);
    }
    DrawTexture(AppleScore, score_apple_x, score_apple_y, WHITE);
    DrawText(("x" + std::to_string(score)).c_str(), score_x, score_y, score_size, BLACK);
}
void BoardGame::close() {
    snake.clear();
    apples.clear();
    UnloadTexture(apple);
    snake.clear();
}
BoardGame::~BoardGame() {

}