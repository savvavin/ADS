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
        if (mid % 2 == 1) {
            cout << "? " << mid << "\n";
            cout.flush();
            ll ai;
            cin >> ai;
            cout << "? " << mid + 1 << "\n";
            cout.flush();
            ll ai_1;
            cin >> ai_1;
            if (ai == ai_1) {
                l = mid + 2;
            } else {
                r = mid;
            }
        } else {
            cout << "? " << mid << "\n";
            cout.flush();
            ll ai;
            cin >> ai;
            cout << "? " << mid - 1 << "\n";
            cout.flush();
            ll ai_1;
            cin >> ai_1;
            if (ai == ai_1) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    cout << "? " << r << "\n";
    cout.flush();
    ll res;
    cin >> res;
    cout << "! " << res << "\n";
    cout.flush();

    return 0;
}
