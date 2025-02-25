#include "../include/GameForm.h"
#include <raylib.h>

GameForm::GameForm() {

}

void GameForm::init() {
    loadAsset();
    isReturn = isClose = false;

    HomeButton.setPosition(HomeButton_x, 0);
    HomeButton.setSize(HomeButton_Width, HomeButton_Height);
    HomeButton.normal_color = Home_Normal_Color;
    HomeButton.hover_color = Home_Hover_Color;
    HomeButton.setFontSize(25);
    HomeButton.setText("Snake Game");

    Home_Motion.setRange(0, HomeButton_y);
    Home_Motion.setDuration(400);
    Home_Motion.setDelay(50);

    playground.setWidth(Playground_width); 
    playground.setCenterPosition(Playground_x, Playground_y);
    playground.setRadius(playground_roundness);
    playground.ChildrenVisible = true;
    playground.color = playground_color;
    playground.motion.setRange(0, Playground_height);
    playground.motion.setDuration(500);
    playground.motion.setDelay(50);
    playground.children.push_back(&board);

    clock.start();

    board.init();
    board.setPosition(Playground_x-Playground_width/2, Playground_y-Playground_height/2);
    board.setSize(Playground_width, Playground_height);
    board.setAppleAndTime(15, 60);

    isStart = false;
}
void GameForm::loadAsset() {
    BACKGROUND_IMAGE = LoadTexture(Background_image);
    BACKGROUND_IMAGE.width = SCREEN_WIDTH;
    BACKGROUND_IMAGE.height = SCREEN_HEIGHT;
}
void GameForm::draw() {
    DrawTexture(BACKGROUND_IMAGE, 0, 0, time_color);
    playground.draw();
    DrawRectangleRoundedLinesEx(playground.getBound(), playground_roundness, playground.getPointCount(), playground_bound_thick, playground_bound_color);
    HomeButton.setPosition(HomeButton.getPosition().x, Home_Motion.get());
    HomeButton.draw();
    if (time_color.r != 100) time_color.b = time_color.r = time_color.g = 255 - clock.getTime()/200;
    if (!isStart) notice.draw();
}
void GameForm::close() {
    UnloadTexture(BACKGROUND_IMAGE);
    playground.children.clear();
    board.close();
}

int GameForm::run() {
    Home_Motion.start();
    playground.motion.start();
    notice.setAppleAndTime(15, 60);
    notice.run();
    while (!WindowShouldClose()) {
        if (isStart) {
            HomeButton.handle();
            playground.handle();
        } else notice.handle();
        BeginDrawing();
            draw();
        EndDrawing();
        if (notice.isOk()) isStart = true;
        if (HomeButton.isClicked()) {
            isClose = true;
            return_index = 0;
        }
        if (isReturn && !Home_Motion.isRunning() && !playground.motion.isRunning()) return return_index;
        if (isClose) {
            Home_Motion.setRange(HomeButton_y, -HomeButton_Height);
            Home_Motion.setDelay(0);
            Home_Motion.setDuration(300);
            Home_Motion.start();
            playground.motion.setRange(Playground_height, 0);
            playground.motion.setDelay(0);
            playground.motion.setDuration(300);
            playground.motion.start();
            playground.ChildrenVisible = false;
            isClose = false;
            isReturn = true;
        }
    }
    return -1;
}
GameForm::~GameForm() {

}