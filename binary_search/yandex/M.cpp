#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll w, h, n;

bool check(ll size) {
    ll cnt = (size / w) * (size / h);
    return cnt >= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w >> h >> n;
    ll l = 0;
    ll r = n * w;
    while (r - l > 1) {
        ll mid = (r - l) / 2 + l;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;

    return 0;
}
