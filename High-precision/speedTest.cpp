//#define ADD_TEST
//#define MUL_TEST
#include <cstdio>
#include <ctime>
#include "Bignum.cpp"

int main(){
	clock_t start, finish;
	
	Bignum a, b, res;
	a = 1145141919810ll;
	b = 19191017ll;

#ifdef ADD_TEST	
	/*
	perform 1000000 additions
	Local : gcc 9.2.0 -O1 64-bit Debug
		#1 : 9.3190
		#2 : 9.2650
		#3 : 9.1030
	Local : gcc 9.2.0 -O2 64-bit Debug
		#1 : 8.8170
		#2 : 8.8110
		#3 : 9.1720
	*/
	start = clock();
	for(long int i = 0; i < 1000000; i++){
		res = a + b;
	}
	finish = clock();
	res.print();
	printf("\n%.4f\n", (double) (finish - start) / CLOCKS_PER_SEC);
#endif

#ifdef MUL_TEST
	/*
	perform 1000 multiplications
	Local : gcc 9.2.0 -O1 64-bit Debug
		#1 : 0.3520
		#2 : 0.3520
		#3 : 0.3580
	Local : gcc 9.2.0 -O2 64-bit Debug
		#1 : 0.3590
		#2 : 0.3510
		#3 : 0.3500
	*/
	start = clock();
	for(long int i = 0; i < 1000; i++){
		res = a * b;
	}
	finish = clock();
	res.print();
	printf("\n%.4f\n", (double) (finish - start) / CLOCKS_PER_SEC);
#endif
	
	return 0;
}
