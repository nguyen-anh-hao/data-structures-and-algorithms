// https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<char, int> romanToIntMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

public:
    int romanToInt(string s) {
        int result = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && romanToIntMap[s[i]] < romanToIntMap[s[i + 1]]) {
                result += romanToIntMap[s[i + 1]] - romanToIntMap[s[i]];
                i++;
            } else {
                result += romanToIntMap[s[i]];
            }
        }

        return result;
    }
};

int main() {
    string s = "III";

    Solution solution;
    int result = solution.romanToInt(s);

    cout << result;

    return 0;
}