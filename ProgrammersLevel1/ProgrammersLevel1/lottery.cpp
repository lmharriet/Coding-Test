#include <iostream>
#include <vector>
#include <unordered_map>

#define LOTTERY_SIZE   6
using namespace std;


vector<int> LotteryRanking(vector<int> lottos, vector<int> win_nums) {
	unordered_map<int, int> lotteryRanking;

	for (int i = LOTTERY_SIZE; i >= 0; i--)
	{
		if (i < 2)
		{
			lotteryRanking.emplace(i, LOTTERY_SIZE); // 1개 또는 0개를 맞추면 6등
			continue;
		}
		lotteryRanking.emplace(i, LOTTERY_SIZE - (i - 1)); //6개를 맞추면 1등
	}

	int winNumCount = 0, zeroNumCount = 0;

	for (int i = 0; i < LOTTERY_SIZE; i++)
	{
		for (int j = 0; j < LOTTERY_SIZE; j++)
		{
			if (lottos[j] == 0)
				continue; // 0이면 아래에서 처리

			if (win_nums[i] == lottos[j])
			{
				winNumCount++;
				continue; //같은 번호는 들어있지 않으므로 찾으면 바로 다음 숫자 검색
			}
		}

		if (lottos[i] == 0)
		{
			zeroNumCount++;
		}
	}

	//cout << "최고 등수 :" << lotteryRanking[winNumCount + zeroNumCount] << '\n';
	//cout << "최저 등수 :" << lotteryRanking[winNumCount] << '\n';

	if (zeroNumCount == LOTTERY_SIZE)
		return { 1,6 }; //모든 알아볼 수 없는 숫자가 0일 때, 전체를 다 맞출 가능성과 전체를 다 틀릴 가능성이 있으므로


	return { lotteryRanking[winNumCount + zeroNumCount] ,lotteryRanking[winNumCount] };
}

//int main()
//{
//	LotteryRanking({ 44, 1, 0, 0, 31, 25 }, { 31, 10, 45, 1, 6, 19 }); // return 3,5;
//	LotteryRanking({ 0, 0, 0, 0, 0, 0 }, { 38, 19, 20, 40, 15, 25 });
//
//
//	return 0;
//}