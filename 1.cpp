#include <iostream> // ǥ������½�Ʈ��
#include <string>
using namespace std;

int main(void)
{
	string str; // ������ ���ڿ�
	int i, sum = 0; // sum = �Է� ���� ���ڿ��� �� ������ �ƽ�Ű�ڵ� ���� ��
	cout << "���ڿ��� �Է��ϼ��� : ";
	cin >> str; // ���ڿ� �Է¹���

	for (i = 0; i < str.length(); i++) { // �迭�� index�� 0���� ����
		sum += int(str[i]); // �� ������ �ƽ�Ű�ڵ� ���� sum�� ������
		cout << int(str[i]) << " ";
		if (i < str.length() - 1) // ���ڿ��� ���� �ƴ϶�� + ���
			cout << "+";
	}
	cout << "= " << sum << endl; // sum ���

	return 0;
}