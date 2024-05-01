#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;
map<int, vector<int>> mp;
map<int, int> level;

void solve()
{
    int n;
    while (cin >> n && n) {
        mp.clear();
        set<int> st;
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            mp[x].push_back(y);
            mp[y].push_back(x);
            st.insert(x);
            st.insert(y);
        }
        int x, y;
        while (cin >> x >> y && (x || y)) {
            level.clear();
            for (auto it : st) level[it] = 1e9;
            queue<int> q;
            q.push(x);
            level[x] = 0;
            while (q.size()) {
                auto vertex = q.front();
                q.pop();
                for (auto child : mp[vertex]) {
                    if (level[vertex] + 1 < level[child]) {
                        q.push(child);
                        level[child] = level[vertex] + 1;
                    }
                }
            }
            int cnt = 0;
            for (auto it : st) if (level[it] > y) cnt++;
            cout << "Case " << _ << ": " << cnt << " nodes not reachable from node " << x << " with TTL = " << y << "." << '\n';
            _++;
        }
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
