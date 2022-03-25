#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;
char s[25][25];
int main() {
	//freopen("D:\\input.txt", "r", stdin);
	//freopen("D:\\output.txt", "w", stdout);
	int i;
	for (i = 1;;i++) {
		scanf("%s", s[i]);
	}
	for (i; i >= 1; i--)
		printf("%s", s[i]);

	return 0;
}

