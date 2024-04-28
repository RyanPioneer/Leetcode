/**
 * Source: tinyurl.com/25hpz9n7
 * Date: 2024/4/28
 * Skill:
 * Ref:
 * Runtime: 161 ms, faster than 68.68% of C++ online submissions
 * Memory Usage: 95.43 MB, less than 71.08% of C++ online submissions
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


class Encrypter {
public:
    unordered_map<char, string> key2value;
    unordered_map<string, int> cnt;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < keys.size(); i++) {
            key2value[keys[i]] = values[i];
        }
        for (auto &i: dictionary) {
            cnt[encrypt(i)]++;
        }
    }

    string encrypt(string word1) {
        string res;

        for (auto &c: word1) {
            if (key2value.find(c) == key2value.end()) {
                return "";
            }
            res += key2value[c];
        }
        return res;
    }

    int decrypt(string word2) {
        return cnt.find(word2) == end(cnt) ? 0 : cnt[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */