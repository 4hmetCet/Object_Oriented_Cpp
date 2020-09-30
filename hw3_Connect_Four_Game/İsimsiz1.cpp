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
		vector< vector<char> >GameCells;//bunun private olmasý gerekiyor
	public:
		 ConnectFour();//bu fonkiyon nesne oluþtupunda çalýþacak
		bool endGame=false;
		int game_mod;
		int row;
		int column;
		bool compareGames(ConnectFour& game1,ConnectFour& game2);//This functýon wiil compare games ,if it returns true first game is better else second game is better for user
		void playGame(ConnectFour& game,int& game_mod,int& row,int& column);
		void endedGame(ConnectFour& game,int& row,int& column);//OYUN BU FONKSÝYOLA BÝTECEK KAZANAN VARSA VEYA BERABERLÝK VARSA BÝLDÝRECEK
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
	 		}while(game_mod!=2&&game_mod!=1);//hatalý giriþi ele aldým
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
	for(k=0;k<column;k++){//TABLOUN ÜSTÜNDEKÝ HARFLERÝ YAZDIRDIM
		char row_name='A'+k;
		cout<<row_name;
		}
		cout<<endl;

		for(int   i = 0 ; i < row ; ++i){ 
			for(int j = 0 ; j < column ; ++j)
    		{     
				if(GameCells[i][j] != 'X' && GameCells[i][j] != 'O')//HAMLE YAPILDIKTAN SONRA YÝNE ORAYA NOKTA KOYMASIN DÝYE BU KONTROLÜ KOYDUM
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
			k=choice-'A';//ALDIÐIMIZ CHAR CHOÝCE U ÝNT E ÇEVÝRDÝM
			}while(k>column-1);//k YI KONTROL ETTÝM K ÝSTEDÝÐÝMÝZ GÝBÝ DEÐÝLSE TEKRAR ÝSTEYECEK
			
		 	if(game.GameCells[0][k]=='X'|| game.GameCells[0][k]=='O'){
				cerr<<"This column is full ,enter a new column please:";
				char c;
				cin>>c;//SÜTUN DOLUYSA YENÝ CHOÝCE ALIR
				k=(c-'A')+1;
			}
		 	do 
			{
				if ( game.GameCells[row-1][k] != 'X' && game.GameCells[row-1][k] != 'O' )//BU NOKTANIN BOÞ OLUP OLMADIÐI KONTRL EDLÝR
				{
					game.GameCells[row-1][k] = 'X';//HMALEYÝ YAPAN PLAYER IN HARFÝ ATANIR BU NOKTAYA
					ctrl=true;//HAMLE YAPILIRSA CONTROL TRUE OLUR VE BU DÖNGÜYE TEKRAR GÝRMEZ
				}
				else
					--row;//HAMLE YAPILMADIYSA BÝR ÜST SATIR A GEÇER 
			}while (  ctrl != true );// BU DÖNGÜ HERHNAGÝ BÝR YERE HAMLE YAPILANA KADAR DEVAM EDER*/
	 }			
	 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
 	void ConnectFour::endedGame(ConnectFour& game,int& row,int& column){
		bool ctrl=true; 
		for(int i=1;i<=column;++i){
			if(game.GameCells[1][i]!='.'){// HER SÜTUNDAKÝ EN ÜST SATIRI KONTROL EDER VE EÐER ORADA NOKTA YOKSA YANÝ X YA DA O VARSA SAYACI BÝR ARTTÝRIR SAYAC SÝZE A EÞÝT OLDUÐUNDA OYUN BERAEBRA BÝTMÝÞ DEMEKTÝR
				ctrl=false;
			}
		} 
		if(ctrl==true){
		 cout<<"Game is Draw\n"; 
		game.endGame=true;
		}
		int win=0;
		for( int i = row; i >= 0; --i )//BÜTÜN SATIR VE SÜTUNLAR TEK TEK KONTROL EDÝLECEK
		{
			for( int j = column; j >= 0; --j )
			{
				if( game.GameCells[i][j] =='X'&& game.GameCells[i][j-1] =='X'&&	game.GameCells[i][j-2] =='X'&&game.GameCells[i][j-3] =='X')
				{
					win = 1;//4 TANE YAN YANA GELEBÝLECEK X YA DA O LARI KONTROL ETTÝM
				}
				if(game.GameCells[i][j] =='X'&&game.GameCells[i-1][j] =='X'&&game.GameCells[i-2][j] =='X'&&game.GameCells[i-3][j] =='X')
				{	
					win = 1;//4 TANE ALT ALTA GELEBÝLCEK X YA DA O LARI KONTROL ETTÝM
				}
				if(game.GameCells[i][j] =='X'&&game.GameCells[i-1][j-1] =='X'&&game.GameCells[i-2][j-2] =='X'&&game.GameCells[i-3][j-3] =='X')
				{
					win = 1;//4 TANE ÇAPARAZ OLARAK GELEBÝLCEK X VE O LARI KONTROL ETTÝM
				}
				if(game.GameCells[i][j] =='X'&&game.GameCells[i-1][j+1] =='X'&&game.GameCells[i-2][j+2] =='X'&&game.GameCells[i-3][j+3] =='X')
				{
					win = 1;//4 TANE DÝÐER TARAFA ÇAPARAZ OLARAK GELEBÝLCEK X VE O LARI KONTROL ETTÝM
				}
			}
		
		}
		if(win==1){
		 cout<<"Oyun Kazanýldý";
		 game.endGame=true;		
		}
	 }
