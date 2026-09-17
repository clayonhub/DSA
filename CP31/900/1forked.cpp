#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> getPositions(int x, int y, int a, int b) {

    vector<pair<int,int>> moves = {
        {a, b},
        {a, -b},
        {-a, b},
        {-a, -b},
        {b, a},
        {b, -a},
        {-b, a},
        {-b, -a}
    };

    set<pair<int,int>> positions;

    for(auto [dx, dy] : moves) {
        positions.insert({x + dx, y + dy});
    }

    return positions;
}

int main() {

    int T;
    cin >> T;

    while(T--) {

        int a, b;
        cin >> a >> b;

        int xK, yK;
        cin >> xK >> yK;

        int xQ, yQ;
        cin >> xQ >> yQ;

        set<pair<int,int>> king = getPositions(xK, yK, a, b);
        set<pair<int,int>> queen = getPositions(xQ, yQ, a, b);

        int ans = 0;

        for(auto position : king) {
            if(queen.count(position))
                ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}