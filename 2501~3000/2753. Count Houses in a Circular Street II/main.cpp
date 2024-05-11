/**
 * Source: is.gd/3MQ7mH
 * Date: 2024/5/11
 * Skill:
 * Ref:
 * Runtime: 94 ms, faster than 44.44% of C++ online submissions
 * Memory Usage: 126.02 MB, less than 33.33% of C++ online submissions
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


 class Street {
 public:
     Street(vector<int> doors);
     void closeDoor();
     bool isDoorOpen();
     void moveRight();
 };


class Solution {
public:
    int houseCount(Street* street, int k) {
        int res = 0, cur = 0, cnt = k;
        while (!street->isDoorOpen()) street->moveRight();
        while (street->isDoorOpen() && cnt--) street->moveRight();
        if (cnt == 0) {
            while (street->isDoorOpen()) {
                street->closeDoor();
                street->moveRight();
                res++;
            }
            return res;
        }

        while (1) {
            cnt = k;
            while (cnt && !street->isDoorOpen()) {
                cnt--;
                cur++;
                street->moveRight();
            }
            if (!street->isDoorOpen()) {
                return res;
            }
            res += cur + 1;
            street->closeDoor();
            cur = 0;
            street->moveRight();
        }
        return res;
    }
};