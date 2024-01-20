/**
 * Source: jpeg.ly/EJBNr
 * Date: 2024/1/20
 * Skill: KMP
 * Ref:
 * Runtime: 136 ms, faster than 99.66% of C++ online submissions
 * Memory Usage: 85.86 MB, less than 89.84% of C++ online submissions
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
#define ULL unsigned long long
#define SZ(X) ((int)(X).size())
const ll carry = 27;


class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> pos_a = get_idx(s, a), pos_b = get_idx(s, b), res;
        int idx_b = 0;
        for (auto &i: pos_a) {
            while (idx_b < SZ(pos_b) && pos_b[idx_b] + k < i) idx_b++;
            if (idx_b == SZ(pos_b)) break;
            if (abs(pos_b[idx_b] - i) <= k) res.push_back(i);
        }
        return res;
    }
    vector<int> get_idx(string s, string pattern) {
        ULL hash_p = 0, h = 1;
        for (auto &i: pattern) {
            hash_p = hash_p * carry + i - 'a' + 1;
            h = h * carry;
        }
        vector<int> res;
        int len = pattern.length();
        ULL hash = 0;
        for (int i = 0; i < len; i++) hash = hash * carry + s[i] - 'a' + 1;
        if (hash == hash_p) res.push_back(0);
        for (int i = len; i < s.length(); i++) {
            hash = hash * carry + s[i] - 'a' + 1 - h * (s[i - len] - 'a' + 1);
            if (hash == hash_p) res.push_back(i - len + 1);
        }
        return res;
    }
};