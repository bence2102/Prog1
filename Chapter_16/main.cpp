/*
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp lines_window.cpp main.cpp `fltk-config --ldflags --use-images` -o a2.out
*/

#include "lines_window.h"
#include "../GUI/Graph.h"

int main()
try {
    Lines_window win {Point{100, 100}, 800, 600, "lines"};
    return gui_main();
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}