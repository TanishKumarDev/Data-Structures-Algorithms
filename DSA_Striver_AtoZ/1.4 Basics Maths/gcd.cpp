#include <bits/stdc++.h>
using namespace std;

int findGcd(int n1, int n2) {
    // for (int i = min(n1, n2); i > 0; i--) {
    //     if (n1 % i == 0 && n2 % i == 0) {
    //         return i;
    //     }
    // }

    if (n2 == 0) return n1;
    return findGcd(n2, n1 % n2);
}

int main()
{
    
    int n1, n2;
    cin >> n1 >> n2; // Input two numbers

    int gcd = findGcd(n1, n2); // Call the function to find GCD
    cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;

    // int gcd = __gcd(n1, n2);
    // cout << "GCD: " << gcd << endl;
    
    return 0;
}