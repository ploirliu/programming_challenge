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
const int MAX_N = 1005;
const int MAX_K = 105;
//ll dp[MAX_K][MAX_N];
int n, k;
class bignum{
public:
	bignum(int size = 4):len(size){
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
	static const int gap =1000000000;
};


bignum dp[MAX_K][MAX_N];
void show(){
	for (int i = 0; i <= k; ++i){
		for (int j = 0; j <= n; ++j){
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
}

void init(){
	for (int i = 0; i < MAX_K; ++i){
		for (int j = 0; j < MAX_N; ++j){
			dp[i][j].set(0);
		}
	}
}
void solve(){
	init();
	for (int i = 0; i <= k; ++i){
		dp[i][0].set(1);
	}
	for (int i = 1; i <= k; ++i){
		for (int j = 1; j <= n; ++j){
			if (j < i){
				dp[i][j] = dp[i - 1][j];
			}
			else{
				dp[i][j] += dp[i - 1][j];
				dp[i][j]+= dp[i][j - i];
			}
		}
		//cout << "i:" << i << endl;
		//show();
	}
	//printf("%lld\n", dp[k][n]);
	cout << dp[k][n] << endl;
}

int main(){
	//freopen("a.in", "r", stdin);
	while (scanf("%d %d",&n,&k) != EOF){
		solve();
	}
	//for (int i = 0; i < 100; ++i){
	//	int a = rand() % INF;
	//	int b = rand() % INF;
	//	cout << a <<"+" << b << "="<< a + b << endl;
	//	bignum b_a, b_b;
	//	b_a.set(a); b_b.set(b);
	//
	//	cout << b_a<<"+"<<b_b;
	//	b_a += b_b;
	//	cout <<"="<< b_a << endl;
	//}
	return 0;
}