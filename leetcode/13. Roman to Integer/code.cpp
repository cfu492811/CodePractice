
int process(char a){
    switch(a){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return 0;
}

int romanToInt(char * s){
    int result = 0;
    for (int i = 0; i < strlen(s); i++){
        int temp = process(s[i]);
        if(temp < process(s[i+1])){
            result += (process(s[i+1]) - temp);
            i++;
        }
        else
            result += temp;
    }
    return result;
}


