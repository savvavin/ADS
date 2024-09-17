#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<ll> a(n);
        for(int i=0; i<n; ++i){
            cin>>a[i];
        }
        vector<ll> b(n);
        for(int i=0; i<n-1; ++i){
            if(a[i]<2*a[i+1]){
                b[i]=1;
            }
        }
        ll res=0;
        ll num=0;
        for(int i=0; i<k; ++i){
            num+=b[i];
        }
        if(num==k){
            ++res;
        }
        for(int i=k; i<n-1; ++i){
            num-=b[i-k];
            num+=b[i];
            if(num==k){
                ++res;
            }
        }
        cout<<res<<"\n";
    }

    return 0;
}
