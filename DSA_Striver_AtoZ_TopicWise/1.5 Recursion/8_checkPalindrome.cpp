#include <bits/stdc++.h>
using namespace std;

// 🔸 Utility to print results
void printResult(string label, bool res) {
    cout << label << ": " << (res ? "Palindrome" : "Not Palindrome") << endl;
}

// 1️⃣ Brute Force
bool isPalindromeBrute(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

// 2️⃣ Better: Two-pointer (no cleaning)
bool isPalindromeBetter(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

// 3️⃣ Optimal: Two-pointer + cleaning
bool isPalindromeOptimal(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        while (l < r && !isalnum(s[l])) l++;
        while (l < r && !isalnum(s[r])) r--;
        if (tolower(s[l]) != tolower(s[r])) return false;
        l++; r--;
    }
    return true;
}

// 4️⃣ Recursive (clean input)
bool isPalindromeRecursive(int i, string &s) {
    if (i >= s.length() / 2) return true;
    if (s[i] != s[s.length() - i - 1]) return false;
    return isPalindromeRecursive(i + 1, s);
}

int main() {
    string s;
    // cout << "Enter a string: ";
    getline(cin, s); // Use getline to allow spaces in input

    // cout << "\n=== Palindrome Check Results ===\n";
    printResult("Brute Force", isPalindromeBrute(s));
    printResult("Better", isPalindromeBetter(s));
    printResult("Optimal (cleaned)", isPalindromeOptimal(s));
    printResult("Recursive", isPalindromeRecursive(0, s));
    
    return 0;
}
