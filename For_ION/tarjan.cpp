#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int,int>
#define mem(x) memset((x),0,sizeof((x)))
#define endl "\n"
#define AC ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int maxn=1e5+50;

struct edge{
    int b,next;
}e[maxn];

int h[maxn];
int etot;

void add(int a,int b){
    e[etot].b=b;
    e[etot].next=h[a];
    h[a]=etot++;
}

int n,m;

int dfn[maxn],low[maxn],vis[maxn],cpt[maxn];  //cpt為連通分量數
int cnt;

void dfs(int x,int fa){
    vis[x]=1;
    dfn[x]=low[x]=++cnt;
    for(int i=h[x];i!=-1;i=e[i].next){
        int b=e[i].b;
        if(!vis[b]){
            dfs(b,x);
            low[x]=min(low[x],low[b]);
            if(low[b]>=dfn[x]) cpt[x]++;
        }
        else if(b!=fa){
            low[x]=min(low[x],dfn[b]);
        }
    }
}

int main(){
    AC;
    int a,b,i,j,T;
    cin>>n>>m;
    for(i=1;i<=n;i++) h[i]=-1;
    for(i=0;i<m;i++){
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    for(i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
            cpt[i]--;
        }
    }
    for(i=1;i<=n;i++){
        if(cpt[i]) cout<<i<<" "<<cpt[i]+1<<"\n";
    }
}
