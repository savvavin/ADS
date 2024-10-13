#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<tuple<ll, ll, ll>> items(n);
    for (ll i = 0; i < n; ++i) {
        cin >> get<0>(items[i]) >> get<1>(items[i]);
        get<2>(items[i]) = i + 1;
    }
    ld l = (ld) 1 / (ld) 1e9;
    ld r = (ld) 1e9;
    vector<pair<ld, ll>> x(n);
    for (ll T = 0; T < 100; ++T) {
        ld mid = (r - l) / 2 + l;
        for (ll i = 0; i < n; ++i) {
            x[i] = {(ld) get<0>(items[i]) - (ld) mid * (ld) get<1>(items[i]), get<2>(items[i])};
        }
        sort(x.rbegin(), x.rend());
        ld sum = 0;
        for (ll i = 0; i < k; ++i) {
            sum += x[i].first;
        }
        if (sum >= 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    for (ll i = 0; i < k; ++i) {
        cout << x[i].second << " ";
    }

    return 0;
}
