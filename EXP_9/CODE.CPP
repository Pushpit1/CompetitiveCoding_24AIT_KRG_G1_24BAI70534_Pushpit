#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int,int>> edges(n-1);
    vector<int> deg(n+1,0);

    for (int i=0;i<n-1;i++){
        cin >> edges[i].first >> edges[i].second;
        deg[edges[i].first]++;
        deg[edges[i].second]++;
    }

    int label = 0;
    vector<int> res(n-1);

    for (int i=0;i<n-1;i++) {
        if (deg[edges[i].first]==1 || deg[edges[i].second]==1)
            res[i] = label++;
    }

    for (int i=0;i<n-1;i++) {
        if (!(deg[edges[i].first]==1 || deg[edges[i].second]==1))
            res[i] = label++;
    }

    for (int x : res) cout << x << endl;
}