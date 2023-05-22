#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED


#include "graphics.hpp"

class widget {
protected:
    int x0, y0, sx0, sy0;
public:
    widget(int x1, int y1, int sx1, int sy1);
    virtual bool selected(int mx, int my);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;



};
#endif // WIDGET_HPP_INCLUDED
