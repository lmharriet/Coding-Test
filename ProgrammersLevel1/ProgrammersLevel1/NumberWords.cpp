#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool CheckIsNumber(char c)
{
	if (static_cast<int>(c) >= 'a' && static_cast<int>(c) <= 'z')
		return true;
	return false;
}

int NumberWords(string s) {
	int answer = 0;
	unordered_map<string, string> numberFormat = { {"zero","0" }, {"one","1" },  {"two","2" },
		{"three","3" },  {"four","4" },  {"five","5" },  {"six","6" },  {"seven","7" },  {"eight","8" },  {"nine","9" } };
	string check = "", number = "";

	for (int i = 0; i < s.length(); i++)
	{
		if (CheckIsNumber(s[i]) == true)
		{
			check += s[i];

			if (numberFormat.count(check) <= 0)
				continue;

			number += numberFormat[check];
			check = "";
		}
		else
		{
			number += s[i];
		}
	}

	answer = stoi(number);
	return answer;
}

int main()
{
	cout << NumberWords("one4seveneight") << '\n';
	cout << NumberWords("23four5six7") << '\n';
	cout << NumberWords("2three45sixseven") << '\n';
	cout << NumberWords("123") << '\n';
	return 0;
}