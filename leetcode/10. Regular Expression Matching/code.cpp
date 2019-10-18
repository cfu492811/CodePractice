#define N 200

char map[N][N];

bool match(char a, char b){
    if(a == '.') return true;
    if(a == b) return true;
    else return false;
}

bool isMatch(char * s, char * p){
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            map[i][j] = -1;
    map[0][0] = 1;
    for (int i = 1; i <= strlen(s); i++){
        map[i][0] = 0;
    }
    for (int i = 1; i <= strlen(p); i++){
    	if (p[i-1] == '*')	map[0][i] = map[0][i-2];
        else map[0][i] = 0;
    }
    for (int i = 1; i <= strlen(s); i++){
        for (int j = 1; j <= strlen(p); j++){
            if (match(p[j-1], s[i-1])){
                map[i][j] = map[i-1][j-1];
                continue;
            }
            if (p[j-1] == '*'){
                if(match(p[j-2], s[i-1]))
                	map[i][j] = map[i-1][j] | map[i][j-2];
				else 
                	map[i][j] = map[i][j-2];
                continue;
            }
            map[i][j] = 0;
        }   
    }
    return ((map[strlen(s)][strlen(p)]) == 1) ? true : false;
}
