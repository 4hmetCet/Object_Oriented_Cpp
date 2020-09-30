#include<iostream>
#include<vector>
using namespace std;

class ConnectFour
{	
	private:
		class Cell{
			public:	
			//	Cell();
				int row;
				int column;//BU CHAR OLACAK
				char cellSign;
				void set(int& rowPos,int& columnPos);//this function will set position of Cell
				int getPosition();
				bool empty;
		};	
		vector< vector<Cell> >GameCells;//bunun private olmasý gerekiyor
	public:
		ConnectFour();//bu fonkiyon nesne oluþtupunda çalýþacak
		bool endGame=false;
		int game_mod;
		int row;
		int column;
		bool compareGames(ConnectFour& game1,ConnectFour& game2);//This functýon wiil compare games ,if it returns true first game is better else second game is better for user
		void playGame(ConnectFour& game);
		void endedGame(ConnectFour& game,char sign);//OYUN BU FONKSÝYOLA BÝTECEK KAZANAN VARSA VEYA BERABERLÝK VARSA BÝLDÝRECEK
		void play();//that plays computer
		void play(ConnectFour& game,char sign);//that plAYS USER
		void displayCurrentBoard(ConnectFour& game);//HAMLELER YAPILDIKTAN SONRADA YENI TABLOYU YAZDIRAN FONKSIYON
		void display_last_board(ConnectFour& game);//BU FONKSIYON OYUN BITTIKTEN SONRA KAZANAN DORTLUYU KUCULTUP YAZDIRACAK
		void readFile();
		void writeFile();
		void currentWidth();
		void currentHeight();
		static void livingCells();
		
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	
	ConnectFour game1;
	game1.playGame(game1);
	game1.displayCurrentBoard(game1);

/*	if(game1.game_mod==1){//EGER GAME_MOD 1 SE OYUN 2 PLAYER LA OYNANACAK
		do{
		game1.play(game1,'X');//USER HAMLESI ALINACAK
		game1.displayCurrentBoard(game1);
		game1.endedGame(game1,'X');
			if(game1.endGame==false){
		game1.play(game1,'O');//USER HAMLESI ALINACAK
		game1.displayCurrentBoard(game1);
		game1.endedGame(game1,'X');
		}
		}while(game1.endGame==false);
	}
	else{
		do{
		game1.play(game1,'X');//USER HAMLESI ALINACAK
		game1.displayCurrentBoard(game1);
		game1.endedGame(game1,'X');
			if(game1.endGame==false){
		game1.play();//CPU HAMLE YAPACAK
		game1.displayCurrentBoard(game1);
		game1.endedGame(game1,'O');
			}
		}while(game1.endGame==false);
	}*/
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	ConnectFour::ConnectFour(){
		cout<<"Let's Play Connect Four"<<endl;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	void ConnectFour::playGame(ConnectFour& game){
		cout<<"CHOOSE GAME MOD "<<"TWO PLAYERS=(1) OR PLAYER-CPU=(2)"<<endl;
		cin>>game.game_mod; 
		if(game.game_mod!=2&&game.game_mod!=1){//GAME_MOD SARTLARA UYMAZSA BURAYA GIRER
			do{
	 		cerr<<"CHOOSE 1 OR 2 PLEASE:"; cin>>game_mod;
	 		}while(game.game_mod!=2&&game.game_mod!=1);//hatalý giriþi ele aldým
		}
		
		
		
		cout<< "Enter row size :"; cin>>game.row;
		cout<<"Enter column size :"; cin>>game.column;	
		
		game.GameCells.resize(game.row);
    	for(int i = 0 ; i <game.row ; ++i)
    	{
        	game.GameCells[i].resize(game.column);
		}
    
    
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void ConnectFour::displayCurrentBoard(ConnectFour& game){
	int k,i;
	for(k=0;k<game.column;k++){//TABLOUN ÜSTÜNDEKÝ HARFLERÝ YAZDIRDIM
		char row_name='A'+k;
		cout<<row_name;
		}
		cout<<endl;

		for(int   i = 0 ; i < game.row ; i++){ 
			for(int j = 0 ; j < game.column ; j++)
    		{     
				/*if(game.GameCells[i][j] != 'X' && game.GameCells[i][j] != 'O')//HAMLE YAPILDIKTAN SONRA YÝNE ORAYA NOKTA KOYMASIN DÝYE BU KONTROLÜ KOYDUM
				game.GameCells[i][j]='.';
   				cout<<game.GameCells[i][j];*/
   				ConnectFour::Cell c[i][j];
   				c[i][j].cellSign='.';
   				
    			game.GameCells[i][j]=c[i][j];
				cout<<game.GameCells[i][j].cellSign;	
					
			}
		cout<<endl;
		}
			cout<<GameCells[0][0].cellSign;
	}/*
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                      
 	void ConnectFour::play(ConnectFour& game,char sign){
		int r=game.row;//GAME.ROW U YEDEKLEDIK CUNKU ASAGIDA GAME.ROW DEGERI DEGISTIKTEN SONRA TEKRAR BU DEGERE IHTIYACIMIZ OLACAK
		int k;
		char choice;
 		bool ctrl=false;
			do{
			cout<<"PlayerOne Please Enter the Letter of Column:";
			cin>>choice;
			k=choice-'A';//ALDIÐIMIZ CHAR CHOÝCE U ÝNT E ÇEVÝRDÝM
			}while(k>game.column-1);//k YI KONTROL ETTÝM K ÝSTEDÝÐÝMÝZ GÝBÝ DEÐÝLSE TEKRAR ÝSTEYECEK
			
		 	if(game.GameCells[0][k]=='X'|| game.GameCells[0][k]=='O'){
				cerr<<"This column is full ,enter a new column please:";
				char c;
				cin>>c;//SÜTUN DOLUYSA YENÝ CHOÝCE ALIR
				k=(c-'A')+1;
			}
		 	do 
			{
				if ( game.GameCells[game.row-1][k] != 'X' && game.GameCells[game.row-1][k] != 'O' )//BU NOKTANIN BOÞ OLUP OLMADIÐI KONTRL EDLÝR
				{
					game.GameCells[game.row-1][k] = sign;//HMALEYÝ YAPAN PLAYER IN HARFÝ ATANIR BU NOKTAYA
					ctrl=true;//HAMLE YAPILIRSA CONTROL TRUE OLUR VE BU DÖNGÜYE TEKRAR GÝRMEZ
				}
				else
					--game.row;//HAMLE YAPILMADIYSA BÝR ÜST SATIR A GEÇER //BURADA BU NESNEYE AIT ROW AZALDIGI ICIN ASAGIDA YDEKELDIGIMIZ DEGERI GERI ALDIK
			}while (  ctrl != true );// BU DÖNGÜ HERHNAGÝ BÝR YERE HAMLE YAPILANA KADAR DEVAM EDER*/
			//game.row=r;	 //FONSIYONA GIREN ROW SAYISINI GERI ALDIK
	// }	 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
 /*	void ConnectFour::play(){//CPU HAMLE YAPACAK
 		
	 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 	
/	// void ConnectFour::endedGame(ConnectFour& game,char sign){
		int ctrl=0; 
		for(int i=0;i<game.column;++i){
			if(game.GameCells[0][i]!='.'){// HER SÜTUNDAKÝ EN ÜST SATIRI KONTROL EDER VE EÐER ORADA NOKTA YOKSA YANÝ X YA DA O VARSA SAYACI BÝR ARTTÝRIR SAYAC SÝZE A EÞÝT OLDUÐUNDA OYUN BERAEBRA BÝTMÝÞ DEMEKTÝR
				ctrl++;
			}
		} 
		if(ctrl==game.column){//EGER CTRL COLUMN A ESIT OLDUYSA BUTUN SUTUNLAR DOLU DEMEKTIR
		 cout<<"Game is Draw\n"; //BUTUN SUTUNLAR DOLDUYSA OYUN BITER
		game.endGame=true;
		}
		int win=0;
		for( int i =0; i <game.row; i++ )//BÜTÜN SATIR VE SÜTUNLAR TEK TEK KONTROL EDÝLECEK
		{
			for( int j =0 ; j <game.column; j++ )
			{
				if( game.GameCells[i][j] ==sign&& game.GameCells[i][j-1] ==sign&&	game.GameCells[i][j-2] ==sign&&game.GameCells[i][j-3] ==sign)
				{
					win = 1;//4 TANE YAN YANA GELEBÝLECEK X YA DA O LARI KONTROL ETTÝM
				}
				if(game.GameCells[i][j] ==sign&&game.GameCells[i-1][j] ==sign&&game.GameCells[i-2][j] ==sign&&game.GameCells[i-3][j] ==sign)
				{	
					win = 1;//4 TANE ALT ALTA GELEBÝLCEK X YA DA O LARI KONTROL ETTÝM
				}
				if(game.GameCells[i][j] ==sign&&game.GameCells[i-1][j-1] ==sign&&game.GameCells[i-2][j-2] ==sign&&game.GameCells[i-3][j-3] ==sign)
				{
					win = 1;//4 TANE ÇAPARAZ OLARAK GELEBÝLCEK X VE O LARI KONTROL ETTÝM
				}
				if(game.GameCells[i][j] ==sign&&game.GameCells[i-1][j+1] ==sign&&game.GameCells[i-2][j+2] ==sign&&game.GameCells[i-3][j+3] ==sign)
				{
					win = 1;//4 TANE DÝÐER TARAFA ÇAPARAZ OLARAK GELEBÝLCEK X VE O LARI KONTROL ETTÝM
				}
			}
		}
		if(win==1){//WIN 1 OLDUYSA YUKARIDAKI KOSULLADAN HERHANGI BIRI GERCEKLESMISTIR
		 cout<<"Oyun Kazanýldý";//VE OYUN KAZANILMISTIR
		 game.endGame=true;		
		}
	 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
