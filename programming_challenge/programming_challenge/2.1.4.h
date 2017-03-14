// this is about dfs
// question is : give number a1,a2...an, decide whether it could select some numbers that add up to k
//  1<= n <=20
// -e8<= ai <= e8
// -e8<= k <=e8

// example 1:
// n=4, a={1,2,4,7}, k=13
// output: Yes 
// 13=2+4+7

// example 2:
// n=4, a={1,2,4,7}, k=15
// output: No

#include <stdio.h>
const int MAX_N = 25;
int a[MAX_N];
int n, k;

bool dfs(int i, int sum){
	if (i == n) return sum == k;
	// not add ai
	if (dfs(i + 1, sum)) return true;
	// add ai
	if (dfs(i + 1, sum + a[i])) return true;
	return false;
}

void solve(){
	if (dfs(0, 0)) printf("Yes\n");
	else printf("No\n");
}




// poj No.2386, mysubmit
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(vector<string> &all,int h,int w, int i, int j){
	all[i][j] = '.';
	int dis_h[3] = { -1, 0, 1 };
	int dis_w[3] = { -1, 0, 1 };
	for (int ii = 0; ii < 3; ++ii){
		for (int jj = 0; jj < 3; ++jj){
			int tmph = i + dis_h[ii], tmpw = j + dis_w[jj];
			if (tmph >= 0 && tmph < h && tmpw >= 0 && tmpw < w && all[tmph][tmpw] == 'W'){
				dfs(all, h, w, tmph, tmpw);
			}
		}
	}
}

int solve(vector<string> &all,int h,int w){
	int out = 0;
	for (int i = 0; i < h; ++i){
		for (int j = 0; j < w; ++j){
			if (all[i][j] == 'W'){
				dfs(all, h, w, i, j);
				++out;
			}
		}
	}
	return out;
}

int main(){
	int h, w;
	vector<string> all;
	cin >> h >> w;
	for (int i = 0; i < h; ++i){
		string s;
		cin >> s;
		all.push_back(s);
	}
	cout << solve(all, h, w) << endl;
	return 0;
}


// poj No.2386, mysubmit,book's submit
#include <cstdio>
int N, M;
const int MAX_ = 105;
char field[MAX_][MAX_];

void b_dfs(int x, int y){
	field[x][y] = '.';
	for (int dx = -1; dx <= 1; ++dx){
		for (int dy = -1; dy <= 1; ++dy){
			int nx = x + dx, ny = y + dy;
			if (0 <= nx && nx < N && 0 <= ny && ny <= M && field[nx][ny] == 'W') b_dfs(nx, ny);
		}
	}
}

void b_solve(){
	int res = 0;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			if (field[i][j] == 'W'){
				b_dfs(i, j);
				++res;
			}
		}
	}
	printf("%d\n", res);
}

// Becareful of the getchar() , that is for '\n'
int b_main(){
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i){
		getchar();
		for (int j = 0; j < M; ++j){
			scanf("%c", &field[i][j]);
		}
	}
	b_solve();
	return 0;
}