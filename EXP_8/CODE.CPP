#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int ans = 0;
    for (int i = 1; i < n-1; i++) {
        if (a[i-1]==1 && a[i]==0 && a[i+1]==1) {
            ans++;
            a[i+1] = 0;
        }
    }
    cout << ans;
}