#include <iostream>
#include <vector>
using namespace std;

int a[10];

bool dfs(int id, int l_last, int r_last){
	if (id == 10)
		return true;
	if (a[id] > l_last && dfs(id + 1, a[id], r_last))
		return true;
	if (a[id] > r_last && dfs(id + 1, l_last, a[id]))
		return true;
	return false;
}

void solve(){
	if (dfs(0, -1, -1))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < 10; ++j)
			cin >> a[j];
		solve();
	}
	return 0;
}