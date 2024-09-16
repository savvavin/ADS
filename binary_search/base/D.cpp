#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool check(ll n, ll m, ll x, ll k){
    ll lcm_nm=(n*m)/__gcd(n, m);
    ll s=0;
    s+=x/n-x/lcm_nm;
    s+=x/m-x/lcm_nm;
    return s>=k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin>>n>>m>>k;
    ll l=0;
    ll r=9e18;
    while(r-l>1){
        ll mid=(r-l)/2+l;
        if(check(n, m, mid, k)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r;

    return 0;
}
