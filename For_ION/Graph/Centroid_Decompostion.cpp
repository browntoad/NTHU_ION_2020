#include<bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define inf 0x3f3f3f3f
#define ll long long
#define endl '\n'
#define AC ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int n,x,y,tsize=0,mxdeep=0;
int sub_size[100005]={0},deep[100005]={0};
set<int> s[100005];
int get_size(int cur,int p)
{
    sub_size[cur]=1;
    for(auto i : s[cur])
        if(i!=p)    sub_size[cur]+=get_size(i,cur);
    return sub_size[cur];
}
int get_centroid(int cur,int p,int n)
{
    for(int i : s[cur])
        if(i != p && sub_size[i]> n/2)   return get_centroid(i,cur,n);
    return cur;
}
void CD(int cur,int p,int depth)
{
    int si=get_size(cur,p);
    int cen=get_centroid(cur,p,si);
    deep[cen]=depth;
    if(depth>mxdeep)    mxdeep=depth;
    for(int i : s[cen])
        if(i!=p)
        {
            s[i].erase(cen);
            CD(i,cen,depth+1);
        };
}
int main(void)
{
    AC
    cin>>n;
    for(int i=0 ; i<n-1 ; i++)
    {
        cin>>x>>y;
        s[x].insert(y);
        s[y].insert(x);
    }
    CD(1,-1,0);
    if(mxdeep>26)  cout<<"Impossible!"<<endl;
    else
        for(int i=1 ; i<=n ; i++)
            cout<<(char)(deep[i]+'A')<<' ';
}
