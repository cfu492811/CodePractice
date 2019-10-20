

bool isPalindrome(int x){
    if (x < 0) return false;
    char temp[12];
    temp[11] = 0;
    temp[10] = '\0';
    while (x >= 10){
        temp[temp[11]] = x%10+48;
        x /= 10;
        temp[11] ++;
    }
    temp[temp[11]] = x%10+48;
    for (int i = 0; i < strlen(temp)/2; i++)
        if (temp[i] != temp[strlen(temp)-i-1]) return false;
    return true;
}


