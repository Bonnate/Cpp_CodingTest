#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int max = *max_element(priorities.begin(), priorities.end());
    
    while(true)
    {
        for(int i = 0; i < priorities.size(); ++i)
            if(priorities[i] == max)
            {
                ++answer;
                priorities[i] = -1;
                max = *max_element(priorities.begin(), priorities.end());

                if(i == location)    
                    return answer;
            }
    }
    
    return answer;
}