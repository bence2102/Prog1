#include <stdio.h> //printf benne van

void my_print(const char* p,  int x){
	printf("p is \"%s\" and x is %d\n", p, x); // %d vagy %i - int
}
int main(){
	printf("1.\n");
	printf("Hello, world!\n\n");

	printf("2.\n");
	char h[] = "Hello";
	char w[] = "World!";
	printf("%s %s\n\n", h, w); //%s formátum specifikátor (string), h és w a formázandó argumentumok

	printf("3.\n");
	my_print("foo",7);
	my_print("Bence",5);
	my_print("Beviz Elek",69);

	return 0;

}