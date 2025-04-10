#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        if (k == 0) {
            cout << 1 << '\n';
            continue;
        }

        int ans = n + 1;

        // Try all subarrays of length up to 130
        for (int i = 0; i < n; ++i) {
            int maxXor = 0;
            for (int j = i; j < min(n, i + 130); ++j) {
                for (int m = i; m <= j; ++m) {
                    for (int l = m; l <= j; ++l) {
                        maxXor = max(maxXor, a[m] ^ a[l]);
                    }
                }
                if (maxXor >= k) {
                    ans = min(ans, j - i + 1);
                    break;  // No need to check longer ones from same i
                }
            }
        }

        cout << (ans == n + 1 ? -1 : ans) << '\n';
    }

    return 0;
}
