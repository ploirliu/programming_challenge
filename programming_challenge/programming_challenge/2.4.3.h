#include <cstdio>
using namespace std;
struct node{
	int val;
	node *lch, *rch;
};

node *insert(node *p, int x){
	if (p == NULL){
		node *q = new node;
		q->val = x;
		q->lch = q->rch = NULL;
		return q;
	}
	else{
		if (x < p->val) p->lch = insert(p->lch, x);
		else p->rch = insert(p->rch, x);
		return p;
	}
}

bool find(node* p, int x){
	if (p == NULL) return false;
	else if (x == p->val) return true;
	else if (x < p->val) return find(p->lch, x);
	else return find(p->rch, x);
}

node *remove(node* p, int x){
	if (p == NULL) return NULL;
	else if (x < p->val) p->lch = remove(p->lch, x);
	else if (x>p->val) p->rch = remove(p->rch, x);
	else if (p->lch == NULL){
		node* q = p->rch;
		delete p;
		return q;
	}
	else if (p->lch->rch == NULL){
		node *q = p->lch;
		q->rch = p->rch;
		delete p;
		return q;
	}
	else{
		node *q;
		for (q = p->lch; q->rch->rch != NULL; q = q->rch);
		node *r = q->rch;
		q->rch = r->lch;
		r->lch = p->lch;
		r->rch = p->rch;
		delete p;
		return r;
	}
	return p;
}




//////////////////////////////////////////////////////////////////////////////
// use of set
#include <set>
int main(){
	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(5);

	set<int>::iterator ite;
	ite = s.find(1);
	if (ite == s.end()) puts("not found");
	else puts("found");

	ite = s.find(2);
	if (ite == s.end()) puts("not found");
	else puts("found");

	s.erase(3);

	if (s.count(3) != 0) puts("found");
	else puts("not found");

	for (ite = s.begin(); ite != s.end(); ++ite){
		printf("%d\n", *ite);
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////






///////////////////////////////////////////////////////////////////////////////
#include <map>
#include <string>
int main(){
	map<int, const char*> m;
	m.insert(make_pair(1, "one"));
	m.insert(make_pair(10, "ten"));
	m[100] = "hundred";

	map<int, const char*>::iterator ite;
	ite = m.find(1);
	puts(ite->second);

	if (ite == m.end()) puts("not found");
	else puts(ite->second);

	puts(m[10]);

	m.erase(10);

	for (ite = m.begin(); ite != m.end(); ++ite){
		printf("%d: %d\n", ite->first, ite->second);
	}

	return 0;
}
///////////////////////////////////////////////////////////////////////////////