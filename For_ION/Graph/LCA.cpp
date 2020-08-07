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
    edge(int a=0,int b=0):
        to(a),val(b){}
};

const int maxn=1e5+5;

int n;
vector<edge> vc[maxn];
int fa[maxn];
int up[maxn][(int)log2(maxn)+5];
int deep[maxn];

void init(){
    mem(fa);
    mem(up);
    for(int i=0;i<n;i++){
        vc[i].clear();
    }
}

void dfs(int x,int dep,int fa){
    deep[x]=dep;
    up[x][0]=fa;
    for(auto i : vc[x]){
        if(i.to!=fa)
            dfs(i.to,dep+1,x);
    }
}

int lca(int u,int v){
    if(deep[u]<deep[v]){
        swap(u,v);
    }
    if(deep[u]!=deep[v]){
        for(int k=(int)log2(n)+1;k>=0;k--){
            if(deep[up[u][k]]>=deep[v])
                u=up[u][k];
        }
    }

    if(u==v) return u;

    for(int k=(int)log2(n)+1;k>=0;k--){
        if(up[u][k]!=up[v][k])
            u=up[u][k],v=up[v][k];
    }

    return fa[u];
}


int main(){
    AC;
    int i,T;
    while(cin>>n && n){
        init();
        int from,to,val;
        for(i=0;i<n;i++){
            cin>>from>>to>>val;
            vc[from].pb(edge(to,val));
            vc[to].pb(edge(from,val));
        }

        dfs(0,0,0);

        for(int k=1;(1<<k)<n;k++){
            for(i=1;i<n;i++){
                up[i][k]=up[up[i][k-1]][k-1];
            }
        }



        int m;
        cin>>m;
        int a,b;
        for(i=0;i<m;i++){
            cin>>a>>b;
            cout<<lca(a,b);
        }

    }
}
