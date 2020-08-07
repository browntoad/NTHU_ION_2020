#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast", "unroll-loops")
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int, int>
#define endl '\n'
//#define TOAD
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS() 
#else
#define bug(...)
#define IOS() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#endif
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 1e9+7;
const ll maxn=105;
ll pow(ll x, ll p){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
            ret%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return ret;
}
ll inv(ll x){
    return pow(x, mod-2);
}
bool cmp(int x, int y){
    return x>y;
}
int graph[maxn][maxn], seen[maxn];
int n, ans=0, s, t, c;
int dfs(int x, int mn){
    //cout << x << ' ' << mn << endl;
    int re = 0;
    if (x==t) return mn;
    seen[x]=1;
    REP1(i,n){
        if (!seen[i]&&graph[x][i]) {
            int tmp=dfs(i, min(mn, graph[x][i]));
            if (tmp>0) {
                graph[x][i]-=tmp;
                graph[i][x]+=tmp;
                re = tmp;
                break;
            }
        }
    }
    //seen[x]=0;
    return re;
}
signed main(){
    IOS();
    int n; cin>>n;
    REP(i,maxn){
        REP(j,maxn){
            graph[i][j]=0;
        }
    }
    cin>>s>>t>>c;
    REP1(i,c){
        int x,y,z; cin>>x>>y>>z;
        graph[x][y]+=z;
        graph[y][x]+=z;

    }
    ans = 0;
    while (1){
        REP1(i, n) seen[i]=0;
        int val=dfs(s, inf);
        if (val>0) ans+=val;
        else break;
    }
    //cout<<"The bandwidth is "<<ans<<'.'<<endl;

}
