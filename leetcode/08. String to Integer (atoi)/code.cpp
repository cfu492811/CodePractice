int isint(char a){
    if (a >= 48 && a <= 57) return 1;
    else return 0;
}

long int trans(char * a){
    long int temp = a[0]-48;
    if (strlen(a) == 1) return temp;
    int i = 1;
    while (i < strlen(a)){
        temp *= 10;
        temp += a[i]-48;
        i++;
    }
    return temp;
}

long int myAtoi(char * str){
    int current = 0;
    while(str[current] == ' '){
        current ++;
    }
    int len = strlen(str);
    int negative = 2147483647;
    int temp = 0;
    int j = 0;
    char integer[200];
    char max[11] = {2,1,4,7,4,8,3,6,4,8};
    int first = 0;
    char op[2] = {0, 0};
    for (int i = current; i < len; i++){
        if (i == current){
            if (str[i] == '-'){
                if (str[i+1] == '+') return 0;
                negative = -2147483648;
                continue;
            }
        }
        if (isint(str[i])){
            if (first)
                integer[j++] = str[i];
            else{
                if (str[i] != '0'){
                    integer[j++] = str[i];
                    first = 1;
                }
            }
        }
        else{
            
            if (str[i] == '+'){
                if (str[i+1] == '+') break;
                
                if(!first) continue;
                else break;
                //op++;
            }
            else break;
        }
    }
    integer[j] = '\0';
    if (strlen(integer) == 0)return 0;
    for (int i = 0; i < strlen(integer); i++){
    }
    if (strlen(integer) > 10)
        return negative;
    else if(strlen(integer) == 10){
        char same = 0;
        char big = 1;
        for (int i = 0; i < 10; i++){
            if (big == 1){
                if (integer[i]-48 < max[i]) big = 0;
                else if(integer[i]-48 > max[i])return negative;
            }
            if (integer[i]-48 == max[i]) same++;
        }
        if (same == 10) return negative;
    }
    long int result = trans(integer);
    if (negative < 0) result *= -1;
    return result;
}


