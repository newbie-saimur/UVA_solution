#include <bits/stdc++.h>
using namespace std;
#define int   long long
int _;

bool is_All_Diff(int n, int m) {
    string s = to_string(n);
    s += to_string(m);
    if (s.size() == 9) s.push_back('0');
    int a[10] = {0};
    for (int i = 0; i < 10; i++) {
        a[s[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (a[i] != 1) return false;
    }
    return true;
}

void solve()
{
    int n, k = 1;
    while (cin >> n && n) {
        if (k > 1) cout << '\n';
        bool flag = true;
        for (int i = 1234; i < 50000; i++) {
            int num = n * i;
            if (num > 99999) break;
            if (is_All_Diff(num, i)) {
                cout << n * i << " / " << setw(5) << setfill('0') << i << " = " << n << '\n';
                flag = false;
            }
        }
        if (flag) cout << "There are no solutions for " << n << ".\n";
        k++;
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
