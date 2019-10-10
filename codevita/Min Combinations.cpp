#include<stdio.h>
#include<math.h>
int main(){
	int times = 0;
	scanf("%d",&times);
	while (times != 0){
		int n1, n2;
		long int a = 1, b = 1;
		//a = 999999999;
		long long int result;
		scanf("%d",&n1);
		scanf("%d",&n2);
		int ai = 1, bi = 1;
		//printf("%d",a);
		long long int min = 9999999999999;
		long long int localmin = 9999999999999;
		
		while(1){
			
			result = n1 * a - n2 * b;
			result = abs(result);
			if (result < localmin){
				if (result < min){
					min = result;
					ai = a;
					bi = b;
					//printf("a:%d\tb:%d\tmin%d\n",a,b,min);
				}
				localmin = result;
			}
			else{
				a++;
				b = 0;
				localmin = 9999999999999;
			}
			b++;
			//printf("a:%d\tb:%d\tr:%ld\tmin%d\tlocal%d\t", a, b, result, min, localmin);
			//printf("\n");
			if (a >= 10000000 || b >= 10000000){
				break;
			}
		}
		printf("%d, %d, %d\n", ai, bi, min);
		//printf("%d %d",ai ,bi);
		//printf("%lld %lld",localmin ,min);
		times--;
	}
	return 0;
} 

/*
Min Combinations
	Problem Description
Alexander The great, while roaming the stretch of Turkey, came across a wise man.

He asked the wise man, "Who is the greatest conqueror of all?". The wise man replied, "A person with great strength and intelligence. Whosoever can solve my puzzle will go on to become the greatest!". The puzzle is as follows; Given two integers 'n1' and 'n2', select two integers 'a' and 'b', such as to solve the equation (n1 * a + n2 * b = x). But there is a catch, 'x' is the smallest positive integer which satisfies the equation. Can you help Alexander become the greatest?

	Constraints
1 <= T <= 1000

-10^7 <= a, b <= 10^7

0 <= n1, n2 <= 10^7

	Input Format
The first line contains the number of Test cases T.

Next T lines contains two space-separated integers, n1 and n2.

	Output
Print the value of x.

	Test Case

	Explanation
Example 1

Input

1

34818 45632

Output

2

Explanation

Given n1 = 34818 and n2 = 45632, if we choose a = 3553 and b = -2711, we get

=> n1 * a + n2 * b = x

=> 34818 * 3553 + 45632 * (-2711)

=> 2

Note: No other value of a and b, within the range, will give smaller value than 2.
*/
