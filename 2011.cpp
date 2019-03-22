#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)

int main(int argc, char *argv[]) {
	freopen("test.txt", "r", stdin);
	long long dp[100000];
	string input;
	cin >> input;

	dp[0] = dp[1] = 1;
	if (input.size() > 1) {
		if (input.at(0) == '0') {
			std::cout << "0";
			return 0;
		}

		if (input.at(0) == '0' && input.at(1) == '0') {
			std::cout << "0";
			return 0;
		}
		if (input.at(0) >= '3' && input.at(1) == '0') {
			std::cout << "0";
			return 0;
		}

		if (input.at(0) == '1' && '0' < input.at(1) && input.at(1) <= '9') { // 한자리 두자리 둘다
			dp[1] = 2;
		}
		else if (input.at(0) == '2' && '0' < input.at(1) && input.at(1) <= '6') {
			dp[1] = 2;
		}

		for (int i = 2; i < input.size(); i++) {
			if (input.at(i - 1) == '0' && input.at(i) == '0') {
				std::cout << "0";
				return 0;
			}
			if (input.at(i - 1) >= '3' && input.at(i) == '0') {
				std::cout << "0";
				return 0;
			}

			if (input.at(i - 1) == '0') { //한자리만
				dp[i] = dp[i - 1];
			}
			else if (input.at(i - 1) >= '3' && input.at(i) >= '1') {
				dp[i] = dp[i - 1];
			}
			else if (input.at(i - 1) <= '2' && input.at(i) == '0') { // 두자리만
				dp[i] = dp[i - 2];
			}
			else if (input.at(i - 1) == '1' && input.at(i) <= '9') { // 한자리 두자리 둘다
				dp[i] = (dp[i - 1] + dp[i - 2])% 1000000;
			}
			else if (input.at(i - 1) == '2' && input.at(i) <= '6') {
				dp[i] = (dp[i - 1] + dp[i - 2])% 1000000;
			}
		}
	}
	std::cout << dp[input.size() - 1];
	return 0;
}