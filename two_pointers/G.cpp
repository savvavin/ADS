#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    vector<ll> cnt(2e6);
    ll l=-1;
    ll r=-1;
    ll cur=0;
    ll s=0;
    for(int i=0; i<n; ++i){
        while(s<n){
            ++cnt[a[s]];
            if(cnt[a[s]]==1){
                ++cur;
            }
            if(cur>k){
                --cnt[a[s]];
                if(cnt[a[s]]==0){
                    --cur;
                }
                break;
            }
            ++s;
        }
        if(r-l<s-i){
            l=i;
            r=s;
        }
        --cnt[a[i]];
        if(cnt[a[i]]==0){
            --cur;
        }
    }
    cout<<l+1<<" "<<r;

    return 0;
}
