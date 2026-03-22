#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int rem;
            if (k != 0)
                rem = sum % k;
            else
                rem = sum;

            if (mp.find(rem) != mp.end()) {
                if (i - mp[rem] >= 2)
                    return true;
            } else {
                mp[rem] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;

    cout << (obj.checkSubarraySum(nums, k) ? "True" : "False") << endl;

    return 0;
}