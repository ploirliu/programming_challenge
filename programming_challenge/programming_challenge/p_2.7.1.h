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
const int INF = 1147483647;
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

const int MAX_N = 1005;
const int MAX_L = 300005;

P all[MAX_N];
P test[MAX_L];
int repair[MAX_L];

int n, d, test_num, repair_num;

int stu[MAX_N];
int now[MAX_N];

void my_init(){
	rep(i, 0, n+1){
		stu[i] = i;
	}
}

int find_f(int i){
	if (stu[i] != i){
		stu[i] = find_f(stu[i]);
		return stu[i];
	}
	return stu[i];
}

bool connect(int i, int j){
	int f_i = find_f(i);
	int f_j = find_f(j);
	//cout << i << ':' << f_i << endl;
	//cout << j << ':' << f_j << endl;
	if (f_i == f_j){
		return true;
	}
	return false;
}

void get_connect(int i, int j){
	int f_i = find_f(i);
	int f_j = find_f(j);
	if (f_i != f_j){
		stu[f_i] = f_j;
	}
}

bool dis(int i, int j){
	int out = (all[i].first - all[j].first)*(all[i].first - all[j].first) + (all[i].second - all[j].second)*(all[i].second - all[j].second);
	if (out <= (d*d))
		return true;
	return false;
}


//#define my_debug
int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
#endif
	gint2(n, d);
	rep(i, 0, n)
		gint2(all[i+1].first, all[i+1].second);
	char c;
	int len = 0;
	my_init();
	init(now, -1);
	scanf("%c", &c);
	while (scanf("%c", &c) != EOF){
		if (c == 'O'){
			int id;
			gint(id);
			rep(i, 0, len){
				if (dis(now[i], id))
					get_connect(now[i], id);
			}
			now[len++] = id;
		}
		if (c == 'S'){
			int id1, id2;
			gint2(id1, id2);
			if (connect(id1, id2)){
				printf("SUCCESS\n");
			}
			else{
				printf("FAIL\n");
			}
		}
#ifdef my_debug
		cout << c << endl;
		show(now, len);
		show(stu, n+1);
#endif
		scanf("%c", &c);
	}
	return 0;
}