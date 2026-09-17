#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        int ans = 1;

        while (n % ans == 0)
            ans++;

        cout << ans - 1 << '\n';
    }
}