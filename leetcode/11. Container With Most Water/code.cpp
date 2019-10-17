
int maxArea(int* height, int heightSize){
    int max = 0;
    int i = 0, j = heightSize - 1;
    int small;
    while(i < j){
        if (height[i] > height[j]) small = j;
        else small = i;
        if((height[small] * (j - i)) > max)
            max = (height[small] * (j - i));
        if (small == j) j--;
        else i++;
    }
    return max;
}

