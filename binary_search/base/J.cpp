#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin>>n>>m;
    ll t;
    cin>>t;
    ll l=0, r=min(n/2,m/2)+1;
    while(r-l>1){
        ll mid=(r-l)/2+l;
        if(n*m-(n-2*mid)*(m-2*mid)<=t){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<<l;

    return 0;
}
