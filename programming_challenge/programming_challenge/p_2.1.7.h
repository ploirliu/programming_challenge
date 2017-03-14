#include <cstdio>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

vector<int> a(8);
const int d[2] = {  4,-4 };

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


void solve(){
	queue<vector<int>> q1;
	queue<int> q2;
	set<vector<int>> s;

	q1.push(a);
	q2.push(0);
	s.insert(a);

	while (!q1.empty()){
		vector<int> p1 = q1.front(); q1.pop();
		int p2 = q2.front(); q2.pop();

		//if (p2 == 28){
		//	for (int i = 0; i < 8; ++i){
		//		cout << p1[i] << " ";
		//		if (i % 4 == 3)
		//			cout << endl;
		//	}
		//	cout << p2 << endl;
		//}

		bool stu = true;
		for (int i = 0; i < 8; ++i){
			if (p1[i] != i){
				stu = false;
				break;
			}
		}
		if (stu){
			cout << p2 << endl;
			return;
		}
		int id = -1;
		for (int i = 0; i < 8; ++i){
			if (p1[i] == 0){
				id = i;
				break;
			}
		}
		if (id == -1)
			continue;
		int tmpid=-1;
		for (int i = 0; i < 2; ++i){
			tmpid = id + d[i];
			if (tmpid >= 0 && tmpid < 8){
				swap(p1[tmpid], p1[id]);
				if (s.count(p1) == 0){
					q1.push(p1);
					q2.push(p2 + 1);
					s.insert(p1);
				}
				swap(p1[tmpid], p1[id]);
			}
		}




		if (id == 0 || id == 4){
			tmpid = id + 1;
			swap(p1[tmpid], p1[id]);
			if (s.count(p1) == 0){
				q1.push(p1);
				q2.push(p2 + 1);
				s.insert(p1);
			}
			swap(p1[tmpid], p1[id]);
		}
		else if (id == 3 || id == 7){
			tmpid = id - 1;
			swap(p1[tmpid], p1[id]);
			if (s.count(p1) == 0){
				q1.push(p1);
				q2.push(p2 + 1);
				s.insert(p1);
			}
			swap(p1[tmpid], p1[id]);
		}
		else{
			tmpid = id - 1;
			swap(p1[tmpid], p1[id]);
			if (s.count(p1) == 0){
				q1.push(p1);
				q2.push(p2 + 1);
				s.insert(p1);
			}
			swap(p1[tmpid], p1[id]);

			tmpid = id + 1;
			swap(p1[tmpid], p1[id]);
			if (s.count(p1) == 0){
				q1.push(p1);
				q2.push(p2 + 1);
				s.insert(p1);
			}
			swap(p1[tmpid], p1[id]);
		}
	}
}



int main(){
	while (cin >> a[0] >> a[1] >> a[2] >> a[3]
		>> a[4] >> a[5] >> a[6] >> a[7]){
		solve();
	}
	return 0;
}