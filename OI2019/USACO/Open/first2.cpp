#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>
//#include "grader.h"
#define F first
#define S second
#define MP make_pair
using namespace std;

void addRoad (int a, int b) {}

int asd = 0;

void buildFarms(){
	// Fill in code here
	// n = getN();
	// q = getQ();
	
}
void notifyFJ(int a, int b){
	// Fill in code here
	a ++, b ++;
	int ra = 0, rb = 0, lca = 0;
	find_lca(a, b, ra, rb, lca);
	if (lca == a)		notify (a, b);
	else if (lca == b)	notify (b, a);
	else if (~ra)		notify (ra, a), notify (lca, b);
	else				notify (rb, b), notify (lca, a);
}