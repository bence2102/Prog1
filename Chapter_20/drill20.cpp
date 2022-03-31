#include <iostream> //cpppreference.com/w/cpp/container/list
#include <array>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>

template<typename C>
void print(const C& c){
	for(auto& i: c){
		std::cout << i << ' ';
	}
	std::cout << std::endl;
}

template<typename C>
void inc(C& c, int n){
	for(auto& i : c){
		i += n;
	}
}
template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){

	for(Iter1 p = f1; p != e1; ++p){
		*f2 = *p;
		f2++; //lehet összevonva is
	}
	return f2;
}

int main(){
	try{
		constexpr int size = 10;

		int arr[size];
		for(int i = 0; i < size; ++i) arr[i] = i;
		std::cout << "C array: ";
		print(arr);

		std::array<int, size> ai;
		std::copy(arr, arr + size, ai.begin());
		std::cout << "std array: ";
		print(ai);

		std::vector<int> vi(size);
		std::copy(arr, arr + size, vi.begin());
		std::cout << "std vector: ";
		print(vi);

		std::list<int> li(size);
		std::copy(arr, arr + size, li.begin());
		std::cout << "std list: ";
		print(li);

		std::array<int,size> ai2 = ai; //első array copyja
		std::vector<int> vi2 = vi; //első vector copyja
		std::list<int> li2 = li; //első list copyja

		print(ai2);
		print(vi2);
		print(li2);

		inc(ai2, 2); //increase by
		inc(vi2, 3);
		inc(li2, 5);

		print(ai2);
		print(vi2);
		print(li2);

		orai_copy(ai2.begin(), ai2.end(), vi2.begin());
		orai_copy(li2.begin(), li2.end(), ai2.begin());

		print(ai2);
		print(vi2);
		print(li2);

		std::vector<int>::iterator vit;
		vit = std::find(vi2.begin(), vi2.end(), 3);
		if( vit != vi2.end()){
			std::cout << "(3) Found at: " << std::distance(vi2.begin(), vit) << std::endl;
		}else{
			std::cout << "(3) Not found" << std::endl;
		}

		std::list<int>::iterator lit;
		lit = std::find(li2.begin(),li2.end(), 27);
		if (lit != li2.end()){
			std::cout << "(27) Found at: " << std::distance(li2.begin(), lit) << std::endl;
		}else{
			std::cout << "(27) Not found" << std::endl;
		}
}

	catch (std::exception& e) {
		std::cerr << "Exception " << e.what() << '\n';
		return 1;
} 	catch (...) {
		std::cerr << "Unknown exception\n";
		return 2;
}
}

