#pragma once

class Form {
public:
    Form();
    virtual void            init()      = 0,
                            loadAsset() = 0,
                            draw()      = 0,
                            close()     = 0;
    virtual int             run() = 0;
    ~Form();
};