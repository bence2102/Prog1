#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <set>

struct Fruit{
	std::string name;
	int quantity;
	double unit_price;

	Fruit(const std::string& n, int q = 0, double p=0.0) : name{n}, quantity{q},
		unit_price{p}{}
};

struct Fruit_ptr_cmp{
	bool operator()(const Fruit* a, Fruit* b){ //operátor túlterhelés
		return a->name < b->name; //név szerint osszehasonlitja a gyumolcsot -> abc sorrend
		//return a->quantity < b->quantity;
	}
};
int main(){
	try {
		std::vector<Fruit> vf {
			Fruit{"Plum", 3},
			Fruit{"Grape", 13},
			Fruit{"Banana", 73},
			Fruit{"Apple", 55},
			Fruit{"Orange", 62},
			Fruit{"Cherry", 21},
			Fruit{"Plum", 43},
			Fruit{"Kiwi", 99},
		};

		std::cout<< "Vector values: " << std::endl;
		for(auto& i : vf){
			std::cout<<i.name<<std::endl;
		}
		std::cout << std::endl;

		std::set<Fruit*, Fruit_ptr_cmp> sf;
		for(auto& f : vf){
			sf.insert(&f);
		}

		std::cout<< "Set values: " << std::endl;
		for(auto& i : sf){
			std::cout<<i->name<<std::endl; //i egy pointer
		}
		std::cout << std::endl;

	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	} catch (...) {
		std::cerr <<"Unknown exception\n";
		return 2;

	}
}