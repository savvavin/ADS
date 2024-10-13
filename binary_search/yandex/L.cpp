#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll a, b, c, d;

ll check(ll pt) {
    ll x = pt * b * d;
    if (x > LLONG_MAX / pt) {
        x = LLONG_MAX / 2;
    } else {
        x = x * (pt - 1) / 2;
    }
    return pt * a - x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        if (a > b * c) {
            cout << -1 << "\n";
            continue;
        }
        if (check(1) == check(1e6)) {
            cout << check(1) << "\n";
            continue;
        }
        ll res = 0;
        ll l = 1;
        ll r = 1e6;
        while (r - l > 2) {
            ll mid1 = l + (r - l) / 3;
            ll mid2 = l + 2 * (r - l) / 3;
            ll q = check(l);
            ll w = check(mid1);
            ll e = check(mid2);
            ll y = check(r);
            res = max({res, q, w, e, y});
            if (q < y) {
                if (w < y) {
                    l = mid1 + 1;
                } else {
                    r = mid2 - 1;
                }
            } else {
                if (q > e) {
                    r = mid2 - 1;
                } else {
                    l = mid1 + 1;
                }
            }
        }
        for (ll i = l; i <= r; ++i) {
            res = max({res, check(i)});
        }
        cout << res << "\n";
    }

    return 0;
}
