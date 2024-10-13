#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll n, m, len;
vector<vector<ll>> a;
vector<vector<ll>> b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> len;
    a.resize(n, vector<ll>(len));
    b.resize(m, vector<ll>(len));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < len; ++j) {
            cin >> a[i][j];
        }
    }
    for (ll i = 0; i < m; ++i) {
        for (ll j = 0; j < len; ++j) {
            cin >> b[i][j];
        }
    }
    ll q;
    cin >> q;
    while (q--) {
        ll i, j;
        cin >> i >> j;
        --i;
        --j;
        vector<ll> cur_a = a[i];
        vector<ll> cur_b = b[j];
        ll l1 = 0;
        ll r1 = len;
        while (r1 - l1 > 1) {
            ll mid = (r1 - l1) / 2 + l1;
            if (cur_a[mid] <= cur_b[mid]) {
                l1 = mid;
            } else {
                r1 = mid;
            }
        }
        ll l2 = -1;
        ll r2 = len-1;
        while (r2 - l2 > 1) {
            ll mid = (r2 - l2) / 2 + l2;
            if (cur_a[mid] < cur_b[mid]) {
                l2 = mid;
            } else {
                r2 = mid;
            }
        }
        if (max(cur_a[l1], cur_b[l1]) < max(cur_a[r2], cur_b[r2])) {
            cout << l1 + 1 << "\n";
        } else {
            cout << r2 + 1 << "\n";
        }
    }

    return 0;
}
