#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    vector<ll> a(n+2);
    for(int i=1; i<=n; ++i){
        cin>>a[i];
    }
    vector<ll> l(n+2);
    for(int i=1; i<=n; ++i){
        if(a[i-1]<a[i]){
            l[i]=l[i-1]+1;
        }else{
            l[i]=1;
        }
    }
    vector<ll> r(n+2);
    for(int i=n; i>=1; --i){
        if(a[i]<a[i+1]){
            r[i]=r[i+1]+1;
        }else{
            r[i]=1;
        }
    }
    ll res=0;
    for(int i=1; i<=n; ++i){
        if(a[i-1]+1<a[i+1]){
            res=max(res, l[i-1]+1+r[i+1]);
        }else{
            res=max(res, max(l[i-1], r[i+1])+1);
        }
    }
    cout<<res;

    return 0;
}
