char * longestCommonPrefix(char ** strs, int strsSize){
    if (!strsSize) return "";
    char * result = (char*)malloc(500*sizeof(char));
    strcpy(result,strs[0]);
    int len = strlen(result);
    for (int j, i = 1; i < strsSize; i++){
        for (j = 0; j < strlen(strs[i]); j++)
            if(result[j] != strs[i][j])
                break;
        result[j] = '\0';
    }
    return result;
}
