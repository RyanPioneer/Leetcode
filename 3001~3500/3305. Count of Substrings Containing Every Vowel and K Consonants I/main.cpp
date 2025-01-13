/**
 * Source: ibit.ly/_O1UZ
 * Date: 2025/1/13
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 9.94 MB, less than 74.32% of C++ online submissions
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


class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int res = 0, n = word.size(), right = 0, consonantNum = 0, cnt[26] = {0};

        vector<int> consonants;
        for (int i = 0; i < n; i++) {
            if (isConsonant(word[i])) {
                consonants.push_back(i);
            }
        }
        consonants.push_back(n);

        for (int left = 0; left < n; left++) {
            while (right < n && ((cnt[0] == 0 || cnt[4] == 0 || cnt[8] == 0 || cnt[14] == 0 || cnt[20] == 0) || consonantNum < k)) {
                if (isConsonant(word[right])) {
                    consonantNum++;
                }
                cnt[word[right++] - 'a']++;
            }
            if ((cnt[0] == 0 || cnt[4] == 0 || cnt[8] == 0 || cnt[14] == 0 || cnt[20] == 0) || consonantNum < k) {
                break;
            }
            if (isConsonant(word[left])) {
                consonantNum--;
            }
            cnt[word[left] - 'a']--;
            if (consonantNum + (isConsonant(word[left]) ? 1 : 0) > k) continue;
            auto it = lower_bound(consonants.begin(), consonants.end(), right);
            res += *it - right + 1;
        }
        
        return res;
    }

    bool isConsonant(char c) {
        // 確保字元是字母
        if (!std::isalpha(c)) {
            return false;
        }

        // 將字元轉為小寫
        char lower = std::tolower(c);

        // 如果不是元音，則為子音
        return !(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u');
    }
};
