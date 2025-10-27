#include "../include/Application.h"
#include "../raylib/src/raylib.h"

Application::Application() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, Program_title);
    SetTargetFPS(FPS);

    forms.push_back(&menu);
    forms.push_back(&game);
}

void Application::run() {
    int form_chosen = 0;
    while (!WindowShouldClose() && form_chosen > -1) {
        int old_chosen = form_chosen;
        forms[old_chosen]->init();
        form_chosen = forms[old_chosen]->run();
        forms[old_chosen]->close();
    }
}
Application::~Application() {
    CloseWindow();
}