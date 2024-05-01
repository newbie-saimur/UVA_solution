#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _, test;
const int N = 30;
vector<int> g[N];
bool visited[N];

void dfs(int vertex) {
    visited[vertex] = 1;
    for (auto x : g[vertex]) {
        if (!visited[x]) dfs(x);
    }
}

void solve()
{
    for (int i = 0; i <= 26; i++) g[i].clear();
    memset(visited, 0, sizeof visited);
    string s;
    char temp; cin >> temp;
    cin.ignore();
    while (getline(cin, s) && s[0] != '\0') {
        g[s[0] - 'A'].push_back(s[1] - 'A');
        g[s[1] - 'A'].push_back(s[0] - 'A');
    }
    int cnt = 0;
    for (char i = 'A'; i <= temp; i++) {
        if (!visited[i - 'A']) {
            dfs(i - 'A');
            cnt++;
        }
    }
    cout << cnt << '\n';
    if (_ != test) cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    test = 1;
    cin >> test;
    for (_ = 1; _ <= test; _++)
    {
        solve();
    }
    return 0;
}
