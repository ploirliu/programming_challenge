#include <cstdio>
#include <vector>
using namespace std;

const int MAX_V = 100005;
//vector<int> G[MAX_V];
//
//int main(){
//	int V, E;
//	scanf("%d %d", &V, &E);
//	for (int i = 0; i < E; ++i){
//		int s, t;
//		scanf("%d %d", &s, &t);
//		G[s].push_back(t);
//	}
//	return 0;
//}

struct vertex{
	vector<vertex*> edge;
};

vertex G[MAX_V];
int main(){
	int V, E;
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; ++i){
		int s, t;
		scanf("%d %d", &s, &t);
		G[s].edge.push_back(&G[t]);
	}
	return 0;
}