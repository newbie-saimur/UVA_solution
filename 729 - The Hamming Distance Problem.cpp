#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;

void solve()
{
	int a, b; cin >> a >> b;
	string s((a - b), '0');
	s += string(b, '1');
	cout << s << '\n';
	while (next_permutation(s.begin(), s.end())) {
		cout << s << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int test = 1;
	cin >> test;
	for (_ = 1; _ <= test; _++)
	{
		solve();
		if (_ != test) cout << '\n';
	}
	return 0;
}
