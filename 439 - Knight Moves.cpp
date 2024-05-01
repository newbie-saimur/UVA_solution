#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;

bool visited[8][8];

vector<pair<int, int>> moves = {
    {1, 2}, {1, -2}, { -1, -2}, { -1, 2}, {2, 1}, {2, -1}, { -2, 1}, { -2, -1}
};

pair<int, int> get(string s) {
    return {s[0] - 'a', s[1] - '1'};
}

bool isValid(int i, int j) {
    return i >= 0 and j >= 0 and i < 8 and j < 8 and !visited[i][j];
}

map<pair<int, int>, int> level;

void solve()
{
    string s1, s2;
    while (cin >> s1 >> s2) {
        if (s1 == s2) {
            cout << "To get from " << s1 << " to " << s2 << " takes " << 0 << " knight moves.\n";
            continue;
        }
        auto [source_x, source_y] = get(s1);
        auto [dest_x, dest_y] = get(s2);
        memset(visited, 0, sizeof visited);
        queue<pair<int, int>> q;
        q.emplace(source_x, source_y);
        visited[source_x][source_y] = 1;
        level[ {source_x, source_y}] = 0;
        while (q.size()) {
            auto &[x, y] = q.front();
            q.pop();
            bool flag = false;
            for (auto &[a, b] : moves) {
                int child_x = a + x;
                int child_y = b + y;
                if (isValid(child_x, child_y)) {
                    level[ {child_x, child_y}] = level[ {x, y}] + 1;
                    q.emplace(child_x, child_y);
                    visited[child_x][child_y] = 1;
                }
            }
            if (flag) break;
        }
        cout << "To get from " << s1 << " to " << s2 << " takes " << level[ {dest_x, dest_y}] << " knight moves.\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    // cin >> test;
    for (_ = 1; _ <= test; _++)
    {
        solve();
    }
    return 0;
}
