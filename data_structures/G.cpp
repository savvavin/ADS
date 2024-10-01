#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    set<ll> fr;
    set<ll> fc;
    vector<ll> r(n + 1);
    vector<ll> c(n + 1);
    for (ll i = 1; i <= n; ++i) {
        fr.insert(i);
        fc.insert(i);
    }
    for (ll i = 0; i < q; ++i) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll x, y;
            cin >> x >> y;
            fr.erase(x);
            fc.erase(y);
            ++r[x];
            ++c[y];
        } else if (t == 2) {
            ll x, y;
            cin >> x >> y;
            --r[x];
            --c[y];
            if (r[x] == 0) {
                fr.insert(x);
            }
            if (c[y] == 0) {
                fc.insert(y);
            }
        } else {
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            auto a = fr.lower_bound(x1);
            auto b = fc.lower_bound(y1);
            if (a == fr.end() || (*a) > x2) {
                cout << "Yes\n";
            } else if (b == fc.end() || (*b) > y2) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}
