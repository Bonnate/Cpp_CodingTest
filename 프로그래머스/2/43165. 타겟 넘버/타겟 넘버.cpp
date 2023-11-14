#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool ch[20];
int answer = 0;

void DFS(vector<int> numbers, int target, int p = 0)
{
    if(p == numbers.size())
    {
        for(int i = 0; i < numbers.size(); ++i)
            target += ch[i] ? +numbers[i] : - numbers[i];
        
        if(!target)
            ++answer;
    }
    else
    {
        for(int i = 0; i < 2; ++i)
        {
            ch[p] = i;
            DFS(numbers, target, p + 1);
        }
    }
}

int solution(vector<int> numbers, int target) {
    
    DFS(numbers, target);
    
    return answer;
}