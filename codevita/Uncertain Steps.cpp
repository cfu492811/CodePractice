#include<stdio.h>
#include<stdlib.h>


int stackTop = 0;
int stairs;

typedef struct number{
	int one;
	int two;
	int three;
	int count;
}number;

number stack[100];

int check(int one, int two, int three){
	int temp = one + two * 2 + three * 3;
	if (temp == stairs) return 1;
	else return 0; 
}

int steps(int i){
	if (i == 1) return 1;
	else return i * steps(i-1);
}

int process(int ways){
	//stairs = one + two * 2 + three * 3;
	//ways = one + two + three;
	int ok = 0;
	for (int i = ways; i >= 0; i--){
		for (int j = 0; j < ways; j++){
			for (int k = 0; k < 2; k++){
				//printf("%d %d %d\n",i,j,k);
				ok = check(i,j,k);
				if (ok) {
					stack[stackTop].one = i;
					stack[stackTop].two = j;
					stack[stackTop].three = k;
					stack[stackTop].count = i+j+k;
					stackTop ++;
				}
			}
		}
	}
	for (int i = 0; i < stackTop; i++){
		printf("%d %d %d %d\n",stack[i].one,stack[i].two,stack[i].three,stack[i].count);
		if (stack[i].one > stack[i].two){
			for (int j = 0; j < stack[i].two + stack[i].three; j++){
				printf("%d ",stack[i].count - j);
			}
			printf("\n");
		} 
		else if (stack[i].one < stack[i].two){
			for (int j = 0; j < stack[i].one + stack[i].three; j++){
				printf("%d ",stack[i].count - j);
			}
			printf("\n");
		}
	}
	
}

int main(){
	
	
	scanf("%d", &stairs);
	
	//printf("%d",stairs);
	
	//for (int i = stairs; i > 0; i--){
		process(stairs);
	//}
	long long int result = steps(8);
	printf("%lld",result);
	
	
	
	return 0;
}
//Uncertain Steps
//1000000007.

/*
Uncertain Steps
	Problem Description
Codu is trying to go down stairs from his building to ground floor.

He can go 3 ways:

1. Walk 1 step at a time.

2. Extend his legs and go 2 steps at a time.

3. Jump down 3 steps at a time.

Given n steps, calculate the number of possible ways to reach the ground floor, provided he can jump 3 steps at most once during this process.

That is, he can jump down 3 steps only once, but at any time, if he wishes, while walking down the stairs.

	Constraints
1 <= N <= 1000000.

	Input Format
Single Integer denoting the number of Steps, N.

	Output
Number of ways to reach ground floor.

As the number can be huge, give output modulo 1000000007.

	Test Case

	Explanation
Example 1

Input

4

Output

7

Explanation

1, 1, 1, 1

1, 2, 1

1, 1, 2

1, 3

2, 1, 1

2, 2

3, 1

Number of ways = 7.
*/






/* 
0000012
0000102
0001002
0010002
0100002
1000002
0000120
0001020
0010020
0100020
1000020
0001200
0010200
0100200
1000200
0012000
0102000
1002000
0120000
1020000
1200000

*/ 













