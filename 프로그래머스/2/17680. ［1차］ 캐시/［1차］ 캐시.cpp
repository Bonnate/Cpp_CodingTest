#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    set<string> s;
    vector<string> v;
    
    for(string _s : cities)
    {
        transform(_s.begin(), _s.end(), _s.begin(), [](char c) { return tolower(static_cast<unsigned char>(c)); });
        v.push_back(_s);
        
        if(s.find(_s) != s.end()) // cache hit
        {
            ++answer;
            
            auto it = find(v.begin(), v.end(), _s);
            if(it != v.end())
                v.erase(it);
        }
        else // cache miss
        {
            answer += 5;
            
            if(s.size() >= cacheSize)
            {
                s.erase(*v.begin());    
                v.erase(v.begin());
            }
            
            if(cacheSize != 0)
                s.insert(_s);
        }
    }
    
    return answer;
}