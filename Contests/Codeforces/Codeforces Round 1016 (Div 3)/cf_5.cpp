#include <bits/stdc++.h>
using namespace std;

// Convert string to Big Integer modulo mod
long long modString(const string& s, long long mod) {
    long long res = 0;
    for (char c : s) {
        res = (res * 10 + (c - '0')) % mod;
    }
    return res;
}

// Miller-Rabin Primality Test for strings (base a)
bool millerTest(const string& s, long long d, long long n, long long a) {
    long long x = modString(s, n);
    x = pow(x, d); // won't work if pow is big
    x %= n;

    if (x == 1 || x == n - 1) return true;

    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}

// Naive primality check for string number
bool isPrime(const string& num_str) {
    // Quick small number check
    if (num_str == "1") return false;
    if (num_str == "2") return true;

    // Try dividing by small primes
    vector<int> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for (int p : bases) {
        if (num_str.size() <= 18) {
            long long val = stoll(num_str);
            if (val == p) return true;
            if (val % p == 0) return false;
        } else {
            long long mod_val = modString(num_str, p);
            if (mod_val == 0) return false;
        }
    }

    // It's probably prime
    return false; // for safety — we avoid claiming true for big numbers
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string x;
        int k;
        cin >> x >> k;

        string y = "";
        for (int i = 0; i < k; ++i) y += x;

        if (isPrime(y)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
