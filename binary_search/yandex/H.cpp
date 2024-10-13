#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll n, a, b, w, h;

bool check(ll d) {
    ll cnt = max((w / (a + 2 * d)) * (h / (b + 2 * d)), (h / (a + 2 * d)) * (w / (b + 2 * d)));
    return cnt >= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> a >> b >> w >> h;
    ll l = 0;
    ll r = min(w, h);
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
