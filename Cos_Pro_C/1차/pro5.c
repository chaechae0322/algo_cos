// You may use include as below.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int pane[103][103];
int inRange(int i, int j, int n){
    return 0 <= i && i < n && 0 <= j && j < n;
}
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int solution(int n) {
    // Write code here.
    int answer = 0;
	int ci = 0, cj = 0;
    int num = 1;
    while(inRange(ci, cj, n) && pane[ci][cj] == 0){
        for(int k = 0; k < 4; k++){
            if(!inRange(ci, cj, n) || pane[ci][cj] != 0) break;
            while(1){
                pane[ci][cj] = num++;
                int ni = ci + dy[k];
                int nj = cj + dx[k];
                if(!inRange(ni, nj, n) || pane[ni][nj] != 0){
                    ci += dy[(k + 1) % 4];
                    cj += dx[(k + 1) % 4];
                    break;
                } 
                ci = ni;
                cj = nj;
            }
        }
    }

	for(int i = 0; i < n; i++) answer += pane[i][i];

    return answer;
}

// The following is main function to output testcase.
int main() {
    int n1 = 3;
    int ret1 = solution(n1);
    
    // Press Run button to receive output. 
    printf("Solution: return value of the function is %d .\n", ret1);
    
    int n2 = 2;
    int ret2 = solution(n2);
    
    // Press Run button to receive output. 
    printf("Solution: return value of the function is %d .\n", ret2);
}