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


typedef struct node{
	int a, b;
	bool operator<(const node &right)const{
		if (a == right.a)
			return b < right.b;
		return a < right.a;
	}
	bool stu;
}node;

const int MAX_N = 5005;
int t, n;
node all[MAX_N];
void show(){
	for (int i = 0; i < n; ++i){
		cout << "(" << all[i].a << "," << all[i].b << ")" << ',';
	}
	cout << endl;
}

void solve(){
	sort(all, all + n);
	//show();
	int ans = 0;
	rep(i, 0, n){
		if (all[i].stu == false){
			all[i].stu = true;
			++ans;
			int a = all[i].a, b = all[i].b;

			rep(j, i + 1, n){
				if (all[j].stu==false && all[j].a >= a && all[j].b >= b){
					all[j].stu = true;
					a = all[j].a, b = all[j].b;
				}
			}
		}
		//rep(k, 0, n)
		//	cout << all[k].stu << ' ';
		//cout << endl;
	}
	pint(ans);
}

int main(){
	//freopen("a.in", "r", stdin);
	//while (scanf("", ) != EOF){
	scanf("%d", &t);
	for (int i = 0; i < t; ++i){
		scanf("%d", &n);
		for (int j = 0; j < n; ++j){
			scanf("%d %d", &all[j].a, &all[j].b);
			all[j].stu = false;
		}
		solve();
	}
	//}
	return 0;
}