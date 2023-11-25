#include <vector>
#include <algorithm>

using namespace std;

void flip(vector<vector<int>>& map, int pos, bool isHorizontal)
{
    if(isHorizontal)
        for(int i = 0; i < map[0].size(); ++i)
            map[pos][i] = map[pos][i] ? 0 : 1;
    else
        for(int i = 0; i < map.size(); ++i)
            map[i][pos] = map[i][pos] ? 0 : 1;
}

bool compare(vector<vector<int>>& map, vector<vector<int>>& target)
{
    for(int i = 0; i < map.size(); ++i)
        for(int j = 0; j < map[0].size(); ++j)
            if(map[i][j] != target[i][j])
                return false;
       
    return true;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {

    // beginning == target인경우에는 0 리턴
    if(compare(beginning, target))
        return 0;
    
    int row = beginning.size();
    int col = beginning[0].size();
    
    // 행 -> 열 순서에서 행이 다른경우? flip
    int answer1 = 0;
    bool escape1 = false;
    bool success1 = false;
    vector<vector<int>> ch = beginning;
    for(int i = 0; i < row; ++i)
        if(ch[i][0] != target[i][0])
        {
            ++answer1;
            flip(ch, i, true);
            if(compare(ch, target))
            {
                escape1 = true;
                success1 = true;
                break;   
            }
        }
    if(!escape1)
        for(int i = 0; i < col; ++i)
            if(ch[0][i] != target[0][i])
            {
                ++answer1;
                flip(ch, i, false);
                if(compare(ch, target))
                {
                    success1 = true;
                    break;
                }
            }
    if(!success1)
        answer1 = -1;    
    
    // 열 -> 행 순서에서 열이 다른경우? flip
    int answer2 = 0;
    bool escape2 = false;
    bool success2 = false;
    ch = beginning;
    for(int i = 0; i < col; ++i)
        if(ch[0][i] != target[0][i])
        {
            ++answer2;
            flip(ch, i, false);
            if(compare(ch, target))
            {
                escape2 = true;
                success2 = true;
                break;   
            }
        }      
    if(!escape2)
        for(int i = 0; i < row; ++i)
            if(ch[i][0] != target[i][0])
            {
                ++answer2;
                flip(ch, i, true);
                if(compare(ch, target))
                {
                    success2 = true;
                    break;             
                }
            }
    if(!success2)
        answer2 = -1;    
    
    // 행 -> 열 순서에서 행이 같은경우? flip
    int answer3 = 0;
    bool escape3 = false;
    bool success3 = false;
    ch = beginning;    
    for(int i = 0; i < row; ++i)
        if(ch[i][0] == target[i][0])
        {
            ++answer3;
            flip(ch, i, true);
            if(compare(ch, target))
            {
                escape3 = true;
                success3 = true;
                break;   
            }
        }
    if(!escape3)
        for(int i = 0; i < col; ++i)
            if(ch[0][i] != target[0][i])
            {
                ++answer3;
                flip(ch, i, false);
                if(compare(ch, target))
                {
                    success3 = true;
                    break;
                }
            }
    if(!success3)
        answer3 = -1;    
    
    // 열 -> 행 순서에서 열이 같은경우? flip
    int answer4 = 0;
    bool escape4 = false;
    bool success4 = false;
    ch = beginning;    
    for(int i = 0; i < col; ++i)
        if(ch[0][i] == target[0][i])
        {
            ++answer4;
            flip(ch, i, false);
            if(compare(ch, target))
            {
                escape4 = true;
                success4 = true;
                break;   
            }
        }   
    if(!escape4)
        for(int i = 0; i < row; ++i)
            if(ch[i][0] != target[i][0])
            {
                ++answer4;
                flip(ch, i, true);
                if(compare(ch, target))
                {
                    success4 = true;
                    break;             
                }
            }
    if(!success4)
        answer4 = -1;
    
    return min({answer1, answer2, answer3, answer4});
}