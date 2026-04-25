#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int l = 0, sum = 0, ans = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum > t) sum -= a[l++];
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}