/**
 * Source: jpeg.ly/MOehD
 * Date: 2023/12/3
 * Skill:
 * Ref:
 * Runtime: 115 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 18.16 MB, less than 85.71% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int res = 0, left = 0;
        for (int right = 1; right < word.length(); right++) {
            if (abs(word[right - 1] - word[right]) > 2) {
                res += helper(word.substr(left, right - left), k);
                left = right;
            }
        }
        return res + helper(word.substr(left, word.length() - left), k);
    }
    int helper(string word, int k) {
        int sz = word.length(), cnt[26], k_num, res = 0;
        for (int num = 1; num * k <= sz && num <= 26; num++) {
            fill(cnt, cnt + 26, 0);
            k_num = 0;
            for (int right = 0; right < sz; right++) {
                cnt[word[right] - 'a']++;
                if (cnt[word[right] - 'a'] == k) k_num++;
                int left = right - k * num;
                if (left >= 0) {
                    if (cnt[word[left] - 'a'] == k) k_num--;
                    cnt[word[left] - 'a']--;
                }
                if (k_num == num) res++;
            }
        }
        return res;
    }
};