#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int,int>
#define mem(x) memset((x),0,sizeof((x)))
#define AC ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct edge{
    int to,val;
    edge(int a,int b):
        to(a),val(b){}
};

const int maxn=1000;
vector<edge> vc[maxn];
vector<int> query[maxn];
bool vis[maxn];
map<pii, int> mp;

int n,m;
int p[maxn];

void init(){
    for(int i=0;i<maxn;i++){
        p[i]=i;
        vis[i]=false;
        vc[i].clear();
        query[i].clear();
    }
}

int find(int x){
    return x==p[x]? x:p[x]=find(p[x]);
}

void unions(int a,int b){ //(a head plug to b head)
    p[find(a)]=find(b);
}

void dfs(int x){
    if(vis[x]) return;
    vis[x]=true;

    for(auto i :vc[x]){
        dfs(i.to);
        unions(i.to,x);
        vis[i.to]=true;
    }

    for(auto i : query[x]){
        if(vis[i]){
            pii p;
            p={i,x};
            mp[p]=find(i);
            p={x,i};
            mp[p]=find(i);
        }
    }
}

int main(){
    AC;
    int i,T;
    int x[maxn],y[maxn];
    while(cin>>n && n){ //number of edges
        mp.clear();
        init();
        dfs(0);
        int from,to,val;
        for(i=0;i<n;i++){
            cin>>from>>to>>val;
            vc[from].pb(edge(to,val));
        }
        cin>>m; //number of queries
        for(i=0;i<m;i++){
            cin>>x[i]>>y[i];
            query[x[i]].pb(y[i]);
            query[y[i]].pb(x[i]);
        }
        dfs(0);
        for(i=0;i<m;i++){
            cout<<mp[{x[i],y[i]}]<<" ";
        }
        cout<<"\n";
    }

}
