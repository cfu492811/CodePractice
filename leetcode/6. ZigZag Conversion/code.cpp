

char * convert(char * s, int row){
    //
	//char result[500];
    char *result = (char*)malloc(1000 * sizeof(char*));
    for (int i = 0; i < 1000; i++) result[i] = 0;
    //printf("\n");
	int swich[1000];
	for (int i = 0; i < 1000; i ++) swich[i] = 0;
    int len = strlen(s);
	int gap = row * 2 - 2;
    if (gap == 0) gap = 1;
	//printf("%d\n",gap);
    int j = 0;
	for (int i = 0; i < row; i++){
		int temp = (gap - 2 * i);
		int tempb = gap - temp;
		//printf("\n%d %d %d\n",i, temp,tempb);
		int point = i;
		while (point < len){
			//printf("%d ", point);
            result[j] = s[point];
            j++;
			if (i == 0){
				//printf("a");
				point += gap;
				continue;
			}
			if (i == row-1){
				point += gap;
				continue;
			}
			if (swich[i] % 2 == 0){
			//	printf("a");
				point+=temp;
			}
			else{
			//	printf("b");
				point+=tempb;
			}
			swich[i]++;
		}
		point = 0;
	}
    //for (int i = 0; i < j; i++){
        //printf("%c ", result[i]);
    //}
    return result;
    //return 0;
} 

