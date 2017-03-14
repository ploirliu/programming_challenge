#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_V = 10005;
int d[MAX_V][MAX_V];
int V;

void warshall_floyd(){
	for (int k = 0; k < V; ++k){
		for (int i = 0; i < V; ++i){
			for (int j = 0; j < V; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
	}
}