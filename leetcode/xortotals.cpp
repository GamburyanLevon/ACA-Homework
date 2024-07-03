#include <iostream>
#include <vector>

int subsetXORSum(std::vector<int> &nums)
{
    int s = nums.size();
    int totalSum = 0;

    int subsets = 1 << s;

    for (int i = 0; i < subsets; ++i)
    {
        int currentXOR = 0;
        for (int j = 0; j < s; ++j)
        {
            if (i & (1 << j))
            {
                currentXOR ^= nums[j];
            }
        }
        totalSum += currentXOR;
    }

    return totalSum;
}

int main()
{
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {5, 1, 6};
    std::vector<int> nums3 = {3, 4, 5, 6, 7, 8};

    std::cout << subsetXORSum(nums1) << std::endl;
    std::cout << subsetXORSum(nums2) << std::endl;
    std::cout << subsetXORSum(nums3) << std::endl;

    return 0;
}
