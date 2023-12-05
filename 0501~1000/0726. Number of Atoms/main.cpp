/**
 * Source: is.gd/GpHENK
 * Date: 2023/12/5
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 8.94 MB, less than 8.97% of C++ online submissions
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


class Solution {
public:
    string countOfAtoms(string formula) {
        int sz = formula.length();
        stack<map<string, int>> st;
        map<string, int> atoms;
        for (int i = 0; i < sz; i++) {
            if (formula[i] == '(') {
                st.push(atoms);
                atoms.clear();
            } else if (formula[i] >= 'A' && formula[i] <= 'Z') {
                int start = i;
                while (i + 1 < sz && formula[i + 1] >= 'a' && formula[i + 1] <= 'z') i++;
                string atom = formula.substr(start, i - start + 1);
                if (i + 1 < sz && formula[i + 1] >= '1' && formula[i + 1] <= '9') {
                    start = ++i;
                    while (i + 1 < sz && formula[i + 1] >= '0' && formula[i + 1] <= '9') i++;
                    int num = stoi(formula.substr(start, i - start + 1));
                    atoms[atom] += num;
                } else {
                    atoms[atom]++;
                }
            } else if (formula[i] == ')') {
                if (i + 1 < sz && formula[i + 1] >= '1' && formula[i + 1] <= '9') {
                    int start = ++i;
                    while (i + 1 < sz && formula[i + 1] >= '0' && formula[i + 1] <= '9') i++;
                    int num = stoi(formula.substr(start, i - start + 1));
                    for (auto &p: atoms) {
                        p.second *= num;
                    }
                }
                map<string, int> prev = st.top();
                st.pop();
                for (auto &p: prev) {
                    atoms[p.first] += p.second;
                }
            }
        }

        string res;
        for (auto &a: atoms) {
            if (a.second == 1) res += a.first;
            else res += a.first + to_string(a.second);
        }
        return res;
    }
};