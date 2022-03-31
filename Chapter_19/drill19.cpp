#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1. 2. feladat
template<typename T>
struct S {
	S (T vv = 0) : val{vv}{} //konstruktor, val-t feltölti vv-vel
	T& get();
	const T& get() const;
	void set(T new_t) {val = new_t;}
	void operator=(const T& s);
private:
	T val;
};

//getterek

template<typename T>
T& S<T>::get(){
	return val;
}

template<typename T>
const T& S<T>::get() const{
	return val;
}

template<typename T>
void S<T>::operator=(const T& s){
	val = s;
}

//12. feladat fgv.
template<typename T>
void read_val(T& v){
	cin >> v; //vektorral nem értelmezhető
}

//input, output operator
template<typename T>
std::ostream& operator <<(ostream& os, vector<T>& v){
	os << "{ ";
	for(int i = 0; i < v.size(); i++){
		os << v[i] << (i < v.size()-1 ? ", ": " "); //operátor túlterhelés hol fog lefutni
	}
	os << "}\n";
	return os;
}

template<typename T>
std::istream& operator >>(istream& is, vector<T>& v){
	char ch = 0;
	is >> ch;
	if(ch /= '{'){
		is.unget();
		return is;
	}
	for(T val; is >> val;){
		v.push_back(val);
		is >> ch;
		if (ch != ',') break;
	}

	return is;
}


int main(){
	S<int> s;
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd {3.2};
	S<std::string> ss {"Hello"};
	S<std::vector<int>> svi {std::vector<int>{1,1,2,3,5,8}}; // s típusú objektum amelynek a tipusparametere int és vektor, objektum -> vektor -> int

	cout << "S<int> : " << s.get() << endl
		 << "S<int> : " << si.get() << endl
	 	 << "S<char> : " << sc.get() << endl
	 	 << "S<double> : " << sd.get() << endl
		 << "S<string> : " << ss.get() << endl;
	 	 //<< "S<vector<int>> : " << sv.get() << endl;
		 cout << "S<vector<int>> : ";
		 for(auto& a : svi.get()){
		 	cout << a << ' ';
	}
	cout << endl;

	sc.set('s');
	cout << "S<char> : " << sc.get() << endl;

	sd = 42.1;
	cout << "S<double> : " << sd.get() << endl;

	int ii;
	read_val(ii);
	S<int> si2 {ii};

	double dd;
	read_val(dd);
	S<double> sd2 {dd};

	string str;
	read_val(str);
	S<string> ss2 {str};

	cout << "S<int> : " << si.get() << endl;
	cout << "S<double> : " << sd2.get() << endl;
	cout << "S<string> : " << ss2.get() << endl;

	vector<int> vec;
	read_val(vec);
	S<vector<int>> svi2 {vec};

	cout << "S<vector<int>> svi2: " << svi2.get() << endl;


}