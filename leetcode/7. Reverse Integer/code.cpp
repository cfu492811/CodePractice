

int reverse(int x){
    char negative = 0;
    int temp = 0;
    if (x == -2147483648) return 0;
    else if (x < 0){
    	negative = 1;
    	x *= -1;
    }
	while(x >= 100){
		temp += x%10;
		temp *= 10;
		x/=10;
	}
	temp += x%10;
	if (temp > 214748364) return 0;
    if (x >= 10){
        x/=10;
        temp *= 10;
        temp += x;
    }
	if (negative == 1) {
		temp *= -1;
	}
    return temp;
}


