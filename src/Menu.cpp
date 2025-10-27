#include "../include/Menu.h"
#include "../raylib/src/raylib.h"

Menu::Menu(): 
    start_button(1) {
}
void Menu::init() {
    Vector2 center = {(SCREEN_WIDTH - Main_button_width)/2,(SCREEN_HEIGHT - Main_button_height)/2};
    isChosen = isReturned = false;
    loadAsset();

    start_button.setPosition(center.x, center.y - Main_button_height - 20);
    start_button.setSize(Main_button_width, Main_button_height);
    start_button.setRadius(0.5);
    start_button.setText("Start");
    start_button.normal_color = main_button_normal_color;
    start_button.hover_color = main_button_hover_color;

    difficult_button.setPosition(center.x, center.y);
    difficult_button.setSize(Main_button_width, Main_button_height);
    difficult_button.setRadius(0.5);
    difficult_button.setText("Difficult: Easy");
    difficult_button.normal_color = main_button_normal_color;
    difficult_button.hover_color = main_button_hover_color;


    quit_button.setPosition(center.x, center.y + Main_button_height + 20);
    quit_button.setSize(Main_button_width, Main_button_height);
    quit_button.setRadius(0.5);
    quit_button.setText("Quit");
    quit_button.normal_color = main_button_normal_color;
    quit_button.hover_color = main_button_hover_color;

    main_box.setDuration(250);
    main_box.setCenterPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    main_box.setRadius(0.2);
    main_box.setDelay(200);
    main_box.setRange({Menu_width, 0}, {Menu_width, Menu_max_height});
    main_box.color = main_box_color;
    main_box.ChildrenVisible = true;

    main_box.children.push_back(&start_button);
    main_box.children.push_back(&difficult_button);
    main_box.children.push_back(&quit_button);
}
void Menu::loadAsset() {
    BACKGROUND_IMAGE = LoadTexture(Background_image);
    BACKGROUND_IMAGE.width = SCREEN_WIDTH;
    BACKGROUND_IMAGE.height = SCREEN_HEIGHT;
}
void Menu::draw() {
    DrawTexture(BACKGROUND_IMAGE, 0, 0, WHITE);
    main_box.draw();
}
int Menu::run() {
    main_box.start();
    int index = 0;
    while (!WindowShouldClose()) {
        main_box.handle();
        BeginDrawing();
            draw();
        EndDrawing();
        if (start_button.isClicked()) {
            index = difficult+start_button.getIndex();
            isChosen = isReturned = true;
        }
        else if (difficult_button.isClicked()) {
            index = difficult_button.getIndex();
            isChosen = isReturned = true;
        }
        else if (quit_button.isClicked()) {
            index = quit_button.getIndex();
            isChosen = isReturned = true;
        }
        if (isChosen) {
            main_box.children.clear();
            main_box.setRange({Menu_width, Menu_max_height}, {Menu_width, 0});
            main_box.setDelay(0);
            main_box.setDuration(200);
            main_box.start();
            main_box.ChildrenVisible = false;
            isChosen = false;
        }
        if (!main_box.isRunning() && isReturned) return index;
    }
    return 0;
}

void Menu::close() {
    UnloadTexture(BACKGROUND_IMAGE);
}
Menu::~Menu() {
}