#include <cstdio>
#include "BIT.cpp"

BIT T;

int main() {
	T.pointUpdata(0, 1);
	T.pointUpdata(1, 1);
	T.pointUpdata(2, 1);
	printf("%lld\n", T.pointQuery(0, 2));
	return 0;
}
