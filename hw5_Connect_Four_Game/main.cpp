#include<iostream>
#include<fstream>
#include"ConnectFourAbstract.h"
#include"ConnectFourAbstract.cpp"
#include"ConnectFourPlus.h"
#include"ConnectFourPlus.cpp"
#include"ConnectFourDiag.h"
#include"ConnectFourDiag.cpp"
#include"ConnectFourUndo.h"
#include"ConnectFourUndo.cpp"
#include"Cell.cpp"
#include"Cell.h"
using namespace std;
using namespace my_namespace;


main(){
	ConnectFourPlus gamePlus;
	ConnectFourDiag gameDiag;
	ConnectFourUndo gameUndo;
	cout<<"Enter P for ConnectFourPlus game"<< endl<<"Enter D for ConectFourDiag game"<<endl<<"Enter U for ConnectFourUndo game"<<endl;
	char gameMod;
	cin>>gameMod;
	if(gameMod!='P'&&gameMod!='D'&&gameMod!='U'){
		do{
			cerr<<"PLEASE ENTER ONE OF THE CORRECT LETTERS:";
			cin>>gameMod;
		}while(gameMod!='P'&&gameMod!='D'&&gameMod!='U');
	}
	if(gameMod=='P'){//GAMEMOD P ISE PLUS OYUNU OYNANCAK
		gamePlus.playGame();
	}
	else if(gameMod=='D'){//GAMEMOD D ISE DIAGONALOYNANACAK
		gameDiag.playGame();
	}
	else if(gameMod=='U'){//GAME MOD U ISE GERI ALINABILEN UNDO OYUNU OYNANACAK
		gameUndo.playGame();
	}


}


