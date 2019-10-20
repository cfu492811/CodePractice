int lengthOfLongestSubstring(char * s){
	int i = 0;
	int start = 0, end = 0;
	int maxstart = 0, maxend = 0;
	while(1){
		//printf("%d",i);
		for (int j = start; j < i; j++){
			if(s[i] == s[j]){
				//printf("\nj %d %c\n",j,s[j]);
				//printf("i %d %c\n",i,s[i]);
				//printf("%d\n",i-start);
				if((i-start)>=(maxend-maxstart)){
					maxstart = start;
					maxend = i;
					
				}
				start = j+1;
			}
		}
		if(s[i] == '\0'){
			break;
		} 
		//printf("\n");
		i++;
		//printf("---------\n");
	}
	printf("\ns = %s\n",s);
	printf("start %d\n",maxstart);
	printf("end %d\n",maxend);
	
	if (strlen(s) == 1) maxend = 1;
	else if(strlen(s) > 1){
		if((i-start)>=(maxend-maxstart)){
			maxstart = start;
			maxend = i;
			
		}
	}
	for (int j = maxstart; j < maxend; j++)
		printf("%c",s[j]);
	printf("\n\n%d",maxend-maxstart);
    return maxend-maxstart;
}

