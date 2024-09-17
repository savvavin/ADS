#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    vector<ll> b(n);
    for(int i=0; i<n; ++i){
        cin>>b[i];
    }
    vector<ll> c(n);
    for(int i=0; i<n; ++i){
        c[i]=a[i]-b[i];
    }
    sort(c.begin(), c.end());
    ll res=0;
    for(int i=0; i<n; ++i){
        if(c[i]>0){
            ll j= lower_bound(c.begin(), c.end(), -c[i]+1)-c.begin();
            res+=i-j;
        }
    }
    cout<<res;

    return 0;
}
