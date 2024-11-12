struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));           //Allocate a fictitious node so that the head of the list is always
    struct ListNode* current = dummy;                                                     //the next node from this one
    int carry = 0;                                                                        //Carry is from the addition of the previous elements on the list and we must keep track of him
    while (l1 != NULL || l2 != NULL || carry > 0) {                                       //We continue if there is at least one element or a carry left
        int sum = carry;                                                                  //If the previous addition had carry we start from it
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next; 
        }
        carry = sum / 10;                                                                 //We need it in mod 10 because every node it's a digit of the number
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));     //Node to store the value from the addition
        newNode->val = sum % 10; 
        newNode->next = NULL;
        current->next = newNode;
        current = current->next;
    }
    struct ListNode* result = dummy->next;                                                //As we said, the head of the list is the next node from dummy, is a placeholder
    free(dummy);
    return result;
}
