//POJ 3617;
#include <stdio.h>
const int MAX_N = 2005;


// mycode
int n;
char c[MAX_N];
char ans[MAX_N];

void solve(){
	int a = 0, b = n - 1;
	int id = 0;
	while (a < b){
		int tmpa = a, tmpb = b;
		while (tmpa < tmpb && c[tmpa] == c[tmpb]){
			++tmpa, --tmpb;
		}
		if (c[tmpa] < c[tmpb])
			ans[id++] = c[a++];
		else
			ans[id++] = c[b--];
	}
	ans[id] = c[a];
	//printf("%s\n", c);
	bool stu = false;
	for (int i = 0; i < n; ++i){
		stu = true;
		if (i % 80 == 0 && i != 0){
			putchar('\n');
			stu = false;
		}
		putchar(ans[i]);
		
	}
	if (stu)
		putchar('\n');
}



// book code
int N;
char S[MAX_N + 1];
void b_solve(){
	int a = 0, b = N - 1;
	while (a <= b){
		bool left = false;
		for (int i = 0; a + i <= b; ++i){
			if (S[a + i] < S[b - i]){
				left = true;
				break;
			}
			else if (S[a + i]>S[b - i]){
				left = false;
				break;
			}
		}
		if (left)putchar(S[a++]);
		else putchar(S[b--]);
	}
	putchar('\n');
}


// new code

void n_solve(){
	int a = 0, b = n - 1;
	int id = 0;
	while (a <= b){
		bool left = false;
		for (int i = 0; a + i <= b; ++i){
			if (c[a + i] < c[b - i]){
				left = true;
				break;
			}
			else if (c[a + i]>c[b - i]){
				left = false;
				break;
			}
		}
		if (id % 80 == 0 && id != 0)
			putchar('\n');
		++id;
		if(left) putchar(c[a++]);
		else putchar(c[b--]);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		getchar();
		scanf("%c", &c[i]);
	}
	n_solve();
	return 0;
}