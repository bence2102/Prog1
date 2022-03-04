//g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill13.cpp `fltk-config --ldflags --use-images` -o a3.out


#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){

		try{
				// 1. feladat: ablak

				Point t1 {300, 50};
				Simple_window win {t1, 1000, 800, "My window"}; 
				win.wait_for_button();

				// 2. feladat: 8x8-as rács

				int x_size = 800;
				int y_size = 800;
				Lines grid; //lines objektum része -> grid

				for(int i = 0; i <= 800; i+=100)
				{
					grid.add(Point(i,0), Point(i, y_size)); //függőleges
					grid.add(Point(0, i), Point(x_size, i)); //vízszintes

				}

				win.attach(grid);
				win.wait_for_button();

				// 3. feladat: átlóban 8 piros négyzet

				Rectangle rect1 (Point(0,0),100,100);
				Rectangle rect2 (Point(100,100),100,100);
				Rectangle rect3 (Point(200,200),100,100);
				Rectangle rect4 (Point(300,300),100,100);
				Rectangle rect5 (Point(400,400),100,100);
				Rectangle rect6 (Point(500,500),100,100);
				Rectangle rect7 (Point(600,600),100,100);
				Rectangle rect8 (Point(700,700),100,100);
				win.attach(rect1);
				win.attach(rect2);
				win.attach(rect3);
				win.attach(rect4);
				win.attach(rect5);
				win.attach(rect6);
				win.attach(rect7);
				win.attach(rect8);
				rect1.set_fill_color(Color::red);
				rect2.set_fill_color(Color::red);
				rect3.set_fill_color(Color::red);
				rect4.set_fill_color(Color::red);
				rect5.set_fill_color(Color::red);
				rect6.set_fill_color(Color::red);
				rect7.set_fill_color(Color::red);
				rect8.set_fill_color(Color::red);
				win.set_label("Fill colors");
				win.wait_for_button();
				
				/*
				int x_grid = 100;
    			int y_grid = 100;

    			Vector_ref<Rectangle> rectangles;
        		for (int i = 0; i < x_size; i+=x_grid) {
            	rectangles.push_back(new Rectangle(Point{i, i}, Point{i+x_grid, i+x_grid}));
            	rectangles[rectangles.size()-1].set_fill_color(Color::red);
            	rectangles[rectangles.size()-1].set_color(Color::invisible);
            	win.attach(rectangles[rectangles.size()-1]);
        		}
        		
    			win.wait_for_button();
    			*/

				// 4. 200x200-as kép 3-szor

				Image badge {Point{200,0},"GUI/badge.jpg"};
				badge.set_mask(Point{100,200},200,200); //bal felső (100,200) ponttól egy 200x200-as képet kívágunk

				Image badge2 {Point{400,200},"GUI/badge.jpg"};
				badge2.set_mask(Point{100,200},200,200);

				Image badge3 {Point{600,400},"GUI/badge.jpg"};
				badge3.set_mask(Point{100,200},200,200);

				win.attach(badge);
				win.attach(badge2);
				win.attach(badge3);
				win.wait_for_button();

				Image badge4 {Point{200,0},"GUI/badge.jpg"};
				badge4.set_mask(Point{100,200},100,100);

				win.attach(badge4);
				win.wait_for_button();


				// 5. feladat: 100x100-as kép ide-oda
				while(true){
					int x = rand() % 7 + 1; //random szám 1 és 7 között, rand() % 7 -> random szám 0 és 6 között
					x*= 100;
					int y = rand() % 7 + 1;
					y*= 100;
					Image monster {Point{x,y}, "GUI/monster.jpg"};
					win.attach(monster);
					win.wait_for_button();
				}

				
		} catch (exception& e) {
				cerr << "exception " << e.what() << '\n';
				return 1;
		} catch (...) {
				cerr << "error\n";
				return 2;
		}
}
