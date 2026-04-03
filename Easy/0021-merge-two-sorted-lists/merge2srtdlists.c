#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;   //Base case: if one of the lists is empty, return the other
    if (list2 == NULL) return list1; 
    struct ListNode dummy;             //Create a dummy node to simplify handling the result
    struct ListNode* tail = &dummy;    //Tail pointer to keep track of the last node in the merged list
    dummy.next = NULL;              
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;  
            list1 = list1->next; 
        } else {
            tail->next = list2;   
            list2 = list2->next;
        }
        tail = tail->next;     
    }
    //Add remaining nodes (if any) from list1 or list2
    if (list1 != NULL) {
        tail->next = list1;      
    } else {
        tail->next = list2;     
    }
    return dummy.next;             //Return the merged list, excluding the dummy node
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode)); //Allocate memory for a new node
    newNode->val = val;                                                           //Set the value of the node
    newNode->next = NULL;                                                         //Initialize the next pointer to NULL
    return newNode;                                                               //Return the created node
}

/*
Complexity Analysis:

Time Complexity: O(n+m), where n is the number of nodes in list1 and m is the number of nodes in list2.
- Each node is processed exactly once, so the total number of operations is proportional to the combined length of the two lists.

Space Complexity: O(1), as the merging process is performed in place without using additional memory for a new list.
*/
