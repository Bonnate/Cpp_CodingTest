#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    
    if(s.size() == 1)
        return 1;
    
    int answer = 1001;
    string s1 = "", s2 = "";
    int id = 0;
    
    for(int i = 1; i <= s.size() / 2; ++i)
    {
        string check = "";
        int streak = 1;
        
        for(int j = 0; j < i; ++j)
            s2.push_back(s[j]);
        
        for(int j = i; j < s.size(); j += i)
        {          
            for(int k = 0; k < i; ++k)
                if(j + k < s.size())
                    s1.push_back(s[j + k]);
             
            if(s1.compare(s2) == 0)
                ++streak;
            else
            {
                if(streak > 1)
                    check += to_string(streak);
                check += s2;
                streak = 1;
            }
                        
            s2 = s1;
            s1.erase(0);
        }
              
        if(streak > 1)
            check += to_string(streak);
        check += s2;
        
        answer = min(answer, (int)check.size());
        
        check.clear();
        s2.erase(0);
    }
    

    return answer;
}