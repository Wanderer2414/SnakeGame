#include "../raylib/src/raylib.h"
#include "Controller.h"
#include "Button.h"

class RoundedButton: public Button {
    public: 
        RoundedButton(const int& index = -1);
        void            draw()  override,
                        setSize(const float& x, const float& y),
                        setRadius(const float& radius),
                        sePointcount(const unsigned int& n);
        unsigned int    getPointCount() const;
        float           getRadius() const;
    private:
        unsigned int    m_point_count = 30;
        float           m_radius = 0.5;
    };