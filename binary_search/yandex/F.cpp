#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll n, x, y;

bool check(ll time) {
    return (time / x + time / y) >= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> y;
    ll l = 0;
    --n;
    ll r = x * n;
    while (r - l > 1) {
        ll mid = (r - l) / 2 + l;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r + min(x, y);

    return 0;
}
