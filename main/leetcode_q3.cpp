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
#define ll long long
#define MK(X, Y) make_pair(X, Y)
typedef pair<int, int> PII;
typedef pair<char, char> PCC;
ll mod = 1e9+7;
const int MX = 1e3 + 10;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int dp[MX], len = s.length();
        fill(dp, dp + MX, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i <= len; i++) {
            int cnt[26] = {0};
            for (int j = i; j > 0; j--) {
                cnt[s[j - 1] - 'a']++;
                int num = 0;
                bool check = true;
                for (int k = 0; k < 26; k++) {
                    if (cnt[k] != 0) {
                        if (num == 0 || num == cnt[k]) {
                            num = cnt[k];
                        } else {
                            check = false;
                            break;
                        }
                    }
                }
                if (check && dp[j - 1] != INT32_MAX) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[len];
    }
};