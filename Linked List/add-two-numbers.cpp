        ListNode *head = new ListNode(0);
        ListNode *head1 = l1, *head2 = l2, *curr = head;
        bool carry = false;

        while(head1 != NULL && head2 != NULL){
            int sum = head1->val + head2->val + (carry ? 1 : 0);
            carry = (sum >= 10) ? true : false;
            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr = newNode;
            head1 = head1->next;
            head2 =  head2->next;
        }

        while(head1 != NULL){
            int sum = head1->val + (carry ? 1 : 0);
            carry = (sum >= 10) ? true : false;
            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr = newNode;
            head1 = head1->next;
        }

        while(head2 != NULL){
            int sum = head2->val + (carry ? 1 : 0);
            carry = (sum >= 10) ? true : false;
            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr = newNode;
            head2 = head2->next;
        }

        if(carry){
            ListNode* newNode = new ListNode(1);
            curr->next = newNode;
        }

        return head->next;
