358. Rearrange String k Distance Apart
https://leetcode.com/problems/rearrange-string-k-distance-apart/

Given a non-empty string s and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
s = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.
Example 2:
s = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.
Example 3:
s = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.

#include <iostream>
#include <string>
#include <array>
#include <queue>

using namespace std;

class Solution {
public:
    string rearrangeString(string s, int k) {
        int sz = s.size();
        if (k < 0) {
            return "";
        }
        if (k <= 1) {
            return s;
        }
        array<int, 26> A = f1(s);
        priority_queue<array<int, 2>> pq = f2(A);
        string result;
        while (!pq.empty()) {
            queue<array<int, 2>> q;
            for (int cnt = min(k, sz), i = 0; i < cnt; ++i, --sz) {
                if (pq.empty()) {
                    return "";
                }
                array<int, 2> top = pq.top();
                pq.pop();
                char ch = top[1] + 'a';
                result.push_back(ch);
                --top[0];
                if (top[0] > 0) {
                    q.push(top);
                }
            }
            while (!q.empty()) {
                array<int, 2> front = q.front();
                q.pop();
                pq.push(front);
            }
        }
        return result;
    }
private:
    array<int, 26> f1(string & s) {
        array<int, 26> result;
        result.fill(0);
        for (const auto & ch : s) {
            int id = ch - 'a';
            ++result[id];
        }
        return result;
    }
    priority_queue<array<int, 2>> f2(array<int, 26> & A) {
        priority_queue<array<int, 2>> result;
        for (int i = 0; i < 26; ++i) {
            if (A[i] > 0) {
                result.push({A[i], i});
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string s, result;
    int k;
    
    s = "aabbcc";
    k = 3;
    result = solution.rearrangeString(s, k);
    cout << result << '\n';
    
    s = "aaabc";
    k = 3;
    result = solution.rearrangeString(s, k);
    cout << result << '\n';

    s = "aaadbbcc";
    k = 2;
    result = solution.rearrangeString(s, k);
    cout << result << '\n';
    
    return 0;
}
