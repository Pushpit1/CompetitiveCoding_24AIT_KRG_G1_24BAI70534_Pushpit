#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    int ones = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) ones++;
        a[i] = (a[i] == 0 ? 1 : -1);
    }

    int max_sum = INT_MIN, cur = 0;
    for (int x : a) {
        cur = max(x, cur + x);
        max_sum = max(max_sum, cur);
    }

    // Edge case: all 1s
    if (max_sum <= 0) {
        cout << ones - 1;
    } else {
        cout << ones + max_sum;
    }

    return 0;
}