class Solution {
public:
    // Declare a memoization table for storing results of subproblems
    int dp[501][501];

    // Recursive helper function to calculate minimum insertions needed to make s[i..j] a palindrome
    int hlo(string &s, int i, int j) {
        // Base case: if left index crosses right, no insertion needed
        if (i > j)
            return 0;

        // Return previously computed result to avoid recomputation
        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters at both ends match, move inward
        if (s[i] == s[j]) {
            return dp[i][j] = hlo(s, i + 1, j - 1);
        } else {
            // If characters don’t match, take the minimum insertions required by:
            // (1) inserting a character at the beginning, or 
            // (2) inserting a character at the end
            return dp[i][j] = 1 + min(hlo(s, i, j - 1), hlo(s, i + 1, j));
        }
    }

    // Main function to find the minimum insertions to make the input string a palindrome
    int minInsertions(string s) {
        int n = s.length() - 1;

        // Initialize the dp array with -1 indicating uncomputed states
        memset(dp, -1, sizeof(dp));

        // Start recursive computation from the full string
        return hlo(s, 0, n);
    }
};
