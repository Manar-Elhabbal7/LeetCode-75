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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr or head->next == nullptr) return nullptr;

        ListNode * solwPtr = head;
        ListNode * fastPtr = head;
        ListNode * prevMid = nullptr;

        while (fastPtr and fastPtr->next) {
            prevMid = solwPtr;
            solwPtr = solwPtr->next;
            fastPtr = fastPtr->next->next;
        }
        prevMid->next = solwPtr->next;
        delete solwPtr;
        return head;
    }
};
