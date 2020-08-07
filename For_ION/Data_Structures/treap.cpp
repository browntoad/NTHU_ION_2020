#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 2e5 + 50;
int x[maxn];

struct Node{
	Node *lch, *rch;
	bool rev;
	int val, size, pri, change, minnum;
	Node(int _val = 0){
		val = minnum = _val;
		change = -INF;
		rev = false;
		size = 1;
		pri = rand();
		lch = rch = NULL;
	}
	inline void set_rev(){
		rev = !rev;
		swap(lch, rch);
	}
	inline void make_change(int _val){
		if(change != -INF) change += _val;
		else change = _val;
		val += _val;
		minnum += _val;
	}
	inline void up(){
		size = 1;
		minnum = val;
		if(lch) size += lch->size, minnum = min(minnum, lch->minnum);
		if(rch) size += rch->size, minnum = min(minnum, rch->minnum);
	}
	inline void down(){
		if(rev){
			if(lch) lch->set_rev();
			if(rch) rch->set_rev();
			rev = 0;
		}
		if(change != -INF){
			if(lch) lch->make_change(change);
			if(rch) rch->make_change(change);
			change = -INF;
		}
	}
} *root = NULL;

inline int getsize(Node* node){
	return node? node->size : 0;
}

inline void split(Node* node, Node*& a, Node*& b, int k){
	if(!node) a = b = NULL;
	else{
		node->down();
		if(k <= getsize(node->lch)){
			b = node;
			split(node->lch, a, b->lch, k);
			b->up();
		}
		else{
			a = node;
			split(node->rch, a->rch, b, k - getsize(node->lch) - 1);
			a->up();
		}
	}
}

inline Node* merge(Node* a, Node* b){
	if(!a || !b) return a? a : b;
	if(a->pri < b->pri){
		a->down();
		a->rch = merge(a->rch, b);
		a->up();
		return a;
	}
	else{
		b->down();
		b->lch = merge(a, b->lch);
		b->up();
		return b;
	}
}

inline void insert(int k, int val){
	Node *a, *b;
	split(root, a, b, k);
	root = merge( merge(a, new Node(val)), b);
}

inline void reverse(int l, int r){
	Node *a, *b, *a2, *b2;
	split(root, a, b, r);
	split(a, a2, b2, l - 1);
	b2->set_rev();
	root = merge( merge(a2, b2), b);
}

inline void erase(int k){
	Node *a, *b, *a2, *b2;
	split(root, a, b, k - 1);
	split(b, a2, b2, 1);
	delete a2;
	root = merge(a, b2);
}

void print(Node* node);

inline void add(int l, int r, int val){
	Node *a, *b, *a2, *b2;
	split(root, a, b, r);
	split(a, a2, b2, l - 1);
	b2->make_change(val);
	root = merge( merge(a2, b2), b);
}

inline void query(int l, int r){
	Node *a, *b, *a2, *b2;
	split(root, a, b, r);
	split(a, a2, b2, l - 1);
	int ans = b2->minnum;
	cout << ans << "\n";
	root = merge( merge(a2, b2), b);
}

inline void rotate(int l, int r, int T){
	Node *a, *b, *a2, *b2, *a3, *b3;
	if(T <= 0) return;
	split(root, a, b, r);
	split(a, a2, b2, l - 1);
	int len = r - l + 1;
	int k = T % len;
	split(b2, a3, b3, len - k);
	root = merge( merge( a2, merge(b3, a3) ), b);
}

signed main(){
	int n, Q;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		int a;
		scanf("%d", &a);
		root = merge(root, new Node(a));
	}
	cin >> Q;
	char s[10];
	while(Q --){
		scanf("%s", s);
		if(s[0] == 'A'){
			int a, b, val;
			scanf("%d%d%d", &a, &b, &val);
			add(a, b, val);
		}
		else if(s[0] == 'I'){
			int a, b;
			scanf("%d%d", &a, &b);
			insert(a, b);
		}
		else if(s[0] == 'D'){
			int a;
			scanf("%d", &a);
			erase(a);
		}
		else if(s[0] == 'M'){
			int a, b;
			scanf("%d%d", &a, &b);
			query(a, b);
		}
		else if(s[0] == 'R' && s[3] == 'E'){
			int a, b;
			scanf("%d%d", &a, &b);
			reverse(a, b);
		}
		else{
			int a, b, T;
			scanf("%d%d%d", &a, &b, &T);
			rotate(a, b, T);
		}
	}
}