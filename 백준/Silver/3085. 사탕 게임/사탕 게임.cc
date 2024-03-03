// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

char board[50][50];
int N;
int ans = INT_MIN;

int dx[4] { -1, +1, 0 ,0 };
int dy[4] { 0, 0, -1, +1 };

void check() {
	char c;
	for (int i = 0; i < N; i++) { // 행 계산
		int count = 1; // 1개부터 시작
		c = board[i][0];
		for (int j = 1; j < N; j++) {
			if ((board[i][j] == c)) {
				count += 1;
			}
			else count = 1;
			c = board[i][j];
			if (count > ans) ans = count;
		}
	}

	for (int j = 0; j < N; j++) { // 열 계산
		int count = 1;
		c = board[0][j];
		for (int i = 1; i < N; i++) {
			if ((board[i][j] == c)) {
				count += 1;
			}
			else count = 1;
			c = board[i][j];
			if (count > ans) ans = count;
		}
	}
}

int main() {
    cin >> N;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> board[i][j];
            
    for(int y = 0; y < N; ++y) // col
        for(int x = 0; x < N; ++x) // row
            for(int k = 0; k < 4; ++k) // 4 path
            {
                // 각 방향을 구하기
                int ddy = y + dy[k];
                int ddx = x + dx[k];
                
                // 벗어난경우 무시
                if(ddy < 0 || ddx < 0 || ddy == N || ddx == N)
                    continue;
                    
                // swap 후 개수를 계산한 후 다시 되돌리기
                swap(board[y][x], board[ddy][ddx]);
                check();
                swap(board[y][x], board[ddy][ddx]);
            }
            
    printf("%d", ans);

    return 0;
}