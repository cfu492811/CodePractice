/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *create(){
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = NULL;
    newNode->next = NULL;
    return newNode;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    char counter1, counter2;
    char carry;
    struct ListNode *head;
    struct ListNode *result = create();
    head = result;
    for(counter1 = 0, counter2 = 0; !(l1 == NULL && l2 == NULL); ){
        
        if (l2 == NULL){
            printf("l2.l1 %d\n", l1->val);
            result->val = l1->val + carry;
            //result->next = create();
            //result = result->next;
            
            
            if (result->val >= 10){
                carry = 1;
                result->val %= 10;
            }
            else carry = 0;
            //counter1++
            if (l1->next != NULL){
                result->next = create();
                result = result->next;
            }
            l1 = l1->next;
            continue;
        }
        if (l1 == NULL){
            printf("l1.l2 %d\n", l2->val);
            result->val = l2->val + carry;
            //result->next = create();
            //result = result->next;
            
            if (result->val >= 10){
                carry = 1;
                result->val %= 10;
            }
            else carry = 0;
            if (l2->next != NULL){
                result->next = create();
                result = result->next;
            }
            l2 = l2->next;
            continue;
        }
        printf("l %d %d\n", l1->val, l2->val);
        result->val = l1->val + l2->val + carry;
        if (result->val >= 10){
            carry = 1;
            result->val %= 10;
        }
        else{
            carry = 0;
        }
        if (l1->next != NULL || l2->next != NULL){
            result->next = create();
            result = result->next;
        }
        
        l1 = l1->next;
        l2 = l2->next;

        
        
    }
    if (carry == 1){
        result->next = create();
        result = result->next;
        result->val = 1;
    }
    
    return head;
}

