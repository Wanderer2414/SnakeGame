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
    Home_Motion.setDelay(0);

    playground.setCenterPosition(Playground_x, Playground_y);
    playground.setRadius(playground_roundness);
    playground.ChildrenVisible = true;
    playground.color = playground_color;
    playground.setRange({Playground_width, 0}, {Playground_width, Playground_height});
    playground.setDuration(500);
    playground.setDelay(0);
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
    if (!isStart) notice.draw();
    else {
        playground.draw();
        DrawRectangleRoundedLinesEx(playground.getBound(), playground_roundness, playground.getPointCount(), playground_bound_thick, playground_bound_color);
        HomeButton.setPosition(HomeButton.getPosition().x, Home_Motion.get());
        HomeButton.draw();
    }
}
void GameForm::close() {
    UnloadTexture(BACKGROUND_IMAGE);
    playground.children.clear();
    board.close();
}

int GameForm::run() {
    notice.setAppleAndTime(15, 60);
    notice.run();
    while (!WindowShouldClose()) {
        if (isStart) {
            HomeButton.handle();
            playground.handle();
        } else notice.handle();
        if (!isStart && notice.isOk()) {
            isStart = true;
            Home_Motion.start();
            playground.start();
        }
        BeginDrawing();
            draw();
        EndDrawing();
        if (HomeButton.isClicked()) {
            isClose = true;
            return_index = 0;
        }
        if (isReturn && !Home_Motion.isRunning() && !playground.isRunning()) return return_index;
        if (isClose) {
            Home_Motion.setRange(HomeButton_y, -HomeButton_Height);
            Home_Motion.setDelay(0);
            Home_Motion.setDuration(300);
            Home_Motion.start();
            playground.setRange({Playground_width, Playground_height}, {Playground_width, 0});
            playground.setDelay(0);
            playground.setDuration(300);
            playground.start();
            playground.ChildrenVisible = false;
            isClose = false;
            isReturn = true;
        }
    }
    return -1;
}
GameForm::~GameForm() {

}