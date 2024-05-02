#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int _;
const int N = 5;
bool visited[N][N];
int a[N][N];
vector<pair<int, int> > moves;

bool isValid(int i, int j) {
    return i >= 0 && j >= 0 && i < N && j < N && !visited[i][j] && a[i][j] == 0;
}

void solve()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    queue<pair<int, int> > q;
    map<pair<int, int>, pair<int, int> > mp;
    q.push(make_pair(0, 0));
    visited[0][0] = 1;
    while (!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
        for (int k = 0; k < (int)(moves.size()); k++) {
            int c = moves[k].first;
            int d = moves[k].second;
            if (isValid(x + c, y + d)) {
                q.push(make_pair(x + c, y + d));
                visited[x + c][y + d] = 1;
                mp[make_pair(x + c, y + d)] = make_pair(x, y);
            }
        }
    }
    vector<pair<int, int> > v;
    v.push_back(make_pair(4, 4));
    int c = 4, d = 4;
    while (true) {
        pair<int, int> temp = mp[make_pair(c, d)];
        int x = temp.first;
        int y = temp.second;
        v.push_back(make_pair(x, y));
        c = x;
        d = y;
        if (x == 0 && y == 0) break;
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << "(" << v[i].first << ", " << v[i].second << ")" << '\n';
    }
}

int main() {
    moves.push_back(make_pair(0, 1));
    moves.push_back(make_pair(0, -1));
    moves.push_back(make_pair(-1, 0));
    moves.push_back(make_pair(1, 0));

    int test = 1;
    // cin >> test;
    for (_ = 1; _ <= test; _++)
    {
        solve();
    }
    return 0;
}
