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
using namespace std;
const int INF = 1147483647;

const int MAX_N=25005;
int n, t;
map<int, vector<int>> all;


//typedef struct node{
//	int start, end;
//	bool operator< (const node& r)const {
//		if (start == r.start){
//			return end>r.end;
//		}
//		return start < r.start;
//	}
//}node;
//node all[MAX_N];
//
////void solve(){
//	if (all.count(1) == 0){
//		printf("-1\n");
//		return;
//	}
//	int now = 1;
//	int out = 0;
//	int next = 1;
//	for (map<int, vector<int>>::iterator it = all.begin(); it != all.end(); ++it){
//		if (it->first > now){
//			if (it->first > next){
//				printf("-1\n");
//				return;
//			}
//			else{
//				now = next;
//				++out;
//			}
//		}
//
//		for (int i = 0; i < it->second.size(); ++i){
//			next = max(next, it->second[i]);
//		}
//
//	}
//	if (next < t)
//		printf("-1\n");
//	else if (now < t)
//		printf("%d\n", out + 1);
//	else
//		printf("%d\n", out);
//}
//
////void solve(){
//	int out = 0;
//	int now_s = 0, now_e = 0;
//	int next_s = -1, next_e = -1; 
//	for (map<int, vector<int>>::iterator it = all.begin(); it != all.end(); ++it){
//		bool stu = true;
//		if (it->first > now_e){
//			if (it->first == (now_e + 1)){
//				for (int i = 0; i < it->second.size(); ++i){
//					next_e = max(next_e, it->second[i]);
//					stu = false;
//				}
//			}
//			now_e = next_e;
//			++out;
//		}
//		if (stu && now_e >= it->first){
//			for (int i = 0; i < it->second.size(); ++i){
//				next_e = max(next_e, it->second[i]);
//			}
//		}
//	}
//	if (next_e < t){
//		printf("%d\n", -1);
//	}
//	else if (now_e < t){
//		printf("%d\n", out+1);
//	}
//	else{
//		printf("%d\n", out);
//	}
//}
//
//void solve(){
//	sort(all, all + n);
//	int now = 0;
//	int out = 0;
//	while (true){
//		++out;
//		int end = now + 1;
//		int next = -1;
//		for (int i = 0; i < n; ++i){
//			if (all[i].start <= end){
//				next = max(next, all[i].end);
//			}
//			else
//				break;
//		}
//		if (next <= now){
//			printf("%d\n", -1);
//			return;
//		}
//		now = next;
//		if (now >= t){
//			printf("%d\n",out);
//			return;
//		}
//	}
//}

void solve(){
	int out = 0;
	int now = 0;
	map<int, vector<int>>::iterator  it = all.begin();
	while (true){
		++out;
		int end = now+1;
		int next = -1;
		while (it!=all.end() && it->first <= end){
			for (int i = 0; i < it->second.size(); ++i){
				next = max(next,it->second[i]);
			}
			++it;
		}
		if (next <= now){
			printf("%d\n",-1);
			return;
		}
		now = next;
		if (now >= t){
			printf("%d\n", out);
			return;
		}
	}
}

int main(){
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; ++i){
		int start, end;
		scanf("%d %d", &start, &end);
		all[start].push_back(end);
	}
	solve();
	return 0;
}