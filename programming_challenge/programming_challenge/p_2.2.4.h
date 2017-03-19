#include <cstdio>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1147483647;
typedef long long ll;


//const int MAX_N = 10005;
//int price[MAX_N];
//int need[MAX_N];
//int n,s;

//int heap[MAX_N];
//int id;
//void insert(int num){
//	int now = id++;
//	heap[now] = num;
//	while (now != 0){
//		int f = (now + 1) / 2 - 1;
//		if (heap[f] > heap[now]){
//			swap(heap[f], heap[now]);
//		}
//		now = f;
//	}
//}
//
//void pop(){
//	int now = 0;
//	heap[now] = heap[--id];
//	while (now < id){
//		int left = (now + 1) * 2 - 1, right = (now + 1) * 2;
//		if (left < id && heap[left] < heap[now]){
//			if (right < id && heap[right]<heap[left]){
//				swap(heap[right], heap[now]);
//				now = right;
//			}
//			else{
//				swap(heap[left], heap[now]);
//				now = left;
//			}
//		}
//		else if(right<id && heap[right]<heap[now]){
//			swap(heap[right], heap[now]);
//			now = right;
//		}
//		else{
//			break;
//		}
//	}
//}
//
//int getTop(){
//	return heap[0];
//}
//
//void addHeap(int num){
//	for (int i = 0; i < id; ++i){
//		heap[i] += num;
//	}
//}
//
//void solve(){
//	id = 0;
//	ll out = 0;
//	for (int i = 0; i < n; ++i){
//		addHeap(s);
//		insert(price[i]);
//		int tmp = getTop();
//		out += (ll)tmp*(ll)need[i];
//	}
//	printf("%lld\n", out);
//}
//
//int main(){
//	while (scanf("%d %d", &n, &s) != EOF){
//		for (int i = 0; i < n; ++i){
//			scanf("%d %d", &price[i], &need[i]);
//		}
//		solve();
//	}
//	return 0;
//}

//void solve(){
//	ll out = 0;
//	for (int i = 0; i < n; ++i){
//		out += (ll)price[i] * (ll)need[i];
//	}
//	printf("%lld\n", out);
//}
//
//int main(){
//	while (scanf("%d %d", &n, &s) != EOF){
//		int tmp = INF;
//		for (int i = 0; i < n; ++i){
//			scanf("%d %d", &price[i], &need[i]);
//			price[i] = tmp = min(price[i], tmp);
//			tmp += s;
//		}
//		solve();
//	}
//	return 0;
//}

int main(){
	int n, s;
	while (scanf("%d %d", &n, &s) != EOF){
		int tmp = INF;
		int price, need;
		ll out=0;
		for (int i = 0; i < n; ++i){
			scanf("%d %d", &price, &need);
			price = tmp = min(price, tmp);
			tmp += s;
			out += (ll)price*(ll)need;
		}
		printf("%lld\n", out);
	}
	return 0;
}