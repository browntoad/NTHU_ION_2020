#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
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
#define bug(x) cerr<<"Line "<<__LINE__<<": "<<#x<<" is "<<x<<endl;
#define IOS() 
#else
#define bug(...)
#define IOS() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#endif
const ll mod = 998244353;
const ll inf=1ll<<60;
const ll maxn=100000^1;
int n;
struct qq{
  int left, right, id;
  int ans1, ans2;
};
bool cmp(qq a, qq b){
  int tmp = sqrt(n);
  if (a.left/tmp==b.left/tmp){
    return a.right<b.right;
  }
  return a.left/tmp<b.left/tmp;
}
bool cmp12(qq a, qq b){
  return a.id<b.id;
}

signed main(){
    //ios_base::sync_with_stdio(0), cin.tie(0);
    int q=0;
    cin>>n>>q;
    //cout << sqrt(n) << endl;
    vector<int> vc(n), arra(n), arrb(n+1);
    REP(i,n) cin>>vc[i];
    vector<qq> vcqq(q);
    REP(i,q){
      cin>>vcqq[i].left>>vcqq[i].right;
      vcqq[i].left--;
      vcqq[i].right--;
      vcqq[i].id=i;
    }
    sort(ALL(vcqq), cmp);
    int L=0, R=-1;
    arrb[0]=n;
    int cura=0;
    REP(i,q){
      int l=vcqq[i].left, r=vcqq[i].right;
      
      while (R<r){
        R++;
        arra[vc[R]-1]++;
        arrb[ arra[vc[R]-1] ]++;
        arrb[ arra[vc[R]-1]-1 ]--;
        cura = max(cura, arra[vc[R]-1]);
      }
      while (L>l){
        L--;
        arra[vc[L]-1]++;
        arrb[ arra[vc[L]-1] ]++;
        arrb[ arra[vc[L]-1]-1 ]--;
        cura = max(cura, arra[vc[L]-1]);
      }
      while (L<l){

        arra[vc[L]-1]--;
        arrb[ arra[vc[L]-1] ]++;
        arrb[ arra[vc[L]-1]+1 ]--;
        if(arrb[cura] <= 0) cura--;
        L++;
      }
      while (R>r){
        arra[vc[R]-1]--;
        arrb[ arra[vc[R]-1] ]++;
        arrb[ arra[vc[R]-1]+1 ]--;
        if(arrb[cura] <= 0) cura--;
        R--;
      }
      vcqq[i].ans1=cura; vcqq[i].ans2=arrb[cura];
      //cout <<"qweqweqwe   "<< l << " " << r << " "  << cura << " "  << arrb[cura] << endl;

    }
    sort(ALL(vcqq), cmp12);
    REP(i,q){
      cout<<vcqq[i].ans1<<' '<<vcqq[i].ans2<<endl;
    }
}
