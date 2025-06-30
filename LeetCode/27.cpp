#include <iostream>
#include <vector>
using namespace std;


int removeElement(vector<int>& nums, int val) {
        
    int i = 0;
    int j = nums.size() - 1;

    while(i <= j)
    {
        if(nums[j] == val)
        {
            --j;
            continue;
        }

        if(nums[i] == val) std::swap(nums[i], nums[j--]);

        ++i;
    }

    return ++j;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
