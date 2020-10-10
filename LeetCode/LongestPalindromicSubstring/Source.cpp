
// https://leetcode.com/problems/longest-palindromic-substring/
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void getSymmetry(string& s, size_t center, bool isEven, size_t& left, size_t& right)
    {
        if (isEven && s[center] != s[center + 1])
        {
            left = center, right = center;
            return;
        }
        else
        {
            left = center, right = isEven ? center + 1 : center;
            while (0 < left && right < s.size() && s[left - 1] == s[right + 1])
            {
                left--;
                right++;
            }
        }
    }

public:
    string longestPalindrome(string s) {
        // dp.. time complexity : O(n^2), space complexity : O(n^2)
        /*const size_t SIZE = s.size();
        vector<vector<char>> dp(SIZE, vector<char>(SIZE, 0));
        size_t left = 0, right = 0;
        for (size_t i = 0; i < SIZE; ++i)
        {
            for (size_t j = 0; j < i; ++j)
            {
                dp[j][i] = (s[i] == s[j]) && (i - j <= 2 || dp[j + 1][i - 1]);
                if (dp[j][i])
                {
                    if (i - j > right - left)
                    {
                        left = j;
                        right = i;
                    }
                }
            }
        }

        return s.substr(left, right - left + 1);*/

        if (s.empty())
        {
            return "";
        }
        else if (1 == s.size())
        {
            return s;
        }

        const size_t SIZE = s.size();
        size_t min = 0, max = 0;
        for (size_t i = 0; i < SIZE - 1; ++i)
        {
            size_t left, right;
            // even
            getSymmetry(s, i, true, left, right);
            if (right - left > max - min)
            {
                min = left;
                max = right;
            }
            // odd
            getSymmetry(s, i, false, left, right);
            if (right - left > max - min)
            {
                min = left;
                max = right;
            }
        }

        return s.substr(min, max - min + 1);
    }
};

int main()
{
    Solution solution;
    string ret = solution.longestPalindrome("babad");
    std::cout << ret << std::endl;

    return 0;
}
