#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(string s) {
	int i = 0;
	int j = s.size() - 1;

	while (i < j) {
		if (s[i] != s[j]) {
			// 's' is not a palindrome
			return false;
		}
		i++;
		j--;
	}

	// 's' is a palindrome
	return true;
}

// time : O(n^3)
// space : O(n)

int helperBottomUp(string str, int n) {

	vector<int> dp(n + 1);

	dp[n] = 1; // at the nth index of dp[], we store f(n)

	for (int i = n - 1; i >= 0; i--) {

		// count the no. of palindromic partitioning of str[i...n-1]

		int count = 0;

		for (int j = i; j < n; j++) {

			string subString = str.substr(i, j - i + 1);
			if (isPalindrome(subString)) {
				count += dp[j + 1];
			}

		}

		dp[i] = count;

	}

	return dp[0]; // at the 0th index of dp[], we store f(0)

}

int main() {

	string str = "abaaa";
	int n = str.size();

	cout << helperBottomUp(str, n) << endl;

	return 0;
}