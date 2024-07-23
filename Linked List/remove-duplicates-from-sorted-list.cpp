class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head, *prev = curr;
        while(curr != NULL){
            if(prev != NULL && curr->val == prev->val){
                prev->next = curr->next;
            }else{
                prev = curr;
            }
            curr = curr->next;
        }

        return head;
    }
};
