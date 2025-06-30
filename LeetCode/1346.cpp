#include <iostream>
#include <algorithm>
#include <vector>


bool checkIfExist(std::vector<int>& arr) {
    std::unordered_set<int> seen;
    for(const int& num : arr)
    {
        if(seen.find(num * 2) != seen.end()) return true;
        if(num % 2 == 0 && seen.find(num / 2) != seen.end()) return true;
        seen.insert(num);
    }
    return false;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
