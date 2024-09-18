#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll m;
    cin >> m;
    vector<ll> zero;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            zero.push_back(i);
        }
    }
    for (int i = 0; i < m; ++i) {
        ll k;
        cin >> k;
        if (k <= zero.size()) {
            cout << zero[k - 1] + 1 << " ";
        } else {
            cout << -1 << " ";
        }
    }

    return 0;
}
