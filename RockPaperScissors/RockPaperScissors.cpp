// RockPaperScissors.cpp
// v.3
// create 14.06.2021
// update 19.06.2021

#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <iostream>
#include <string>
#include <random>
#include <conio.h>

enum RPS
{
	ROCK = 0,
	PAPER,
	SCISSORS
};

enum IFRPS
{
	iROCK = 'r',
	iPAPER = 'p',
	iSCISSORS = 's'
};

class Player
{
public:

	void ScoreUp() { this->score += 1; }

	std::string& SetName() { return name; }
	std::string GetName() { return name; }
	int GetScore() { return score; }

	~Player() {}

private:
	std::string name;
	int score = 0;
};

bool sendOut()
{
	std::string a;
	std::cout << " Do you want to go out?\n> ";
	std::cin >> a;
	if (std::tolower(a[0]) == 'y') return false;
}

void GamePVP()
{
	Player a, b;
	bool game = true; std::string gs1, gs2; char sp1, sp2;
	std::cout << " Enter player1 name:\n > ";
	std::cin >> a.SetName();
	std::cout << " Enter player2 name:\n > ";
	std::cin >> b.SetName();
	system("cls");

	do
	{
		std::cout << " Game account: "
			<< a.GetName() << " - " << a.GetScore() << " : "
			<< b.GetName() << " - " << b.GetScore() << "\n\n";

		std::cout << " Enter " << a.GetName() <<  ", step(r,s,p):\n > ";
		sp1 = _getch(); std::tolower(sp1); std::cout << std::endl;
		std::cout << " Enter " << b.GetName() << ", step(r,s,p):\n > ";
		sp2 = _getch(); std::tolower(sp2); std::cout << std::endl;

		if (sp1 == sp2)
		{
			std::cout << " Draw =(\n";
			game = sendOut();
		}
		else if (sp1 == IFRPS::iROCK && sp2 == IFRPS::iSCISSORS ||
			     sp1 == IFRPS::iPAPER && sp2 == IFRPS::iROCK || 
			     sp1 == IFRPS::iSCISSORS && sp2 == IFRPS::iPAPER)

		{
			std::cout << " " << a.GetName() << " won =)\n"; a.ScoreUp();
			game = sendOut();
		}
		else if (sp2 == IFRPS::iROCK && sp1 == IFRPS::iSCISSORS ||
				 sp2 == IFRPS::iPAPER && IFRPS::iROCK ||
				 sp2 == IFRPS::iSCISSORS && sp1 == IFRPS::iPAPER)
		{
			std::cout << " " << b.GetName() << " won =)\n"; b.ScoreUp();
			game = sendOut();
		}
		else
		{
			std::cout << "\n Incorrect input!\n";
			Sleep(500);
			game = sendOut();
		}
			
		system("cls");
	} while (game != false);
}

void GamePVE()
{
	bool game = true; std::string gs; char sp, bs; int pscr = 0, bscr = 0;
	do
	{
		srand(time(NULL));
		int bot_step = 1 + rand() % 9;
		if (bot_step <= 3 ) bs = 'p';
		else if (bot_step > 3 && bot_step < 7 ) bs = 's';
		else if (bot_step >= 7 ) bs = 'r';

		std::cout << " Game account: "
			<< "Player" << " - " << pscr << " : "
			<< "Bot" << " - " << bscr << std::endl;

		std::cout << " Enter, step(r,s,p):\n > ";
		std::cin >> gs; sp = std::tolower(gs[0]);

		if (sp == bs)
		{
			std::cout << " Draw =(\n";
			game = sendOut();
		}
		else if (sp == IFRPS::iROCK && bs == IFRPS::iSCISSORS ||
				 sp == IFRPS::iPAPER && bs == IFRPS::iROCK ||
				 sp == IFRPS::iSCISSORS && bs == IFRPS::iPAPER)
		{
			std::cout << " You won =)\n"; pscr++;
			game = sendOut();
		}
		else if (bs == IFRPS::iROCK && sp == IFRPS::iSCISSORS ||
				 bs == IFRPS::iPAPER && IFRPS::iROCK ||
				 bs == IFRPS::iSCISSORS && sp == IFRPS::iPAPER)
		{
			std::cout << " Bot won =)\n"; bscr++;
			game = sendOut();
		}
		else
		{
			std::cout << "\n Incorrect input!\n";
			Sleep(500);
			game = sendOut();
		}

		system("cls");
	} while (game != false);
}

char SetMode()
{
	char mode;
	std::cout << " Rock, Paper, Scissors! Created by Notidman\n\n"
		<< " Select a game mode:\n\n"
		<< " 1)Game 1 vs 1\n"
		<< " 2)Playing against a bot\n"
		<< " 3)Instructions\n"
		<< " 4)Exit\n"
		<< "\n > ";
	std::cin >> mode;
	system("cls");
	return mode;
}

void Inst()
{
	system("cls");
	std::cout << " Rule game:\n\n"
		<< " > Paper beats stone (\"paper wraps around stone\").\n"
		<< " > The stone beats the scissors(\"the stone blunts or breaks the scissors\")\n"
		<< " > Scissors beat paper(\"scissors cut paper\").\n";
	std::cout << "\n How to play:\n\n"
		<< " > Enter your choice during your turn\n ( Paper(P/p), Rock(R/r), Scissors(S/s) )\n";
	std::cout << "\n Press the key to exit!\n";
	system("pause>nul");
	system("cls");
}

int main()
{
	HWND consoleWindow = GetConsoleWindow(); SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	system("mode con cols=80 lines=25");
	bool gameset = true;

	while (gameset)
	{
		char m = SetMode();
		switch (m)
		{
		case '1':
			GamePVP();
			break;
		case '2':
			GamePVE();
			break;
		case '3':
			Inst();
			break;
		case '4':
			std::cout << "\n Goodbye\n";
			Sleep(1000);
			std::cout << "\n Press the key to exit!\n";
			system("pause>nul");
			gameset = false;
			break;
		default:
			std::cout << "\n What??\n";
			Sleep(1000);
			system("cls");
			break;
		}
	}
	system("pause>nul");
}

