#include <cstdio>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

vector<int> a(8);
const int d[4] = {  4,-4,1,-1 };
map<int, int> dp;
//void solve(){
//	int id = -1;
//	for (int i = 0; i < a.size(); ++i){
//		if (a[i] == 0){
//			id = i;
//			break;
//		}
//	}
//	queue<vector<int>> q1;
//	queue<int> q2;
//	queue<int> q3;
//	set<vector<int>> s;
//
//	q1.push(a);
//	q2.push(id);
//	q3.push(0);
//	s.insert(a);
//
//	while (!q1.empty()){
//		vector<int> p1 = q1.front(); q1.pop();
//		int p2 = q2.front(); q2.pop();
//		int p3 = q3.front(); q3.pop();
//
//		for (int i = 0; i < 8; ++i){
//			cout << p1[i] << " ";
//		}
//		cout << endl << p2 << endl << p3 << endl;
//
//		if (p2<0 || p2>7)
//			continue;
//		bool stu = true;
//		for (int i = 0; i < 8; ++i){
//			if (p1[i] != i){
//				stu = false;
//				break;
//			}
//		}
//		if (stu){
//			cout << p3 << endl;
//			return;
//		}
//		for (int i = 0; i < 4; ++i){
//			int tmpid = p2 + d[i];
//			if (tmpid >= 0 && tmpid < 8){
//				swap(a[tmpid], a[p2]);
//				if (s.count(a) == 0){
//					q1.push(a);
//					q2.push(tmpid);
//					q3.push(p3 + 1);
//					s.insert(a);
//				}
//				swap(a[tmpid], a[p2]);
//			}
//		}
//	}
//}
int m_cprs(){
	int num = 0;
	for (int i = 0; i < 8; ++i){
		num = num * 10 + a[i];
	}
	return num;
}
void m_dcprs(int num){
	for (int i = 7; i >= 0; --i){
		a[i] = num % 10;
		num /= 10;
	}
}

//void solve(){
//	queue<int> q1;
//	queue<int> q2;
//	set<int> s;
//
//	q1.push(m_cprs());
//	q2.push(0);
//	s.insert(m_cprs());
//
//	while (!q1.empty()){
//		m_dcprs(q1.front()); q1.pop();
//		int p2 = q2.front(); q2.pop();
//
//		//if (p2 == 28){
//		//	for (int i = 0; i < 8; ++i){
//		//		cout << p1[i] << " ";
//		//		if (i % 4 == 3)
//		//			cout << endl;
//		//	}
//		//	cout << p2 << endl;
//		//}
//
//		bool stu = true;
//		for (int i = 0; i < 8; ++i){
//			if (a[i] != i){
//				stu = false;
//				break;
//			}
//		}
//		if (stu){
//			cout << p2 << endl;
//			return;
//		}
//		int id = -1;
//		for (int i = 0; i < 8; ++i){
//			if (a[i] == 0){
//				id = i;
//				break;
//			}
//		}
//		if (id == -1)
//			continue;
//		int tmpid=-1;
//		for (int i = 0; i < 4; ++i){
//			if ((id == 3 && i == 2) || (id == 4) && (i == 3))
//				continue;
//			tmpid = id + d[i];
//			if (tmpid >= 0 && tmpid < 8){
//				swap(a[tmpid], a[id]);
//				if (s.count(m_cprs()) == 0){
//					q1.push(m_cprs());
//					q2.push(p2 + 1);
//					s.insert(m_cprs());
//				}
//				swap(a[tmpid], a[id]);
//			}
//		}
//	}
//}
void solve(){
	for (int i = 0; i < 8; ++i){
		a[i] = i;
	}
	queue<int> q1;
	queue<int> q2;

	q1.push(m_cprs());
	q2.push(0);
	dp[m_cprs()] = 0;

	while (!q1.empty()){
		m_dcprs(q1.front()); q1.pop();
		int p2 = q2.front(); q2.pop();

		int id = -1;
		for (int i = 0; i < 8; ++i){
			if (a[i] == 0){
				id = i;
				break;
			}
		}
		if (id == -1)
			continue;
		int tmpid = -1;
		for (int i = 0; i < 4; ++i){
			if ((id == 3 && i == 2) || (id == 4) && (i == 3))
				continue;
			tmpid = id + d[i];
			if (tmpid >= 0 && tmpid < 8){
				swap(a[tmpid], a[id]);
				if (dp.count(m_cprs()) == 0){
					q1.push(m_cprs());
					q2.push(p2 + 1);
					dp[m_cprs()]=p2+1;
				}
				swap(a[tmpid], a[id]);
			}
		}
	}
}


int main(){
	solve();
	while (cin >> a[0] >> a[1] >> a[2] >> a[3]
		>> a[4] >> a[5] >> a[6] >> a[7]){
		cout << dp[m_cprs()] << endl;
	}
	return 0;
}