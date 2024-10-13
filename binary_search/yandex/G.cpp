#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll n, k;
vector<ll> v;

bool check(ll len) {
    ll cnt = 0;
    for (ll i = 0; i < n; ++i) {
        cnt += v[i] / len;
    }
    return cnt >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    v.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ll l = 0;
    ll r = 2e8;
    while (r - l > 1) {
        ll mid = (r - l) / 2 + l;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l;

    return 0;
}
