#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include <vector>

class Window {
protected:
    int XX = 400;
    int YY = 400;

    std::vector<widget *> widgets;
public:
    Window(int X, int Y);
    virtual ~Window(){ }
    void event_loop();
    void registerwidget(widget * w) {widgets.push_back(w);}
};


#endif // WINDOW_HPP_INCLUDED
