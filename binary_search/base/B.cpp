#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool check(vector<ll>& a, ll k, ll x, ll y){
    ll extra=0;
    for(int i=0; i<a.size(); ++i){
        ll need=a[i]-k*y;
        if(need>0){
            extra+=(need+x-y-1)/(x-y);
        }
    }
    return extra<=k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x, y;
    cin>>n>>x>>y;
    vector<ll> a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    ll l=0;
    ll r=1e9;
    while(r-l>1){
        ll mid=(r-l)/2+l;
        if(check(a, mid, x, y)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r;

    return 0;
}
