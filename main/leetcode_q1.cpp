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
const int MX = 30;


class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int pos1[26] = {0}, pos2[26] = {0}, n = s.length(), res = 0;
        for (int i = 0; i < n; i++) {
            pos1[s[i] - 'a'] = i;
            pos2[t[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; i++) {
            res += abs(pos1[i] - pos2[i]);
        }
        return res;
    }
};