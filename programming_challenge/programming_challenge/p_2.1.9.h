#include <cstdio>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
const int INF = 1147483647;
const int MAX_N = 15;

int all[MAX_N];
int n;
int sum;

void solve(){
	for (int i = 1; i <= n; ++i){
		all[i] = i;
	}
	int b[MAX_N];
	do{
		memcpy(b, all, sizeof(all));
		//for (int i = 1; i <= n; ++i){
		//	cout << b[i] << ' ';
		//}
		for (int k = n; k > 1; --k){
			for (int i = 1; i < k; ++i){
				b[i] = b[i] + b[i + 1];
			}
		}
		int out = b[1];
		if (out == sum){
			for (int i = 1; i <= n; ++i){
				if (i == 1)
					cout << all[i];
				else
					cout << ' ' << all[i];
			}
			cout << endl;
			return;
		}
		
		//cout << endl << out << endl;
	} while (next_permutation(&all[1], &all[1] + n));
}

int main(){
	cin >> n >> sum;
	solve();
	return 0;
}