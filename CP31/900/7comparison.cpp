#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int curr = 1;
        int maxi = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1])
                curr++;
            else
                curr = 1;

            maxi = max(maxi, curr);
        }

        cout << maxi + 1 << '\n';
    }
}