#include <bits/stdc++.h>
using namespace std;

// ✅ Approach 1: Iterative Counting of Digits
// TC: O(n * d), SC: O(1)
int findNumbers_Iterative(vector<int>& nums) {
    int count = 0;
    for (int num : nums) {
        int digits = 0;
        while (num > 0) {
            num /= 10;
            digits++;
        }
        if (digits % 2 == 0) count++;
    }
    return count;
}

// ✅ Approach 2: String Conversion to Count Digits
// TC: O(n * d) , SC: O(1)
int findNumbers_StringConv(vector<int>& nums) {
    int count = 0;
    for (int num : nums) {
        if (to_string(num).length() % 2 == 0)
            count++;
    }
    return count;
}

// ✅ Approach 3: Logarithmic Method
// TC: O(n) , SC: O(1)
int findNumbers_Log(vector<int>& nums) {
    int count = 0;
    for (int num : nums) {
        int digits = floor(log10(num)) + 1;
        if (digits % 2 == 0)
            count++;
    }
    return count;
}

// ✅ Approach 4: Range-Based Check (Optimized for known limits)
// TC: O(n) , SC: O(1)
int findNumbers_RangeBased(vector<int>& nums) {
    int count = 0;
    for (int num : nums) {
        if ((num >= 10 && num <= 99) ||  // 2 digits
            (num >= 1000 && num <= 9999) ||  // 4 digit
            (num == 100000)) { // 6 digit
            count++;
        }
    }
    return count;
}

// 🚀 Driver Code to Test All Approaches
int main() {
    vector<int> nums = {12, 345, 2, 6, 7896};

    cout << "Input: {12, 345, 2, 6, 7896}" << endl;

    cout << "Approach 1 (Iterative): " << findNumbers_Iterative(nums) << endl;
    cout << "Approach 2 (String Conversion): " << findNumbers_StringConv(nums) << endl;
    cout << "Approach 3 (Logarithmic): " << findNumbers_Log(nums) << endl;
    cout << "Approach 4 (Range-Based): " << findNumbers_RangeBased(nums) << endl;

    return 0;
}
