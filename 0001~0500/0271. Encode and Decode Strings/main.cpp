/**
 * Source: ibit.ly/MrSWn
 * Date: 2025/4/20
 * Skill:
 * Ref:
 * Runtime: 27 ms, faster than 78.28% of C++ online submissions
 * Memory Usage: 23.30 MB, less than 96.90% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

class Codec {
   public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (const auto& str : strs) {
            res += to_string(str.size()) + '#' + str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = s.find('#', i);
            int len = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
