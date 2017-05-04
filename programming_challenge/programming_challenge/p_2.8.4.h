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
int n, m, x;
const int MAX_N = 1005;

P r[MAX_N][MAX_N];
int r_num[MAX_N];


bool stu[MAX_N];
int len[MAX_N];
int len2[MAX_N];

void myinit(){
	init(r_num, 0);
}



void spfa(int id,int *mylen){
	init(stu, 0);
	fill(mylen, mylen + n + 1, INF);
	queue<int> q;
	mylen[id] = 0;
	stu[id] = true;
	q.push(id);
	while (!q.empty()){
		int tmp = q.front(); q.pop();
		stu[tmp] = false;
		rep(i, 0, r_num[tmp]){
			P &tmp2 = r[tmp][i];
			if (mylen[tmp2.first] > mylen[tmp] + tmp2.second){
				mylen[tmp2.first] = mylen[tmp] + tmp2.second;
				if (stu[tmp2.first] == false){
					stu[tmp2.first] = true;
					q.push(tmp2.first);
				}
			}
		}
	}
}

void solve(){
	int out = -1;
	spfa(x, len2);
	rep(i, 1, n + 1){
		if (i != x && len2[i]<INF){
			spfa(i,len);
			if (len[x] < INF)
				out = max(out, len[x] + len2[i]);
		}
#ifdef my_debug
		cout<<endl;
		show(len2, n + 1);
		show(len, n + 1);
		cout << endl;
#endif

	}
	pint(out);
}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
#endif
	while (gint3(n,m,x) != EOF){
		myinit();
		int tmp1, tmp2, tmp;
		rep(i, 0, m){
			gint3(tmp1, tmp2, tmp);
			r[tmp1][r_num[tmp1]].first = tmp2;
			r[tmp1][r_num[tmp1]].second = tmp;
			++r_num[tmp1];
		}
		solve();
	}
	return 0;
}