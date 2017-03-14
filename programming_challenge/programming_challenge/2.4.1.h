//#include <stdio.h>
//
//
///////////////////////////////////////////////////////////////////////
//// realize of heap
//const int MAX_N = 100005;
//int heap[MAX_N], sz = 0;
//void push(int x){
//	int i = sz++;
//	while (i > 0){
//		int p = (i - 1) / 2;
//		
//		if (heap[p] <= x)break;
//
//		heap[i] = heap[p];
//		i = p;
//	}
//	heap[i] = x;
//}
//int pop(){
//	int ret = heap[0];
//	int x = heap[--sz];
//	int i = 0;
//	while (i * 2 + 1 < sz){
//		int a = i * 2 + 1, b = i * 2 + 2;
//		if (b < sz && heap[b] < heap[a]) a = b;
//
//		if (heap[a] >= x)break;
//
//		heap[i] = heap[a];
//		i = a;
//	}
//	heap[i] = x;
//	return ret;
//}
///////////////////////////////////////////////////////////////////////
//
//
//
//
//
/////////////////////////////////////////////////////////////////////
//#include <queue>
//#include <cstdio>
//using namespace std;
//int main(){
//	priority_queue<int> pque;
//	pque.push(3);
//	pque.push(5);
//	pque.push(1);
//	while (!pque.empty()){
//		printf("%d\n", pque.top());
//		pque.pop();
//	}
//	return 0;
//}
/////////////////////////////////////////////////////////////////////
//
//



///////////////////////////////////////////////////////////////////////////
// poj 2431
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct node{
	int a;
	int b;
	bool operator < (const node &right) const{
		return this->a < right.a;
	}
}node;

const int MAX_N = 10005;
node all[MAX_N];
int n;
int l, p;

void solve(){
	int ans = 0;
	sort(all, all + n);
	all[n].a = l; all[n].b = 0;
	priority_queue<int> q;
	for (int i = 0; i <= n; ++i){
		while (p < all[i].a && !q.empty()){
			p += q.top();
			q.pop();
			++ans;
		}
		if (p >= all[i].a)
			q.push(all[i].b);
		else
			break;
	}
	if (p >= all[n].a) printf("%d\n", ans);
	else printf("%d\n", -1);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d %d", &all[i].a, &all[i].b);
	}
	scanf("%d %d", &l, &p);
	for (int i = 0; i < n; ++i)
		all[i].a = l - all[i].a;
	solve();
	return 0;
}

// book's code
int L, P, N;
int A[MAX_N], B[MAX_N];
void solve(){
	A[N] = L;
	B[N] = 0;
	N++;
	priority_queue<int> que;
	int ans = 0, pos = 0, tank = P;
	for (int i = 0; i < N; ++i){
		int d = A[i] - pos;
		while (tank - d < 0){
			if (que.empty()){
				puts("-1");
				return;
			}
			tank += que.top();
			que.pop();
			++ans;
		}
		tank -= d;
		pos = A[i];
		que.push(B[i]);
	}
	printf("%d\n", ans);
}


// good;
void solve(){
	int ans = 0;
	sort(all, all + n);
	all[n].a = l; all[n].b = 0;
	priority_queue<int> q;
	for (int i = 0; i <= n; ++i){
		while (p < all[i].a){
			if (q.empty()){
				printf("-1\n");
				return;
			}
			p += q.top();
			q.pop();
			++ans;
		}
		if (p >= all[i].a)
			q.push(all[i].b);
		else
			break;
	}
	printf("%d\n", ans);
}
///////////////////////////////////////////////////////////////////////////










/////////////////////////////////////////////////////////////////////////////////
//poj 3253
typedef long long ll;
#include <functional>
int N, L[MAX_N];
void solve(){
	ll ans = 0;
	priority_queue<int, vector<int>, greater<int> >que;
	for (int i = 0; i < N; ++i){
		que.push(L[i]);
	}
	while (que.size()>1){
		int l1, l2;
		l1 = que.top();
		que.pop();
		l2 = que.top();
		que.pop();

		ans += l1 + l2;
		que.push(l1 + l2);
	}
	printf("%lld\n",ans);
}
/////////////////////////////////////////////////////////////////////////////////