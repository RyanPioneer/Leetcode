/**
 * Source: is.gd/qOYE6r
 * Date: 2024/4/7
 * Skill:
 * Ref:
 * Runtime: 43 ms, faster than 74.95% of C++ online submissions
 * Memory Usage: 17.20 MB, less than 97.99% of C++ online submissions
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

const int MX = 1e5+10;


int main(int argc, char **argv) {
    set<int> ms = {1,2,3,4,5,6,7,8,9,10};
    ms.insert(0);
    ms.insert(2);
    ms.insert(6);
    ms.insert(7);
    ms.insert(8);
    ms.erase(0);
    auto it = ms.begin();
    auto it2 = ms.lower_bound(6);
    cout << *it2 << endl;
    cout << distance(it, it2) << endl;
}