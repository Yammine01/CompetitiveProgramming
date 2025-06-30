#include <iostream>
#include <algorithm>
#include <vector>


int findKthPositive(std::vector<int>& arr, int k)
{
    int count = 0;

    auto itr = arr.begin();
    for(int i = 0; i < arr.size() + k; ++i)
    {
        if(k == count) return i;
        if(i != *itr) 
        {
            ++count;
            continue;
        }

       ++itr; 
    }
    return -1;
}


int main(int argc, const char *argv[])
{
    std::vector<int> v = {2, 3, 4, 7, 11};
    std::cout << findKthPositive(v, 5);
    return 0;
}
