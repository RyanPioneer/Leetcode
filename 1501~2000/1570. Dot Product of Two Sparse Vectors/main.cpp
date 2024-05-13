/**
 * Source: ibit.ly/KmC_w
 * Date: 2024/5/13
 * Skill:
 * Ref:
 * Runtime: 129 ms, faster than 93.11% of C++ online submissions
 * Memory Usage: 168.77 MB, less than 76.41% of C++ online submissions
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


class SparseVector {
public:
    vector<int> encoded;
    SparseVector(vector<int> &nums) {
        encoded.clear();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                encoded.push_back(i);
                encoded.push_back(nums[i]);
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sz1 = this->encoded.size(), sz2 = vec.encoded.size();
        int pos1 = 0, pos2 = 0, res = 0;
        while (pos1 < sz1 && pos2 < sz2) {
            while (pos1 < sz1 && this->encoded[pos1] < vec.encoded[pos2]) {
                pos1 += 2;
            }
            while (pos1 < sz1 && pos2 < sz2 && this->encoded[pos1] > vec.encoded[pos2]) {
                pos2 += 2;
            }
            if (pos1 >= sz1 || pos2 >= sz2) break;
            if (this->encoded[pos1] == vec.encoded[pos2]) {
                res += this->encoded[pos1 + 1] * vec.encoded[pos2 + 1];
                pos1 += 2;
                pos2 += 2;
            }
        }
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);