#include <iostream>
#include <functional>

int sum(int x, int y){
	return x+y;
}

class Add {
public:
	int operator()(int x, int y) const {return x+y;}

};

struct add_x {
	add_x(int val) : x(val) {}
	int operator() (int y) const {return x+y;} //operátor túlterhelés
	int operator<< (int y) const {return x+y;}
	int operator>> (int y) const {return x+y;}
	void operator+ (int y) {x-=y;}

private:
	int x;
};

int main(){
	// típus név
	add_x add42(42);
	int i = add42(8);

	std::cout << i << std::endl;
	add42+7;
	std::cout << (add42<<8) << std::endl;
	std::cout << (add42>>7) << std::endl;

	//típus							név
	std::function<int(int, int)> func; //egy olyan fgv-nek a feje, ami 2 int-et vár paramértéknek, visszatérése is int lesz

	func = sum;

	std::cout << func(5, 7) << std::endl;

	std::function<double(double,double)> sum = [] (double A, double B) {return A+B;};

	std::cout << sum(4.5,6.9) << std::endl;
}
