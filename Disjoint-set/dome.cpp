#include <cstdio>
#include "Disjoint-set.cpp"
DisjointSet S;

int main(){
	S.merge(1, 3);
	S.merge(2, 3);
	S.merge(3, 6);
	if(S.isSameRoot(1, 3)){
		printf("1 and 3 have the same root!\n");
	}else{
		printf("1 and 3 have not the same root!\n");
	}
	if(S.isSameRoot(2, 4)){
		printf("2 and 4 have the same root!\n");
	}else{
		printf("2 and 4 have not the same root!\n");
	}
	return 0;
}
