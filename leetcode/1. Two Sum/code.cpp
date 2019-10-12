

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *re = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (unsigned int i = 0; i < numsSize; i++){
        for (unsigned int j = i+1; j < numsSize; j++){
            if ((nums[i] + nums[j]) == target){
                re[0] = i;
                re[1] = j;
                return re;
            }
        }
    }
    return re;
}


