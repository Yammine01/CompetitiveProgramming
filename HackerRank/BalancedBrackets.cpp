#include <iostream>
#include <map>
#include <stack>
using namespace std;

string isBalanced(string s) {
    if(s.size() % 2 != 0) return "NO";

    map<char, char> brackets;
    brackets.insert({'(', ')'});
    brackets.insert({'[', ']'});
    brackets.insert({'{', '}'});

    stack<char> sequence;

    for(auto itr = brackets.begin(); itr != brackets.end(); ++itr) {
            if(s[0] == itr->second) return "NO";
    }
    sequence.push(s[0]);

    for(int i = 1; i < s.size(); ++i) {
        if(sequence.empty()) {
            sequence.push(s[i]);
            continue;
        }

        int temp_size = sequence.size();

        for(auto itr = brackets.begin(); itr != brackets.end(); ++itr) {
            if(s[i] == itr->second) {
                if(sequence.top() != itr->first) return "NO";
                sequence.pop();
                break;
            }
        }
        if(temp_size == sequence.size()) sequence.push(s[i]);
    }
    return sequence.empty() ? "YES" : "NO";
}


int main(int argc, char const *argv[])
{
    string s = "{(([])[])[]}";

    cout << isBalanced(s);

    return 0;
}
