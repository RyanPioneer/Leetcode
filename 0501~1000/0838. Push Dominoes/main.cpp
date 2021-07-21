/** 
 * Source: https://leetcode.com/problems/push-dominoes/
 * Date: 2021/7/21
 * Skill: 
 * Runtime: 20 ms, faster than 71.50% of C++ online submissions
 * Memory Usage: 12.5 MB, less than 35.93% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      1 <= n <= 10^5
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int index = 0, sz = dominoes.length(), left = -1, i;
        while (index < sz) {
            if (dominoes[index] == 'L') {
                for (i = left+1; i < index; i++) dominoes[i] = 'L';
                left = index;
            } else if (dominoes[index] == 'R') {
                left = index; 
                while (index < sz-1 && dominoes[++index] != 'L') {
                    if (dominoes[index] == 'R') {
                        for (int i = left+1; i < index; i++) dominoes[i] = 'R';
                        left = index;
                    }
                }
                if (index == sz-1 && dominoes[index] != 'L') {
                    for (i = left+1; i <= index; i++) dominoes[i] = 'R';
                    break;
                }
                int dot = (index-left-1)/2;
                for (i = 1; i <= dot; i++) {
                    dominoes[index-i] = 'L';
                    dominoes[left+i] = 'R';
                }
                left = index;
            }
            index++;
        }
        return dominoes;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();