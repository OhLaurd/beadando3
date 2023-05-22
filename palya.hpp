#ifndef PALYA_HPP
#define PALYA_HPP
#include "graphics.hpp"
#include "widget.hpp"


class palya: public widget
{
protected:
    bool checked;
    std::string _text;
public:
    palya(int x, int y, int sx, int sy,std::string text);
    virtual void draw();
    virtual void handle(genv::event ev);

};
#endif // PALYA_HPP
