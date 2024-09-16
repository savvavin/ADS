#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool check(vector<ll>& a, ll k, ll m){
    ll rev=0;
    ll ub=0;
    for(int i=0; i<a.size(); ++i){
        if(a[i]<=rev){
            ++rev;
        }else if(ub<k){
            ++ub;
            ++rev;
        }
    }
    return rev>=m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    ll l=-1;
    ll r=n;
    while(r-l>1){
        ll mid=(r-l)/2+l;
        if(check(a, mid, m)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r;

    return 0;
}
