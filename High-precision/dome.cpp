#include <cstdio>
#include "Bignum.cpp"

int main() {
	/* Dome */
	
	Bignum m, n;
	Bignum t;
	
	m = 123456;				// =
	printf("m : ");
	m.print();				// print()	"123456"
	printf("\n");
	printf("%d\n", m.getLen());
	
	printf("Enter the number : n\n>>> ");
	n.scan();				// scan()
	printf("\n");
	
	t = m;					// =
	printf("n : ");
	t.print();				// "123456"
	printf("\n");
	
	t = m + n;				// +
	printf("m + n : ");
	t.print();				// "123460"
	printf("\n");

	t = m * n;				// *
	printf("m * n : ");
	t.print();				// "493824"
	printf("\n");

	t = power(m, 10);			// power(base, p)
								// return base ^ p
	printf("power(m, 10) : ");
	t.print();				// "8224...8176"
	printf("\n");
	
	t = tenMod(m, 4);			// tenMod(num, k) 
								// return num mod (10 ^ k)
	printf("tenMod(m, 4) : ");
	t.print();				// "3456"
	printf("\n");
	
	t = 123456789;
	printf("\nt :\n");
	t.print();
	printf("\nlet the 3th bit of t be 5:\n");
	t.writeBit(t.getLen() - 3, 5);
	t.print();
	printf("\n");
	
	if(m != n){				// != and ==
		printf("m != n\n");
	}
	else{
		printf("m == n\n");
	}
	
	return 0;
}
