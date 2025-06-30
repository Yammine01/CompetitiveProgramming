#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>


int countWords(vector<string>& words1, vector<string>& words2) {
    std::unordered_map<std::string, int> occ;

    std::for_each(words1.begin(), words1.end(),
    [&occ] (const std::string& word)
    {
        ++occ[word];
    }
    );

    std::for_each(words2.begin(), words2.end(),
    [&occ] (const std::string& word)
    {
        if(occ[word] < 2) --occ[word];
    }
    );

    return count_if(occ.begin(), occ.end(),
    [] (const std::pair<std::string, int> pair)
    {
        return pair.second == 0;
    });
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
