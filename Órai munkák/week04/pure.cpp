#include <iostream>
#include <cmath>

//mellékhatás

int absolute(int a){
	return abs(a);
}
int main(){
	int x,y;
	x = 1;
	x*=15;
	std::cout << "Absolute value of 0.025: " << abs(0.025) << std::endl; //tiszta függvény -> kiszámítható hogy mit fog adni (adott bemenetre, adott kimenet)
	std::cout << "Absolute value of 0.025: " << absolute(25) << std::endl;
}