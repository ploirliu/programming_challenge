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
#define rep(i,start,end) for(int i=(start);i<(end);++i)
#define pint(i) printf("%d\n",(i))
#define gint(i) scanf("%d",&(i))
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


const int MAX_K = 405;
const int MAX_A = 405 * 105 * 15;

typedef struct node{
	int h, a, c;
	bool operator<(const node &right)const{
		return a < right.a;
	}
}node;

node all[MAX_K];
int dp[2][MAX_A];
int k;

inline int id(int i){
	return i & 1;
}

inline int last(int i){
	return (i - 1) & 1;
}

void myshow(int i){
	rep(j, 0, 50){
		cout << j<<":"<<dp[id(i)][j] << ' ';
	}
	cout << endl;
}


void solve(){
	sort(all, all + k);
	init(dp, -1);
	dp[0][0] = dp[1][0] = 0;
	rep(i, 0, k){
		rep(j, 0, (all[i].a + 1)){
			if (dp[last(i)][j] >= 0){
				dp[id(i)][j] = all[i].c;
			}
			else if ((j - all[i].h) >= 0 && dp[id(i)][j - all[i].h] > 0){
				dp[id(i)][j] = dp[id(i)][j - all[i].h] - 1;
			}
		}
		//myshow(i);
	}
	int out = 0;
	rep(i, 0, MAX_A){
		if (dp[id(k - 1)][i] >= 0)
			out = max(out, i);
	}
	printf("%d\n", out);
}

int main(){
//	freopen("a.in", "r", stdin);
	while (gint(k) != EOF){
		rep(i, 0, k){
			gint(all[i].h);
			gint(all[i].a);
			gint(all[i].c);
		}
		solve();
	}
	return 0;
}