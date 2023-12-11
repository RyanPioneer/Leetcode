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
    int countTestedDevices(vector<int>& batteryPercentages) {
        int res = 0, dec = 0, len = SZ(batteryPercentages);
        for (int i = 0; i < len; i++) {
            if (batteryPercentages[i] == 0) continue;
            for (int j = i + 1; j < len; j++) {
                if (batteryPercentages[j] == 0) continue;
                batteryPercentages[j]--;
            }
            res++;
        }
        return res;
    }
};