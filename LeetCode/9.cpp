#include <iostream>
#include <string>
using namespace std;

bool palindrome(int x) {
    string pal = to_string(x);

    int position = 0;

    while(position <= pal.size() / 2) {
        if(pal[position] != pal[pal.size() - 1 - position]) return false;
        ++position;
    }
    return true;
}


int main(int argc, char const *argv[])
{
    int x = -1;

    cout << x << (palindrome(x) ? " is palindrome" : " is not palindrome");

    return 0;
}
