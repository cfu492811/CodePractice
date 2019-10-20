

int threeSumClosest(int* nums, int numsSize, int target){
    int max = 999999;
    int result = 0;
    for (int i = 0; i < numsSize; i++){
        for (int j = i + 1; j < numsSize; j++){
            for (int k = j + 1; k < numsSize; k++){
                int temp = (nums[i] + nums[j] + nums[k]);
                int diff = (temp > target) ? (temp - target) : (target - temp);
                if (diff < max){
                    max = diff;
                    result = temp;
                }
            }
        }
    }
    return result;
}


