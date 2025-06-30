#include <iostream>
#include <algorithm>
#include <vector>


vector<int> sortArrayByParityII(vector<int>& nums) {
    std::vector<int> ans(nums.size());

    int i = 0, j = 1;

    std::for_each(nums.begin(), nums.end(),
    [&i, &j, &ans](int n)
    {
        int &k = n % 2 == 0 ? i : j;
        ans[k] = n;
        k += 2;
    });
    return ans;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
