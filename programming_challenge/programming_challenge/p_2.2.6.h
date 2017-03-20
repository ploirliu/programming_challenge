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

typedef struct node{
	int price, num;
	bool operator<(const struct node &right)const{
		return price>right.price;
	}
}node;
const int MAX_N = 25;

node all[MAX_N];
int n, c;

int cost[MAX_N];

bool get(int id,int num){
	if (id == n){
		if (num > 0)
			return false;
		return true;
	}
	int tmp = num / all[id].price;
	if (tmp<=all[id].num && num%all[id].price == 0){
		cost[id] = tmp;
		return true;
	}
	else{
		tmp = min(tmp, all[id].num);
		if (get(id + 1, num - (tmp*all[id].price))){
			cost[id] = tmp;
			return true;
		}
		else{
			++tmp;
			if (all[id].num >= tmp && (all[id].price*tmp) >= num){
				cost[id] = tmp;
				return true;
			}
		}
	}
	return false;
}

void solve(){
	sort(all, all + n);
	int out = 0;
	int id = 0;
	for (; id <n ; ++id){
		if (all[id].price >= c){
			out += all[id].num;
		}
		else{
			break;
		}
	}
	memset(cost, 0, sizeof(cost));
	while (get(id, c)){
		bool stu = true;
		while (stu){
			for (int i = 0; i < n; ++i){
				if (cost[i]>all[i].num){
					stu = false;
					break;
				}
			}
			if (stu){
				++out;
				for (int i = 0; i < n; ++i){
					all[i].num -= cost[i];
				}
			}
		}
		memset(cost, 0, sizeof(cost));
	}
	printf("%d\n", out);
}

int main(){
	while (scanf("%d %d", &n, &c) != EOF){
		for (int i = 0; i < n; ++i){
			scanf("%d %d", &all[i].price, &all[i].num);
		}
		solve();
	}
	return 0;
}