/**
 * Source: tinyurl.com/yrqmcugm
 * Date: 2023/10/19
 * Skill:
 * Runtime: 531 ms, faster than 41.33% of C++ online submissions
 * Memory Usage: 275.69 MB, less than 19.00% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


typedef struct node{
    char c;
    struct node* next;
    struct node* prev;
    node(char ch) {
        c = ch;
        next = prev = nullptr;
    }
    node(char ch, struct node* n, struct node* p) {
        c = ch;
        next = n;
        prev = p;
    }
} Node;

class TextEditor {
    Node *dummy_head = new Node('1');
    Node *cur_pos = dummy_head;
public:
    TextEditor() {
    }

    void addText(string text) {
        for (int i = 0; i < text.length(); i++) {
            Node *new_node = new Node(text[i], cur_pos->next, cur_pos);
            if (new_node->next != nullptr)
                new_node->next->prev = new_node;
            cur_pos->next = new_node;
            cur_pos = new_node;
        }
    }

    int deleteText(int k) {
        int num = 0;
        for (int i = 0; i < k; i++) {
            if (cur_pos->prev == nullptr)
                break;
            num++;
            Node *tmp = cur_pos;
            if (tmp->next != nullptr)
                cur_pos->next->prev = tmp->prev;
            cur_pos->prev->next = tmp->next;
            cur_pos = tmp->prev;
            delete tmp;
        }
        return num;
    }

    string cursorLeft(int k) {
        for (int i = 0; i < k; i++) {
            if (cur_pos->prev == nullptr)
                break;
            cur_pos = cur_pos->prev;
        }
        string res;
        Node *tmp = cur_pos;
        for (int i = 0; i < 10; i++) {
            if (tmp->prev == nullptr)
                break;
            res.push_back(tmp->c);
            tmp = tmp->prev;
        }
        reverse(begin(res), end(res));
        return res;
    }

    string cursorRight(int k) {
        for (int i = 0; i < k; i++) {
            if (cur_pos->next == nullptr)
                break;
            cur_pos = cur_pos->next;
        }
        string res;
        Node *tmp = cur_pos;
        for (int i = 0; i < 10; i++) {
            if (tmp->prev == nullptr)
                break;
            res.push_back(tmp->c);
            tmp = tmp->prev;
        }
        reverse(begin(res), end(res));
        // show();
        return res;
    }
    void show() {
        string res;
        Node *tmp = dummy_head;
        while (tmp->next != nullptr) {
            res.push_back(tmp->next->c);
            tmp = tmp->next;
        }
        cout << res << endl;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */


int main() {
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}