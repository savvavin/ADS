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
    ll l=0;
    ll r=0;
    map<ll, ll> m;
    ll minn=1e6;
    ll maxx=0;
    ll res=0;
    ++m[a[l]];
    while(l<n && r<n){
        minn=min(minn, a[r]);
        maxx=max(maxx, a[r]);
        if(maxx-minn>1){
            if(a[r]==maxx){
                while(m[minn]>0){
                    --m[a[l]];
                    ++l;
                }
                ++minn;
            }else{
                while(m[maxx]>0){
                    --m[a[l]];
                    ++l;
                }
                --maxx;
            }
        }
        res=max(res, r-l+1);
        ++r;
        ++m[a[r]];
    }
    cout<<res;

    return 0;
}
