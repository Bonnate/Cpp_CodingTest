#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    
    sort(people.begin(), people.end());
    int front = 0;
    int rear = people.size() - 1;
    
    int answer = 0;
    
    while(front <= rear)
    {
        if(people[rear] + people[front] <= limit)
        {
            ++front;
            --rear;
        }
        else
        {
            --rear;
        }
        
        ++answer;
    }
    
    return answer;
}