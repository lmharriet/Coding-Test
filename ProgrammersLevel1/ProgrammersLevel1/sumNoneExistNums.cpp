#include <iostream>
#include <vector>

/*
없는 숫자 더하기

0부터 9까지의 숫자 중 일부가 들어있는 배열 numbers가 매개변수로 주어집니다. 
numbers에서 찾을 수 없는 0부터 9까지의 숫자를 모두 찾아 더한 수를 return 하도록 solution 함수를 완성해주세요.


풀이
0~9 모두 더하면 45
vector내부에 존재하는 숫자 더해서 45에서 뺀 값 리턴
*/


using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    for (const int num : numbers)
        answer += num;
  
    return 45-answer;
}

int main()
{
    cout << solution({ 1,2,3,4,6,7,8,0 })<<'\n';
    cout << solution({ 5,8,4,0,6,7,9 })<<'\n';

	return 0;
}