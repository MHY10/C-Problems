#include <iostream> // 표준입출력스트림
#include <cstdlib> // 랜덤값 사용을 위해
#include <ctime> // srand()호출에 이용
using namespace std;

class Game {
private:
	int user_hp; // 사용자의 HP
	int computer_hp; // 컴퓨터의 HP
public:
	void condition(); // 게임 조건
	void init(int uhp, int chp); // 처음 HP 값
	int user_choose(); // 사용자의 선택
	int computer_choose(); // 컴퓨터의 선택
	void choosePrint(int user_choose, int computer_choose); // 선택결과 출력
	void result(int user_ch, int computer_ch); // 게임 결과
	int Getuserhp(); //사용자의 HP
	int Getcomputerhp(); // 컴퓨터의 HP
	void HPprint(); // 각각의 HP 출력
	void whoisWin(); // 승자 판별
};

void Game::condition() { // 조건
	cout << "가위바위보 게임 대결" << endl;
	cout << "사용자 HP = 50, 컴퓨터 HP = 50" << endl;
	cout << "선택 : 1=가위 or 2=바위 or 3=보 " << endl;
	cout << "이기면 +10HP 지면 -10HP // HP=0이면 게임 끝" << endl;
	cout << "=================================" << endl;
}

void Game::init(int uhp, int chp) { // 처음 HP 값
	user_hp = uhp;
	computer_hp = chp;
}

int Game::user_choose() { // 사용자의 선택 (1=가위,2=바위,3=보) 
	int user_ch;
	cout << "선택 = ";
	cin >> user_ch; // 사용자로부터 입력받음
	return user_ch;
}

int Game::computer_choose() { // 컴퓨터의 선택 (1=가위,2=바위,3=보) 
	int computer_ch;
	computer_ch = rand() % 3 + 1;
	return computer_ch;
}

void Game::choosePrint(int user_choose, int computer_choose) { // 선택결과 출력
	if (user_choose == 1)
		cout << "사용자 선택 = 가위 & ";
	if (user_choose == 2)
		cout << "사용자 선택 = 바위 & ";
	if (user_choose == 3)
		cout << "사용자 선택 = 보위 & ";

	if (computer_choose == 1)
		cout << "컴퓨터 선택 = 가위" << endl;
	if (computer_choose == 2)
		cout << "컴퓨터 선택 = 바위" << endl;
	if (computer_choose == 3)
		cout << "컴퓨터 선택 = 보" << endl;
}

void Game::result(int user_ch, int computer_ch) { // 게임 결과
	if (user_ch == computer_ch) {
		cout << "비김 >> ";
	}
	if (user_ch == 1) {
		if (computer_ch == 2) { // 컴퓨터가 이김
			computer_hp += 10;
			user_hp -= 10;
			cout << "컴퓨터가 이김 >> ";
		}
		if (computer_ch == 3) { // 사용자가 이김
			user_hp += 10;
			computer_hp -= 10;
			cout << "사용자가 이김 >> ";
		}
	}
	if (user_ch == 2) {
		if (computer_ch == 1) { // 사용자가 이김
			user_hp += 10;
			computer_hp -= 10;
			cout << "사용자가 이김 >> ";
		}
		if (computer_ch == 3) { // 컴퓨터가 이김
			computer_hp += 10;
			user_hp -= 10;
			cout << "컴퓨터가 이김 >> ";
		}
	}
	if (user_ch == 3) {
		if (computer_ch == 2) { // 사용자가 이김
			user_hp += 10;
			computer_hp -= 10;
			cout << "사용자가 이김 >> ";
		}
		if (computer_ch == 1) { // 컴퓨터가 이김
			computer_hp += 10;
			user_hp -= 10;
			cout << "컴퓨터가 이김 >> ";
		}
	}
}
int Game::Getuserhp() {
	return user_hp;
}

int Game::Getcomputerhp() {
	return computer_hp;
}

void Game::HPprint() { // 각각의 HP 출력
	cout << "사용자 HP = " << user_hp << " , ";
	cout << "컴퓨터 HP = " << computer_hp << endl;
	cout << "*********************************" << endl;
}

void Game::whoisWin() {
	if (user_hp == 0)
		cout << "가위바위보 게임 대결은 컴퓨터가 이겼습니다" << endl;
	if (computer_hp == 0)
		cout << "가위바위보 게임 대결은 사용자가 이겼습니다" << endl;
}

int main(void)
{
	srand((unsigned int)time(NULL)); // 실행할 때마다 다른 난수를 사용하기 위해
	Game run; // 객체 run 생성
	run.condition(); // 게임 조건 출력

	int user_ch, computer_ch; // 사용자의 선택, 컴퓨터의 선택
	int uhp, chp; // 사용자의 HP, 컴퓨터의 HP

	run.init(50, 50); // 처음 HP값 : 사용자의 HP = 50, 컴퓨터의 HP = 50
	
	while (true) { // 무한 루프
		user_ch = run.user_choose(); // 사용자의 선택
		computer_ch = run.computer_choose(); // 컴퓨터의 선택
		run.choosePrint(user_ch,computer_ch); // 선택결과 출력

		if (user_ch != 1 && user_ch != 2 && user_ch != 3) { // 잘못입력한 경우
			cout << "잘못 입력하였습니다" << endl;
			break;
		}

		run.result(user_ch, computer_ch); // 게임 결과

		uhp = run.Getuserhp(); // 사용자의 HP
		chp = run.Getcomputerhp(); // 컴퓨터의 HP
		run.HPprint(); // 각각의 HP 출력

		if (uhp == 0 || chp == 0) { // 둘 중 하나의 HP가 0이면 게임 종료
			run.whoisWin(); // 승자 판별
			break;
		}
	}
	return 0;
}