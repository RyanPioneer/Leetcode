/**
 * Source: is.gd/SiWts8
 * Date: 2023/12/24
 * Skill:
 * Ref:
 * Runtime: TLE
 * Memory Usage:
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
#define SZ(X) ((int)(X).size())
const int MX = 1002;


class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int original_len[101], changed_len[101];
        unordered_map<string, int> str2id;
        int id = 1, offset = 202;
        for (auto &s: original) {
            reverse(begin(s), end(s));
            if (str2id.find(s) == str2id.end()) str2id[s] = id++;
        }
        for (auto &s: changed) {
            reverse(begin(s), end(s));
            if (str2id.find(s) == str2id.end()) str2id[s] = id++;
        }
        unordered_map<int, int> hash2cost;
        for (int i = 0; i < SZ(original); i++) {
            original_len[i] = original[i].length();
            changed_len[i] = changed[i].length();
            int hash = str2id[original[i]] * offset + str2id[changed[i]];
            if (hash2cost.find(hash) != hash2cost.end()) hash2cost[hash] = min(hash2cost[hash], cost[i]);
            else hash2cost[hash] = cost[i];
        }
        for (int i = 0; i < SZ(original); i++) {
            int len1 = original_len[i];
            for (int j = 0; j < SZ(original); j++) {
                if (i == j || len1 != original_len[j]) continue;
                int hash1 = str2id[original[j]] * offset + str2id[original[i]];
                if (hash2cost.find(hash1) == hash2cost.end()) continue;
                for (int k = 0; k < SZ(changed); k++) {
                    if (len1 != changed_len[k]) continue;
                    int hash2 = str2id[original[i]] * offset + str2id[changed[k]];
                    if (hash2cost.find(hash2) == end(hash2cost)) continue;
                    int hash3 = str2id[original[j]] * offset + str2id[changed[k]];
                    if (hash2cost.find(hash3) == end(hash2cost)) hash2cost[hash3] = hash2cost[hash1] + hash2cost[hash2];
                    else hash2cost[hash3] = min(hash2cost[hash3], hash2cost[hash1] + hash2cost[hash2]);
                }
            }
        }
        int dp[1002];
        fill(dp, dp + 1002, INT32_MAX / 2);
        dp[0] = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] == target[i]) dp[i + 1] = dp[i];
            string prev = source.substr(0, i + 1);
            string t = target.substr(0, i + 1);
            reverse(begin(prev), end(prev));
            reverse(begin(t), end(t));
            for (int j = 0; j <= i; j++) {
                if (str2id.find(prev) != str2id.end() && str2id.find(t) != str2id.end()) {
                    int id1 = str2id[prev], id2  = str2id[t];
                    int hash = id1 * offset + id2;
                    if (hash2cost.find(hash) != hash2cost.end()) {
                        dp[i + 1] = min(dp[i + 1], hash2cost[hash] + dp[j]);
                    }
                }
                prev.pop_back();
                t.pop_back();
            }
        }
        return dp[source.length()] < INT32_MAX / 2 ? dp[source.length()] : -1;
    }
};