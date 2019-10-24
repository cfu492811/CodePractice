#define swap(a,b,t) t=a; a=b; b=t;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *temp;
    if (!l2) return l1;
    if (!l1) return l2;
    struct ListNode *l1temp = l1;
    struct ListNode *prev = NULL;
    prev = l1temp;
    while(l2){
        if(!l1temp){
            prev->next = l2;
            break;
        }
        if(l1temp->val > l2->val){
            temp = l2->next;
            l2->next = l1temp;
            if (l1temp == l1){
                l1 = l2;
                prev = l1;
            }
            else{
                prev->next = l2;
                prev = l2;
            }
            l2 = temp;
        }
        else{
            prev = l1temp;
            l1temp = l1temp->next;
        }
    }
    
    return l1;
}


