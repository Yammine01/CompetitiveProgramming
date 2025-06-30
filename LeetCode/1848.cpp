#include <iostream>
#include <algorithm>
#include <vector>


int getMinDistance(std::vector<int>& nums, int target, int start)
{
    int minDistance = nums.size();

    int i = start, j = start;

    while(true)
    {
        if(i < nums.size() && nums[i++] == target) return std::abs(i - start) - 1;
        if(j < 0 && nums[j--] == target) return std::abs(i - start) - 1;
    }
}


int main(int argc, const char *argv[])
{
    std::vector<int> v = {1, 2, 3, 2, 2, 5, 4, 3, 4, 6, 7, 5, 9};

    std::cout << getMinDistance(v, 5, 4) << std::endl;

    return 0;
}
