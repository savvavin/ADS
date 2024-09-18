#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;
    cin>>n>>k;
    ll x=(n-k+1)/2;
    cout<<(x<k ? 0 : x-k);


    return 0;
}
