
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
        {
            nums1.swap(nums2);
        }

        const int n = nums1.size();
        const int m = nums2.size();
        int left = 0, right = n;
        while (left <= right)
        {
            int i = (right - left + 1) / 2 + left;
            int j = (n + m + 1) / 2 - i;
            int nums1_1 = i > 0 ? nums1[i - 1] : INT_MIN;
            int nums1_2 = i < n ? nums1[i] : INT_MAX;
            int nums2_1 = j > 0 ? nums2[j - 1] : INT_MIN;
            int nums2_2 = j < m ? nums2[j] : INT_MAX;
            if (nums1_1 > nums2_2)
            {
                right = i - 1;
            }
            else if (nums2_1 > nums1_2)
            {
                left = i + 1;
            }
            else
            {
                int leftMax = max(nums1_1, nums2_1);
                int rightMin = min(nums1_2, nums2_2);
                if (0 != (n + m) % 2)
                {
                    return leftMax;
                }
                else
                {
                    return (leftMax + rightMin) / 2.0;
                }
            }
        }

        return 0.0;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1{  };
    vector<int> nums2{ 1 };
    std::cout.precision(4);
    std::cout << std::fixed << solution.findMedianSortedArrays(nums1, nums2) << std::endl;

    return 0;
}