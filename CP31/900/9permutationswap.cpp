#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;

            ans = gcd(ans, abs(i - x));
        }

        cout << ans << '\n';
    }
}