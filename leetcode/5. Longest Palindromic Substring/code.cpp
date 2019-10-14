char table[1100][1100];

int check(char * s, int a, int b){
    if (table[a][b] == 1){
    	return table[a][b];
	}
	int mid = (a+b)/2;
	for (int i = 0, j = 0; i <= (mid - a); i++, j++){
		//if (mid+i > b)break;
		//if (mid-i < a)break;
		int temp;
		if((a+b)%2 == 0){// odd
			//if ((a+i) >= (b-i)){
			//printf("ab odd  %d %c %d %c %d \n",i,s[mid+i],mid+i,s[mid-i],mid-i);
				//printf("%d %d")
			//}
			temp = i;
		}
		else{
			//if (s[mid-i] == s[mid+i+1]) table[mid-i][mid+i+1] = 1;
			//printf("ab even %d %c %d %c %d \n",i,s[mid+i+1],mid+1+i,s[mid-i],mid-i);
			temp = i+1;
		}
		//printf("table[%d][%d]=%d\n",mid-i,mid+temp,table[mid-i][mid+temp]);
		//if (table[mid-i][mid+temp] != -1) return table[mid-i][mid+temp];
        if (s[mid-i] == s[mid+temp]){
            table[mid-i][mid+temp] = 1;
            //printf("ab %d %c %d %c %d \n",temp,s[mid+temp],mid+temp,s[mid-i],mid-i);
        }
        else{
            //printf("%c %c\n",s[mid-i] , s[mid+temp]);
            table[mid-i][mid+temp] = 0;
            return 0;
        }
	}
	//printf("reach\n");
	/*
    for (int i = 0; ;i++){
        if ((a+i) >= (b-i)){
        	table[a][b] = 1;
        	return 1;
		}
        if (s[a+i] != s[b-i]){
            return 0;
        }
    }*/
    return 1;
}

char * longestPalindrome(char * s){
    //char ss[10] = "aaaddssd";
    for (int i = 0; i < 1100; i++){
    	for (int j = 0; j < 1100; j++){
    		table[i][j] = -1;
		}
	}
    char *result = (char*)malloc(1500*sizeof(char));
    int max = 0;
    int start = 0;
    int end = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        for (int j = len - 1; j >= i; j--){
        	//printf("i %d j %d\n",i,j);
            int a = check(s, i, j);
            if (a == 1){
            	if ((j-i) == 0) if (max == 0) max = 1; 
            	if ((j-i+1) > max){
					max = j-i+1;
					start = i;
					end = j;
				}
			}
            //printf("\t\tresult %d\n",a);
        }
    }
    int i, j = 0;
    for (i = start, j = 0; i <= end; i++, j++){
    	//printf("%c %d\n",s[i],j);
        result[j] = s[i];
	}
    result[j] = '\0';
	printf("%s\n",result);
    printf("%d",max);

    return result;
}