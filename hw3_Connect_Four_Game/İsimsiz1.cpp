#include<iostream>
#include<vector>
using namespace std;
struct game
{
	char playerSign;
};
class ConnectFour
{	
	private:
		class Cell{
			public:	
				int row;
				int column;
				char cellSign;
				void set(int& rowPos,int& columnPos);//this function will set position of Cell
				int getPosition();
				bool empty;
		};	
		vector< vector<char> >GameCells;//bunun private olmas� gerekiyor
	public:
		 ConnectFour();//bu fonkiyon nesne olu�tupunda �al��acak
		bool endGame=false;
		int game_mod;
		int row;
		int column;
		bool compareGames(ConnectFour& game1,ConnectFour& game2);//This funct�on wiil compare games ,if it returns true first game is better else second game is better for user
		void playGame(ConnectFour& game,int& game_mod,int& row,int& column);
		void endedGame(ConnectFour& game,int& row,int& column);//OYUN BU FONKS�YOLA B�TECEK KAZANAN VARSA VEYA BERABERL�K VARSA B�LD�RECEK
		void play();//that plays computer
		void play(ConnectFour& game, int& row,int& column);//that plAYS USER
		void displayCurrentBoard(ConnectFour& game,int& row,int& column);
		void readFile();
		void writeFile();
		void currentWidth();
		void currentHeight();
		static void livingCells();
};
int main(int argc, char** argv){
	ConnectFour game1;
	game1.playGame(game1,game1.game_mod,game1.row,game1.column);
	game1.displayCurrentBoard(game1,game1.row,game1.column);
	do{
	game1.play(game1,game1.row,game1.column);
	game1.displayCurrentBoard(game1,game1.row,game1.column);
	//game1.endedGame(game1,game1.row,game1.column);
	}while(game1.endGame==false);
	return 0;	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	ConnectFour::ConnectFour(){
		cout<<"Let's Play Connect Four"<<endl;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7	
	void ConnectFour::playGame(ConnectFour& game,int& game_mod,int& row,int& column){
		cout<<"CHOOSE GAME MOD "<<"TWO PLAYERS=(1) OR PLAYER-CPU=(2)"<<endl;
		cin>>game_mod; 
		if(game_mod!=2&&game_mod!=1){//TERCIH SARTLARA UYMAZSA BURAYA GIRER
			do{
	 		cerr<<"CHOOSE 1 OR 2 PLEASE:"; cin>>game_mod;
	 		}while(game_mod!=2&&game_mod!=1);//hatal� giri�i ele ald�m
		}
		cout<< "Enter row size :"; cin>>row;
		cout<<"Enter column size :"; cin>>column;
			
		GameCells.resize(row);
    	for(int i = 0 ; i <row ; ++i)
    	{
        	GameCells[i].resize(column);
    	}
    	
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void ConnectFour::displayCurrentBoard(ConnectFour& game,int& row,int& colmun){
	int k,i;
	for(k=0;k<column;k++){//TABLOUN �ST�NDEK� HARFLER� YAZDIRDIM
		char row_name='A'+k;
		cout<<row_name;
		}
		cout<<endl;

		for(int   i = 0 ; i < row ; ++i){ 
			for(int j = 0 ; j < column ; ++j)
    		{     
				if(GameCells[i][j] != 'X' && GameCells[i][j] != 'O')//HAMLE YAPILDIKTAN SONRA Y�NE ORAYA NOKTA KOYMASIN D�YE BU KONTROL� KOYDUM
				GameCells[i][j]='.';
   				cout<<GameCells[i][j];
    		}
		cout<<endl;
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                      
 	void ConnectFour::play(ConnectFour& game, int& row, int& column){
		int k;
		char choice;
 		bool ctrl=false;
			do{
			cout<<"PlayerOne Please Enter the Letter of Column:";
			cin>>choice;
			k=choice-'A';//ALDI�IMIZ CHAR CHO�CE U �NT E �EV�RD�M
			}while(k>column-1);//k YI KONTROL ETT�M K �STED���M�Z G�B� DE��LSE TEKRAR �STEYECEK
			
		 	if(game.GameCells[0][k]=='X'|| game.GameCells[0][k]=='O'){
				cerr<<"This column is full ,enter a new column please:";
				char c;
				cin>>c;//S�TUN DOLUYSA YEN� CHO�CE ALIR
				k=(c-'A')+1;
			}
		 	do 
			{
				if ( game.GameCells[row-1][k] != 'X' && game.GameCells[row-1][k] != 'O' )//BU NOKTANIN BO� OLUP OLMADI�I KONTRL EDL�R
				{
					game.GameCells[row-1][k] = 'X';//HMALEY� YAPAN PLAYER IN HARF� ATANIR BU NOKTAYA
					ctrl=true;//HAMLE YAPILIRSA CONTROL TRUE OLUR VE BU D�NG�YE TEKRAR G�RMEZ
				}
				else
					--row;//HAMLE YAPILMADIYSA B�R �ST SATIR A GE�ER 
			}while (  ctrl != true );// BU D�NG� HERHNAG� B�R YERE HAMLE YAPILANA KADAR DEVAM EDER*/
	 }			
	 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
 	void ConnectFour::endedGame(ConnectFour& game,int& row,int& column){
		bool ctrl=true; 
		for(int i=1;i<=column;++i){
			if(game.GameCells[1][i]!='.'){// HER S�TUNDAK� EN �ST SATIRI KONTROL EDER VE E�ER ORADA NOKTA YOKSA YAN� X YA DA O VARSA SAYACI B�R ARTT�RIR SAYAC S�ZE A E��T OLDU�UNDA OYUN BERAEBRA B�TM�� DEMEKT�R
				ctrl=false;
			}
		} 
		if(ctrl==true){
		 cout<<"Game is Draw\n"; 
		game.endGame=true;
		}
		int win=0;
		for( int i = row; i >= 0; --i )//B�T�N SATIR VE S�TUNLAR TEK TEK KONTROL ED�LECEK
		{
			for( int j = column; j >= 0; --j )
			{
				if( game.GameCells[i][j] =='X'&& game.GameCells[i][j-1] =='X'&&	game.GameCells[i][j-2] =='X'&&game.GameCells[i][j-3] =='X')
				{
					win = 1;//4 TANE YAN YANA GELEB�LECEK X YA DA O LARI KONTROL ETT�M
				}
				if(game.GameCells[i][j] =='X'&&game.GameCells[i-1][j] =='X'&&game.GameCells[i-2][j] =='X'&&game.GameCells[i-3][j] =='X')
				{	
					win = 1;//4 TANE ALT ALTA GELEB�LCEK X YA DA O LARI KONTROL ETT�M
				}
				if(game.GameCells[i][j] =='X'&&game.GameCells[i-1][j-1] =='X'&&game.GameCells[i-2][j-2] =='X'&&game.GameCells[i-3][j-3] =='X')
				{
					win = 1;//4 TANE �APARAZ OLARAK GELEB�LCEK X VE O LARI KONTROL ETT�M
				}
				if(game.GameCells[i][j] =='X'&&game.GameCells[i-1][j+1] =='X'&&game.GameCells[i-2][j+2] =='X'&&game.GameCells[i-3][j+3] =='X')
				{
					win = 1;//4 TANE D��ER TARAFA �APARAZ OLARAK GELEB�LCEK X VE O LARI KONTROL ETT�M
				}
			}
		
		}
		if(win==1){
		 cout<<"Oyun Kazan�ld�";
		 game.endGame=true;		
		}
	 }
