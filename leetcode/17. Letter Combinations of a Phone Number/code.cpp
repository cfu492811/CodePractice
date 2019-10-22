char letter[8][5] = {{'a','b','c'},
				{'d','e','f'},
				{'g','h','i'},
				{'j','k','l'},
				{'m','n','o'},
				{'p','q','r','s'},
				{'t','u','v'},
				{'w','x','y','z'}};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** temp;
int len = 0;
int re(int a, char * digits){
    for (int i = 0; i < strlen(letter[digits[a]-50]); i++){
        if (len != 0)
            for (int j = 0; j < a; j++) 
                if (temp[len][j] == '\0') temp[len][j] = temp[len-1][j];
        if (a == strlen(digits) - 1) {
            temp[len++][a] = letter[digits[a]-50][i];
        }
        else if (a < strlen(digits)) {
            temp[len][a] = letter[digits[a]-50][i];
            re(a + 1, digits);
        }
    }
    return 0;
}

char ** letterCombinations(char * digits, int* returnSize){
    temp = (char**)malloc(500 * sizeof(char*));
    for (int i = 0; i < 500; i++){
        temp[i] = (char*)malloc((strlen(digits) + 1) * sizeof(char));
        for (int j = 0; j < (strlen(digits) + 1); j++){
            temp[i][j] = '\0';
        }
    }
    if(strlen(digits) == 0) {
        *returnSize = 0;
        return temp;
    }
    len = 0;
    re(0, digits);
    *returnSize = len;
    return temp;
}


