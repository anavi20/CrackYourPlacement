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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0), *curr1 = list1, *curr2 = list2, *head = dummy;

        while(curr1 != NULL && curr2 != NULL){
            if(curr1->val <= curr2->val){
                dummy->next = curr1;
                curr1 = curr1->next;
            }else{
                dummy->next = curr2;
                curr2 = curr2->next;
            }
            dummy = dummy->next;
        }

        while(curr1 != NULL){
            dummy->next = curr1;
            curr1 = curr1->next;
            dummy = dummy->next;
        }
        while(curr2 != NULL){
            dummy->next = curr2;
            curr2 = curr2->next;
            dummy = dummy->next;
        }

        return head->next;
    }
};
