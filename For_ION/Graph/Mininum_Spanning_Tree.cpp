#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#define endl '\n'
#define REP(i,n) for (int i=0;i<(n);i++)
using namespace std;
int par[100005];
struct Edge{
	int a,b,weight;
}edge[200005];

bool cmp (Edge a, Edge b){
	return a.weight < b.weight;
}
int find(int x){
	if (par[x]==x) return x;
	else return par[x] = find(par[x]);
}
void uni(int a, int b){
	a=find(a); b=find(b);
	par[a]=b;
}
int main (){
	int n,m;
	while (cin>>n>>m){
		REP(i,n) par[i]=i;
		REP(i,m){
			cin>>edge[i].a>>edge[i].b>>edge[i].weight;
		}
		sort(edge,edge+m,cmp);
		long long ans=0;
		int cnt = 0;
		REP(i,m){
			if (find(edge[i].a)==find(edge[i].b)) continue;
			else {
				uni(edge[i].a, edge[i].b);
				ans+=edge[i].weight;
				cnt++;
			}
		}
		if (cnt<n-1) ans=-1;
		//cout<<ans<<endl;
	}
}
