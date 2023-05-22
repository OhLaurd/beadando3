#include "palya.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;


palya::palya(int x, int y, int sx, int sy,string text):widget(x,y,sx,sy),_text(text)
{
    checked=false;
}

void palya::draw()
{
    for(int i= 1;i<=15;i++)
    {
        gout<<move_to(x0*i,y0)<<color(0,0,0)<< box(sx0,sy0)<<move_to(x0*i,y0) << color(255,255,255)<<
              line_to((x0*i)+sx0,y0)<<line_to((x0*i)+sx0,y0+sy0)<<line_to(x0*i,y0+sy0)<<line_to(x0*i,y0);
        for (int j= 1; j <=15; j++) {
            gout<<move_to(x0*i,y0*j)<<color(0,0,0)<< box(sx0,sy0)<<move_to(x0*i,y0*j) << color(255,255,255)<<
                  line_to((x0*i)+sx0,y0*j)<<line_to((x0*i)+sx0,(y0*j)+sy0)<<line_to(x0*i,(y0*j)+sy0)<<line_to(x0*i,y0*j);

        }
    }




};
void palya::handle(event ev)
{
    for (int i = 1; i <= 15; i++) {
            for (int j = 1 ; j <= 15; j++) {
                if (ev.type == ev_mouse && ev.button == btn_left && x0*i<ev.pos_x && x0*i+sx0>ev.pos_x &&
                        y0*j<ev.pos_y && y0*j+sy0>ev.pos_y) {
                    checked = !checked;
                    gout<<move_to(x0*i,y0+j)<<text("X");
                    }

                }



     }

}
