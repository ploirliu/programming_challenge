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
#define pint2(i,j) printf("%d %d",(i),(j))
#define gint(i) scanf("%d",&(i))
#define gint2(i,j) scanf("%d %d",&(i),&(j))
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

typedef struct node{
	int min, max;
	bool operator<(const node& right)const{
		if (max == right.max)
			return min < right.min;
		return max < right.max;
	}
	friend ostream &operator<<(ostream &output, const node &now){
		output << "min:" << now.min << ",max:" << now.max;
		return output;
	}
}node;

typedef struct node2{
	int spf, num;
	bool operator<(const node2& right)const{
		return spf < right.spf;
	}
	friend ostream &operator<<(ostream &output, const node2& now){
		output << "spf:" << now.spf << ",num:" << now.num;
		return output;
	}
}node2;

const int MAX_C = 2505;
const int MAX_L = 2505;

node cow[MAX_C];
node2 sun[MAX_L];
int c, l;


//void myshow(int i){
//	rep(j, 0, ){
//		cout << dp[id(i)][j] << ' ';
//	}
//	cout << endl;
//}


void solve(){
	//sort(cow, cow + c);
	////show(cow, c);
	//priority_queue<int,vector<int>,std::greater<int> > p;
	//rep(i, 0, l){
	//	rep(j, 0, sun[i].num)
	//		p.push(sun[i].spf);
	//}
	//int out = 0;
	//rep(i, 0, c){
	//	vector<int> vtmp;
	//	while (!p.empty()){
	//		int tmp = p.top();
	//		//cout << tmp << endl;
	//		if (tmp >= cow[i].min){
	//			if (tmp <= cow[i].max){
	//				p.pop();
	//				++out;
	//				break;
	//			}
	//			else{
	//				break;
	//			}
	//		}
	//		else{
	//			vtmp.push_back(tmp);
	//			p.pop();
	//		}
	//	}
	//	rep(j, 0, vtmp.size())
	//		p.push(vtmp[j]);
	//}
	//printf("%d\n", out);
	//sort(sun, sun + l);
	//show(sun, l);
	//priority_queue<node> p;
	//rep(i, 0, c)
	//	p.push(cow[i]);
	//int ans = 0;
	//int cur
	sort(cow, cow + c);
	sort(sun, sun + l);
	//show(cow, c);
	//show(sun, l);
	int ans = 0;
	rep(i, 0, c){
		rep(j, 0, l){
			if (sun[j].num && sun[j].spf <= cow[i].max){
				if (sun[j].spf >= cow[i].min){
					++ans;
					--sun[j].num;
					break;
				}
			}
			if(sun[j].spf>cow[i].max){
				break;
			}
		}
	}
	pint(ans);
}


bool mycmp(const node &left, const node &right){
	if (left.min == right.min)
		return left.max < right.max;
	return left.min < right.min;
}

void solve2(){
	sort(cow, cow + c,mycmp);
	sort(sun, sun + l);
	int cur = 0;
	priority_queue<int,vector<int>,greater<int> > p;
	int ans = 0;
	rep(i, 0, l){
		while (cur < c && cow[cur].min <= sun[i].spf){
			p.push(cow[cur].max);
			++cur;
		}
		while (!p.empty() && sun[i].num){
			int tmp = p.top(); p.pop();
			//cout << tmp << endl;
			if (sun[i].spf <= tmp){
				++ans;
				--sun[i].num;
			//	break;
			}
		}
	}
	pint(ans);
}


int main(){
	//freopen("a.in", "r", stdin);
	while (scanf("%d %d",&c,&l) != EOF){
		rep(i, 0, c){
			gint(cow[i].min);
			gint(cow[i].max);
		}
		rep(i, 0, l){
			gint(sun[i].spf);
			gint(sun[i].num);
		}
		solve2();
	}
	return 0;
}