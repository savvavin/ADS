#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll l = 1;
    ll r = n;
    while (r - l > 1) {
        ll mid = (r - l) / 2 + l;
        cout << "? " << mid << "\n";
        cout.flush();
        ll x;
        cin >> x;
        if (x == 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << "! " << l << "\n";
    cout.flush();

    return 0;
}
