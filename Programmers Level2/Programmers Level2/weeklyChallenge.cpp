#include <iostream>
#include <vector>
//#include <string>
//#include <unordered_map>
//#include <algorithm>

using namespace std;

//weekly challenge - 1
//부족한 금액 계산하기


long long solution(int price, int money, int count)
{
	long long answer = -1, multiple = 0;

	for (long long i = 1; i <= count; i++)
	{
		multiple += (price * i);
	}

	answer = (money - multiple < 0) ? (money - multiple) * -1 : 0;
	return answer;
}


int main()
{
	cout << solution(3, 20, 4);

	return 0;
}