/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *temp[500];
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    int m = 0;
    node = head;
    while(node != NULL){
        temp[m++] = node;
        node = node->next;
    }
    if(m == 1) return 0;
    if(n == 1){
        temp[m-2]->next = NULL;
        node = temp[0];
        return node;
    }
    if(m == n){
        node = temp[1];
        return node;
    }
    temp[m-n-1]->next = temp[m-n+1];
    for (int i = 0; i < 50; i ++){
        if(temp[i]->next == NULL){
            break;
        }
    }
    node = temp[0];
    return node;
}


