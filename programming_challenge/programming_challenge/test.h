
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;



string s;

int d_tuple(){
	int out = 0;
	int t = 0;
	for (int i = 0; i < s.length(); ++i){
		if (i > 0 && s[i] == s[i - 1]){
			++t;
			if (t < 3)
				++out;
		}
		else{
			t = 1;
			++out;
		}
	}
	return out;
}

int add_num(){
	int out = 0;
	bool stu1, stu2, stu3;
	stu1 = stu2 = stu3 = false;
	for (int i = 0; i < s.length(); ++i){
		if (s[i] >= 'a' && s[i] <= 'z')
			stu1 = true;
		if (s[i] >= 'A' && s[i] <= 'Z')
			stu2 = true;
		if (s[i] >= '0' && s[i] <= '9')
			stu3 = true;

	}
	out = 3 - stu1 - stu2 - stu3;
	return out;
}


void solve(){
	int out = 0;
	int add = add_num();
	int sub = (s.length() - d_tuple());
	out = add + sub;
	if (s.length() < 8){
		int len = s.length() + add;
		if (len < 8){
			out = add + sub;
			out += (8 - len);
		}
		else{
			out = add + (len - 8);
		}
	}
	else{
		out = max(add, sub);
		int len = s.length() - sub + add;
		if (len > 20)
			out += (len - 20);
	}
	cout << out << endl;
}

int main(){
	while(cin >> s)
	solve();
	return 0;
}