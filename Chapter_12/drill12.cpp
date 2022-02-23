/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill12.cpp `fltk-config --ldflags --use-images` -o a2.out
*/

// koordináták (x,y), jobbra, le !!

#include "./GUI/Simple_window.h" //ablak, next button
#include "./GUI/Graph.h" //alakzatok

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){

		try{
				Point t1 {100, 100}; //innentől kezdődik az ablak bal felső sarka
				Simple_window win {t1, 600, 400, "My window"}; //ablak létrehozás, (pont, méret, cím)
				win.wait_for_button();

				Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"}; //(vízszintes tengely lesz, pont ahonnan indul, hossz, osztások száma, label)
				xa.set_color(Color::dark_red);
				xa.label.set_color(Color::blue);
				win.attach(xa);
				win.set_label("x axis");
				win.wait_for_button();

				Axis ya {Axis::y, Point{20, 300}, 280, 10, "y axis"};
				ya.set_color(Color::dark_red);
				ya.label.set_color(Color::blue);
				win.attach(ya);
				win.set_label("y axis");
				win.wait_for_button();

				Function sine {sin, 0, 100, Point{20,150}, 1500, 25, 25}; //sin fgv, 0-100-ig, a (0,0) pont a (20, 150)-be van, 1000 pont, x érték * 50, y érték * 50
				sine.set_color(Color::blue);
				win.attach(sine);
				win.set_label("sine");
				win.wait_for_button();

				Polygon poly; //sokszög létrehozás - ahány pont, annyi szög
				poly.add(Point{300, 200}); //polygon csúcsai hol legyenek
				poly.add(Point{350, 100});
				poly.add(Point{400, 200});
				poly.add(Point{450, 100});
				poly.set_color(Color::yellow);
				poly.set_style(Line_style::dash);
				win.attach(poly);
				win.set_label("triangle");
				win.wait_for_button();

				Rectangle r {Point{200, 200}, 100, 50}; //bal felső sarok, SZ, M
				win.attach(r);
				win.set_label("rectangle");
				win.wait_for_button();

				Closed_polyline poly_rect; //4 pont a polyline-ban jó helyen nem elég a téglalaphoz, a poly_rect objektum sem az
				poly_rect.add(Point{100, 50});
				poly_rect.add(Point{200, 50});
				poly_rect.add(Point{200, 100});
				poly_rect.add(Point{100, 100});
				poly_rect.add(Point{50, 75}); //nem birtokolja egy téglalap tulajdonságait, mert annak nincs soha 5 pontja
				win.attach(poly_rect);

				r.set_fill_color(Color::magenta);
				poly.set_style(Line_style(Line_style::dash, 4)); //4-szeres vastagság
				poly_rect.set_style(Line_style(Line_style::dash, 2)); //a körvonal a kitöltésen van
				poly_rect.set_fill_color(Color::green);
				win.set_label("Fill colors");
				win.wait_for_button();

				Text t {Point{350, 275}, "Hello, graphical world!"};
				t.set_font(Font::courier);
				t.set_font_size(15);
				win.attach(t);
				win.set_label("text");
				win.wait_for_button();

				Image ii {Point{100,100}, "GUI/badge.jpg"};
				win.attach(ii);
				win.set_label("Image");
				win.wait_for_button();

				ii.move(230,200); //még ennyivel pluszba elmozgatja
				win.set_label("Image move");
				win.wait_for_button();

				Circle c {Point{100,200},50};
				Ellipse e {Point{100,200},75,25};
				e.set_color(Color::dark_red);
				Mark m{Point{100,200},'x'};

				ostringstream oss; // rendszerkimenet formázásához
				oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" << win.y_max();
				Text sizes{Point{100,20},oss.str()};

				Image cal {Point{330,300},"GUI/snow_cpp.gif"}; //320*240 pixel gif
				cal.set_mask(Point{40,40},200,150); //a kép középső részét jeleníti meg

				win.attach(c);
				win.attach(m);
				win.attach(e);

				win.attach(sizes);
				win.attach(cal);
				win.set_label("Canvas #12");
				win.wait_for_button();

		} catch (exception& e) {
				cerr << "exception " << e.what() << '\n';
				return 1;
		} catch (...) {
				cerr << "error\n";
				return 2;
		}

}