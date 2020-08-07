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
    int b,val;
    edge(int x,int y):
        b(x),val(y){}
};

struct CMP{
    bool operator()(edge x,edge y){
        return x.val>y.val;
    }
};

int m,n;
priority_queue< edge, vector<edge> , CMP > pq;
vector<edge> vc[maxn];
int dis[maxn];

void dijkstra(int x,int T){
    memset(dis,INF,sizeof(dis));
    dis[x]=0;
    pq.push(edge(x,dis[x]));
    while(!pq.empty()){
        edge p=pq.top();
        pq.pop();
        if(p.val>dis[p.b]) continue;
        for(int i=0;i<vc[p.b].size();i++){
            edge now=vc[p.b][i];
            if(dis[now.b]>p.val+now.val){
                dis[now.b]=p.val+now.val;
                pq.push(edge(now.b,dis[now.b]));
            }
        }
    }
}

int main(){
    AC;
    int a,b,i,T,val;
    while(cin>>m>>n && m){
        for(i=0;i<m;i++){
            cin>>a>>b>>val;
            vc[a].pb(edge(b,val));
            vc[b].pb(edge(a,val));
        }
        dijkstra(n,n);
        cout<<dis[1]<<"\n";
    }
}
