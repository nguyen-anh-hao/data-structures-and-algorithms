// https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int INF = INT_MAX;

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;

        int i, j, k;
        i = j = k = 0;

        while (i < m || j < n) {
            int nums1_i = INF;
            int nums2_j = INF;

            if (i < m)
                nums1_i = nums1[i];
            if (j < n)
                nums2_j = nums2[j];

            if (nums1_i < nums2_j) {
                result.push_back(nums1_i);
                i++;
            } else {
                result.push_back(nums2_j);
                j++;
            }
        }

        nums1 = result;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;

    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    Solution solution;
    solution.merge(nums1, m, nums2, n);

    for (auto item : nums1)
        cout << item << ' ';

    return 0;
}