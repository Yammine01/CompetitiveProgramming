#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


vector<int> partitionLabels(string s)
{
    std::array<int, 26> span; span.fill(-1);
    std::vector<std::pair<int, int>> intervals;

    for(int i = 0; i < s.size(); ++i)
    {
        const char letter = s[i];
        if(span[letter - 97] == -1)
        {
            intervals.push_back({i, i});
            span[letter - 97] = intervals.size() - 1;
        }
        else
        {
            intervals[span[letter - 97]].second = i;
        }
    }

    std::vector<int> answer;
    std::pair<int, int> current = intervals[0];

    for(int i = 1; i < intervals.size(); ++i)
    {
        std::pair<int, int> next = intervals[i];

        if(current.second > next.first)
        {
            current.second = std::max(current.second, next.second);
            continue;
        }

        answer.push_back(current.second - current.first + 1);
        current = intervals[i];
    }
    answer.push_back(current.second - current.first + 1);
    return answer;
}


int main(int argc, char const *argv[])
{
    string s ="ababcbacadefegdehijhklij";
    vector<int> v = partitionLabels(s);

    for(int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
    
    return 0;
}
