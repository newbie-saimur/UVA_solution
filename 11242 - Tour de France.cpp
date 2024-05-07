#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;

void solve()
{
	int rear_sprockets[10], front_sprockets[10], front, rear;
	double drive[100];
	while (cin >> front && front) {
		cin >> rear;
		for (int i = 0; i < front; i++) cin >> front_sprockets[i];
		for (int i = 0; i < rear; i++) cin >> rear_sprockets[i];

		int k = 0;
		for (int i = 0; i < front; i++) {
			for (int j = 0; j < rear; j++) {
				drive[k++] = (double)rear_sprockets[j] / (double)front_sprockets[i];
			}
		}

		sort(drive, drive + k);

		double mx = -1;
		for (int i = 0; i + 1 < k; i++) {
			mx = max(mx, drive[i + 1] / drive[i]);
		}
		cout << fixed << setprecision(2) << mx << '\n';
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
