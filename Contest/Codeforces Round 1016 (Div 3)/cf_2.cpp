#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        double min_cost = 1e18;
        int min_removed = n - 1;

        // Go through all possible subsequences
        // Since n can be up to 100, limit to subsequences up to 18 digits (safe for stoll)
        int total = 1 << min(n, 18);
        for (int mask = 1; mask < total; ++mask) {
            string temp = "";
            int sum = 0;
            for (int i = 0; i < min(n, 18); ++i) {
                if (mask & (1 << i)) {
                    temp += s[i];
                    sum += s[i] - '0';
                }
            }

            if (sum == 0) continue;
            long long val = stoll(temp);
            double cost = (double)val / sum;
            int removed = n - temp.size();
            if (cost < min_cost) {
                min_cost = cost;
                min_removed = removed;
            } else if (abs(cost - min_cost) < 1e-9) {
                min_removed = min(min_removed, removed);
            }
        }

        // Also check full string
        long long full_val = stoll(s);
        int full_sum = accumulate(s.begin(), s.end(), 0, [](int acc, char c) {
            return acc + (c - '0');
        });
        if (full_sum > 0) {
            double full_cost = (double)full_val / full_sum;
            if (full_cost < min_cost || (abs(full_cost - min_cost) < 1e-9 && 0 < min_removed)) {
                min_cost = full_cost;
                min_removed = 0;
            }
        }

        cout << min_removed << '\n';
    }
    return 0;
}
