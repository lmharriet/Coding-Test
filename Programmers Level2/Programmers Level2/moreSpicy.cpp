#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int moreSpicy(vector<int> scoville, int K) {
	priority_queue<int, vector<int>, greater<int>> pq;

	int count = 0;
	int minscoville = 0;

	for (const auto& iter : scoville)
	{
		if (iter < K)
		{
			pq.push(iter);
		}
	}

	while (!pq.empty())
	{
		minscoville = pq.top();
		pq.pop();
		if (minscoville >= K)
			break;
		if (pq.empty() == true)
			return -1;

		minscoville += (pq.top() * 2);
		pq.pop();
		pq.push(minscoville);
		count++;
	}

	return count;
}

int main()
{
	cout << moreSpicy({ 1,2,3,9,10,12 }, 7);
	//cout << moreSpicy({ 1,2,3,4,47 }, 100);
	return 0;
}