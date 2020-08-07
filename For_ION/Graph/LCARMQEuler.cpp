#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int,int>
#define mem(x) memset((x),0,sizeof((x)))
#define AC ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int maxn=1e5+5;

struct edge{
    int to,val;
    edge(int a,int b):
        to(a),val(b){}
};

int n;

vector<int> euler;
vector<edge> vc[maxn];
int deep[maxn];
int exist[maxn];
int f[maxn][25];

void init(){
    euler.clear();
    mem(f);
    for(int i=0;i<n;i++){
        exist[i]=deep[i]=0;
        vc[i].clear();
    }
}

void dfs(int x,int dep,int f,int cnt){
    if(exist[x]==0) exist[x]=cnt;
    euler.pb(x);
    for(auto i : vc[x]){
        if(i.to!=f)
            dfs(i.to,dep+1,x,cnt+1);
    }

}

void initRMQ(){
    int i;
    for(i=0;i<n;i++){
        f[i][0]=euler[i];
    }
}

void RMQ(){
    int i,j;
    for(j=0;j<20;j++){
        for(i=1;i+(i<<j)<=n;i++){
            f[i][j]=min(f[i][j-1],f[i+(1<<j)][j-1]);
        }
    }
}

void query(int a,int b){
    int i;
    int k=log2(b-a);
    cout<<min(f[a][k],f[b-(1<<k)][k]);
}

int main(){
    AC;
    int a,b,m,n,i,T;

    while(cin>>n && n){
        init();
        int from,to,val;
        for(i=0;i<n;i++){
            cin>>from>>to>>val;
            vc[from].pb(edge(to,val));
            vc[to].pb(edge(from,val));
        }
        initRMQ();
        RMQ();
        dfs(0,0,0,0);

        int m;
        cin>>m;
        int a,b;
        for(i=0;i<m;i++){
            cin>>a>>b;
            query(exist[a],exist[b]);
        }

    }

}
