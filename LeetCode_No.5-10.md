# LeetCode No.5-10

## 5. 最长回文子串
~~~C++
string longestPalindrome(string s)
{
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length()));
    int maxLen = 0;
    string maxPal = "";
    for (int len = 1; len <= s.length(); len++) //遍历所有的长度
        for (int start = 0; start < s.length(); start++)
        {
            int end = start + len - 1;
            if (end >= s.length())
                break;

            dp[start][end] = (len == 1 || len == 2 || dp[start + 1][end - 1]) && s[start] == s[end]; //长度为 1 和 2 的单独判断下
            if (dp[start][end] && len > maxLen)
            {
                maxPal = s.substr(start, end - start + 1);
                //maxLen = len;
            }
        }
    return maxPal;
}
~~~
动态规划思路记录
