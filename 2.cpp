#include <iostream> // ǥ������½�Ʈ��
#include <cstdlib> // ������ ����� ����
#include <ctime> // srand()ȣ�⿡ �̿�
using namespace std;

int main(void)
{
	int size, row, col, random, black = 0;
	// size = �ٵ��� ũ��, row = ��, col = ��, random = ����, black = �״� ������ ����
	cout << "�ٵ����� ũ�⸦ �Է��ϼ��� : ";
	cin >> size;
	row = size; col = size;
	char **board = new char *[size]; // ������ �迭
	srand((unsigned int)time(NULL)); // ������ ������ �ٸ� ������ ����ϱ� ����

	if (size >= 7) {
		for (int j = 0; j < row; j++) // ���� �޸� �Ҵ�
			board[j] = new char[col];

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				random = rand();
				if (random % 3 == 0) {
					board[i][j] = 'b'; // 'b'�� �浹
					cout << "��";
				}
				else {
					board[i][j] = 'w'; // 'w'�� �鵹
					cout << "��";
				}
			}
			cout << endl;
		}
	}

	for (int k = 0; k < size; k++) { // �ٵ��� �𼭸� �浹�� �ʿ���� ���� �ν�
		if (board[0][k] == 'b')
			board[0][k] = 'n'; // �ʿ���� ���� 'n'
		if (board[row - 1][k] == 'b')
			board[row - 1][k] = 'n';
		if (board[k][0] == 'b')
			board[k][0] = 'n';
		if (board[k][col - 1] == 'b')
			board[k][col - 1] = 'n';
	}

	for (int i = 1; i < col-1; i++) { // 1�� �ɷ����� ��
		for (int j = 1; j < row - 1; j++)
			if (board[i][j] == 'b')
				if ((board[i - 1][j] == 'n') || (board[i + 1][j] == 'n')
					|| (board[i][j - 1] == 'n') || (board[i][j + 1] == 'n'))
					board[i][j] = 'n';
	}
	for (int i = 1; i < col - 1; i++) { // 2�� �ɷ����� ��
		for (int j = row - 1; j > 1; j--)
			if (board[i][j] == 'b')
				if ((board[i - 1][j] == 'n') || (board[i + 1][j] == 'n')
					|| (board[i][j - 1] == 'n') || (board[i][j + 1] == 'n'))
					board[i][j] = 'n';
	}
	for (int j = 1; j < row - 1; j++) { // 3�� �ɷ����� ��
		for (int i = col - 1; i > 1; i--)
			if (board[i][j] == 'b')
				if ((board[i - 1][j] == 'n') || (board[i + 1][j] == 'n')
					|| (board[i][j - 1] == 'n') || (board[i][j + 1] == 'n'))
					board[i][j] = 'n';
	}
	for (int j = row - 1; j > 1; j--) { // 4�� �ɷ����� ��
		for (int i = col - 1; i > 1; i--)
			if (board[i][j] == 'b')
				if ((board[i - 1][j] == 'n') || (board[i + 1][j] == 'n')
					|| (board[i][j - 1] == 'n') || (board[i][j + 1] == 'n'))
					board[i][j] = 'n';
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++)
			if (board[i][j] == 'b') // ���� ������ ����
				black++;
	}
	cout << endl;
	cout << "�� ���� " << black << "�� �׾����ϴ�" << endl; // ���

	// ���� �޸� ����
	for (int j = 0; j < row; j++)
		delete[] board[j];
	delete[] board;

	return 0;
}