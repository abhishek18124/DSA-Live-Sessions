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

vector<string> p;

int countPalindromicPartitioning(string str, int n, int i) {

	// base case

	if (i == n) {
		for (string s : p) {
			cout << s << " ";
		}
		cout << endl;
		return 1;
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
			p.push_back(subString);
			count += countPalindromicPartitioning(str, n, j + 1);
			p.pop_back(); // backtracking
		}

	}

	return count;

}

int main() {

	string str = "abaaa";
	int n = str.size();

	cout << countPalindromicPartitioning(str, n, 0) << endl;

	return 0;
}