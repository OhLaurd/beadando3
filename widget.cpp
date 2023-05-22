#include "widget.hpp"
#include "graphics.hpp"
using namespace genv;

widget::widget(int x1, int y1, int sx1, int sy1) : x0(x1), y0(y1), sx0(sx1), sy0(sy1)
{
}

bool widget::selected(int mx, int my)
{
    return mx>x0 && mx<x0+sx0 && my>y0 && my<y0+sy0;
}
void write(int x, int y, std::string s){
    int th = gout.cascent() + gout.cdescent();
    gout << move_to(x-gout.twidth(s)/2,y-th/2) << text(s);
}
