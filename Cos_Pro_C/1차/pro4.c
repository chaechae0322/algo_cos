// You may use include as below.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long num) {
    // Write code here.
	long long answer = 0;
	long long nx_num = num + 1;
	
	answer = nx_num;
	int cnt = 1;
	while(1)
	{
		if(nx_num == 0) break;
		if(nx_num % 10 == 0) answer += cnt;
		nx_num /= 10; 
		cnt *= 10;
	}
			
    return answer;
}

// The following is main function to output testcase.
int main() {
    long long num = 9949999;
    long long ret = solution(num);

    // Press Run button to receive output. 
    printf("Solution: return value of the function is %lld .\n", ret);
}