#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

void getName(string &name, int& coins);
void getRule(char ans);
void getBet(int &bet, int &coins);
void getCard(int suit[], int value[]);
void printCard(int suit[], int value[]);
int random(int lo, int hi); //choose random number
void changeCard(int value[], int suit[], int temp);
void changevalue(int value[]);
bool royalflush(int suit[], int value[]);
bool straightflush(int suit[], int value[]);
bool fourKind(int suit[], int value[]);
bool flush(int suit[], int value[]);
bool straight(int suit[], int value[]);
bool fullHouse(int suit[], int value[]);
bool threeKind(int suit[], int value[]);
bool twoPair(int suit[], int value[]);
bool onePair(int suit[], int value[]);
int getPoints(int suit[], int value[], int &bet, int &coins);

const int MAX = 5;

int main() {
	string name;
	int bet = 0;
	int coins = 0;
	char cardNum; //Nth card
	char ans;
	int temp = 0;
	int suit[MAX];
	int value[MAX];
	//int card[4][5];

	srand(time(0));

	cout <</*setw(50)<<*/"Welcome to this game!" << endl << endl;

	getName(name, coins); //input name
	getRule(ans);
	cout << "You have total coins: " << coins << endl;
	do {
		getBet(bet, coins);
		getCard(suit, value);
		printCard(suit, value);
		cout << "Do you want to change cards? y/n" << endl;
		cin >> ans;
		if (ans == 'y') {
			changeCard(value, suit, temp);
			printCard(suit, value);
		}
		changevalue(value);
		getPoints(suit, value, bet, coins);
		cout << endl << "Do you want to do this again? y/n" << endl;
		cin >> ans;
		cout << endl;
	} while (ans == 'y' && coins > 0);
	cout << "Thanks for you playing, you have " << coins
			<< " coins, Have a good day." << endl << endl;

	return 0;
}

void getName(string &name, int& coins) {
	cout << "Please enter your first name: ";
	getline(cin, name);
	for (int i = 0; i < name.size(); i++)
		name[i] = toupper(name[i]);
	cout << endl << "Welcome " << name << ". It is game time!" << endl << endl;
	coins = 50;
}

void getRule(char ans) {
	cout << "Do you want to know rules? y/n" << endl;
	cin >> ans;
	if (ans == 'y') {
		cout << endl << "Rules" << endl << endl;
	}
}

void getBet(int& bet, int& coins) {
	do {
		cout << "Please enter bet of coins: 0 ~ " << coins << endl;
		cin >> bet;
		if (bet <= 0 || bet > coins)
			cout << "The bet is not in the range" << endl;
	} while (bet <= 0 || bet > coins);
	coins = 50 - bet;
	if (coins <= 0) {
		cout << "You lost all coins" << endl;
	}

}

int random(int lo, int hi) { //range of valid numbers

	int range = hi - lo + 1;

	int randomNumber = lo + (rand() % range);

	return randomNumber;

}

void getCard(int suits[], int values[]) {
	int suit = 0;
	int value = 0;
	bool sameValue;
	for (int i = 0; i < MAX; i++) {
		do {
			sameValue = false;
			value = random(0, 51);
			for (int j = 0; j < i; j++) {
				if (value == values[j]) {
					sameValue = true;
					break;
				}
			}
		} while (sameValue);

		values[i] = value;
		suit = static_cast<int>(value / 13);
		suits[i] = suit;
	}
}

void printCard(int suit[], int value[]) {
	cout << "Your get these cards: " << endl;
	for (int i = 0; i < MAX; i++) {
		switch (value[i] % 13 + 1) {
		case 1:
			cout << " Ace ";
			break;
		case 2:
			cout << " Two ";
			break;
		case 3:
			cout << " Three ";
			break;
		case 4:
			cout << " Four ";
			break;
		case 5:
			cout << " Five ";
			break;
		case 6:
			cout << " Six ";
			break;
		case 7:
			cout << " Seven ";
			break;
		case 8:
			cout << " Eight ";
			break;
		case 9:
			cout << " Nine ";
			break;
		case 10:
			cout << " Ten ";
			break;
		case 11:
			cout << " Jack ";
			break;
		case 12:
			cout << " Queen ";
			break;
		case 13:
			cout << " King ";
			break;
		}

		switch (suit[i]) {
		case 0:
			cout << "of Hearts" << endl;
			break;
		case 1:
			cout << "of Clubs" << endl;
			break;
		case 2:
			cout << "of Diamonds" << endl;
			break;
		case 3:
			cout << "of Spades" << endl;
			break;
		}
	}
}

void changeCard(int value[], int suit[], int temp)

{

	bool same;
	int count_change = 0;
	string cardNum;
	cout << "Enter the card number you want to change" << endl;
	cin >> cardNum;
	if (cardNum.size() == 0)
		cout << "no changes.";
	else
		for (int i = 0; i < cardNum.size(); i++) {
			if (isdigit(cardNum[i]) && (cardNum[i] - 49 < 6)) {
				do {
					same = false;
					temp = random(0, 51);
					for (int i = 0; i < MAX; i++) {
						if (temp == value[i]) {
							same = true;
							break;
						}
					}
				} while (same);
				value[cardNum[i] - 49] = temp;
				suit[cardNum[i] - 49] = temp / 13;
				count_change++;
			}
			if (count_change > 4)
				break;
		}
}

void changevalue(int value[]) {
	int temp;
	for (int i = 0; i < MAX; i++) {
		value[i] = value[i] % 13 + 1;
	}
	for (int i = 0; i < MAX; i++) {
		for (i = 0; i < MAX; i++) {
			for (int j = i + 1; j < MAX; j++) {
				if (value[i] > value[j]) {
					temp = value[i];
					value[i] = value[j];
					value[j] = temp;
				}
			}
		}
	}
}

int getPoints(int suit[], int value[], int &bet, int &coins) {

	cout << coins << endl;
	if (royalflush(suit, value)) {
		cout << "You got Royal Flush" << endl << "You win " << 2500 * bet
				<< " Pionts" << endl;
		coins = coins + (2500 / 5) * bet;
		cout << "Now, you have " << coins << " coins" << endl;
	}

	else if (straightflush(suit, value)) {
		cout << "You got Straight Flush" << endl << "You win " << 250 * bet
				<< " Pionts" << endl;
		coins = coins + (250 / 5) * bet;
		cout << "Now, you have " << coins << " coins" << endl;
	}

	else if (fourKind(suit, value)) {
		cout << "You got Four of a Kind " << endl << "You win " << 125 * bet
				<< " Pionts" << endl;
		coins = coins + (125 / 5) * bet;
		cout << "Now, you have " << coins << " coins" << endl;
	}

	else if (fullHouse(suit, value)) {
		cout << "You got Full House" << endl << "You win " << 40 * bet
				<< " Pionts" << endl;
		coins = coins + (40 / 5) * bet;
		cout << "Now, you have " << coins << " coins" << endl;
	}

	else if (flush(suit, value)) {
		cout << "You got Flush " << endl << "You win " << 25 * bet << " Pionts"
				<< endl;
		coins = coins + (25 / 5) * bet;
		cout << "Now, you have " << coins << " coins" << endl;
	}

	else if (straight(suit, value)) {
		cout << "You got Straight " << endl << "You win " << 20 * bet
				<< " Pionts" << endl;
		coins = coins + (20 / 5) * bet;
		cout << "Now, you have " << coins << " coins" << endl;
	}

	else if (threeKind(suit, value)) {
		cout << "You got Three of a Kind" << endl << "You win " << 15 * bet
				<< " Pionts" << endl;
		coins = coins + (15 / 5) * bet;
		cout << "Now, you have " << coins << " coins" << endl;
	}

	else if (twoPair(suit, value)) {
		cout << "You got Two Pair" << endl << "You win " << 10 * bet
				<< " Pionts" << endl;
		coins = coins + (10 / 5) * bet;
		cout << "Now, you have " << coins << " coins" << endl;
	}

	else if (onePair(suit, value)) {
		cout << "You got One Pair" << endl << "You win " << 5 * bet << " Pionts"
				<< endl;
		coins = coins + (5 / 5) * bet;
		cout << "Now, you have " << coins << " coins" << endl;
	}

	else {
		cout << "Sorry, you did not get angthing" << endl << "You lost "
				<< 5 * bet << " Points" << endl;\
		cout << "Now, you have " << coins << " coins" << endl;
	}
}

bool royalflush(int suit[], int value[]) {
	bool ace = false, king = false;
	if (straight(suit, value) && flush(suit, value))
		for (int i = 0; i < MAX; i++) {
			if (value[i] == 0)
				ace = true;
			else if (value[i] == 12)
				king = true;
		}
	if (ace && king)
		return true;
	else
		return false;
}

bool straightflush(int suit[], int value[]) {
	if (straight(suit, value) && flush(suit, value))
		return true;
	else
		return false;
}

bool fourKind(int suit[], int value[]) {
	int pos1;
	for (int i = 1; i < MAX; i++) {
		if (value[0] != value[i])
			pos1 = i;
	}
	for (int i = 1; i < MAX; i++) {
		if (value[0] != value[i] && value[pos1] != value[i])
			return false;
	}
	int num = 0;
	int num2 = 0;
	for (int i = 0; i < MAX; i++) {
		if (value[0] - value[i] == 0)
			num++;
		else if (value[pos1] - value[i] == 0)
			num2++;
	}
	if (num == 4 || num2 == 4)
		return true;
	else
		return false;
}

bool flush(int suit[], int value[]) {
	for (int i = 1; i < MAX; i++) {
		if (suit[i] != suit[0])
			return false;
	}
	return true;
}

bool straight(int suit[], int value[]) {
	if (value[0] != 0) {
		for (int i = 0; i < 4; i++) {
			if (value[i] + 1 != value[i + 1])
				return false;
		}
		return true;
	} else {
		bool in = true;
		for (int i = 0; i < 4; i++) {
			if (value[i] + 1 != value[i + 1])
				in = false;
		}
		if (in)
			return true;
		else {
			if (value[0] == 0 && value[1] == 9 && value[2] == 10
					&& value[3] == 11 && value[4] == 12)
				return true;
			else
				return false;
		}
	}
}

bool fullHouse(int suit[], int value[]) {
	int pos1;
	for (int i = 1; i < MAX; i++) {
		if (value[0] != value[i])
			pos1 = i;
	}
	for (int i = 1; i < MAX; i++) {
		if (value[0] != value[i] && value[pos1] != value[i])
			return false;
	}
	int num = 0;
	int num2 = 0;
	for (int i = 0; i < MAX; i++) {
		if (value[0] - value[i] == 0)
			num++;
		else if (value[pos1] - value[i] == 0)
			num2++;
	}
	if ((num == 3 && num2 == 2) || (num == 2 && num2 == 3))
		return true;
	else
		return false;
}

bool threeKind(int suit[], int value[]) {
	int pos1, pos2;
	for (int i = 1; i < MAX; i++) {
		if (value[0] != value[i])
			pos1 = i;
	}
	for (int i = 1; i < MAX; i++) {
		if (value[0] != value[i] && value[pos1] != value[i])
			pos2 = i;
	}
	int num = 0;
	int num2 = 0;
	int num3 = 0;
	for (int i = 0; i < MAX; i++) {
		if (value[0] - value[i] == 0)
			num++;
		else if (value[pos1] - value[i] == 0)
			num2++;
		else if (value[pos2] - value[i] == 0)
			num3++;
	}
	if (num == 3 || num2 == 3 || num3 == 3)
		return true;
	else
		return false;
}

bool twoPair(int suit[], int value[]) {
	int pos1, pos2, pos3;
	for (int i = 1; i < MAX; i++) {
		if (value[0] != value[i])
			pos1 = i;
	}
	for (int i = 1; i < MAX; i++) {
		if (value[0] != value[i] && value[pos1] != value[i])
			pos2 = i;
	}
	for (int i = 1; i < MAX; i++) {
		if (value[0] != value[i] && value[pos1] != value[i]
				&& value[pos2] != value[i])
			pos3 = i;
	}
	int num = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	for (int i = 0; i < MAX; i++) {
		if (value[0] - value[i] == 0)
			num++;
		else if (value[pos1] - value[i] == 0)
			num2++;
		else if (value[pos2] - value[i] == 0)
			num3++;
		else if (value[pos3] - value[i] == 0)
			num4++;
	}
	if ((num == 2 && (num2 == 2 || num3 == 2 || num4 == 2))
			|| (num2 == 2 && (num3 == 2 || num4 == 2))
			|| (num3 == 2 && num4 == 2))
		return true;
	else
		return false;
}

bool onePair(int suit[], int value[]) {
	int pos1, pos2, pos3;
	for (int i = 1; i < MAX; i++) {
		if (value[0] != value[i])
			pos1 = i;
	}
	for (int i = 1; i < MAX; i++) {
		if (value[0] != value[i] && value[pos1] != value[i])
			pos2 = i;
	}
	for (int i = 1; i < MAX; i++) {
		if (value[0] != value[i] && value[pos1] != value[i]
				&& value[pos2] != value[i])
			pos3 = i;
	}
	for (int i = 1; i < MAX; i++) {
		if (value[0] != value[i] && value[pos1] != value[i]
				&& value[pos2] != value[i] && value[pos3] != value[i])
			return false;
	}
	return true;
}

