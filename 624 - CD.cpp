#include <bits/stdc++.h>
using namespace std;
int _;

vector<vector<int>> best;
vector<int> a(21), val;
int n, k, INF = 1e9;

void calculate_sum(int index, int sum, vector<int> &v) {
	if (sum <= n) {
		best.push_back(v);
		val.push_back(sum);
	}
	if (index == k) return;
	v.push_back(a[index]);
	sum += a[index];
	calculate_sum(index + 1, sum, v);
	v.pop_back();
	sum -= a[index];
	calculate_sum(index + 1, sum, v);
}

void solve()
{
	while (cin >> n) {
		cin >> k;
		a.resize(k);
		val.clear();
		best.clear();
		for (int i = 0; i < k; i++) cin >> a[i];
		vector<int> v;
		calculate_sum(0, 0, v);
		int mx = -INF, pos = -1;
		for (int i = 0; i < val.size(); i++) {
			if (val[i] > mx) {
				mx = val[i];
				pos = i;
			}
		}
		for (auto x : best[pos]) {
			cout << x << ' ';
		}
		cout << "sum:" << mx << '\n';
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
