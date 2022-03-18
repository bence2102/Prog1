#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


class Person{
public:
	Person(){}
	//Person(std::string n, int a) : n{n}, a{a}{
	Person(string fn, string ln, int a) : fn{fn}, ln{ln}, a{a}{
		if(a < 0 || a >= 150){
			throw runtime_error("Invalid age");
		}
	string n = fn+ln;
	const string badchars = ";:\"'[]*@^%&$#!"; // \ azért kell mert nélküle karakter megadásnak érzi, aminek hiányzik a másik "-e
	for(int i = 0; i < n.size(); i++){
		for (int j = 0; j < sizeof(badchars); j++)
			if(n[i] == badchars[j]) throw runtime_error("Illegal character");
		}
	}
	string first() const {return fn;}
	string last() const {return ln;}
	//string name() const {return n;}
	int age() const {return a;}

private:
	//string n;
	string fn;
	string ln;
	int a;
};

ostream& operator <<(ostream& os, const Person& p){
	return os << p.first() << " " << p.last() << " " << p.age();
}

istream& operator >>(istream& is, Person& p){
	//string n;
	string fn;
	string ln;
	int a;

	//is >> n >> a;
	is >> fn >> ln >> a;
	p = Person(fn, ln, a); //Person(n,a); 

	return is;
}

int main(){
		Person p;
		//p.n = "Goofy";
		//p.a = 63;
		p = Person("Goofy", "is",63);

		cout<<p.first() << " " << p.last() << " " << p.age()<<endl; // REFAKTORÁLÁS - ha átnevezünk egy állományt, fgv-t

		Person p2;
		Person p3;

		cin >> p2 >> p3;
		cout << p2 << " " << p3 << endl;

		vector<Person> vec;

		for(Person p; cin >> p;){ //while(cin >> p)
			if(p.first() == "end") break;
			vec.push_back(p);
		}

		// Person típus változó, neve p, a vec-ból fog jönni(kollekció) --> cout(p)
		for(Person p: vec){
			cout << p << endl;
		}

}
