#include <bits/stdc++.h>
using namespace std;

// Function to print array
void printArray(vector<int> &arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// Approach 1: Brute Force (Using an Extra Array)
vector<int> reverseArrayBrute(vector<int> &arr) {
    int n = arr.size();
    vector<int> rev(n);
    for (int i = n - 1; i >= 0; i--) {
        rev[n - i - 1] = arr[i];
    }
    return rev;
}

// Approach 2: In-place Iterative Method
void reverseArrayInPlace(vector<int> &arr) {
    int p1 = 0, p2 = arr.size() - 1;
    while (p1 < p2) {
        swap(arr[p1], arr[p2]);
        p1++; p2--;
    }
}

// Approach 3: Recursive Method
void reverseArrayRecursive(vector<int> &arr, int start, int end) {
    if (start < end) {
        swap(arr[start], arr[end]);
        reverseArrayRecursive(arr, start + 1, end - 1);
    }
}

// Approach 4: Using STL Reverse Function
void reverseArraySTL(vector<int> &arr) {
    reverse(arr.begin(), arr.end());
}

int main() {
    int n;
    // cout << "Enter size of array: ";
    cin >> n;
    
    vector<int> arr(n);
    // cout << "Enter array elements: ";
    for (int &x : arr) cin >> x;

    // Brute Force Approach
    vector<int> resultBrute = reverseArrayBrute(arr);
    cout << " (Brute Force): ";
    printArray(resultBrute);

    // In-place Iterative Approach
    vector<int> arrInPlace = arr;  // Copy the original array to use in the in-place approach
    reverseArrayInPlace(arrInPlace);
    cout << " (In-place Iterative): ";
    printArray(arrInPlace);

    // Recursive Approach
    vector<int> arrRecursive = arr;  // Copy the original array for recursive approach
    reverseArrayRecursive(arrRecursive, 0, arrRecursive.size() - 1);
    cout << " (Recursive): ";
    printArray(arrRecursive);

    // STL Reverse Approach
    vector<int> arrSTL = arr;  // Copy the original array for STL approach
    reverseArraySTL(arrSTL);
    cout << " (STL): ";
    printArray(arrSTL);

    return 0;
}
