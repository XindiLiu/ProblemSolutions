class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* lasttail = new ListNode(-1, head);
        ListNode* ans = lasttail;
        ListNode* i = head;
        while (i != nullptr) {
            count++;
            if (count == 1) {
                lasttail->next = i;
            }
            if (count == k) {
                ListNode* tmp = lasttail->next;
                lasttail->next = i;
                i = i->next;
                lasttail = tmp;
                ListNode* tmp2 = lasttail->next;
                lasttail->next = nullptr;
                for (int j = 1; j < k; ++j) {
                    ListNode* tmp3 = tmp2->next;
                    tmp2->next = tmp;
                    tmp = tmp2;
                    tmp2 = tmp3;
                }
                count = 0;

            }
            else i = i->next;
        }
        return ans->next;
    }
};