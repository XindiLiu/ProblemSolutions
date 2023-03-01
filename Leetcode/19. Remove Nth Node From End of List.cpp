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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto node = head;
        int i = 0;
        while (i < n) {
            node = node->next;
            i++;
        }
        if (node == nullptr) { // n == sz, remove head
            return head->next;
        }
        auto pred = head; // predeccessor of the node to remove
        while (node->next != nullptr) {
            node = node->next;
            pred = pred->next;
        }
        pred->next = (pred->next)->next;
        return head;
    }
};