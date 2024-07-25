class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = NULL, *curr = head;

        while (curr != NULL) {
            if (curr->val == val) {
                if (prev == NULL) {
                    head = curr->next;
                    // curr->next = NULL;
                    curr = curr->next;
                }else{
                    prev->next = curr->next;
                    curr = curr->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};

