#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Sorting - TC: O(n log n) and SC: O(1)
int secondLargest_brute(vector<int>& arr) {
    int n = arr.size();
    
    // Sort the array in non-decreasing order
    sort(arr.begin(), arr.end());

    // Start from second last element as the last element is the largest
    for (int i = n - 2; i >= 0; i--) {
        // Return the first element which is not equal to the largest element
        if (arr[i] != arr[n - 1]) {
            return arr[i];
        }
    }

    // If no second largest element was found, return -1
    return -1;
}

// Approach 2: Using Two Traversals -  TC: O(n) and SC: O(1)
int secondLargest_twoTraversals(vector<int>& arr) {
    int n = arr.size();

    int largest = -1, secondLargest = -1;

    // Finding the largest element in the first traversal
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest)
            largest = arr[i];
    }

    // Finding the second largest element in the second traversal
    for (int i = 0; i < n; i++) {
        // Update second largest if the current element is greater than second largest and not equal to largest
        if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

// Approach 3: Using One Traversal -  TC: O(n) and SC: O(1)
int secondLargest_oneTraversal(vector<int>& arr) {
    int n = arr.size();

    int largest = -1, secondLargest = -1;

    // Finding the second largest element in one traversal
    for (int i = 0; i < n; i++) {
        // If arr[i] > largest, update second largest with largest and largest with arr[i]
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } 
        // If arr[i] < largest and arr[i] > second largest, update second largest with arr[i]
        else if (arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main() {
    int n;
    
    // Taking input for the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    // Taking input for the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Approach 1: Using Sorting
    cout << "Second largest by Sorting (secondLargest_brute): " << secondLargest_brute(arr) << endl;

    // Approach 2: Using Two Traversals
    cout << "Second largest by Two Traversals (secondLargest_twoTraversals): " << secondLargest_twoTraversals(arr) << endl;

    // Approach 3: Using One Traversal
    cout << "Second largest by One Traversal (secondLargest_oneTraversal): " << secondLargest_oneTraversal(arr) << endl;

    return 0;
}
