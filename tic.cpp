#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define blank '_'
using namespace std;

char sq[10], t[10];
void clearboard();
void copyboard();
void drawboard();
int checkwin(char *a);
//int userch();
int aich();

int main()
{
    int choice,player,cont;
    char mark;
	clearboard();
//	int bestch(char mark);
//	
//	sq[5] = sq[2] = 'X';
//	cout << checkwin(sq) << endl;
//	cout << bestch('X') << endl;
	
	do{

	drawboard();
    //board();
    player=(player%2)?1:2;
    mark=(player==1)?'X':'O';

	if(player == 1){
    	cout << "\n\n\n\t\t\tPlayer 1|| Enter your choice:-\t";
    	cin >> choice;
	}
	else{
		choice = aich();
	}
	
	cout << choice;

	if(sq[choice] == blank)
	{
		sq[choice] = mark;
	}
	else
	{
		cout << "Invalid move";
		player--;
		getch();
	}

    
    
    
	drawboard();
    //board();
    cont=checkwin(sq);

    player++;
   }while(cont==-1);
	

	
	
	
	return 0;
}

void clearboard()
{
	for(int i=1 ; i < 10 ; i++)
	{
		sq[i] = blank;
	}
}
void copyboard()
{
	for(int i=1 ; i < 10 ; i++)
	{
		t[i] = sq[i];
	}
}

//int userch()
//{
//	int ch;
//	cin >> ch;
//	return ch;
//}


void drawboard()
{
    system("cls");
    cout << "\n\n\t\t\t\tTIC - TAC - TOE GAME";
    cout << "\n \n\t\t\t ";					//"Player 1-(X) \t\t Player 2-(O)";
    cout << "\n\n\t\t\t\t|     |     |     |";
    cout << "\n\t\t\t\t|  "<< sq[1] <<"  |  "<< sq[2] <<"  |  "<< sq[3] <<"  |";
    cout << "\n\t\t\t\t|     |     |     |";
    cout << "\n\t\t\t\t|-----|-----|-----|";
    cout << "\n\t\t\t\t|     |     |     |";
    cout << "\n\t\t\t\t|  "<< sq[4] <<"  |  "<< sq[5] <<"  |  "<< sq[6] <<"  |";
    cout << "\n\t\t\t\t|     |     |     |";
    cout << "\n\t\t\t\t|-----|-----|-----|";
    cout << "\n\t\t\t\t|     |     |     |";
    cout << "\n\t\t\t\t|  "<< sq[7] <<"  |  "<< sq[8] <<"  |  "<< sq[9] <<"  |";
    cout << "\n\t\t\t\t|     |     |     |";

}

int checkwin(char *a)
{
	if(a[1] != blank)
	{
		if(a[1] == a[2] && a[2] == a[3])
			return 1;
		else if(a[1] == a[4] && a[4] == a[7])
			return 1;
	}
	
	if(a[9] != blank)
	{
		if(a[7] == a[8] && a[8] == a[9])
			return 1;
		else if(a[3] == a[6] && a[6] == a[9])
			return 1;
	}
	
	if(a[5] != blank)
	{
		if(a[4] == a[5] && a[5] == a[6])
			return 1;
		else if(a[2] == a[5] && a[5] == a[8])
			return 1;
		else if(a[1] == a[5] && a[5] == a[9])
			return 1;
		else if(a[3] == a[5] && a[5] == a[7])
			return 1;
	}													//winnner found
	
	for(int i = 1 ; i < 10 ; i++)
	{
		if(a[i] == blank)
		{
			return -1;				//continue
		}
	}
	
	return 0;						//draw
}

int aich()
{
	int num;
	int bestch(char mark);
	
	if(bestch('O') != 0)
		return bestch('O');
	else if(bestch('X') != 0)
		return bestch('X');
	else{
		int j;
		for(;;)
		{
			if(sq[5] == blank)
				return 5;
			if(sq[1] != blank && sq[9] == blank)
				return 9;
			if(sq[2] != blank && sq[1] == blank)
				return 1;
			if((sq[3] != blank || sq[4] != blank) && sq[7] == blank) 
				return 7;
			if(sq[6] != blank && sq[3] == blank)
				return 3;
			j = (rand()%5)*2+1;
			if((sq[1] != blank && sq[1] == sq[9])|| (sq[3] != blank && sq[3] == sq[7]))
				j =j-1;
			if(sq[j] == blank)
				return j;
		}
	}
}


int bestch(char tmark)
{
	for(int i=1;i<10;i++)
	{
		copyboard();
		if(t[i] == blank){
			t[i] = tmark;
			
			//cout << checkwin(t) << endl;
			if(checkwin(t) == 1)
				return i;
		}
	}
	return 0;
}
