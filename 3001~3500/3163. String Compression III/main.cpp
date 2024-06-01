/**
 * Source: t.ly/VlCIw
 * Date: 2024/5/27
 * Skill:
 * Ref:
 * Runtime: 77 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 28.39 MB, less than 80.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;

#define ll long long
const int MX = 1e5+7;


class Solution {
public:
    string compressedString(string word) {
        string res;
        int count = 1;
        char c = word[0];
        for (int i = 1; i < word.length(); i++) {
            if (word[i] == c) {
                count++;
                if (count == 9) {
                    res += to_string(count);
                    res.push_back(c);
                    count = 0;
                    c = '?';
                }
            } else {
                if (count > 0) {
                    res += to_string(count);
                    res.push_back(c);
                }
                count = 1;
                c = word[i];
            }
        }
        if (count) {
            res += to_string(count);
            res.push_back(c);
        }
        return res;
    }
};