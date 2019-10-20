
int ref(char a){
    switch(a){
        case '(':return 1;
        case '[':return 2;
        case '{':return 3;
        case '}':return -3;
        case ']':return -2;
        case ')':return -1;
    }
    return 0;
}



bool isValid(char * s){
    char * stack = (char*)malloc(strlen(s) * sizeof(s));
    int top = 0;
    if (strlen(s)%2 == 1) return false;
    for (int i = 0; i < strlen(s); i++){
        if(!top) stack[top++] = ref(s[i]);
        else{
            char temp = ref(s[i]);
            if((stack[top-1] + temp) == 0){
                top --;
            }
            else if(temp > 0){
                stack[top++] = temp;
            }
            else return false;
        }
    }

    return (!top) ? true : false;
}


