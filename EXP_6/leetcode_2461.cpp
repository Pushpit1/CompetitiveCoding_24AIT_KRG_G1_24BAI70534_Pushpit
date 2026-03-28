#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> elements;
        long long current_sum = 0;
        long long max_sum = 0;
        int begin = 0;

        for (int end = 0; end < n; end++) {

            while (elements.find(nums[end]) != elements.end()) {
                current_sum -= nums[begin];
                elements.erase(nums[begin]);
                begin++;
            }

            current_sum += nums[end];
            elements.insert(nums[end]);

            if (end - begin + 1 == k) {
                max_sum = max(max_sum, current_sum);
                current_sum -= nums[begin];
                elements.erase(nums[begin]);
                begin++;
            }
        }

        return max_sum;
    }
};