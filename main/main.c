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


#include <stdio.h>

const int MX = 1e5+10;

void swap(char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void reverseString(char* s, int sSize){
    if (s == NULL) return;
    int j = sSize - 1;
    for (int i = 0; i < sSize/2; i++) {
        swap( &s[i], &s[j] );
        j--;
    }
}



int main() {
    int array[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int *ptr = (int *) (&array + 1);
    int *ptr2 = array;
    int ptr3 = array + 1;
    printf("%d\n", &array);
    printf("%d", ptr);
}

