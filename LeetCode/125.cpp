#include <iostream>
#include <algorithm>
using namespace std;


bool isPalindrome(string s) {
    if(s.size() == 1) return true;

    int i = 0, j = s.size() - 1;
    while(i <= j) {
        while(i < j && !isalnum(s[i])) ++i;
        while(j > i && !isalnum(s[j])) --j;

        if(tolower(s[i]) != tolower(s[j])) return false;

        ++i; --j;
    }
    return true;
}


int main(int argc, char const *argv[])
{
    string s = "P0p";

    cout << (isPalindrome(s) ? "YES" : "NO");

    return 0;
}
