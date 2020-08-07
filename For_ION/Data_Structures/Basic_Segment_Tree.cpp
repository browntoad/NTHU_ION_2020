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
const ll maxn=5e3+5;
ll pw(ll x, ll p){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return ret;
}

ll inv(ll a, ll b){
    return 1<a ? b - inv(b%a,a)*b/a : 1;
}
//================================================================================

//Range Minimum Query

vector<int> seg(4*maxn), vc(maxn);


void build(int l, int r, int x){
    if (l==r){
        seg[x]=vc[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid, x+x);
    build(mid+1, r, x+x+1);
    seg[x]=min(seg[x+x], seg[x+x+1]);
}
int QU(int l, int r, int nl, int nr, int x){
    if (nl>r||nr<l){
        return iinf;
    }
    if (nl>=l&&nr<=r){
        return seg[x];
    }
    int mid=(nl+nr)/2;
    return min(QU(l,r,nl, mid, x+x), QU(l, r, mid+1, nr, x+x+1));
}
void MO(int pos, int nl, int nr, int val, int x){
    if (nl==nr){
        seg[x]=val;
        return;
    }
    int mid=(nl+nr)/2;
    if (pos>=nl&&pos<=mid){
        MO(pos, nl, mid, val, x+x);
    }
    else {
        MO(pos, mid+1, nr, val, x+x+1);
    }
    seg[x]=max(seg[x+x], seg[x+x+1]);
}
signed main(){
    IOS();
    

}
