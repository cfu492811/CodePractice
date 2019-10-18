

char * intToRoman(int num){
    int temp = num;
    char len = 0;
    char map[10];
    char * result = (char*)malloc(50*sizeof(char));
    char rom[8] = {'I','V','X','L','C','D','M'};
    while(temp > 0){
        map[len] = temp%10;
        temp /= 10;
        len++;
        
    }
    int k = 0;
    for (int i = len -1; i >= 0; i--){
        while (map[i] > 0){
            if (map[i] == 9){
                result[k++] = rom[i * 2]; //9 0 2 90 2 4 900 4 6
                result[k++] = rom[i * 2 + 2];
                map[i] -= 9;
                continue;
                
            }
            if (map[i] > 4){
                result[k++] = rom[i * 2 + 1];
                map[i] -= 5;
                continue;
            }
            if (map[i] == 4){
                result[k++] = rom[i * 2];
                result[k++] = rom[i * 2 + 1];
                map[i] -= 4;
                continue;
            }
            else{
                result[k++] = rom[i * 2];
                map[i] -= 1;
            }
            
        }
    }
    result[k] = '\0';
    
    
    return result;
}


