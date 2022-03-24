// g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill15func_graphing.cpp `fltk-config --ldflags --use-images` -o a.out
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x) + slope(x);}

int main(){

	try{
		//1. 600x 600 ablak, piros tengelyek
		Point t1 {300, 300};
		Simple_window win {{100,100}, 600, 600, "Function graphs."};

		Axis xa {Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
		xa.set_color(Color::red);
		xa.label.set_color(Color::blue);
		win.attach(xa);
		win.wait_for_button();
		Axis ya {Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};
		ya.set_color(Color::red);
		ya.label.set_color(Color::blue);
		win.attach(ya);
		win.wait_for_button();

		const int rmin = -10; //range min
		const int rmax = 11;

		const int nop = 400; //number of points

		const int sc = 20; //scale

		const int startx = 300;
		const int starty = 300;

		//1.
		Function g1(one,rmin,rmax, Point{startx,starty}, nop, sc, sc); //konstansfüggvény
		win.attach(g1);
		win.wait_for_button();

		Function g2(slope, rmin,rmax, Point{startx,starty}, nop, sc, sc); //slope (x/2) függvény
		win.attach(g2);
		win.wait_for_button();

		Text tg2 {Point{100, 380}, "x/2"}; //szoveg 
		tg2.set_font_size(15);
		win.attach(tg2);
		win.wait_for_button();

		Function g3(square, rmin,rmax, Point{startx,starty}, nop, sc, sc); //masodfoku függvény
		g3.set_color(Color::green);
		win.attach(g3);
		win.wait_for_button();

		Function g4(cos, rmin,rmax, Point{startx,starty}, nop, sc, sc); //cos függvény
		g4.set_color(Color::blue);
		win.attach(g4);
		win.wait_for_button();

		Function g5(sloping_cos, rmin,rmax, Point{startx,starty}, nop, sc, sc); ////sloping_cos függvény
		g5.set_color(Color::yellow);
		win.attach(g5);
		win.wait_for_button();

	} catch (exception& e) {
			cerr << "exception " << e.what() << '\n';
			return 1;
	} catch (...) {
			cerr << "error\n";
			return 2;
	}

}