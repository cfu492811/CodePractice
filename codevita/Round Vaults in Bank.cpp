#include<stdio.h>
#include<stdlib.h>
int amount;
int lockers;

int count_amount(){
	if (lockers % 5 == 0)
		amount = lockers * 2 / 5;
	else
		amount = (lockers / 5) * 2 + 1;
}

int slide(int *check, int j){
	int count = 0;
	for (int i = 0; i < 5; i++){
		printf("%d ",i+j);
		if (check[i] == 1)
			count ++;
	}
	printf("\n");
	if (count == 2) return 1;
	else return 0;
}
//0 1 2 3 4 5 6 7 8
//        4 5 6 7 8

        
int available(int *check){
	int a = 1;
	for (int i = 0; i < lockers - 4; i++){
		printf("bbb");
		a = slide(&check[i], i);
		//if (!a) return 0;
	}
	int count = 0;
	for (int i = 0; i < lockers; i++){
		if (check[i]) count ++;
	}
	if (count == amount) return 1;
	else return 0;
	//printf("a = %d",a);
}


int check_big(int *input, int *check, int cur){
	
	
	
	
	
}


int main(){
	
	scanf("%d", &lockers);
	int check[50];
	int input[] = {1000, 2000, 1000, 5000, 9000, 6000, 3000, 4000, 1000};//{0,31,28,31,30,31,30,31,31,30,31,30,31};
	count_amount();
	
	for (int i = 0; i < lockers - 5; i++){
		//check_big(&input[i], check, i);
		printf("\n");
	}/*
	for (int i = 0; i < 5; i++){
		for (int j = i+1; j < 5; j++){
			printf("%d %d\n",i,j);
		}
	}*/
	int a = available(check);
	printf("--%d",a);
	return 0;
}
//Round Vaults in Bank
//{1000, 2000, 1000, 5000, 9000, 5000, 3000, 4000, 1000}


/*

Round Vaults in Bank
	Problem Description
In the strong room of ABC bank there are N vaults arranged in a circle. The amount of money inside each vault displayed on the door. You can empty any number of vaults as long as you do not empty more than 2 out of any 5 adjacent vaults. If you attempt to break more than 2 of any 5 adjacent vaults, an alarm sounds and the sentry a sharp shooter will kill you instantly with his laser gun! Note that as the vaults are arranged in a circle, the last vault is adjacent to the first one.

The output is the maximum amount of money that can be emptied without sounding the alarm

	Constraints
N<=50, Amount in each vault <=50000

	Input Format
The first line contains an integer N which is the number of vaults. The next line has a sequence of positive integers of length N, giving the amount of cash in its vaults in order

	Output
The maximum amount of money that can be looted without sounding the alarm.

	Test Case

	Explanation
Example 1

Input

9

1000, 2000, 1000, 5000, 9000, 5000, 3000, 4000, 1000

Output

15000

Explanation

The vaults 1, 5, 6 are looted, giving a total loot of (1000+5000+9000)=15000

Example 2

Input

10

1000,2000,3000,5000,9000,7000,6000,4000,7000,5000

Output

26000

Explanation

There are 10 vaults arranged in a circle. The amounts in the vaults are 1000, 2000, .. 5000.

One way of getting the maximum is to loot vaults 4, 5, 9 and 10 giving a total of 26000. Hence the output is 26000. Note that no 5 adjacent vaults have more than 2 looted.

*/
