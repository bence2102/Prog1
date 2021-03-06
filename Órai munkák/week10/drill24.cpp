#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;



int main()
try{
	cout << "sizeof:\n";
	cout << "char\t" << sizeof(char) << "\n";
	cout << "short\t" << sizeof(short) << "\n";
	cout << "int\t" << sizeof(int) << "\n";
	cout << "long\t" << sizeof(long) << "\n";
	cout << "float\t" << sizeof(float) << "\n";
	cout << "double\t" << sizeof(double) << "\n";
	cout << "int*\t" << sizeof(int*) << "\n";
	cout << "double*\t" << sizeof(double*) << "\n";
	cout << "long*\t" << sizeof(long*) << "\n";
	cout << "float*\t" << sizeof(float*) << "\n";

	cout << "Matrix sizes:\n";
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10,10);
	Matrix<int, 3> e(10,10,10);
	cout << "1D int, 10 elem\t\t" << sizeof(a) << '\n';
	cout << "1D int, 100 elem\t\t" << sizeof(b) << '\n';
	cout << "1D int, 10 elem\t\t" << sizeof(c) << '\n';
	cout << "2D int, 10x10 elem\t\t" << sizeof(d) << '\n';
	cout << "3D int, 10x10x10 elem\t\t" << sizeof(e) << '\n';

	cout << "Number of elements:\n";
	cout << "a:\t" << a.size() << '\n';
	cout << "b:\t" << b.size() << '\n';
	cout << "c:\t" << c.size() << '\n';
	cout << "d:\t" << d.size() << '\n';
	cout << "e:\t" << e.size() << '\n';

	int i;
	cout << "Enter integers: ";
	while(cin >> i)
		if(i < 0)
			cout << "No square root!" << endl;
		else
			cout << sqrt(i) << endl;

	cin.clear(); //eltárolt hibákat törli
	cin.ignore();
	cout << "\nEnter 10 floats: " << endl;
	Matrix<double> md(10);
	double d2;
	for(int i = 0; i<md.size(); ++i)
		cin >> d2;
		if(!cin) throw runtime_error("Error while reading from cin!");
		md[i] = d2;

	cout << "Matrix: \n" << md << '\n';

	// 6
	cout << "Enter the dimensions: " << endl;
	int m,n;
	cin >> m >> n;
	cout << endl;

	Matrix<double, 2> mtable(n,m);
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			mtable(i, j) = (i+1)*(j+1);
			cout << setw(5) << mtable(i,j); //setw string szélességét lehet állítani
		}
		cout << '\n';
	}		

	Matrix<complex<double>> m4(10);
	cout << "\nEnter 10 complex numbers (Re, Im): ";
	complex<double> comp;
	for(int i = 0; i < 10; ++i){
		cin >> comp;
		if(!cin) throw runtime_error("Problem reading complex number!");
		m4[i] = comp;
	}
	complex<double> sum;
	for(int i = 0; i < m4.size(); ++i){
		sum += m4[i];
	}
	cout << "Sum: " << sum << '\n';

}catch(exception& e) {
	cerr << "Exception: " << e.what() << '\n';
}catch(...) {
	cerr << "Unknown exception!" << '\n';
}