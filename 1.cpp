#include <iostream> // 표준입출력스트림
#include <string>
using namespace std;

int main(void)
{
	string str; // 저장할 문자열
	int i, sum = 0; // sum = 입력 받은 문자열의 각 문자의 아스키코드 값의 합
	cout << "문자열을 입력하세요 : ";
	cin >> str; // 문자열 입력받음

	for (i = 0; i < str.length(); i++) { // 배열의 index는 0부터 시작
		sum += int(str[i]); // 각 문자의 아스키코드 값을 sum에 더해줌
		cout << int(str[i]) << " ";
		if (i < str.length() - 1) // 문자열의 끝이 아니라면 + 출력
			cout << "+";
	}
	cout << "= " << sum << endl; // sum 출력

	return 0;
}