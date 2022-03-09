#include <iostream>

/*
	[] lambda introducer
	() argument list
	{} function body

	[] captures nothing
	[&] captures all by reference
	[=] all by value
	[&A, =B] A by reference, B by value
	[=, &A] A by reference, others by value

	


*/
int main(){
	[](){ //parameter,
	std::cout << "Hello C++ lambda" << std::endl;

	}

	(); //meghívás

	auto sum = [](double A, double B) {return A+B;}; //típusa függvény

	auto add = sum;

	std::cout << add(3.25, 5.65) << std::endl;

	auto add2 = [](double A, double B) -> double {return A + B;};

	std::cout << add2(3.25, 5.65) << std::endl;

	double pi = 3.1416; //nem referencia szerint adtuk át, ezért nem írhatjuk át az értékét (read-only)

	auto func = [&pi](double A){
		std::cout << "The value of pi: " <<pi<<std::endl;
		pi+=A;
	};

	func(1.0);
	func(2.0);

	auto gene_lambda = [](auto arg) {return arg+arg;};

	std::cout<< gene_lambda(5) << std::endl;
	std::cout<< gene_lambda(3.1416) << std::endl;



}