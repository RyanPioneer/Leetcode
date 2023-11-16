/**
 * Source: ibit.ly/PH-4e
 * Date: 2023/11/16
 * Skill:
 * Runtime: 1233 ms, faster than 14.97% of C++ online submissions
 * Memory Usage: 655.36 MB, less than 5.44% of C++ online submissions
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

class Operation {
public:
    ll add, mul;
    Operation() : add(0), mul(1){}
    Operation(ll inc, ll m) : add(inc), mul(m){}
    void operator+(Operation const& other) {
        add = (add * other.mul + other.add) % mod;
        mul = mul * other.mul % mod;
    }
};


class BIT {
public:
    Operation *op[MX];

    BIT() {
        for (int i = 0; i < MX; i++) {
            op[i] = new Operation();
        }
    }

    void update(int idx, Operation *other) {
        while (idx < MX) {
            op[idx]->operator+(*other);
            idx += idx & -idx;
        }
    }

    Operation *query(int idx) {
        Operation *num = new Operation();
        while (idx > 0) {
            num->operator+(*op[idx]);
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
        Operation *op = new Operation(inc, 1);
        tree->update(MX - pos, op);
    }

    void multAll(int m) {
        Operation *op = new Operation(0, m);
        tree->update(MX - pos, op);
    }

    int getIndex(int idx) {
        if (idx >= pos) return -1;
        ll num = nums[idx];
        idx = MX - idx - 1;
        Operation *op = tree->query(idx);
        return (num * op->mul % mod + op->add) % mod;
    }
};


int main() {
}