/**
 * Source: ibit.ly/PH-4e
 * Date: 2023/11/16
 * Skill:
 * Runtime: 418 ms, faster than 49.66% of C++ online submissions
 * Memory Usage: 270.74 MB, less than 5.44% of C++ online submissions
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


#define ll long long
ll mod = 1e9+7;

const int MX = 1e5+1;


class BIT {
public:
    int add[MX], mul[MX];

    BIT() {
        for (int i = 0; i < MX; i++) {
            add[i] = 0;
            mul[i] = 1;
        }
    }

    void update_add(int idx, ll num) {
        while (idx < MX) {
            add[idx] = (add[idx] + num) % mod;
            idx += idx & -idx;
        }
    }

    void update_mul(int idx, ll num) {
        while (idx < MX) {
            mul[idx] = mul[idx] * num % mod;
            add[idx] = add[idx] * num % mod;
            idx += idx & -idx;
        }
    }

    ll query_sum(int idx) {
        ll num = 0;
        while (idx > 0) {
            num = ((num * mul[idx]) + add[idx]) % mod;
            idx -= idx & -idx;
        }
        return num;
    }

    ll query_mul(int idx) {
        ll num = 1;
        while (idx > 0) {
            num = num * mul[idx] % mod;
            idx -= idx & -idx;
        }
        return num;
    }
};

class Fancy {
public:
    vector<ll> nums;
    int pos = 0;
    BIT *tree = new BIT();
    Fancy() {
    }

    void append(int val) {
        nums.push_back(val);
        pos++;
    }

    void addAll(int inc) {
        tree->update_add(MX - pos, inc);
    }

    void multAll(int m) {
        tree->update_mul(MX - pos, m);
    }

    int getIndex(int idx) {
        if (idx >= pos) return -1;
        ll num = nums[idx];
        idx = MX - idx - 1;
        return (num * tree->query_mul(idx) % mod + tree->query_sum(idx)) % mod;
    }
};


int main() {
}