/**
 * Source: t.ly/ZSmci
 * Date: 2023/11/6
 * Skill:
 * Runtime: 142 ms, faster than 99.15% of C++ online submissions
 * Memory Usage: 93.09 MB, less than 73.94% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class TrieNode {
public:
    TrieNode *next[26];
    bool is_word = false;
};

class StreamChecker {
    TrieNode *root = new TrieNode();
    vector<char> input;
public:
    StreamChecker(vector<string>& words) {
        for (auto &w: words) {
            TrieNode * node = root;
            for (int i = w.length() - 1; i >= 0; i--) {
                char c = w[i];
                if (node->next[c - 'a'] == nullptr) {
                    node->next[c - 'a'] = new TrieNode();
                }
                node = node->next[c - 'a'];
            }
            node->is_word = true;
        }
    }

    bool query(char letter) {
        input.push_back(letter);
        TrieNode * node = root;
        for (auto iter = input.rbegin(); iter != input.rend(); ++iter) {
            if (node->next[*iter - 'a'] == nullptr) {
                return false;
            }
            node = node->next[*iter - 'a'];
            if (node->is_word) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */


int main() {
}