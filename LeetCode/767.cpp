#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cmath>
using namespace std;


struct element
{
    char letter;
    int freq;

    element(char c, int f) : letter(c), freq(f) {}
    
    bool operator<(const element& other) const{
        if(other.freq == freq) return other.letter < letter;
        return other.freq > freq;
    }
};


string reorganizeString(string s) {
    map<char, int> seen;
    
    for(auto c : s) {
        if(++seen[c] > ceil(s.size() / 2.0)) return "";
    }

    priority_queue<element> pq;

    for(auto& it : seen) {
        pq.emplace(it.first, it.second);
    }

    string answer = "";

    while(!pq.empty()) {
        element e1 = pq.top();
        pq.pop();
        answer += e1.letter;

        if(pq.empty()) break;

        element e2 = pq.top();
        pq.pop();
        answer += e2.letter;

        if(--e1.freq > 0) pq.push(e1);
        if(--e2.freq > 0) pq.push(e2);
    }
    
    return answer;
}


int main(int argc, char const *argv[])
{
    cout << reorganizeString("aaaaabbbb");

    return 0;
}