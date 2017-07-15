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
	cout << tar[i] << ' '; \
	cout << endl;




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

//int n_stu[MAX_N];
//void n_init(){
//	rep(i, 0, n)
//		n_stu[i] = i;
//}
//int n_getf(int id){
//	if (n_stu[id] != id){
//		n_stu[id] = n_getf(n_stu[id]);
//	}
//	return n_stu[id];
//}
//bool n_same(int i, int j){
//	if (n_getf(i) == n_getf(j))
//		return true;
//	return false;
//}
//void n_union(int i, int j){
//	int fi = n_getf(i), fj = n_getf(j);
//	if (fi != fj){
//		n_stu[fi] = fj;
//	}
//}

#define my_debug

const int MAX_N = 17;
const int MAX_M = 17;
int mod;
int n,m;
bool color[MAX_N][MAX_M];
//bool used[MAX_N][MAX_M];
int dp[2][1 << MAX_M];


void solve(){
	int *crt = dp[0], *next = dp[1];
	crt[0] = 1;
	for (int i = n - 1; i >= 0; i--){
		for (int j = m - 1; j >= 0; j--){
			for (int used = 0; used < 1 << m; used++){
				if ((used >> j & 1) || color[i][j]){
					next[used] = crt[used & ~(1 << j)];
				}
				else{
					int res = 0;
					if (j + 1 < m && !(used >> (j + 1) & 1) && !color[i][j + 1]){
						res += crt[used | 1 << (j + 1)];
					}
					if (i + 1 < n && !color[i + 1][j]){
						res += crt[used | 1 << j];
					}
					next[used] = res%mod;
				}
				
			}
			cout << i << "," << j << endl;
			cout << "crt" << endl;
			for (int used = 0; used < 1 << m;used++)
			cout << used<<":"<<crt[used] << " ";
			cout << endl<<"next" << endl;
			for (int used = 0; used < 1 << m; used++)
				cout << used << ":" << next[used] << " ";
			cout << endl;
			swap(crt, next);
		}
	}
	printf("%d\n", crt[0]);
}

int main(){
	m = n = 3;
	mod = 1 << 25;
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			if (i == j && i == 1){
				color[i][j] = true;
			}
			else{
				color[i][j] = false;
			}
		}
	}
	solve();
	return 0;
}