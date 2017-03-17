#include <cstdio>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
using namespace std;
const int INF = 1147483647;

const int MAX_N = 50005;

typedef struct node{
	int first, second;
	int id;
	bool operator<(const struct node &right)const {
		if (second == right.second){
			return first>right.first;
		}
		return second < right.second;
	}
}P;


P all[MAX_N];
int stu[MAX_N];
int n;

//bool cmp(const P &a, const P &b){
//	if (a.second == b.second)
//		return a.first > b.first;
//	return a.second < b.second;
//}
//
//bool cmp1(int &a, int &b){
//	return abs(a) < abs(b);
//}
//
//bool un_finished(){
//	for (int i = 0; i < n; ++i){
//		if (stu[i] == 0)
//			return true;
//	}
//	return false;
//}
//
//int getN(){
//	int *tmp = new int[2 * n];
//	for (int i = 0; i < n; ++i){
//		tmp[2 * i] = all[i].first;
//		tmp[2 * i + 1] = -all[i].second;
//	}
//	sort(tmp, tmp + 2 * n, cmp1);
//	int out = 0;
//	int tmp1 = 0;
//	for (int i = 0; i < 2 * n; ++i){
//		if (tmp[i]>0){
//			++tmp1;
//		}
//		else{
//			--tmp1;
//		}
//		out = max(out, tmp1);
//	}
//	delete tmp;
//	return out;
//}


//void solve(){
//	int out = 0;
//	priority_queue<P> q[2];
//	int now = 0;
//	for (int i = 0; i < n; ++i){
//		q[now].push(all[i]);
//	}
//	while (!q[0].empty() || !q[1].empty()){
//		++out;
//		int next = (now + 1) & 1;
//		int tmp = 0;
//		while (!q[now].empty()){
//			P p = q[now].top(); q[now].pop();
//			if (p.first>tmp){
//				stu[p.id] = out;
//				tmp = p.second;
//			}
//			else{
//				q[next].push(p);
//			}
//		}
//		now = next;
//	}
//
//
//
//	printf("%d\n", out);
//	for (int i = 0; i < n; ++i){
//		printf("%d\n", stu[i]);
//	}
//}
//

//void solve(){
//	vector<int> cache;
//	sort(all, all + n);
//	for (int i = 0; i < n; ++i){
//		bool tmp = true;
//		for (int j = 0; j < cache.size(); ++j){
//			if (cache[j] < all[i].first){
//				tmp = false;
//				cache[j] = all[i].second;
//				stu[all[i].id] = j + 1;
//			}
//		}
//		if (tmp){
//			cache.push_back(all[i].second);
//			stu[all[i].id] = cache.size();
//		}
//	}
//	printf("%d\n", cache.size());
//	for (int i = 0; i < n; ++i){
//		printf("%d\n", stu[i]);
//	}
//}

typedef struct stall{
	int end;
	int id;
	bool operator<(const struct stall &right)const{
		return end>right.end;
	}
}stall;

void solve(){
	sort(all, all + n);
	priority_queue<stall> q;
	int id = 1;
	for (int i = 0; i < n; ++i){
		if (q.size() && q.top().end<all[i].first){
			stall tmp = q.top(); q.pop();
			tmp.end = all[i].second;
			stu[all[i].id] = tmp.id;
			q.push(tmp);
		}
		else{
			stall tmp;
			tmp.end = all[i].second;
			tmp.id = id;
			stu[all[i].id] = id;
			++id;
			q.push(tmp);
		}
	}
	printf("%d\n",q.size());
	for (int i = 0; i < n; ++i){
		printf("%d\n", stu[i]);
	}
}

int main(){
	while (scanf("%d\n", &n) != EOF){
		for (int i = 0; i < n; ++i){
			scanf("%d %d", &all[i].first, &all[i].second);
			all[i].id = i;
		}
		solve();
	}
	return 0;
}