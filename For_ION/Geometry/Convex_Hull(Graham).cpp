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
#define pdd pair<double ,double>
#define endl '\n'
//#define TOAD
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS()
#else
#define bug(...)
#define IOS() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#endif
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 1e9+7;
const ll maxn=1e5+5;
ll pw(ll x, ll p){
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
    return pw(x, mod-2);
}

bool cmp(pii x, pii y){
    if (x.f!=y.f) return x.f<y.f;
    return x.s<y.s;
}
pii subtract(pii x, pii y){
    return {x.f-y.f, x.s-y.s};
}
int cross(pii x, pii y){
    return x.f*y.s-x.s*y.f;
}
vector<pii> ConvexHull(vector<pii> vc, int n){
    vector<pii> tubao, res;
    sort(ALL(vc), cmp);
    REP(i,n){
        while (SZ(tubao)>=2&&cross(subtract(tubao[SZ(tubao)-2], tubao[SZ(tubao)-1]), subtract(vc[i], tubao[SZ(tubao)-1]))>=0){
            tubao.pop_back();
        }
        tubao.pb(vc[i]);
    }
    tubao.pop_back();
    REP(i,SZ(tubao)) res.pb(tubao[i]);
    tubao.clear();
    reverse(ALL(vc));

    REP(i,n){
        while (SZ(tubao)>=2&&cross(subtract(tubao[SZ(tubao)-2], tubao[SZ(tubao)-1]), subtract(vc[i], tubao[SZ(tubao)-1]))>=0){
            tubao.pop_back();
        }
        tubao.pb(vc[i]);
    }
    tubao.pop_back();
    REP(i,SZ(tubao)) res.pb(tubao[i]);
    return res;
}
signed main(){
    IOS();
    int n; cin>>n;
    vector<pii> vc(n);
    REP(i,n) cin>>vc[i].f>>vc[i].s;
    vector<pii> convexhull=ConvexHull(vc, n);
    /*REP(i,SZ(convexhull)){
        cout<<convexhull[i].f<<' '<<convexhull[i].s<<endl;
    }
    */
}
