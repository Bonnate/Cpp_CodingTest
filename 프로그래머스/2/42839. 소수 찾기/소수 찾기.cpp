#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int sel[7];
bool ch[7];
vector<bool> v;
set<string> duplicatedSet;
int answer = 0;

void DFS(string numbers, int select, int s)
{
    if(s == select)
    {
        string num;
        for(int i = 0; i < select; ++i)
            num.push_back(numbers[sel[i]]);
            
        while(num.size() > 0)
            if(num[0] == '0')
                num.erase(0, 1);
            else
                break;
        
        if(num.size() > 0 && duplicatedSet.find(num) == duplicatedSet.end())
        {
            duplicatedSet.insert(num);
            if(v[stoi(num)])
                ++answer;
        }
    }
    else
    {
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(!ch[i])
            {
                ch[i] = true;
                sel[s] = i;
                DFS(numbers, select, s + 1);
                ch[i] = false;
            }
        }
    }
}

int solution(string numbers) {

    sort(numbers.begin(), numbers.end(), greater<int>());
    int num = stoi(numbers);

    v = vector<bool>(num, true);
    v[0] = v[1] = false;
    
    for(int i = 2; i <= sqrt(num); ++i)
        for(int j = i * 2; j <= num; j += i)
            v[j] = false;
    
    for(int i = 1; i <= numbers.size(); ++i)
        DFS(numbers, i, 0);
    
    return answer;
}