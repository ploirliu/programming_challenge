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
		for (int i = 0; i <len; ++i){
			num[i] = right.num[i];
		}
		return *this;
	}
	void set(int a){
		for (int i = 0; i <len; ++i){
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


//#define my_debug
const int MAX_N = 10005;
const int MAX_M = 20005;

//typedef struct node{
//	int start, end, dis, cost;
//	bool operator<(const node &right)const{
//		if (dis == right.dis){
//			return cost > right.cost;
//		}
//		return dis > right.dis;
//	}
//	friend ostream& operator<< (ostream &out, node &right){
//		out << right.start << "," << right.end << "," << right.dis << "," << right.cost;
//		return out;
//	}
//}node;
//
//int n, m;
//priority_queue<node> q;
//
//int stu[MAX_N];
//void u_init(){
//	rep(i, 0, n + 1){
//		stu[i] = i;
//	}
//}
//int get_f(int id){
//	if (id != stu[id]){
//		stu[id] = get_f(stu[id]);
//	}
//	return stu[id];
//}
//int u_same(int id1, int id2){
//	if (get_f(id1) != get_f(id2))
//		return false;
//	return true;
//}
//void u_union(int id1, int id2){
//	int f1 = get_f(id1), f2 = get_f(id2);
//	if (f1 != f2){
//		stu[f1] = f2;
//	}
//}
//
//int s_tree(){
//	int out = 0;
//	u_init();
//	while (!q.empty()){
//		node tmp = q.top(); q.pop();
//#ifdef my_debug
//		cout << tmp << endl;
//#endif
//		if (u_same(tmp.start, tmp.end))
//			continue;
//		out += tmp.cost;
//		u_union(tmp.start, tmp.end);
//	}
//	return out;
//}
//void solve(){
//	pint(s_tree());
//}

int n, m;
typedef pair<int, P> ROAD;
int len[MAX_N];
vector<ROAD> r[MAX_N];
bool used[MAX_N];
int cost[MAX_N];
void my_init(){
	rep(i, 0, n + 1)
		r[i].clear();
}
void solve(){
	int out = 0;
	while (true){
		int tmpdis = INF, tmpid = -1;
		rep(i, 1, n + 1){
			if (used[i] == false && len[i] < tmpdis){
				tmpdis = len[i];
				tmpid = i;
			}
		}
		if (tmpid == -1)
			break;
		out += cost[tmpid];
		used[tmpid] = true;
		rep(i, 0, r[tmpid].size()){
			ROAD &tmp = r[tmpid][i];
			if (used[tmp.first])
				continue;
			if (len[tmp.first] > (len[tmpid] + tmp.second.first)){
				len[tmp.first] = len[tmpid] + tmp.second.first;
				cost[tmp.first] = tmp.second.second;
			}
			else if (len[tmp.first] == (len[tmpid] + tmp.second.first) && cost[tmp.first] > tmp.second.second){
				cost[tmp.first] = tmp.second.second;
			}
		}
	}
	pint(out);
}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
#endif
	while (gint2(n,m) != EOF){
		if (n == 0 && m == 0)
			break;
		my_init();
		fill(len, len + n + 1, INF);
		fill(used, used + n + 1, false);
		fill(cost, cost + n + 1, INF);
		len[1] = 0;
		cost[1] = 0;
		int start, end, dis, cost;
		rep(i, 0, m){
			gint3(start, end, dis);
			gint(cost);
			r[start].push_back(ROAD(end, P(dis, cost)));
			r[end].push_back(ROAD(start, P(dis, cost)));
		}
		solve();
	}
	return 0;
}