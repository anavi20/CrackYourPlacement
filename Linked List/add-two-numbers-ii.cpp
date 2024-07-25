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
    ListNode* reverseList(ListNode* head){
        ListNode *curr = head, *currNext = head->next, *prev = NULL;
        while(currNext != NULL){
            curr->next = prev;
            prev = curr;
            curr = currNext;
            currNext = currNext->next;
        }
        curr->next = prev;
        return curr; 
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1 = reverseList(l1);
        ListNode *head2 = reverseList(l2);

        ListNode *curr1 = head1, *curr2 = head2, *prev = NULL, *head = NULL;
        bool isCarry = false;
        while(curr1 != NULL && curr2 != NULL){
            int sum = curr1->val + curr2->val + ((isCarry) ? 1 : 0);
            isCarry = (sum > 9) ? 1 : 0;
            ListNode *newNode = new ListNode(sum%10);
            if(prev == NULL){
                prev = newNode;
                head = newNode;
            }else{
                prev->next = newNode;
                prev = prev->next;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1 != NULL){
            int sum = curr1->val + ((isCarry) ? 1 : 0);
            isCarry = (sum > 9) ? 1 : 0;
            ListNode *newNode = new ListNode(sum%10);
            prev->next = newNode;
            prev = prev->next;
            curr1 = curr1->next;
        }
        while(curr2 != NULL){
            int sum = curr2->val + ((isCarry) ? 1 : 0);
            isCarry = (sum > 9) ? 1 : 0;
            ListNode *newNode = new ListNode(sum%10);
            prev->next = newNode;
            prev = prev->next;
            curr2 = curr2->next;
        }

        if(isCarry){
            ListNode *newNode = new ListNode(1);
            prev->next = newNode;
        }

        reverseList(head1);
        reverseList(head2);
        
        return reverseList(head);
    }
};


// Without reversing
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1 = l1, *head2 = l2;
        stack<int> st1, st2;
        while(head1 != NULL){
                st1.push(head1->val);
                head1 = head1->next;
         }
        while(head2 != NULL){
                st2.push(head2->val);
                head2 = head2->next;
            }
        ListNode* head = NULL;
        bool isCarry = 0;
        while(!st1.empty() || !st2.empty()){
            int sum = 0;
            if(!st1.empty()){
                sum += st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                sum += st2.top();
                st2.pop();
            }
            sum += (isCarry) ? 1 : 0;
            isCarry = (sum > 9) ? 1 : 0;
            ListNode* newNode = new ListNode(sum%10);
            if(head == NULL){
                head = newNode;
            }else{
                newNode->next = head;
                head = newNode;
            }
        }

        if(isCarry){
            ListNode* newNode = new ListNode(1);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};
