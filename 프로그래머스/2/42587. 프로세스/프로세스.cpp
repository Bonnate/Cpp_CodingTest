#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    int answer = 0;
    int lastIdx = 0;
    for(int i = 9; i >= 0; --i)
    {
        int last = lastIdx;
        
        for(int j = 0; j < priorities.size(); ++j)
        {
            int idx = j + lastIdx;
            while(idx >= priorities.size())
                idx -= priorities.size();
            
            if(priorities[idx] == i)
            {
                ++answer;
                
                if(idx == location)
                    return answer;    
                
                last = idx;
            }
        }
        
        lastIdx = last;
    }
    
    return 0;
}