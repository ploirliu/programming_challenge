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

//#define my_debug

const int MAX_N = 100006;
int stu[2 * MAX_N];
int n, m;

int g_f(int i){
	if (stu[i] != i){
		stu[i] = g_f(stu[i]);
	}
	return stu[i];
}

bool same(int i, int j){
	int fi = g_f(i), fj = g_f(j);
	if (fi == fj)
		return true;
	return false;
}

void con(int i, int j){
	int fi = g_f(i), fj = g_f(j);
	if (fi != fj){
		stu[fi] = fj;
	}
}

void myinit(){
	rep(i, 0, 2*(n + 1))
		stu[i] = i;
}

void solve(){

}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int t;
	gint(t);
	rep(i, 0, t){
		gint2(n, m);
		myinit();
		int id1, id2;
		char c;
		rep(j, 0, m){
			scanf("%c", &c);
			scanf("%c", &c);
			gint2(id1, id2);
			if (c == 'A'){
				if (same(id1, id2) || same(id1 + n, id2 + n))
					printf("In the same gang.\n");
				else if (same(id1, id2 + n) || same(id1 + n, id2))
					printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			}
			if (c == 'D'){
				con(id1, id2 + n);
				con(id1 + n, id2);
			}
#ifdef my_debug
			cout << c << ' ' << id1 << ' ' << id2 << endl;
			show(stu, 2 * (n + 1));
#endif
		}
	}
	
	return 0;
}