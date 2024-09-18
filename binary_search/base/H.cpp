#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    ll l=1,r=1e9;
    while (l<r){
        ll m=(l+r)/2;
        ll x=0;
        for (int i=0;i<n;++i){
            x+=a[i]/m;
        }
        if (x>=k){
            l=m+1;
        }
        else{
            r=m;
        }
    }
    cout<<l-1;

    return 0;
}
