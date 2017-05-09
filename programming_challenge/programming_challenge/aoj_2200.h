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
const int INF = 1 << 26;
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


#define my_debu
const int MAX_N = 205;
const int MAX_M = 10005;
int n, m;

int sea[MAX_N][MAX_N];
int land[MAX_N][MAX_N];
const int MAX_R = 1005;
int r;
int dir[MAX_R];

int dp[MAX_N][MAX_N];

void myinit(){
	rep(i, 0, MAX_N){
		rep(j, 0, MAX_N){
			sea[i][j] = land[i][j] = i == j ? 0 : INF;
			dp[i][j] = INF;
		}
	}
}

void floy_land(){
	rep(k, 1, n + 1){
		rep(i, 1, n + 1){
			rep(j, 1, n + 1){
				land[i][j] = min(land[i][j], land[i][k] + land[k][j]);
			}
		}
	}
}

void floy_sea(){
	rep(k, 1, n + 1){
		rep(i, 1, n + 1){
			rep(j, 1, n + 1){
				sea[i][j] = min(sea[i][j], sea[i][k] + sea[k][j]);
			}
		}
	}
}
void myshow(){
	rep(i, 1, n + 1){
		rep(j, 1, n + 1){
			cout << dp[i][j] <<' ';
		}
		cout << endl;
	}
}
void solve(){
	floy_land();
	floy_sea();
	int out =INF;
	dp[dir[0]][dir[0]] = 0;
	rep(i, 1, r){
		//int tmp = INF;
		out = INF;
		rep(j, 1, n + 1){
			dp[dir[i]][j] = INF;
			rep(k, 1, n + 1){
				if (j == k){
					dp[dir[i]][j] = min(dp[dir[i]][j], dp[dir[i - 1]][k] + land[dir[i]][dir[i - 1]]);
				}
				else{
					dp[dir[i]][j] = min(dp[dir[i]][j], dp[dir[i - 1]][k] + land[dir[i - 1]][k] + sea[k][j] + land[j][dir[i]]);
				}
			}
			out = min(out, dp[dir[i]][j]);
			//cout << i << ":" << j << endl;
			//myshow();
		}
		//out += tmp;
		//cout << "out:" << out << endl;
	}
	pint(out);
}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
#endif
	while (gint2(n,m) != EOF){
		if (n + m == 0)
			break;
		myinit();
		int a, b,c;
		char d;
		rep(i, 0, m){
			gint3(a, b, c);
			scanf("%c", &d);
			scanf("%c", &d);
			if (d == 'L'){
				land[a][b] = land[b][a] = c;
			}
			if (d == 'S'){
				sea[a][b] = sea[b][a] = c;
			}
		}
		gint(r);
		rep(i, 0, r)
			gint(dir[i]);
		solve();
	}
	return 0;
}