#include <bits/stdc++.h>
using namespace std;

bool canMakeKSegments(const vector<int>& a, int x, int k) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int num : a) {
        freq[num]++;
        if (freq.size() == x) {
            count++;
            freq.clear();  // start new segment
        }
    }
    return count >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        int low = 0, high = n, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canMakeKSegments(a, mid, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
