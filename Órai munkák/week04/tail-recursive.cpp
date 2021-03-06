#include <iostream>

unsigned int factorial_rec(int x){
	if(x==0) return 1;
	return x*factorial_rec(x-1);

}

unsigned int factorial_TR(int x, int y){
	if (x == 0)
	{
		return y;
	}
	return factorial_TR(x-1,x*y);
}

unsigned int factorial(int x){
	return factorial_TR(x,1);
}

int main(){
	std::cout<<factorial(3) << std::endl;
	std::cout<<factorial_rec(3) << std::endl; //ha az utolsó művelet a rekurzív függvényhívás <- farokrekurzió
}