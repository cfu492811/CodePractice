
int throw(int * num, int s){
    if (s >= 0) return num[s];
    return -1;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int sort[5000];
    for (int i = 0, j = 1, k = 1; i < nums1Size+nums2Size; i++){
        int a = throw(nums1, nums1Size-j);
        int b = throw(nums2, nums2Size-k);
        if(b>a){
            sort[nums1Size+nums2Size-i-1] = b;
            k++;
        }
        else if(b<=a){
            sort[nums1Size+nums2Size-i-1] = a;
            j++;
        }
    }
    float result;
    int a, b;
    if ((nums1Size+nums2Size)%2 == 0){
        b = (nums1Size+nums2Size)/2;
        a = b-1;
        result = (float)(sort[b]+sort[a])/2;
    }
    else{
        b = (nums1Size+nums2Size)/2;
        result = sort[b];
    }
    return result;
}

