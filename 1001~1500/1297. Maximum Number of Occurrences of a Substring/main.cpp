/**
 * Source: ibit.ly/Vb5qp
 * Date: 2023/11/17
 * Skill:
 * Runtime: 638 ms, faster than 25.05% of C++ online submissions
 * Memory Usage: 151.61 MB, less than 22.60% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#include <vector>
#include <iostream>
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


const int MX = 26;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> str2num;
        int right = 0, cnt[MX] = {0}, len = s.length(), number = 0, res = 0;
        string cur = "";
        for (int left = 0; left <= len - minSize; ++left) {
            while (right < len && right - left < maxSize) {
                int a = s[right] - 'a';
                if (number == maxLetters && cnt[a] == 0) break;
                cnt[a]++;
                if (cnt[a] == 1) number++;
                right++;
            }
            if (right >= left + minSize) {
                cur = s.substr(left, minSize);
                int pos = left + minSize - 1;
                while (pos < right) {
                    str2num[cur]++;
                    res = max(res, str2num[cur]);
                    pos++;
                    cur.push_back(s[pos]);
                }
            }
            cnt[s[left] - 'a']--;
            if (cnt[s[left] - 'a'] == 0) number--;
        }
        return res;
    }
};


int main() {
    Solution s;
}