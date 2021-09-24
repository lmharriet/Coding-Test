#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*

최댓값과 최솟값

문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다.
str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 "(최소값) (최대값)"형태의 문자열을 반환하는 함수, solution을 완성하세요.
예를들어 s가 "1 2 3 4"라면 "1 4"를 리턴하고, "-1 -2 -3 -4"라면 "-4 -1"을 리턴하면 됩니다.

*/

int CalculateASCIINum(const string& s)
{
	int num = 0;
	int squarenum = s.length() - 1;
	for (const char c : s)
	{
		num += atoi(&c) * pow(10, squarenum);
		squarenum--;
	}

	return num;
}
string solution(string s) {
	string answer = "";
	vector<int> nums;
	int asciiNum = 0;
	bool bMinus = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '-')
		{
			bMinus = true;
			continue;
		}

		if (s[i] == ' ' || i == s.length() - 1)
		{
			if (i == s.length() - 1)
				answer += s[i];

			asciiNum = CalculateASCIINum(answer);

			if (bMinus == true)
			{
				asciiNum *= -1;
				bMinus = false;
			}

			nums.emplace_back(asciiNum);

			answer = "";
			asciiNum = 0;
			continue;
		}

		answer += s[i];
	}

	sort(nums.begin(), nums.end());

	return { to_string(nums[0]) + " " + to_string(nums[nums.size() - 1]) };
}

int main()
{
	cout << solution("1 2 3 4") << '\n';
	cout << solution("-1 -2 -3 -4") << '\n';
	cout << solution("11 21 31 41");
	return 0;
}