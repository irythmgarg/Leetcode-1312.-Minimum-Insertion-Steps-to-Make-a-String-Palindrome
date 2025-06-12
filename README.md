# Leetcode-1312.-Minimum-Insertion-Steps-to-Make-a-String-Palindrome

# 🧵 Leetcode 1312: Minimum Insertion Steps to Make a String Palindrome

This problem focuses on determining the **minimum number of insertions** required to transform a given string into a palindrome. Let's explore all the major approaches to solving it, starting from basic recursion to efficient dynamic programming. 💡

---

## 📘 Problem Statement

Given a string `s`, return the **minimum number of characters** that need to be inserted to make `s` a palindrome.

---

## 🌀 Approach 1: Pure Recursion

### 🔍 Idea:

* Try to match characters at the beginning (`i`) and end (`j`) of the string.
* If characters match, move both inward.
* If not, insert a character and take the minimum of inserting at start or end.

### 🧠 Recursive Logic:

```cpp
int hlo(string &s, int i, int j) {
    if (i > j) return 0;
    if (s[i] == s[j]) return hlo(s, i + 1, j - 1);
    return 1 + min(hlo(s, i + 1, j), hlo(s, i, j - 1));
}
```

### ❗ Drawbacks:

* Exponential Time Complexity: **O(2^n)**
* Inefficient for long strings

---

## 🧠 Approach 2: Top-Down DP (Memoization)

### 💡 Idea:

* Use a memoization table `dp[i][j]` to cache results of overlapping subproblems.
* Avoid redundant computation.

### ⚙️ Logic:

```cpp
int dp[501][501];
int hlo(string &s, int i, int j) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j]) return dp[i][j] = hlo(s, i + 1, j - 1);
    return dp[i][j] = 1 + min(hlo(s, i + 1, j), hlo(s, i, j - 1));
}
```

### 🧮 Complexity:

* Time: **O(n^2)**
* Space: **O(n^2)** (for memo table)

---

## 🧊 Approach 3: Bottom-Up DP (Tabulation)

### 🔍 Idea:

* Use a 2D DP table to build solution from substrings.
* If characters match: `dp[i][j] = dp[i+1][j-1]`
* Else: `dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1])`

### 💻 Code Sketch:

```cpp
vector<vector<int>> dp(n, vector<int>(n, 0));
for (int l = 2; l <= n; l++) {
    for (int i = 0; i <= n - l; i++) {
        int j = i + l - 1;
        if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
        else dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
    }
}
```

### 📈 Complexity:

* Time: **O(n^2)**
* Space: **O(n^2)**

---

## 📝 Final Thoughts:

* This problem can be viewed as the complement of the **Longest Palindromic Subsequence**.
* Another alternative solution: `n - LPS(s)`
* Practice both recursive and iterative DP to get better at dynamic programming patterns.

---

**Made with ❤️ by Ridham Garg**
