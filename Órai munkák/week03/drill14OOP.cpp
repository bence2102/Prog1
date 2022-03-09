 /*
					OOP
Célja: minden ami körülöttem van, az objektum
Osztály: az objektumnak milyen tulajdonságai lesznek
viselkedések - függvények
pl. állatkert: 

OSZTÁLY emlős (
	int lábak száma, -> PUBLIC
	string szőrzet, -> PROTECTED
	int súly, -> PRIVATE
	void mozog (1. ->, 2. ->, 3. ->, 4. ->))

EMLŐS E; <- OSZTÁLY, az E egy konkrét példány objektum (new = new EMLŐS(konst))

Speciális eset: 

pl. OSZTÁLY kutya: EMLŐS S
		string név;
		int marmagasság;
		jatek kedvenc.jatek;
		void játszik(jatek j)
		harap(j);

Szülőtől kapott tulajdonságokat kiegészíti saját tulajdonságokkal, viselkedéssel

Polimorfizmus: Egy fgv. többféle állapotban is létezhet egyszerre

EMLŐS E = K;
E.mozog();

OSZTÁLY kenguru (emlős)
	int eletkor;
	int ugrásmagasság;

	void mozog(){
	1 & 2 ->
	}

	VEC <EMLŐS> v;
	v[0].mozog(); (kutya)
	v[1].mozog(); (kenguru)

Absztrakt függvények: Jelentés nélküli függvény.
Absztrakt osztály: Ha rendelkezik legalább egy absztrakt fgv-nyel

Getter
int GETSÚLY(){
	return súly <- le tudjuk kérni hiába private dolgainkat
	}

Setter
void SETSÚLY(int s2){
	súly = s2; <- módosíthatóvá tettem
}
*/

// drill 14

#include <string>
#include <iostream>
using namespace std; //csak cout-ot kelljen írni

class B1 {
	public:
		virtual void vf() { cout << "B1::vf" << endl;} //virtual - számít rá, hogy felül lesz írva
		void f() {cout << "B1::f()" << endl;}
		virtual void pvf() = 0; // tisztán virtuális fgv. kérdés drill (nem ad vissza semmit, a 0-val azt jelezzük, hogy egy üres függvény, ami nem értelmezhető, de később valaki majd felül fogja definiálni)

};

class D1 : public B1{
		public:
				void vf() {cout << "D1::vf()" << endl;}

};

class D2 : public D1 {
		public:
				void pvf() {cout << "D2:pvf()" << endl;}
};

class B2 {
		public:
			virtual void pvf() = 0;

};

class D21 : public B2{
		public:
				string s;
				void pvf(){cout << s << endl;}
};

class D22 : public B2{
		public:
				int n;
				void pvf(){cout << n << endl;}
};

void f(B2& b2ref){
	b2ref.pvf();
}

int main(){

	/*B1 b1;
	b1.vf();
	b1.f();

	D1 d1;
	d1.vf();
	d1.f();

	B1& bref = d1;
	bref.vf();
	bref.f();*/

	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();

	D21 d21;
	d21.s = "d21.s";
	d21.pvf();

	D22 d22;
	d22.n = 22;
	d22.pvf();

	f(d21);
	f(d22);


}
