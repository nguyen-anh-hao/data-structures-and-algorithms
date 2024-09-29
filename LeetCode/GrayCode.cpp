// https://leetcode.com/problems/gray-code/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int INF = INT_MAX;

public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int totalCodes = 1 << n;

        for (int i = 0; i < totalCodes; ++i)
            result.push_back(i ^ (i >> 1));

        return result;
    }
};

int main() {
    int n = 2;

    Solution solution;
    vector<int> result = solution.grayCode(n);

    for (auto item : result)
        cout << item << ' ';

    return 0;
}