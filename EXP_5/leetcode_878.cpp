#include <iostream>
using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long l = 1, r = (long long)n * min(a, b);
        long long mod = 1e9 + 7;

        long long lcm = (1LL * a * b) / gcd(a, b);

        while (l < r) {
            long long mid = l + (r - l) / 2;

            long long count = mid / a + mid / b - mid / lcm;

            if (count < n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l % mod;
    }
};

int main() {
    Solution obj;
    int n = 5, a = 2, b = 4;

    cout << obj.nthMagicalNumber(n, a, b) << endl;

    return 0;
}