class Solution {
public:
    // Recursive helper function to compute the minimum insertions 
    // needed to make the substring s[i..j] a palindrome
    int hlo(string &s, int i, int j) {
        // Base case: if left index crosses right, no insertions needed
        if (i > j)
            return 0;

        // If characters at both ends match, move inward
        if (s[i] == s[j]) {
            return hlo(s, i + 1, j - 1);
        } 
        else {
            // If characters differ, try both:
            // 1. Insert at start (i+1 to j)
            // 2. Insert at end (i to j-1)
            // Add 1 to account for the insertion
            return 1 + min(hlo(s, i, j - 1), hlo(s, i + 1, j));
        }
    }

    // Main function to find the minimum number of insertions 
    // needed to make the entire string a palindrome
    int minInsertions(string s) {
        int n = s.length() - 1;

        // Start the recursion from the full string
        return hlo(s, 0, n);
    }
};
