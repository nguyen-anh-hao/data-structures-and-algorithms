// https://leetcode.com/problems/search-insert-position/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int result = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    Solution solution;
    int result = solution.searchInsert(nums, target);

    cout << result;

    return 0;
}