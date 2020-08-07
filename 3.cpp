#include <iostream> // ǥ������½�Ʈ��
#include <cstdlib> // ������ ����� ����
#include <ctime> // srand()ȣ�⿡ �̿�
using namespace std;

class Game {
private:
	int user_hp; // ������� HP
	int computer_hp; // ��ǻ���� HP
public:
	void condition(); // ���� ����
	void init(int uhp, int chp); // ó�� HP ��
	int user_choose(); // ������� ����
	int computer_choose(); // ��ǻ���� ����
	void choosePrint(int user_choose, int computer_choose); // ���ð�� ���
	void result(int user_ch, int computer_ch); // ���� ���
	int Getuserhp(); //������� HP
	int Getcomputerhp(); // ��ǻ���� HP
	void HPprint(); // ������ HP ���
	void whoisWin(); // ���� �Ǻ�
};

void Game::condition() { // ����
	cout << "���������� ���� ���" << endl;
	cout << "����� HP = 50, ��ǻ�� HP = 50" << endl;
	cout << "���� : 1=���� or 2=���� or 3=�� " << endl;
	cout << "�̱�� +10HP ���� -10HP // HP=0�̸� ���� ��" << endl;
	cout << "=================================" << endl;
}

void Game::init(int uhp, int chp) { // ó�� HP ��
	user_hp = uhp;
	computer_hp = chp;
}

int Game::user_choose() { // ������� ���� (1=����,2=����,3=��) 
	int user_ch;
	cout << "���� = ";
	cin >> user_ch; // ����ڷκ��� �Է¹���
	return user_ch;
}

int Game::computer_choose() { // ��ǻ���� ���� (1=����,2=����,3=��) 
	int computer_ch;
	computer_ch = rand() % 3 + 1;
	return computer_ch;
}

void Game::choosePrint(int user_choose, int computer_choose) { // ���ð�� ���
	if (user_choose == 1)
		cout << "����� ���� = ���� & ";
	if (user_choose == 2)
		cout << "����� ���� = ���� & ";
	if (user_choose == 3)
		cout << "����� ���� = ���� & ";

	if (computer_choose == 1)
		cout << "��ǻ�� ���� = ����" << endl;
	if (computer_choose == 2)
		cout << "��ǻ�� ���� = ����" << endl;
	if (computer_choose == 3)
		cout << "��ǻ�� ���� = ��" << endl;
}

void Game::result(int user_ch, int computer_ch) { // ���� ���
	if (user_ch == computer_ch) {
		cout << "��� >> ";
	}
	if (user_ch == 1) {
		if (computer_ch == 2) { // ��ǻ�Ͱ� �̱�
			computer_hp += 10;
			user_hp -= 10;
			cout << "��ǻ�Ͱ� �̱� >> ";
		}
		if (computer_ch == 3) { // ����ڰ� �̱�
			user_hp += 10;
			computer_hp -= 10;
			cout << "����ڰ� �̱� >> ";
		}
	}
	if (user_ch == 2) {
		if (computer_ch == 1) { // ����ڰ� �̱�
			user_hp += 10;
			computer_hp -= 10;
			cout << "����ڰ� �̱� >> ";
		}
		if (computer_ch == 3) { // ��ǻ�Ͱ� �̱�
			computer_hp += 10;
			user_hp -= 10;
			cout << "��ǻ�Ͱ� �̱� >> ";
		}
	}
	if (user_ch == 3) {
		if (computer_ch == 2) { // ����ڰ� �̱�
			user_hp += 10;
			computer_hp -= 10;
			cout << "����ڰ� �̱� >> ";
		}
		if (computer_ch == 1) { // ��ǻ�Ͱ� �̱�
			computer_hp += 10;
			user_hp -= 10;
			cout << "��ǻ�Ͱ� �̱� >> ";
		}
	}
}
int Game::Getuserhp() {
	return user_hp;
}

int Game::Getcomputerhp() {
	return computer_hp;
}

void Game::HPprint() { // ������ HP ���
	cout << "����� HP = " << user_hp << " , ";
	cout << "��ǻ�� HP = " << computer_hp << endl;
	cout << "*********************************" << endl;
}

void Game::whoisWin() {
	if (user_hp == 0)
		cout << "���������� ���� ����� ��ǻ�Ͱ� �̰���ϴ�" << endl;
	if (computer_hp == 0)
		cout << "���������� ���� ����� ����ڰ� �̰���ϴ�" << endl;
}

int main(void)
{
	srand((unsigned int)time(NULL)); // ������ ������ �ٸ� ������ ����ϱ� ����
	Game run; // ��ü run ����
	run.condition(); // ���� ���� ���

	int user_ch, computer_ch; // ������� ����, ��ǻ���� ����
	int uhp, chp; // ������� HP, ��ǻ���� HP

	run.init(50, 50); // ó�� HP�� : ������� HP = 50, ��ǻ���� HP = 50
	
	while (true) { // ���� ����
		user_ch = run.user_choose(); // ������� ����
		computer_ch = run.computer_choose(); // ��ǻ���� ����
		run.choosePrint(user_ch,computer_ch); // ���ð�� ���

		if (user_ch != 1 && user_ch != 2 && user_ch != 3) { // �߸��Է��� ���
			cout << "�߸� �Է��Ͽ����ϴ�" << endl;
			break;
		}

		run.result(user_ch, computer_ch); // ���� ���

		uhp = run.Getuserhp(); // ������� HP
		chp = run.Getcomputerhp(); // ��ǻ���� HP
		run.HPprint(); // ������ HP ���

		if (uhp == 0 || chp == 0) { // �� �� �ϳ��� HP�� 0�̸� ���� ����
			run.whoisWin(); // ���� �Ǻ�
			break;
		}
	}
	return 0;
}