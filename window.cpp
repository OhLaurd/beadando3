#include "window.hpp"
#include "graphics.hpp"
#include "widget.hpp"

using namespace std;
using namespace genv;


Window::Window(int X, int Y) : XX(X), YY(Y) {
        gout.open(XX,YY);
    gout << font("LiberationSans-Regular.ttf", 15);
}

void Window::event_loop() {
        gout << color(64,64,64) << move_to(0,0) <<box(XX,YY) << color(255,255,255);
    for(widget * wg : widgets) {
        wg-> draw();
    }

    gout<< refresh;
    event ev;
    int focus = -1;
    while(gin >> ev) {
        if(ev.type == ev_mouse && ev.button == btn_left) {
            for(size_t i=0; i<widgets.size(); i++) {
                if(widgets[i]-> selected(ev.pos_x, ev.pos_y)) {
                    focus = i;
                }
            }
        }

        if(focus!=-1) {
            widgets[focus] -> handle(ev);
        }
        for(widget * w : widgets) {
            w->draw();
        }
        gout << refresh;
    }
}
