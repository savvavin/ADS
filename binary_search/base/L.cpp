#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin>>n>>k;
    ll l=1, r=1e18;
    while(l<r){
        ll mid=(r-l)/2+l;
        ll a=0, b=mid;
        while(b>0){
            a+=b;
            b/=k;
        }
        if(a>=n){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<l;

    return 0;
}
