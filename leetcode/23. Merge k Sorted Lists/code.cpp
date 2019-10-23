/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* create(){
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next = NULL;
    return temp;
}
#define N 500

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode** list = (struct ListNode**)malloc(sizeof(struct ListNode*) * listsSize);
    struct ListNode* temp;
    int * array = (int*)malloc(sizeof(int) * listsSize);
    if(!listsSize)return 0;
    int count = 0;
    for (int i = 0; i < listsSize; i++){
        array[i] = 0;
        temp = lists[i];
        while(temp != NULL){
            temp = temp->next;
            array[i]++;
        }
        count += array[i];
    }
    int * sort = (int*)malloc(sizeof(int) * count);
    count = 0;
    for (int i = 0; i < listsSize; i++){
        for (int j = 0; j < array[i]; j++){
            sort[count++] = lists[i][j*2].val;
        }
    }
    for (int i = 0; i < count; i++){
        for (int j = 0, a; j < count-1; j++){
            if (sort[j] > sort[j+1]) {
                a = sort[j];
                sort[j] = sort[j+1];
                sort[j+1] = a;
            }
        }
    }
    if(!count) return 0;
    struct ListNode* head = create();
    head->val = sort[0];
    temp = head;
    for (int i = 1; i < count; i++){
        temp->next = create();
        temp = temp->next;
        temp->val = sort[i];
    }
    return head;
}
