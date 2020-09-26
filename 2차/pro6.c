// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(char* commands) {
    // 여기에 코드를 작성해주세요.
    int* answer;
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	int pos[] = {0,0};
	
	for(int i = 0; i < strlen(commands); i++)
	{
		switch(commands[i])
		{
			case 'L': pos[0] += dx[0];
					  pos[1] += dy[0];
					  break;
			case 'R': pos[0] += dx[1];
					  pos[1] += dy[1];
					  break;
			case 'U': pos[0] += dx[2];
					  pos[1] += dy[2];
					  break;
			case 'D': pos[0] += dx[3];
					  pos[1] += dy[3];
					  break;
		}	
	}
	answer = pos;
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    char* commands = "URDDL";
    int* ret = solution(commands);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 {");
    for(int i = 0; i < 2; i++){
        if (i != 0) printf(", ");
        printf("%d", ret[i]);
    }
    printf("} 입니다.\n");
}