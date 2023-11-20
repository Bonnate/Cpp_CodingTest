#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    if(board.size() == 1 || board[0].size() == 1)
    {
        bool isEscape = true;
        
        for(int i = 0; i < board.size() && isEscape; ++i)
            for(int j = 0; j < board[0].size(); ++j)
                if(board[i][j] == 1)
                {
                    isEscape = false;
                    break;
                }
    
        if(isEscape)
            return 0;
        else
            return 1;
    }
    
    for(int i = 1; i < board.size(); ++i)
    {
        for(int j = 1; j < board[0].size(); ++j)
        {
            if(board[i][j])
            {
                board[i][j] = 1 + min({board[i-1][j-1],board[i-1][j],board[i][j-1]});
                answer = max(answer, board[i][j] * board[i][j]);
            }
        }
    }
    
    return answer;
}