#include<iostream>
#include<vector>
using namespace std;

class ConnectFour
{	
	private:
		class Cell{
			public:	
				int row;//HUCRENIN BULUNDUGU SATIRI TUTACAK	
				char column;//HUCRENIN POZISYONUNU TUTACAK(A,B,C,D,.....)
				char cellSign;
				void setPos(ConnectFour::Cell& c,int& rowPos,char& columnPos);//this function will set position of Cell
				int getRow(ConnectFour::Cell& c);
				char getColumn(ConnectFour::Cell& c);
				bool empty;
		};	
		vector< vector<char> >GameCells;//CELL LERI TUTAN MULTIDIAMENSIONAL VECTOR 
		void play();//that plays computer
		void play(ConnectFour& game,char sign);//that plAYS USER
		void endedGame(ConnectFour& game,char sign);//OYUN BU FONKS�YOLA B�TECEK KAZANAN VARSA VEYA BERABERL�K VARSA B�LD�RECEK
		void displayCurrentBoard(ConnectFour& game);//HAMLELER YAPILDIKTAN SONRADA YENI TABLOYU YAZDIRAN FONKSIYON
		void display_last_board(ConnectFour& game);//BU FONKSIYON OYUN BITTIKTEN SONRA KAZANAN DORTLUYU KUCULTUP YAZDIRACAK
		bool endGame=false;//OYUN BITTIYSE BU DEGISKEN TRUE OLACAK 
		int game_mod;//GAME MOD DEGISKENI	
		int row;//SATIR SAYISI
		int column;//SUTUN SAYISI
	public:
		ConnectFour();//bu fonkiyon nesne olu�tupunda �al��acak
		bool compareGames(ConnectFour& game1,ConnectFour& game2);//This funct�on wiil compare games ,if it returns true first game is better else second game is better for user
		void playGame(ConnectFour& game);//KULLANICIDAN SIZE VE GAME MOD ALINACAK VE OYUN OYNANCAK
		void readFile();
		void writeFile();
		void currentWidth();
		void currentHeight();
		static void livingCells();
	
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	ConnectFour game1,game2;
	game1.playGame(game1);
	}
	
	ConnectFour::ConnectFour(){
		cout<<"Let's Play The Game\n";
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	void ConnectFour::playGame(ConnectFour& game){
		cout<<"CHOOSE GAME MOD "<<"TWO PLAYERS=(1) OR PLAYER-CPU=(2)"<<endl;
		cin>>game.game_mod; 
		if(game.game_mod!=2&&game_mod!=1){//GAME_MOD SARTLARA UYMAZSA BURAYA GIRER
			do{
	 		cerr<<"CHOOSE 1 OR 2 PLEASE:"; cin>>game_mod;
	 		}while(game.game_mod!=2&&game.game_mod!=1);//hatal� giri�i ele ald�m
		}
		cout<< "Enter row size :"; cin>>game.row;//BOARD IN SATIR SAYISINI ALDIK
		cout<<"Enter column size :"; cin>>game.column;	//BOARDIN SUTUN SAYISINI ALDIK
		
		game.GameCells.resize(game.row);//SATIR�ARI OLUSTURDUK		
    	for(int i = 0 ; i <game.row ; ++i)
    	{
        	game.GameCells[i].resize(game.column);//HER SATIRA SUTUN OLUSUTRUDK
		}
    	
		game.displayCurrentBoard(game);//ILK BOARDU YAZDIRIDIM
	if(game.game_mod==1){//EGER GAME_MOD 1 SE OYUN 2 PLAYER LA OYNANACAK
		do{
		game.play(game,'X');//USER HAMLESI ALINACAK
		game.displayCurrentBoard(game);//HAMLDEN SONRAKI BOARD U YAZDIRDIK
		game.endedGame(game,'X');//OYUN BITTIP BITMEDIGI KONTROL EDILDI 
			if(game.endGame==false){//OYUN HANLEDEN SONRA BITMEDIYSE KARSI TARAFIN HAMLESINE GECILCEK
		game.play(game,'O');//USER HAMLESI ALINACAK
		game.displayCurrentBoard(game);
		game.endedGame(game,'X');//OYUNUN BITIP BITMEDIGI KONTROL EDILDI
		}
		}while(game.endGame==false);//OYUN BITMEDIGI SURECE HAMLELER YAPILMAYA DEVAM EDECEK
	}
	else{
		do{
		game.play(game,'X');//USER HAMLESI ALINACAK
		game.displayCurrentBoard(game);//HAMLDEEN SONRA OTUN BOARDU YAZDIRILACAK	
		game.endedGame(game,'X');//OYUNUN BITIP BITMEDIGI KONTROL EDILECEK
			if(game.endGame==false){//OYUN BITMEDIYDE CPU HAMLE YAPAPACK
		game.play();//CPU HAMLE YAPACAK
		game.displayCurrentBoard(game);//CPU NUN HAMLESINDEN SONRA OYUN BOARDU YAZDIRILACAK	
		game.endedGame(game,'O');//OYUNUN BITIP BITMEDIGI KONTROL EDILECEK
			}
		}while(game.endGame==false);//OYUN BITMEDIGI SURECE OYUN DEVAM EDECEK
	}
	
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void ConnectFour::displayCurrentBoard(ConnectFour& game){
	int k,i;
	for(k=0;k<game.column;k++){//TABLOUN �ST�NDEK� HARFLER� YAZDIRDIM
		char row_name='A'+k;
		cout<<row_name;
		}
		cout<<endl;

		for(int   i = 0 ; i < game.row ; ++i){ 
			for(int j = 0 ; j < game.column ; ++j)
    		{     
				if(game.GameCells[i][j] != 'X' && game.GameCells[i][j] != 'O')//HAMLE YAPILDIKTAN SONRA Y�NE ORAYA NOKTA KOYMASIN D�YE BU KONTROL� KOYDUM
				game.GameCells[i][j]='.';
   				cout<<game.GameCells[i][j];
    		}
		cout<<endl;
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                      
 	void ConnectFour::play(ConnectFour& game,char sign){
		int r=game.row;//GAME.ROW U YEDEKLEDIK CUNKU ASAGIDA GAME.ROW DEGERI DEGISTIKTEN SONRA TEKRAR BU DEGERE IHTIYACIMIZ OLACAK
		int k;
		char choice;
 		bool ctrl=false;
			do{
			cout<<"PlayerOne Please Enter the Letter of Column:";
			cin>>choice;
			k=choice-'A';//ALDI�IMIZ CHAR CHO�CE U �NT E �EV�RD�M
			}while(k>game.column-1);//k YI KONTROL ETT�M K �STED���M�Z G�B� DE��LSE TEKRAR �STEYECEK
			
		 	if(game.GameCells[0][k]=='X'|| game.GameCells[0][k]=='O'){
				cerr<<"This column is full ,enter a new column please:";
				char c;
				cin>>c;//S�TUN DOLUYSA YEN� CHO�CE ALIR
				k=(c-'A')+1;
			}
		 	do 
			{
				if ( game.GameCells[game.row-1][k] != 'X' && game.GameCells[game.row-1][k] != 'O' )//BU NOKTANIN BO� OLUP OLMADI�I KONTRL EDL�R
				{
					game.GameCells[game.row-1][k] = sign;//HMALEY� YAPAN PLAYER IN HARF� ATANIR BU NOKTAYA
					ctrl=true;//HAMLE YAPILIRSA CONTROL TRUE OLUR VE BU D�NG�YE TEKRAR G�RMEZ
				}
				else
					--game.row;//HAMLE YAPILMADIYSA B�R �ST SATIR A GE�ER //BURADA BU NESNEYE AIT ROW AZALDIGI ICIN ASAGIDA YDEKELDIGIMIZ DEGERI GERI ALDIK
			}while (  ctrl != true );// BU D�NG� HERHNAG� B�R YERE HAMLE YAPILANA KADAR DEVAM EDER*/
			game.row=r;	 //FONSIYONA GIREN ROW SAYISINI GERI ALDIK
	 }	 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
 	void ConnectFour::play(){//CPU HAMLE YAPACAK
 		
	 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 	
	 void ConnectFour::endedGame(ConnectFour& game,char sign){
		int ctrl=0; 
		for(int i=0;i<game.column;++i){
			if(game.GameCells[0][i]!='.'){// HER S�TUNDAK� EN �ST SATIRI KONTROL EDER VE E�ER ORADA NOKTA YOKSA YAN� X YA DA O VARSA SAYACI B�R ARTT�RIR SAYAC S�ZE A E��T OLDU�UNDA OYUN BERAEBRA B�TM�� DEMEKT�R
				ctrl++;
			}
		} 
		if(ctrl==game.column){//EGER CTRL COLUMN A ESIT OLDUYSA BUTUN SUTUNLAR DOLU DEMEKTIR
		 cout<<"Game is Draw\n"; //BUTUN SUTUNLAR DOLDUYSA OYUN BITER
		game.endGame=true;
		}
		int win=0;
		for( int i =0; i <game.row; i++ )//B�T�N SATIR VE S�TUNLAR TEK TEK KONTROL ED�LECEK
		{
			for( int j =0 ; j <game.column; j++ )
			{
				if( game.GameCells[i][j] ==sign&& game.GameCells[i][j-1] ==sign&&	game.GameCells[i][j-2] ==sign&&game.GameCells[i][j-3] ==sign)
				{
					win = 1;//4 TANE YAN YANA GELEB�LECEK X YA DA O LARI KONTROL ETT�M
				}
				if(game.GameCells[i][j] ==sign&&game.GameCells[i-1][j] ==sign&&game.GameCells[i-2][j] ==sign&&game.GameCells[i-3][j] ==sign)
				{	
					win = 1;//4 TANE ALT ALTA GELEB�LCEK X YA DA O LARI KONTROL ETT�M
				}
				if(game.GameCells[i][j] ==sign&&game.GameCells[i-1][j-1] ==sign&&game.GameCells[i-2][j-2] ==sign&&game.GameCells[i-3][j-3] ==sign)
				{
					win = 1;//4 TANE �APARAZ OLARAK GELEB�LCEK X VE O LARI KONTROL ETT�M
				}
				if(game.GameCells[i][j] ==sign&&game.GameCells[i-1][j+1] ==sign&&game.GameCells[i-2][j+2] ==sign&&game.GameCells[i-3][j+3] ==sign)
				{
					win = 1;//4 TANE D��ER TARAFA �APARAZ OLARAK GELEB�LCEK X VE O LARI KONTROL ETT�M
				}
			}
		}
		if(win==1){//WIN 1 OLDUYSA YUKARIDAKI KOSULLADAN HERHANGI BIRI GERCEKLESMISTIR
		 cout<<"Oyun Kazanildi";//VE OYUN KAZANILMISTIR
		 game.endGame=true;		
		}
	 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

