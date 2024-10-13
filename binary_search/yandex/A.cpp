#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<ll> coords;
ll n, k;

bool check(ll dist) {
    ll cows = 1;
    ll last_cow = coords[0];
    for (auto c : coords) {
        if (c - last_cow >= dist) {
            ++cows;
            last_cow = c;
        }
    }
    return cows >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    coords.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> coords[i];
    }
    ll l = 0;
    ll r = 2e9;
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
