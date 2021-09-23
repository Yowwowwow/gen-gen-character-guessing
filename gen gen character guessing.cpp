#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string> 
using namespace std;

void y(){
		cout << "Yes.";
	}
	void n(){
		cout << "No.";
	}	
int main(){
	char lll = 92;
	printf("      ________"); printf("\n");
	printf("     /        %c", lll); printf("\n");
	printf("____/__________%c", lll); printf("\n");
	printf("   /\n");
	printf("  /____________\n");
	printf("         ______/\n");
	printf("  ______/\n");
	printf(" /______________ gen\n");
	srand(time(NULL));
	char lower[26], upper[26], symb[26], board[60];
	for(int i = 97;i<=122;i++) lower[i-97] = i;
	for(int i = 65;i<=90;i++) upper[i-65] = i;
	for(int i = 33;i<=47;i++) symb[i-33] = i;
	for(int i = 58;i<=64;i++) symb[i-43] = i;
	for(int i = 91;i<=94;i++) symb[i-69] = i;
	int a, b; char temp;
	for(int i = 0;i<1387;i++) 
	{
	a = rand()%26;
	b = rand()%26;
	temp=lower[a];
	lower[a] = lower[b];
	lower[b] = temp;
	}
	for(int i = 0;i<1387;i++) 
	{
	a = rand()%26;
	b = rand()%26;
	temp=upper[a];
	upper[a] = upper[b];
	upper[b] = temp;
	}
	for(int i = 0;i<1387;i++) 
	{
	a = rand()%26;
	b = rand()%26;
	temp=symb[a];
	symb[a] = symb[b];
	symb[b] = temp;
	}
	a=b=20; int c = 20, rrr;
	for(int i = 87; i<9487; i+=8787)
	{
		rrr = rand()%3;
		if(rrr==0) a++; else if(rrr==1) b++ ;else c++;
		rrr = rand()%3;
		if(rrr==0) a--; else if(rrr==1) b-- ;else c--;
	}
	for(int i=0;i<a;i++) board[i] = lower[i];
	for(int i=a;i<a+b;i++) board[i] = upper[i-a];
	for(int i=a+b;i<60;i++) board[i] = symb[i-a-b];
	for(int i = 0;i<1387;i++) 
	{
	a = rand()%60;
	b = rand()%60;
	temp=board[a];
	board[a] = board[b];
	board[b] = temp;
	}
	printf("Welcome to gen gen character guessing! The game is simple, the computer will generate 60 characters, \nforming a rectangle with a width of 10 and a height of 6, \nand YOU have to guess what the computer's secret character is by asking the computer questions! \nThe computer will only answer \"Yes.\" or \"No.\" (or \"I don't understand.\", \nin which case this question won't count as an attempt.) \nTry to do it in as few attempts as possible!(No more than 11 or you lose!) \nQuestions available:\n");
	printf("a?: Is it a lower case letter?\nA?: Is it an upper case letter?\n!?: Is it a symbol that is not a letter?\nleft: Is it in the left section?\nright: Is it in the right section?\ntop: Is it in the top section?\nbottom: Is it in the bottom section?\ntop-left: Is it in the top-left section?\ntop-right: Is it in the top-right section?\nbottom-left: Is it in the bottom-left section?\nbottom-right: Is it in the bottom-right section?\ncorner: Is it in the exact corner?\nedge: Is it at the edge?\ninside: Is it inside and not at the edge?\n(any character alone): Is it (the character)?\n");
	cout << "Input anything to start the game. ";
	string input;
	getline(cin, input);
	cout << "\n";
	for(int i=0;i<6;i++){
		for(int j=0;j<10;j++) printf("%c", board[10*i + j]);
		printf("\n");
	}
	cout << "\n";
	int ans = rand()%60;
	//cout << ans; cout << board[ans];
	bool over = false;
	int att = 0;
	while(!over)
	{
		att++;
		if(att > 11) break;
		printf("\n%d. Q: ", att);
		getline(cin, input);
		cout << "   A: ";
		if(input=="a?")
			if(board[ans]>='a' && board[ans]<='z') y(); else n();
		else if(input=="A?")
			if(board[ans]>='A' && board[ans]<='Z') y(); else n();
		else if(input=="!?")
			if((board[ans]>='!' && board[ans]<='/') || (board[ans]>=':' && board[ans]<='@') || (board[ans]>='[' && board[ans]<='^')) y(); else n();
		else if(input=="left")
			if(ans%10<5) y(); else n();
		else if(input=="right")
			if(ans%10>4) y(); else n();
		else if(input=="top")
			if(ans/10<3) y(); else n();
		else if(input=="bottom")
			if(ans/10>2) y(); else n();
		else if(input=="top-left")
			if(ans%10<5 && ans/10<3) y(); else n();
		else if(input=="top-right")
			if(ans%10>4 && ans/10<3) y(); else n();
		else if(input=="bottom-left")
			if(ans/10>2 && ans%10<5) y(); else n();
		else if(input=="bottom-right")
			if(ans/10>2 && ans%10>4) y(); else n();
		else if(input=="corner")
			if(ans==0 || ans==9 || ans==50 || ans==59) y(); else n();
		else if(input=="edge")
			if(ans%10==0 || ans%10==9 || ans/10==0 || ans/10==5) y(); else n();
		else if(input=="inside")
			if(!(ans%10==0 || ans%10==9 || ans/10==0 || ans/10==5)) y(); else n();
		else if(input.length()==1)
			if(input.c_str()[0]==board[ans]) {y(); over=true;} else n();
		else {cout << "I don't understand."; att--;}
	}
	if(att!=1 && att<11)
		printf("\n\nCongratulations! You won! You guessed the secret character!\nIt was %c! It took you %d attempts.", board[ans], att);
	else if(att<11) printf("\n\nIncredible! You won! You guessed the secret character on the FIRST TRY!\nIt was %c! WOW!", board[ans]);
	else if(att==11) printf("\n\nCongratulations! You won! You guessed the secret character!\nIt was %c! It took you %d attempts. You could have lost if... you know...", board[ans], att);
	else printf("\n\nToo bad! You lost! The secret character was %c. Try again next time.", board[ans]);
	cout << "\n\nGAME OVER\n\n";
	cout << "Input anything to close the game. ";
	getline(cin, input);
	return 87;
}
