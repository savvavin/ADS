#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ld c;
    cin >> c;
    ld l = 0;
    ld r = c;
    for (ll i = 0; i < 200; ++i) {
        ld mid = (r - l) / 2 + l;
        if (mid * mid + sqrt(mid) <= c) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout.precision(10);
    cout << l;

    return 0;
}
