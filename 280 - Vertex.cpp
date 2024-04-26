#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;

const int N = 105;
vector<int> g[N];
bool visited[N];


void dfs(int vertex, int isConsidered) {
    if (isConsidered) visited[vertex] = 1;
    for (auto child : g[vertex]) {
        if (!visited[child]) dfs(child, 1);
    }
}

void print(vector<int> &ans) {
    int n = ans.size();
    if (n) cout << n << ' ';
    else cout << n << '\n';

    for (int i = 0; i < n; i++) {
        if (i == n - 1) cout << ans[i] << '\n';
        else cout << ans[i] << ' ';
    }
}

void solve()
{
    int n;
    while (cin >> n && n) {
        for (int i = 0; i <= n; i++) g[i].clear();
        int x;
        while (cin >> x && x) {
            int y;
            while (cin >> y && y) {
                g[x].push_back(y);
            }
        }
        int q; cin >> q;
        while (q--) {
            memset(visited, 0, sizeof visited);
            int v; cin >> v;
            dfs(v, 0);

            vector<int> ans;
            for (int i = 1; i <= n; i++) {
                if (!visited[i]) ans.push_back(i);
            }

            print(ans);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    //cin>>test;
    for (_ = 1; _ <= test; _++)
    {
        solve();
    }
    return 0;
}
