#include <iostream> // 표준입출력스트림
#include <cstdlib> // 랜덤값 사용을 위해
#include <ctime> // srand()호출에 이용
using namespace std;

int main(void)
{
	int size, row, col, random, black = 0;
	// size = 바둑판 크기, row = 행, col = 열, random = 난수, black = 죽는 검은돌 개수
	cout << "바둑판의 크기를 입력하세요 : ";
	cin >> size;
	row = size; col = size;
	char **board = new char *[size]; // 이차원 배열
	srand((unsigned int)time(NULL)); // 실행할 때마다 다른 난수를 사용하기 위해

	if (size >= 7) {
		for (int j = 0; j < row; j++) // 동적 메모리 할당
			board[j] = new char[col];

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				random = rand();
				if (random % 3 == 0) {
					board[i][j] = 'b'; // 'b'는 흑돌
					cout << "●";
				}
				else {
					board[i][j] = 'w'; // 'w'는 백돌
					cout << "○";
				}
			}
			cout << endl;
		}
	}

	for (int k = 0; k < size; k++) { // 바둑판 모서리 흑돌을 필요없는 돌로 인식
		if (board[0][k] == 'b')
			board[0][k] = 'n'; // 필요없는 돌은 'n'
		if (board[row - 1][k] == 'b')
			board[row - 1][k] = 'n';
		if (board[k][0] == 'b')
			board[k][0] = 'n';
		if (board[k][col - 1] == 'b')
			board[k][col - 1] = 'n';
	}

	for (int i = 1; i < col-1; i++) { // 1번 걸러내기 ↘
		for (int j = 1; j < row - 1; j++)
			if (board[i][j] == 'b')
				if ((board[i - 1][j] == 'n') || (board[i + 1][j] == 'n')
					|| (board[i][j - 1] == 'n') || (board[i][j + 1] == 'n'))
					board[i][j] = 'n';
	}
	for (int i = 1; i < col - 1; i++) { // 2번 걸러내기 ↙
		for (int j = row - 1; j > 1; j--)
			if (board[i][j] == 'b')
				if ((board[i - 1][j] == 'n') || (board[i + 1][j] == 'n')
					|| (board[i][j - 1] == 'n') || (board[i][j + 1] == 'n'))
					board[i][j] = 'n';
	}
	for (int j = 1; j < row - 1; j++) { // 3번 걸러내기 ↗
		for (int i = col - 1; i > 1; i--)
			if (board[i][j] == 'b')
				if ((board[i - 1][j] == 'n') || (board[i + 1][j] == 'n')
					|| (board[i][j - 1] == 'n') || (board[i][j + 1] == 'n'))
					board[i][j] = 'n';
	}
	for (int j = row - 1; j > 1; j--) { // 4번 걸러내기 ↖
		for (int i = col - 1; i > 1; i--)
			if (board[i][j] == 'b')
				if ((board[i - 1][j] == 'n') || (board[i + 1][j] == 'n')
					|| (board[i][j - 1] == 'n') || (board[i][j + 1] == 'n'))
					board[i][j] = 'n';
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++)
			if (board[i][j] == 'b') // 죽은 검은돌 세기
				black++;
	}
	cout << endl;
	cout << "흑 돌이 " << black << "개 죽었습니다" << endl; // 결과

	// 동적 메모리 해제
	for (int j = 0; j < row; j++)
		delete[] board[j];
	delete[] board;

	return 0;
}