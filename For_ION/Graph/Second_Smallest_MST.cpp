#include<bits/stdc++.h>
#define pb push_back
#define inf 0x3f3f3f3f
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define AC ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
struct edge
{
    int u,v;
    ll w;
}e[500005];
int n,m,fa[1005],dep[1005],up[20][1005];
ll mn[20][1005];
ll ans=0,sec=0;
vector< pii > v[1005];
vector<edge> T;
bool cmp(edge a, edge b)
{
    return a.w<b.w;
}
int Find(int x)
{
    return x==fa[x] ? x : fa[x]=Find(fa[x]);
}
void Union(int a, int b, int w)
{
    v[a].pb({b,w});
    v[b].pb({a,w});
    ans+=w;
    a=Find(a);
    b=Find(b);
    fa[a]=b;
}
void dfs(int u, int p , int deep)
{
    up[0][u]=p;
    dep[u]=deep;
    for(auto i : v[u])
        if(i.first!=p )
            dfs(i.first,u,deep+1),mn[0][i.first]=i.second;
}
void init()
{
    for(int k=1 ; k < 12 ; k++)
        for(int i=1 ; i <= n ; i++)
        {
            up[k][i]=up[k-1][up[k-1][i]];
            mn[k][i]=max(mn[k-1][i], mn[k-1][up[k-1][i]]);
        }
}
int lca(int x, int y)
{
    ll maxpath=0;
    if(x==y)    return 0;
    if(dep[x]>dep[y])   swap(x,y);
    for(int i=11 ; i>=0 ; i--)
        if( up[i][y]!=0 && dep[up[i][y]]>= dep[x])
        {
            maxpath=max(maxpath,mn[i][y]);
            y=up[i][y];
        }
    if(y==x)    return maxpath;
    for(int i=11 ; i>=0 ; i--)
        if(up[i][x] != up[i][y] && up[i][x]!=0 && up[i][y]!=0 )
        {
            maxpath=max(maxpath, max(mn[i][x], mn[i][y]));
            x=up[i][x];
            y=up[i][y];
        }
    return max(maxpath,max(mn[0][x],mn[0][y]));
}
int main(void)
{
	AC
	cin>>n>>m;
	int gp=n;
	for(int i=0 ; i< 1000 ; i++)    fa[i]=i;
	for(int i=0 ; i<m ; i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e,e+m,cmp);
    for(int i=0 ; i<m ; i++)
        if(Find(e[i].u)!= Find(e[i].v) )
            Union(e[i].u, e[i].v, e[i].w),gp--;
        else
            T.pb(e[i]);
    if(gp!=1)
        cout<<-1<<" "<<-1<<endl;
    else if(T.empty())
        cout<<ans<<" "<<-1<<endl;
    else
    {
        dfs(1,0,0);
        init();
        for(auto i : T)
        {
            int maxpath=lca(i.u, i.v);
            if(sec==0 || sec>(ans-maxpath+i.w))
                sec=ans-maxpath+i.w;
        }
        cout<<ans<<" "<<sec<<endl;
    }
}