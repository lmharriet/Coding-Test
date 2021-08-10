#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


#pragma region weekly challenge_1 (부족한 금액 계산하기)
//
//long long solution(int price, int money, int count)
//{
//	long long answer = -1, multiple = 0;
//
//	for (long long i = 1; i <= count; i++)
//	{
//		multiple += (price * i);
//	}
//
//	answer = (money - multiple < 0) ? (money - multiple) * -1 : 0;
//	return answer;
//}

#pragma endregion

#pragma region weekly challenge_2(상호 평가)

char GetGrade(float InScore)
{
	if (InScore >= 90) return 'A';
	if (InScore >= 80) return 'B';
	if (InScore >= 70) return 'C';
	if (InScore >= 50) return 'D';

	return 'F';
}
string solution(vector<vector<int>> scores) {
	string answer = "";
	unordered_map<int, int> myself;
	vector<int> row;
	int sameScoreCount = 0;
	float Avg = 0;
	bool isMinMax = false;

	for (int i = 0; i < scores.size(); i++)
	{
		myself[i] = scores[i][i];

		for (int j = 0; j < scores[i].size(); j++)
		{
			row.emplace_back(scores[j][i]);
			Avg += scores[j][i];

			if (myself[i] == scores[j][i]) //내가 유일하게 나한테 최고점 혹은 최저점을 준 게 아닐 수 있으니 같은 점수 체크
			{
				sameScoreCount++;
			}
		}

		sort(row.begin(), row.end());


		if (myself[i] == row[0] || myself[i] == row[row.size() - 1])
		{
			if (isMinMax == false && sameScoreCount <= 1)
			{
				Avg -= myself[i];
				isMinMax = true;
			}
		}

		answer += GetGrade(Avg / (scores.size() - static_cast<int>(isMinMax)));

		//데이터 초기화
		row.clear();
		Avg = 0;
		sameScoreCount = 0;
		isMinMax = false;
	}

	return answer;
}
#pragma endregion



int main()
{
	//weekly challenge_1(부족한 금액 계산하기)
	//cout << solution(3, 20, 4);

	//weekly challenge_2(상호 평가)
	cout << solution({ { 100,90,98,88,65 }, { 50,45,99,85,77 }, { 47,88,95,80,67 }, { 61,57,100,80,65 }, { 24,90,94,75,65 } });
	cout << solution({{ 50,90 }, { 50,87 }});
	cout << solution({ {70,49,90 }, { 68,50,38 },{73,31,100} });

	return 0;
}