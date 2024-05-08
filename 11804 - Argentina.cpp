#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;

bool sorta(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return (a.second < b.second);
    else return (a.first > b.first);
}

void solve()
{
    vector<pair<string, pair<int, int>>> mp;
    vector<pair<int, int>> pr;
    for (int i = 0; i < 10; i++) {
        string s; cin >> s;
        int x, y; cin >> x >> y;
        mp.push_back({s, {x, y}});
        pr.push_back({x, y});
    }
    bool visited[10] {0};
    sort(pr.begin(), pr.end(), sorta);
    sort(mp.begin(), mp.end());
    vector<string> v, v1;
    for (int i = 0; i < 10; i++) {
        auto &[x, y] = pr[i];
        if (i < 5) {
            for (int j = 0; j < mp.size(); j++) {
                auto &[p, q] = mp[j].second;
                if (p == x && q == y) {
                    v.push_back(mp[j].first);
                    mp.erase(mp.begin() + j);
                    break;
                }
            }
        }
        else {
            for (int j = 0; j < mp.size(); j++) {
                auto &[p, q] = mp[j].second;
                if (p == x && q == y) {
                    v1.push_back(mp[j].first);
                    mp.erase(mp.begin() + j);
                    break;
                }
            }
        }
    }
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    cout << "(" << v[0];
    for (int i = 1; i < 5; i++) cout << ", " << v[i];
    cout << ")\n";
    cout << "(" << v1[0];
    for (int i = 1; i < 5; i++) cout << ", " << v1[i];
    cout << ")\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    cin >> test;
    for (_ = 1; _ <= test; _++)
    {
        cout << "Case " << _ << ":\n";
        solve();
    }
    return 0;
}
