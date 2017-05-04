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
#include <string.h>
using namespace std;
const int INF = 1 << 28;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,start,end) for(int i=(start);i<(end);++i)
#define pint(i) printf("%d\n",(i))
#define pint2(i,j) printf("%d %d",(i),(j))
#define pint3(i,j,k) printf("%d %d %d",(i),(j),(k))
#define gint(i) scanf("%d",&(i))
#define gint2(i,j) scanf("%d %d",&(i),&(j))
#define gint3(i,j,k) scanf("%d %d %d",&(i),&(j),&(k))
#define init(tar,val) memset((tar),(val),sizeof((tar)))
#define show(tar,len) for(int i=0;i<(len);++i) \
	cout<<tar[i]<<' ';\
	cout<<endl;




class bignum{
public:
	bignum(int size = 4) :len(size){
	}
	~bignum(){
	}
	int size()const{
		return len;
	}
	//int get(int id)const{
	//	return num[id];
	//}
	friend ostream &operator<<(ostream &output, const bignum &b){
		bool stu = false;
		for (int i = int(b.len - 1); i >= 0; --i){
			if (stu)
				printf("%09d", b.num[i]);
			else if (b.num[i] > 0){
				printf("%d", b.num[i]);
				stu = true;
			}
		}
		if (stu == false)
			printf("0");
		return output;
	}
	const bignum& operator+=(const bignum&right){
		int add = 0;
		for (int i = 0; i < len; ++i){
			int tmp = 0;
			if (i < right.size()){
				tmp = right.num[i] + num[i] + add;
			}
			else{
				tmp = num[i] + add;
			}
			num[i] = tmp%gap;
			add = tmp / gap;
		}
		return *this;
	}
	const bignum& operator=(const bignum&right){
		for (int i = 0; i < len; ++i){
			num[i] = right.num[i];
		}
		return *this;
	}
	void set(int a){
		for (int i = 0; i < len; ++i){
			num[i] = a%gap;
			a /= gap;
		}
	}
private:
	int  num[4];
	int len;
	static const int gap = 1000000000;
};


//inline int id(int i){
//	return i & 1;
//}
//
//inline int last(int i){
//	return (i - 1) & 1;
//}
//
//void myshow(int i){
//	rep(j, 0, ){
//		cout << dp[id(i)][j] << ' ';
//	}
//	cout << endl;
//}


#define my_debug
const int MAX_N = 505;
const int MAX_E = 6000;
const int MAX_W = 205;
int len[MAX_N];
int n, m, w;
int e;
typedef pair<P, int> ROAD;
ROAD road[MAX_E];
P r[MAX_N][MAX_N];
int r_num[MAX_N];
int my[MAX_W];

bool n_loop(int id){
	fill(len, len + n + 1, INF);
	len[id] = 0;
	rep(i, 1, n + 1){
		rep(j, 0, e){
			ROAD &r = road[j];
			if (len[r.first.second] > len[r.first.first] + r.second){
				len[r.first.second] = len[r.first.first] + r.second;

				if (i == n)
					return true;
			}
		}
	}
	return false;
}

bool n_loop_spfa(int id){
	bool stu[MAX_N];
	int count[MAX_N];
	init(stu, 0); init(count, 0);
	fill(len, len + n + 1, INF);
	queue<int> q;
	stu[id] = true; count[id] = 1; len[id] = 0; q.push(id);
	while (!q.empty()){
		id = q.front(); q.pop();
		stu[id] = false;
		if (count[id] > n)
			return true;
		rep(i, 0, r_num[id]){
			P &tmp = r[id][i];
			if (len[tmp.first] > len[id] + tmp.second){
				len[tmp.first] = len[id] + tmp.second;
				if (stu[tmp.first] == false){
					stu[tmp.first] = true;
					++count[tmp.first];
					q.push(tmp.first);
				}
			}
		}
	}
	return false;
}

void solve(){
	rep(i, 0, w){
		if (n_loop_spfa(my[i])){
			printf("YES\n");
			return;
		}
	}
		printf("NO\n");
}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
#endif
	int t;
	gint(t);
	rep(i, 0, t){
		init(r_num, 0);
		gint3(n, m, w);
		int tmp1, tmp2, tmp;
		int id = 0;
		rep(j, 0, m){
			gint3(tmp1, tmp2, tmp);
			road[id].first.first = tmp1, road[id].first.second = tmp2, road[id].second = tmp;
			++id;
			road[id].first.first = tmp2, road[id].first.second = tmp1, road[id].second = tmp;
			++id;
			r[tmp1][r_num[tmp1]].first = tmp2; r[tmp1][r_num[tmp1]].second = tmp;
			++r_num[tmp1];
			r[tmp2][r_num[tmp2]].first = tmp1; r[tmp2][r_num[tmp2]].second = tmp;
			++r_num[tmp2];
		}
		rep(j, 0, w){
			gint3(tmp1, tmp2, tmp);
			road[id].first.first = tmp1, road[id].first.second = tmp2, road[id].second = -tmp;
			++id;
			my[j] = tmp2;
			r[tmp1][r_num[tmp1]].first = tmp2; r[tmp1][r_num[tmp1]].second = -tmp;
			++r_num[tmp1];
		}
		e = id;
		solve();
	}
	return 0;
	}