#include <iostream>
#include <algorithm>
#include <vector>


std::vector<int> findAnagrams(const std::string& s, const std::string& p)
{
    if(p.size() > s.size()) return {};

    std::vector<int> pLetters(26, 0);
    std::vector<int> window(26, 0);
    for(int i = 0; i < p.size(); ++i)
    {
        ++pLetters[p[i] - 97];
        ++window[s[i] - 97];
    }

    std::vector<int> answer;
    int i = 0, j = p.size() - 1;
    if(pLetters == window) answer.push_back(0);

    while(j < s.size() - 1)
    {
        --window[s[i++] - 97];
        ++window[s[++j] - 97];

        if(pLetters == window) answer.push_back(i);
    }
    return answer;
}


int main(int argc, const char *argv[])
{
    
    return 0;
}
