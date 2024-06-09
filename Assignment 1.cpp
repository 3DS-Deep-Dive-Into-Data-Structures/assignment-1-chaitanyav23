#include <bits/stdc++.h>
using namespace std;

long long x(int n, int a, int b, const vector<long long>& q) {
    vector<long long> p(n + 1, 0);
    for (long long i = 0; i < n; ++i) {
        p[i + 1] = p[i] + q[i];
    }
    
    // Here p is a vector array for Prefix sums to calculate the sum of any subarray [i, j]

    long long z = LLONG_MIN;
    // z is the maximum sum
    multiset<long long> y;
    // y is a multiset data structure used to keep track of prefix sums

    for (long long i = a; i <= n; ++i) {
        if (i > b) {
            auto it = y.find(p[i - b - 1]);
            y.erase(it);
        }
        y.insert(p[i - a]);
        z = max(z, p[i] - *y.begin());
    }
    // size of the y never exceeds b 

    return z;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> q(n);
    for (long long i = 0; i < n; ++i) {
        cin >> q[i];
    }

    cout << x(n, a, b, q) << endl;
    
// I have taken x as function for the Maximum sub array because the name is too long
// Here q is a vector array of size n
    
    return 0;
}

