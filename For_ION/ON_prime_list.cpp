#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mem(x, a) memset(x, a, sizeof(x))
#define AC ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;

const int maxn = 1e6 + 50;
int p[maxn];
vector<int> prime;

void era(int n){
	fill(p + 2, p + n + 1, 1);
	for(int i = 2; i <= n; i ++){
		if(p[i] == 1) prime.pb(i);
		for(int j : prime){
			if(i * j > n) break;
			p[i * j] = j;
			if(i % j == 0) break;
		}
	}
}

main(){
	AC;
	era(maxn - 50);
}

