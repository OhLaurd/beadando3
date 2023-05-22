
//#include "kijelzo.hpp"
//#include "nyomogomb.hpp"
#include "widget.hpp"
//#include "szamos.hpp"
//#include "kivalaszto.hpp"
#include "palya.hpp"

#include <vector>
using namespace std;
using namespace genv;

void loop(vector<widget*>& widgets) {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        for (widget * w : widgets) {
            w->draw();
        }
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }

        gout << refresh;
    }

}

int main()
{
    gout.open(400,400);
    gout.load_font("Fonts/LiberationSans-Bold.ttf");
    vector<widget*> w;
    vector<string>v;
    for(int i =0;i<5;i++)
        v.push_back(to_string(rand()));
    /*szamos * s1 = new szamos(10,100,60,30);
    kivalaszto * k1 = new kivalaszto(10,200,60,140,v);
    w.push_back(s1);
    w.push_back(k1);
    nyomogomb * n1 = new nyomogomb(10,150,30,30,"1");
    nyomogomb * n2 = new nyomogomb(50,150,30,30,"2");
    nyomogomb * n3 = new nyomogomb(10,190,30,30,"3");
    nyomogomb * n4 = new nyomogomb(50,190,30,30,"+");
    kijelzo * j1 = new kijelzo(10,110,70,30);
    w.push_back(n1);
    w.push_back(n2);
    w.push_back(n3);
    w.push_back(n4);
    w.push_back(j1);*/
    palya * p1 = new palya(20,20,40,40,"");
    w.push_back(p1);




    for (widget * wg : w) {
    wg->draw();
}
gout << refresh;
loop(w);
return 0;
}
