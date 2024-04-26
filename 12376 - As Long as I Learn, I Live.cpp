#include <bits/stdc++.h>
using namespace std;
#define int      long long

const int N = 105;
vector<int> g[N];
int val[N], ans, _, node;


void dfs(int vertex) {
    int max_child, max_val = INT_MIN;
    for (auto child : g[vertex]) {
        if (val[child] > max_val) {
            max_val = val[child];
            max_child = child;
        }
    }
    if (g[vertex].size()) {
        ans += max_val;
        node = max_child;
        dfs(max_child);
    }
}

void solve()
{
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        g[i].clear();
    }
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
    }
    ans = 0;
    dfs(0);
    cout << "Case " << _ << ": " << ans << " " << node << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    cin >> test;
    for (_ = 1; _ <= test; _++)
    {
        solve();
    }
    return 0;
}
