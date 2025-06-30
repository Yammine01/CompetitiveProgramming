#include <iostream>
#include <algorithm>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    std::fill(std::copy_if(nums.begin(), nums.end(), nums.begin(), [](int i){return i != 0;}), nums.end(), 0);
}

int main(int argc, char const *argv[])
{
    std::vector<int> v = {0,1,0,3,12};
    moveZeroes(v);

    std::for_each(v.begin(), v.end(), [](int i){std::cout << i << " ";});
    std::cout << std::endl;

    return 0;
}
