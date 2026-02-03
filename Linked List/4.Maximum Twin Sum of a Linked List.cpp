/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* cur = head;

      //we will use vector to store the valus of each node to easily sum each twin values
        vector<int> vals;
        while (cur) {
            vals.push_back(cur->val);
            cur = cur->next;
        }

        int mx = -1;
        int n = vals.size();

        for (int i = 0; i < n / 2; i++) {
            mx = max(mx, vals[i] + vals[n - 1 - i]);
        }

        return mx;
    }
};
