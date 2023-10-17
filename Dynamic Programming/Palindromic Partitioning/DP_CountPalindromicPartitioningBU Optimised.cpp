#include<iostream>
#include<vector>

using namespace std;

// time : O(n^2 + n^2) ~ O(n^2)
// space : O(n^2 + n) ~ O(n^2)

int helperBottomUpOptimised(string str, int n) {

	vector<vector<bool>> memo(n, vector<bool>(n));

	for (int i = 0; i < n; i++) {
		int j = i;
		memo[i][j] = true;
	}

	for (int i = 0; i < n - 1; i++) {
		int j = i + 1;
		memo[i][j] = str[i] == str[j] ? true : false;
	}

	for (int i = n - 3; i >= 0; i--) {
		for (int j = i + 2; j < n; j++) {
			// memo[i][j] = check if str[i...j] is a palindrome
			memo[i][j] = str[i] == str[j] and memo[i + 1][j - 1];
		}
	}

	vector<int> dp(n + 1);

	dp[n] = 1; // at the nth index of dp[], we store f(n)

	for (int i = n - 1; i >= 0; i--) {

		// count the no. of palindromic partitioning of str[i...n-1]

		int count = 0;

		for (int j = i; j < n; j++) {

			if (memo[i][j]) {
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

	cout << helperBottomUpOptimised(str, n) << endl;

	return 0;
}