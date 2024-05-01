#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;

void solve()
{
    int n;
    while (cin >> n && n) {
        vector<int> g[n];
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int color[n] {0};
        bool visited[n] {0};
        queue<int> q;

        q.push(0);
        visited[0] = 1;
        color[0] = 1;
        bool flag = false;
        
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (auto child : g[x]) {
                if (!visited[child]) {
                    q.push(child);
                    visited[child] = 1;
                    if (color[x] == 1) color[child] = 2;
                    else color[child] = 1;
                }
                if (color[child] == color[x]) {
                    cout << "NOT BICOLORABLE.\n";
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) cout << "BICOLORABLE.\n";
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
