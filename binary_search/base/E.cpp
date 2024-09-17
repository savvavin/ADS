#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool check(vector<vector<ll>>& a, ll n, ll k, ll x){
    vector<vector<ll>> p(n+1, vector<ll>(n+1));
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1];
            if(a[i-1][j-1]<=x){
                ++p[i][j];
            }
        }
    }
    for(int i=k; i<=n; ++i){
        for(int j=k; j<=n; ++j){
            ll res=p[i][j]-p[i-k][j]-p[i][j-k]+p[i-k][j-k];
            if(res>=(k*k+1)/2){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin>>n>>k;
    vector<vector<ll>> a(n, vector<ll>(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin>>a[i][j];
        }
    }
    ll l=0;
    ll r=1e9;
    ll res=r;
    while(l<=r){
        ll mid=(r-l)/2+l;
        if(check(a, n, k, mid)){
            res=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<res;

    return 0;
}
