#include "GameForm.h"
#include "Menu.h"
#include "raylib.h"
#include <vector>
#include "Form.h"
#include "Configuration.h"
#pragma once

class Application {
public:
    Application();
    void                    run();
    ~Application();
private:
    Menu                    menu;
    GameForm                game;
    std::vector<Form*>      forms;
};