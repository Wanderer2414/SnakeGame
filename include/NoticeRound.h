#pragma once
#include "Clock.h"
#include "Controller.h"
#include "LinearMotion.h"
#include "Configuration.h"
#include "../raylib/src/raylib.h"

#define n_width SCREEN_WIDTH
#define n_height 200
#define n_roundness 0.1
#define notice_point_count 30

class NoticeRound:Controller {
public:
    NoticeRound(const int& index = -1);
    bool                isOk();
    virtual void        draw()      override,
                        handle()    override,
                        setPosition(const float& x, const float& y) override;
    void                run(),
                        loadAssets(),
                        unloadAssets(),
                        setAppleAndTime(const int& apple, const int& time);
private:
    bool                m_is_ok = false;
    int                 m_apple = 0,
                        m_time  = 0;
    Clock               clock;
    Rectangle           m_bound;
    Texture2D           APPLE_IMAGE;
    LinearMotion        motion;
};