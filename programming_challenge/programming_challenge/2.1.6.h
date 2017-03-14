#include<stdio.h>
using namespace std;

const int MAX_N = 1000;

bool used[MAX_N];
int perm[MAX_N];

void permutation1(int pos, int n){
	if (pos == n){
		/*
			TODO
		*/
		return;
	}
	for (int i = 0; i < n; ++i){
		if (!used[i]){
			perm[i] = i;
			used[i] = true;
			permutation1(i + 1, n);
			used[i] = false;
		}
	}
	return;
}

#include <algorithm>

int perm2[MAX_N];

void permutation2(int n){
	for (int i = 0; i < n; ++i){
		perm2[i] = i;
	}
	do{
		/*
			TODO
		*/
	} while (next_permutation(perm2, perm2 + n));
	return;
}