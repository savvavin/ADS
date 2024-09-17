#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, d;
    cin>>n>>d;
    vector<ll> x(n);
    for(int i=0; i<n; ++i){
        cin>>x[i];
    }
    ll res=0;
    ll l=0;
    ll r=0;
    while(l<n && r<n){
        while(r+1<n && x[r+1]-x[l]<=d){
            ++r;
        }
        ll num=r-l;
        if(num>=2){
            res+=num*(num-1)/2;
        }
        ++l;
    }
    cout<<res;

    return 0;
}
