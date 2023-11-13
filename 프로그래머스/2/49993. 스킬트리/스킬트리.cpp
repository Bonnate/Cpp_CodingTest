#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

bool contains(string skill, char element)
{
    for(char c : skill)
        if(c == element)
            return true;
        return false;
}

int solution(string skill, vector<string> skill_trees) {
    
    int answer = 0;
    
    map<char, int> m;
    for(int i = 0; i < skill.size(); ++i)
        m[skill[i]] = i;
    
    for(string s : skill_trees)
    {
        string v;
        
        for(char c : s)
            if(contains(skill, c))
                v.push_back(c);
        
        for(char c : skill)
           if(!contains(v, c))       
               v.push_back(c);
        
        bool success = true;
        for(int i = 1; i < v.size(); ++i)
            if(m[v[i - 1]] > m[v[i]])
            {
                success = false;
                break;
            }
        
        if(success)
            ++answer;
    }
    
    return answer;
}