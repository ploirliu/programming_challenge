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

template<class T>
bool cmpless(const T &a, const T &b){
	return a < b;
}

template<class T>
bool cmpbigger(const T &a, const T &b){
	return a > b;
}




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

const int MAX_P = 40005;
int t, p;
int all[MAX_P];
int stu[MAX_P];

//void show(){
//	rep(i, 0, p){
//		cout <<all[i]<< ' ';
//	}
//	cout << endl;
//}



void solve(){
	show(all,p);
	fill(stu,stu+p,INF);
	//init(stu, -1);
	int ans = 0;
	rep(i, 0, p){
		int* id = upper_bound(stu, stu + p, all[i],cmpless<int>);
		*id = all[i];
		//cout << "id-stu" << id - stu << endl;
		//ans = max(ans, stu[i]);
		ans = max(ans, id - stu+1);
		show(stu, p);
	}
	pint(ans);
}

int main(){
	freopen("a.in", "r", stdin);
	//while (scanf("", ) != EOF){
	gint(t);
	rep(i, 0, t){
		gint(p);
		rep(j, 0, p){
			gint(all[j]);
		}
		solve();
	}
	//}
	return 0;
}