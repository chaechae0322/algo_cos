// You may use include as below.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool possible(char x, char y)
{
	return ( x >= 'A' && x <= 'H' && y >= '1' && y <= '8');
}

int solution(char* pos) {
    // Write code here.
    int answer = 0;
	char dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	char dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

	for(int i = 0; i < 8; i++)
		if(possible(pos[0] + dx[i], pos[1] + dy[i])) answer++;
	
    return answer;
}

// The following is main function to output testcase.
int main() {
    char* pos = "A7";
    int ret = solution(pos);

    // Press Run button to receive output. 
    printf("Solution: return value of the function is %d .\n", ret);
}