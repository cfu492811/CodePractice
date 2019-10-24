char ** array;
int end = 0;
int length = 0;

char check(char a){
    if(a == 1) return ')';
    else if(a == 0) return '(';
    else return '\0';
}

int legal(char a[]){
    if(a[0] == ')') return 0;
    int top = 1;
    for (int i = 1; i < end; i++){
        if(a[i] == '(') top++;
        else if(a[i] == ')') top--;
        if (top < 0) return 0;
    }
    if(top > 0) return 0;
    return 1;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void re(int n){
    for (int i = 0; i < 2; i++){
        if (n == 0)
            if (i == 1)
                break;
        if (n == end - 1){
            array[length++][n] = i;
            for (int m = 0; m < n; m++)
                if (array[length][m] == '\0') array[length][m] = array[length-1][m];
            
        }
        else{
            array[length][n] = i;
            re(n+1);
        }
    }
}

char ** generateParenthesis(int n, int* returnSize){
    
    end = n * 2;
    int l = (2<<(end)-1) + 1;
    array = (char**)malloc(sizeof(char*) * (l));
    for(int i = 0; i < l; i++){
        array[i] = (char*)malloc(sizeof(char) * (2 * n + 1));
        for(int j = 0; j < (2 * n + 1); j++){
            array[i][j] = '\0';
        }
    }
    printf("%d %d\n",l,(2 * n + 1));
    if(n == 1) {
        array[0][0] = '(';
        array[0][1] = ')';
        (*returnSize) = 1;
        return array;
    }
    length = 0;
    re(0);
    for(int i = 0; i < l; i++)
        for(int j = 0; j < (2 * n + 1); j++)
            array[i][j] = check(array[i][j]);
    int m = 0, nn = 0;
    for(int i = 0; i < length; i++){
        int a = legal(array[i]);
        if(!a)continue;
        nn = 0;
        for(int j = 0; j < end; j++){
            if(array[i][j])
                array[m][nn++] = array[i][j];
        }
        array[m][nn] = '\0';
        m++;
    }
    for (int i = m; i < length; i++){
        for(int j = 0; j < end; j++){
            array[i][j] = '\0';
        }
    }
    (*returnSize) = m;
    return array;
}


