#pragma once
class Controller {
public:
    Controller(const int& index);
    int                 getIndex() const;
    virtual void        draw() = 0,
                        handle()  = 0,
                        setPosition(const float& x, const float& y) = 0;
private:
    int                 m_index = -1;
};