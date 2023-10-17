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

int helperTopDown(string str, int n, int i, vector<int>& dp) {

	// lookup

	if (dp[i] != -1) {
		return dp[i];
	}


	// base case

	if (i == n) {
		return dp[i] = 1;
	}

	// recursive case

	// count the no. of palindromic partitioning of str[i...n-1]

	int count = 0;

	// decide the next cut

	for (int j = i; j < n; j++) {

		// can you make a cut at the jth index

		string subString = str.substr(i, j - i + 1);
		if (isPalindrome(subString)) {
			// make a cut at the jth index
			count += helperTopDown(str, n, j + 1, dp);
		}

	}

	return dp[i] = count;

}

int main() {

	string str = "abaaa";
	int n = str.size();

	vector<int> dp(n + 1, -1);
	cout << helperTopDown(str, n, 0, dp) << endl;

	return 0;
}