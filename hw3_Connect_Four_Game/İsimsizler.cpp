#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class ConnectFour
{	
	private:
		class Cell{
			private:
				int row;//HUCRENIN BULUNDUGU SATIRI TUTACAK	
				char column;//HUCRENIN POZISYONUNU TUTACAK(A,B,C,D,.....)
			public:	
				char cellSign;//BU DEGER X VEYA O OLACAK
				bool isFull=false;//BU CELLIN CELLSIGNI EGER X VEYA O OLURSA BU DEGER TRUE OLACAK VE O CELL E BI DAHA HAMLE YAPILAMAYACAK
				void setPos(int& rowPos,char& columnPos);//this function will set position of Cell
				const int getRow();
				const char getColumn ();
				
		};	
		vector< vector<Cell> >GameCells;//CELL LERI TUTAN MULTIDIAMENSIONAL VECTOR 
		void play();//that plays computer
		void play(int& position,char sign);//that plAYS USER
		void endedGame(char sign);//OYUN BU FONKSÝYOLA BÝTECEK KAZANAN VARSA VEYA BERABERLÝK VARSA BÝLDÝRECEK
	
		void display_last_board(char Sign);//BU FONKSIYON OYUN BITTIKTEN SONRA KAZANAN DORTLUYU KUCULTUP YAZDIRACAK
		int move();//KULLANICIDAN HAMLE ALACAK VE DUNDURECEK
		int row;//SATIR SAYISI
		int column;//SUTUN SAYISI
		void readFile() ;//BU FONSIYON KAYITLI OYUNU DOSYADAN OKUYACAK
		void writeFile();//BU FONSIYON OYUN U FILE A YAZACAK
		const int currentWidth() ;
		const int currentHeight();
		void player2player();//BU FONSIYON PLAYER TO PLAYER OYUNU OYNAYACAK
		void player2cpu();//BU FONKSIYON PLAYER TO CPU OYUNU PYNAYACAK
		int game_mod;//GAME MOD DEGISKENI	
		void getLivingCells();
		inline void displayCurrentBoard();//HAMLELER YAPILDIKTAN SONRADA YENI TABLOYU YAZDIRAN FONKSIYON
	public:
		bool endGame=false;//OYUN BITTIYSE BU DEGISKEN TRUE OLACAK 
		void one_object_game();//BU FOKNSIYONDA SADECE PALYERONE VE PLAYERTWO O OBJECT ICIN BIRER HAMLE YAPACAK 
		void playGame();//KULLANICIDAN SIZE VE GAME MOD ALINACAK VE OYUN OYNANCAK//BU FONSIYONUN ICINDE PLAYER2PLAYER VE PLAYER2CPU FONKSIYONLARI CALISACAK
		ConnectFour();//bu fonkiyon nesne oluþtupunda çalýþacak VE PLAYGAME FONKSIYONU DA BUNUN ICINDE CALISACAK
		//PLAYGAME OLUSTURULAN  NESNEYE GORE CALISACAK
		bool compareGames(const ConnectFour& game1,const ConnectFour& game2);//This functýon wiil compare games ,if it returns true first game is better else second game is better for user
};
		int livingCells=0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	ConnectFour game1,game2,game3,game4,game5;//BES TANE NESNE OLUSTRDUK
	game1.playGame();//HER BIR NESNEYI TEK TEK OLUSTURDUK
	game2.playGame();
	game3.playGame();
	game4.playGame();
	game5.playGame();
do{
	if(game1.endGame==false){//EEGER GAME1 OYUNU BITMEDIYSE OYUN OYNANCAK
	
			cout<<"OBJECT 1\n"<<endl;
			game1.one_object_game();//GAME1 ICIN HAMLELER ALINACAK VE ALINAN HAMLELER YAPILACAK 
			//BU FONLSIYONUN ICINDE EGER OYUN BITTIYSE ENDGAME DEGISKENI TRUE OLACAK VE BU OBJECT IVIN OYUN OYNANMAYACAK
		}
	if(game2.endGame==false){//EGER GAME2 OYUNU BITMEDIYSE OYUN OYNANACAK
			cout<<"OBJECT 2\n"<<endl;
			game2.one_object_game();//GAME2 ICIN HAMLELER ALINACAK VE ALINAN HAMLELER YAPILACAK
			//BU FONKSIYONUN ICINDE EGER OYUN BITTIYSE ENDGAME DEGISKENI TRUE OLACAK VE OBJECT ICIN OYUN BI DAH OYNANMAYACAK
	}
	if(game3.endGame==false){//EGER GAME3 OYUNU BITMEDIYSE OYUN OYNANACAK
		cout<<"OBJECT 3\n"<<endl;
			game3.one_object_game();//GAME3 ICIN HAMLELER ALINACAK VE ALINAN HAMLELER YAPILACAK
			//BU FONKSIYONUN ICINDE EGER OYUN BITTIYSE ENDGAME DEGISKENI TRUE OLACAK VE OBJECT ICIN OYUN BI DAH OYNANMAYACAK
	}
	if(game4.endGame==false){
		cout<<"OBJECT 4\n"<<endl;
		game4.one_object_game();//GAME4 ICIN HAMLELER ALINACAK VE ALINAN HAMLELER YAPILACAK
			//BU FONKSIYONUN ICINDE EGER OYUN BITTIYSE ENDGAME DEGISKENI TRUE OLACAK VE OBJECT ICIN OYUN BI DAH OYNANMAYACAK
	}
	if(game5.endGame==false){
		cout<<"OBJECT 5\n"<<endl;
		game5.one_object_game();//GAME5 ICIN HAMLELER ALINACAK VE ALINAN HAMLELER YAPILACAK
			//BU FONKSIYONUN ICINDE EGER OYUN BITTIYSE ENDGAME DEGISKENI TRUE OLACAK VE OBJECT ICIN OYUN BI DAH OYNANMAYACAK
	}
}while(game1.endGame==false&&game2.endGame==false&&game3.endGame==false&&game4.endGame==false&&game5.endGame==false);//BUTUN OYUNLAR BITMEDIKCE PROGRAM CALISMAYA DEVAM EDECEK

	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////77
	const int ConnectFour::currentHeight(){
		return row;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	const int ConnectFour::currentWidth(){
		return column;
	}		
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7	
	const int ConnectFour::Cell::getRow(){
		return row;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
	const char ConnectFour::Cell::getColumn(){
		return column;
	}	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7	
	void ConnectFour::Cell::setPos(int& rowPos,char& columnPos){
		row=rowPos;
		column=columnPos;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////777
	ConnectFour::ConnectFour(){
		cout<<"Let's Play The Game\n";
		
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	void ConnectFour::playGame(){
		cout<<"TO SAVE GAME .....'s'"<<endl<<"TO LOAD GAME .....'l'"<<endl;
		cout<<"CHOOSE GAME MOD "<<"TWO PLAYERS=(1) OR PLAYER-CPU=(2)"<<endl;
		cin>>game_mod; 
		if(game_mod!=2&&game_mod!=1){//GAME_MOD SARTLARA UYMAZSA BURAYA GIRER
			do{
	 		cerr<<"CHOOSE 1 OR 2 PLEASE:"; cin>>game_mod;
	 		}while(game_mod!=2&&game_mod!=1);//HATALI GIRISI ELE ALDIM
		}
		cout<< "Enter row size :"; cin>>row;//BOARD IN SATIR SAYISINI ALDIK
		cout<<"Enter column size :"; cin>>column;	//BOARDIN SUTUN SAYISINI ALDIK
		
		GameCells.resize(row);//SATIRÞARI OLUSTURDUK		
    	for(int i = 0 ; i <row ; ++i)
    	{
        	GameCells[i].resize(column);//HER SATIRA SUTUN OLUSUTRUDK
		}
    	/*char k=GameCells[1][2].getColumn(); BU NOKTADA BULUNAN CELL IN BULUNDUGU SUTUN U DONDURUYOR 
		cout<<k;*/
		displayCurrentBoard();//ILK BOARDU YAZDIRIDIM
	//EGER TEK OBJECT ILE OYNASAYDIK BURASI YETERLI OLACAKTI
	/*if(game_mod==1){//EGER GAME_MOD 1 SE OYUN 2 PLAYER LA OYNANACAK
		do{
		player2player();
		}while(endGame==false);//OYUN BITMEDIGI SURECE OYUN DEVAM EDECEK
	}
	else{
		do{
		player2cpu();
		}while(endGame==false);//OYUN BITMEDIGI SURECE OYUN DEVAM EDECEK
	}*/
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void ConnectFour::one_object_game(){
			if(game_mod==1){//EGER GAME_MOD 1 SE OYUN 2 PLAYER LA OYNANACAK
			displayCurrentBoard();//ILK BOARDU YAZDIRIDIM
			player2player();
		
			}
	
		else{
			displayCurrentBoard();//ILK BOARDU YAZDIRIDIM
			player2cpu();
			
		}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void ConnectFour::player2cpu(){
			
			int mov=move();
			play(mov,'X');//USER HAMLESI ALINACAK
			displayCurrentBoard();//HAMLDEEN SONRA OTUN BOARDU YAZDIRILACAK	
			endedGame('X');//OYUNUN BITIP BITMEDIGI KONTROL EDILECEK
				
				if(endGame==false){//OYUN BITMEDIYSE CPU HAMLE YAPAPACK
			play();//CPU HAMLE YAPACAK
			displayCurrentBoard();//CPU NUN HAMLESINDEN SONRA OYUN BOARDU YAZDIRILACAK	
			endedGame('O');//OYUNUN BITIP BITMEDIGI KONTROL EDILECEK
			}
				getLivingCells();
		

	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
	void ConnectFour::player2player(){
	
		int mov=move();
		play(mov,'X');//USER HAMLESI ALINACAK
		displayCurrentBoard();//HAMLDEN SONRAKI BOARD U YAZDIRDIK
		endedGame('X');//OYUN BITTIP BITMEDIGI KONTROL EDILDI 
			if(endGame==false){//OYUN HANLEDEN SONRA BITMEDIYSE KARSI TARAFIN HAMLESINE GECILCEK
		int mov2=move();
		play(mov2,'O');//USER HAMLESI ALINACAK
		displayCurrentBoard();
		endedGame('O');//OYUNUN BITIP BITMEDIGI KONTROL EDILDI
		}
		getLivingCells();

	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	inline void ConnectFour::displayCurrentBoard(){
	int k,i;
	for(k=0;k<column;k++){//TABLOUN ÜSTÜNDEKÝ HARFLERÝ YAZDIRDIM
		char column_name='A'+k;
		cout<<column_name;
		}
		cout<<endl;

		for(int   i = 0 ; i < row ; ++i){ 
			for(int j = 0 ; j <column ; ++j)
    		{     
				if(GameCells[i][j].isFull==false)//HAMLE YAPILDIKTAN SONRA YÝNE ORAYA NOKTA KOYMASIN DÝYE BU KONTROLÜ KOYDUM
				GameCells[i][j].cellSign='.';
   				cout<<GameCells[i][j].cellSign;
    			char colpos='A'+j;//CHAR A DONUSTURDUM
				GameCells[i][j].setPos(i,colpos);	//HER CELLIN DEGIKENLERINI BULUNDUGU POZISYONA GORE DEGISTIRFDIM
			}
		cout<<endl;
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                      
 	int ConnectFour::move(){
 			int k;
		char choice;
			do{
			cerr<<"Please Enter the Letter of Column:";
			cin>>choice;
			k=choice-'A';//ALDIÐIMIZ CHAR CHOÝCE U ÝNT E ÇEVÝRDÝM
					if(choice=='s'){//s GIRILIRSE OYUN KAYDEDILECEK
						writeFile();//OYUN KAYDEDILIYO...
						cout<<"file saved\n"; 
					}
					
					else if(choice=='l'){
						readFile();//KAYITLI OYUN DIZIYE ATANACAK
						displayCurrentBoard();
					}
			}while(k>column-1);//k YI KONTROL ETTÝM K ÝSTEDÝÐÝMÝZ GÝBÝ DEÐÝLSE TEKRAR ÝSTEYECEK
				
		 	if(GameCells[0][k].isFull==true){
				cerr<<"This column is full ,enter a new column please:";
				char c;
				cin>>c;//SÜTUN DOLUYSA YENÝ CHOÝCE ALIR
				k=(c-'A');
			}
	 return k;
	 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7 
 	void ConnectFour::play(int& position,char sign){
		int r=row;//GAME.ROW U YEDEKLEDIK CUNKU ASAGIDA GAME.ROW DEGERI DEGISTIKTEN SONRA TEKRAR BU DEGERE IHTIYACIMIZ OLACAK
		bool ctrl=false;
		 	do 
			{
				if ( GameCells[row-1][position].isFull != true)//BU NOKTANIN BOÞ OLUP OLMADIÐI KONTRL EDLÝR
				{
					GameCells[row-1][position].cellSign = sign;//HMALEYÝ YAPAN PLAYER IN HARFÝ ATANIR BU NOKTAYA
					 GameCells[row-1][position].isFull=true;
					ctrl=true;//HAMLE YAPILIRSA CONTROL TRUE OLUR VE BU DÖNGÜYE TEKRAR GÝRMEZ
				}
				else
					--row;//HAMLE YAPILMADIYSA BÝR ÜST SATIR A GEÇER //BURADA BU NESNEYE AIT ROW AZALDIGI ICIN ASAGIDA YDEKELDIGIMIZ DEGERI GERI ALDIK
			}while (  ctrl != true );// BU DÖNGÜ HERHNAGÝ BÝR YERE HAMLE YAPILANA KADAR DEVAM EDER*/
			row=r;	 //FONSIYONA GIREN ROW SAYISINI GERI ALDIK
	 }	 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
 	void ConnectFour::play(){//CPU HAMLE YAPACAK
 		cout<<"CPU'S TURN!!\n";
		 	int r=row;
			 int drop;
		drop=column/2;//BAÞLANGIÇ HAMLEYÝ ORTADAN YAPMAK STRATEJÝK OLARAK MANTIKLI
			if(GameCells[1][drop].isFull==true){
			drop=drop+1;
			}
			
			for( int i = row-1; i > 0; --i )
			{
				for( int j = column-1; j > 0; --j )
				{
			
					if( GameCells[i][j].cellSign == 'X'     &&//ÜÇ TANE X ÜST ÜSTEYSE BÝLGÝSAYAR OYUNUN KARÞI TARAF TARAFINDAN KAZANILMASINI ENGELLMEK ÝÇÝN O SÜTUNA HAMLE YAPR
						GameCells[i-1][j].cellSign == 'X' &&
						GameCells[i-2][j].cellSign == 'X' ){
						drop=j;	
						}
					 else if( GameCells[i][j].cellSign == 'O'&&//ÜÇ TANE O YÜST ÜSTEYSE BÝLGÝSAYAR OYUNU BÝTÝRMEK Ý.ÝN O SÜTUNA HAMLE YAPAR
						GameCells[i-1][j].cellSign == 'O' &&
						GameCells[i-2][j].cellSign == 'O'){
						drop=j;
						}
					 else if(GameCells[i][j].cellSign == 'X'&&//ÜÇ TANE X YAN YANAYSA BÝLGÝSAYAR OYUNUN KARÞI TARAF TARAFNINDAN KAZANILMASINI ENGELLEMEK ÝÇÝN O SATIR DA YAN SÜTUNA HAMLE YAPAR
						GameCells[i][j+1].cellSign == 'X' &&
						GameCells[i][j+2].cellSign == 'X'){	
						drop=j+3;			
						}
					  else if(GameCells[i][j].cellSign == 'X'&&//BÝR X BÝR BOÞLUK VE ÝKÝ X VARSA BÝLGÝSAYR ARAYA O YU KOYAR
						GameCells[i][j+2].cellSign == 'X' &&
						GameCells[i][j+3].cellSign == 'X'){	
						drop=j+1;			
						}
					  else if(GameCells[i][j].cellSign == 'X'&&//ÝKÝ X BÝR BOÞLUK VE BÝR X VARSA BÝLGÝSAYAR ARAYA O YU KOYAR
						GameCells[i][j+1].cellSign == 'X' &&
						GameCells[i][j+3].cellSign == 'X'){	
						drop=j+2;			
						}
					 else if(GameCells[i][j].cellSign == 'O'&&//ÜÇ TANE O YANYANAYSA BÝLGÝSAYAR KAZANMAK Ý.N DÖRDÜNCÜ O NUN OLMASI GEREKAN YERE HAMLE YAPR
						GameCells[i][j+1].cellSign == 'O' &&
						GameCells[i][j+2].cellSign == 'O'){
							drop=j+3;
						}
				}		
			}
		
		bool control=false;
	
			do //CPU NORMAL MOVE ÝÞLEMÝNÝ YAPAR
		{
			if ( GameCells[row-1][drop].isFull != true )//DÝZÝNÝN BU NOKTASININ DOLU OLUP OLMADIÐI KONTROL EDLÝLÝR
			{
				GameCells[row-1][drop].cellSign = 'O';//BU FONSÝYONU ÇALIÞTIRAN PLAYER IN HARF Ý BURAYA ATANIR
				GameCells[row-1][drop].isFull = true;//BU NOKTANIN DOLU OLDUGUNU BELIRTMIS OLDUK
				control=true;
			}
			else
			--row;//EÐER HAMLE YAPILMADIYSA BÝ ÜST SATIR A BAKILIR
		}while (  control != true );	//HERHANGÝ BÝ NOKTYAA HAMLE YAPILDIÐINDA TEKRAR WHÝLE DÖNGÜSÜNE GÝRMEZ	
	 	row=r;
	 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 	
	 void ConnectFour::endedGame(char sign){
		int ctrl=0; 
		for(int i=0;i<column;++i){
			if(GameCells[0][i].isFull!=false){// HER SÜTUNDAKÝ EN ÜST SATIRI KONTROL EDER VE EÐER ORADA NOKTA YOKSA YANÝ X YA DA O VARSA SAYACI BÝR ARTTÝRIR SAYAC SÝZE A EÞÝT OLDUÐUNDA OYUN BERAEBRA BÝTMÝÞ DEMEKTÝR
				ctrl++;
			}
		} 
		
		if(ctrl==column){//EGER CTRL COLUMN A ESIT OLDUYSA BUTUN SUTUNLAR DOLU DEMEKTIR
		 cout<<"Game is Draw\n"; //BUTUN SUTUNLAR DOLDUYSA OYUN BITER
		endGame=true;
		}
		
		int win=0;
		for( int i =0; i <row; i++ )//BÜTÜN SATIR VE SÜTUNLAR TEK TEK KONTROL EDÝLECEK
		{
			for( int j =0 ; j <column; j++ )
			{
				if( GameCells[i][j].cellSign ==sign&& GameCells[i][j-1].cellSign ==sign&&	GameCells[i][j-2].cellSign ==sign&&GameCells[i][j-3].cellSign ==sign)
				{
					win = 1;//4 TANE YAN YANA GELEBÝLECEK X YA DA O LARI KONTROL ETTÝM
				}
				if(GameCells[i][j].cellSign ==sign&&GameCells[i-1][j].cellSign ==sign&&GameCells[i-2][j].cellSign ==sign&&GameCells[i-3][j].cellSign ==sign)
				{	
					win = 1;//4 TANE ALT ALTA GELEBÝLCEK X YA DA O LARI KONTROL ETTÝM
				}
				if(GameCells[i][j].cellSign ==sign&&GameCells[i-1][j-1].cellSign ==sign&&GameCells[i-2][j-2].cellSign ==sign&&GameCells[i-3][j-3].cellSign ==sign)
				{
					win = 1;//4 TANE ÇAPARAZ OLARAK GELEBÝLCEK X VE O LARI KONTROL ETTÝM
				}
				if(GameCells[i][j].cellSign ==sign&&GameCells[i-1][j+1].cellSign==sign&&GameCells[i-2][j+2].cellSign ==sign&&GameCells[i-3][j+3].cellSign ==sign)
				{
					win = 1;//4 TANE DÝÐER TARAFA ÇAPARAZ OLARAK GELEBÝLCEK X VE O LARI KONTROL ETTÝM
				}
			}
		}
		if(win==1){//WIN 1 OLDUYSA YUKARIDAKI KOSULLADAN HERHANGI BIRI GERCEKLESMISTIR
		 display_last_board(sign);//OYUN KAZANILDIYSA KAZANAN DORTLUYU KUCULTUP BOARD U TEKRAR YAZDIRACAK
		 if(game_mod==1){
		 		if(sign=='X')
		 		cout<<"PLAYER ONE WON!!!!\n";
				else
				cout<<"PLAYER TWO WON!!!!\n";		 
		 }
		 else{
		 		if(sign=='X')
		 		cout<<"PLAYER ONE WON!!!!\n";
				else
				cout<<"CPU WON!!!!\n";		 
		 }
			endGame=true;//BUNU TRUE YA		
		}
	 }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void ConnectFour::display_last_board(char Sign){
		for(int k=0;k<column;k++){//BITTIKTEN SONRAKI OYUN BOARDUNU AYIRMAK ICIN YAPTIM 
		cout<<"--";
		} cout<<endl;	
			int k,i;
	for(k=0;k<column;k++){//E ÜSTTEKÝ HARFLERÝ YAZADIRDIM
		char column_name='A'+k;
		cout<<column_name;
		}
		cout<<endl;

	for( int i =0; i<row; i++ )
	{
		for( int j =0; j<column; j++ )
		{
			if( GameCells[i][j].cellSign ==Sign && GameCells[i+1][j+1].cellSign ==Sign && GameCells[i+2][j+2].cellSign ==Sign && GameCells[i+3][j+3].cellSign ==Sign)//EGER DORT TANE YI YANYANA BULDUYSA
			{
			//BULDUGU NIKYALARDAKI CHAR DEGERLERINI KUCULTUP YAZDIRACAK VE AYNI ISLEMI BUTUN OLASILIKLAR ICIN KONTROL EDECEK
			GameCells[i][j].cellSign =char(((int)Sign)+32); GameCells[i+1][j+1].cellSign =char(((int)Sign)+32); GameCells[i+2][j+2].cellSign =char(((int)Sign)+32); GameCells[i+3][j+3].cellSign=char(((int)Sign)+32);
			}
			if( GameCells[i][j].cellSign ==Sign &&GameCells[i][j+1].cellSign ==Sign &&GameCells[i][j+2].cellSign ==Sign &&GameCells[i][j+3].cellSign ==Sign)
			{
			GameCells[i][j].cellSign =char(((int)Sign)+32); GameCells[i][j+1].cellSign =char(((int)Sign)+32);	GameCells[i][j+2].cellSign =char(((int)Sign)+32); GameCells[i][j+3].cellSign =char(((int)Sign)+32);
			}
			if( GameCells[i][j].cellSign==Sign  &&	GameCells[i+1][j].cellSign ==Sign && GameCells[i+2][j].cellSign == Sign &&  GameCells[i+3][j].cellSign ==Sign )
			{	
			GameCells[i][j].cellSign =char(((int)Sign)+32);	GameCells[i+1][j].cellSign =char(((int)Sign)+32); GameCells[i+2][j].cellSign =char(((int)Sign)+32); GameCells[i+3][j].cellSign =char(((int)Sign)+32);
			}
			if( GameCells[i][j].cellSign ==Sign &&	GameCells[i+1][j-1].cellSign == Sign &&	GameCells[i+2][j-2].cellSign ==Sign &&	GameCells[i+3][j-3].cellSign == Sign)
			{
			GameCells[i][j].cellSign =char(((int)Sign)+32);	GameCells[i+1][j-1].cellSign =char(((int)Sign)+32);	GameCells[i+2][j-2].cellSign =char(((int)Sign)+32);GameCells[i+3][j-3].cellSign =char(((int)Sign)+32);
			}
			if ( GameCells[i][j].cellSign == Sign && GameCells[i][j+1].cellSign == Sign && GameCells[i][j+2].cellSign == Sign &&  GameCells[i][j+3].cellSign == Sign )
			{
			GameCells[i][j].cellSign =char(((int)Sign)+32); GameCells[i][j+1].cellSign =char(((int)Sign)+32); GameCells[i][j+2].cellSign =char(((int)Sign)+32); GameCells[i][j+3].cellSign =char(((int)Sign)+32); 
			}
			cout<<GameCells[i][j].cellSign;
		
		}
		cout<<endl;
	}
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void ConnectFour::writeFile(){
		ofstream file;
		file.open("Save File.txt");
	//	file<<row<<column<<game_mod<<endl;
		int k,i,j;
	for(k=0;k<column;k++){//TABLOUN ÜSTÜNDEKÝ HARFLERÝ YAZDIRDIM
		char column_name='A'+k;
		file<<column_name;
		}
		file<<endl;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			file<< GameCells[i][j].cellSign;
		}
			file << endl;
	}
		file.close();
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////77	
	void ConnectFour::readFile(){
	std::ifstream load("Save File.txt", std::ifstream::in);
	//load>>row>>column>>game_mod;
	
	int k;
	for(k=0;k<column;k++){//TABLOUN ÜSTÜNDEKÝ HARFLERÝ OKUTTUM
		char column_name='A'+k;
		load>>column_name;
		}
	int m,n;
	for(m = 0; m <row; m++)
	{
		for(n = 0; n <column; n++)
		{
			char data;
			load>>data;
			GameCells[m][n].cellSign=data;//ALINAN CHAR TIPINDEKI DATA YI DZININ BUTUN ELEMANLARNA ATADIM
			if(data=='X'|| data=='O')
			GameCells[m][n].isFull=true;
		}
	}
	cout<<endl;
	load.close();//DOSYA KAPATILDI
		
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
	void ConnectFour::getLivingCells(){
		for(int i=0;i<row;i++){ 
			for(int j=0;j<column;j++)
    		{     
				if(GameCells[i][j].isFull==true)//HAMLE YAPILDIKTAN SONRA YÝNE ORAYA NOKTA KOYMASIN DÝYE BU KONTROLÜ KOYDUM
				livingCells++;
    		}
		cout<<endl;
		}
	cout<<"Living Cells:"<<livingCells<<endl;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool ConnectFour::compareGames(const ConnectFour& game1,const ConnectFour& game2){//EGER PARAMETRE OLARAK ALDIGIMIZ OYUNLARDAN ILKI USER1 BI HAMLE SONRA_
	//OYUNU BITIREBILCEKSE TRUE EGEER IKINCISI BITIREBILECEKSE FALSE DONDURAN FONKSIYON//
		for( int i =0; i <game1.row; i++ )//BÜTÜN SATIR VE SÜTUNLAR TEK TEK KONTROL EDÝLECEK
		{
			for( int j =0 ; j <game1.column; j++ )
			{
				if( game1.GameCells[i][j].cellSign =='X'&& game1.GameCells[i][j-1].cellSign =='X'&&	game1.GameCells[i][j-2].cellSign =='X'&&game1.GameCells[i][j-3].cellSign!='O')
				{
					return true;//UC TANE X IN YANAYANA OLUP LMADIGINI VE ONLARIN YANINDA O OLMADIGINI  KONTROL ETTIM ve UC TANE X YANAYANAYSA GAME1 KULLANICI ICIN DAHA IYIDIR
					//EGER DURUM BU SEKILDEYSE GAME1 DE OYUN BIR HAMKE SONRA BITER BU YUZDEN GAME2 DEN DAHA IYIDIR
				}
				if(game1.GameCells[i][j].cellSign =='X'&&game1.GameCells[i-1][j].cellSign =='X'&&game1.GameCells[i-2][j].cellSign =='X'&&game1.GameCells[i-3][j].cellSign !='O')
				{	
					return true;//UC TANE X IN YANAYANA OLUP LMADIGINI VE ONLARIN YANINDA O OLMADIGINI  KONTROL ETTIM ve UC TANE X YANAYANAYSA GAME1 KULLANICI ICIN DAHA IYIDIR
					//EGER DURUM BU SEKILDEYSE GAME1 DE OYUN BIR HAMKE SONRA BITER BU YUZDEN GAME2 DEN DAHA IYIDIR				
				}
				if(game1.GameCells[i][j].cellSign =='X'&&game1.GameCells[i-1][j-1].cellSign =='X'&&game1.GameCells[i-2][j-2].cellSign =='X'&&game1.GameCells[i-3][j-3].cellSign !='O')
				{
					return true;//UC TANE X IN YANAYANA OLUP LMADIGINI VE ONLARIN YANINDA O OLMADIGINI  KONTROL ETTIM ve UC TANE X YANAYANAYSA GAME1 KULLANICI ICIN DAHA IYIDIR
					//EGER DURUM BU SEKILDEYSE GAME1 DE OYUN BIR HAMKE SONRA BITER BU YUZDEN GAME2 DEN DAHA IYIDIR	
				}
				if(game1.GameCells[i][j].cellSign =='X'&&game1.GameCells[i-1][j+1].cellSign=='X'&&game1.GameCells[i-2][j+2].cellSign =='X'&&game1.GameCells[i-3][j+3].cellSign !='O')
				{
					return true;//UC TANE X IN YANAYANA OLUP LMADIGINI VE ONLARIN YANINDA O OLMADIGINI  KONTROL ETTIM ve UC TANE X YANAYANAYSA GAME1 KULLANICI ICIN DAHA IYIDIR
					//EGER DURUM BU SEKILDEYSE GAME1 DE OYUN BIR HAMKE SONRA BITER BU YUZDEN GAME2 DEN DAHA IYIDIR	
				}
			}
		}
		
		for( int i =0; i <game2.row; i++ )//BÜTÜN SATIR VE SÜTUNLAR TEK TEK KONTROL EDÝLECEK
		{
			for( int j =0 ; j <game2.column; j++ )
			{
				if( game2.GameCells[i][j].cellSign =='X'&& game2.GameCells[i][j-1].cellSign =='X'&&	game2.GameCells[i][j-2].cellSign =='X'&&game2.GameCells[i][j-3].cellSign!='O')
				{
					return false;//UC TANE X IN YANAYANA OLUP LMADIGINI VE ONLARIN YANINDA O OLMADIGINI  KONTROL ETTIM ve UC TANE X YANAYANAYSA GAME1 KULLANICI ICIN DAHA IYIDIR
					//EGER DURUM BU SEKILDEYSE GAME1 DE OYUN BIR HAMKE SONRA BITER BU YUZDEN GAME2 DEN DAHA IYIDIR
				}
				if(game2.GameCells[i][j].cellSign =='X'&&game2.GameCells[i-1][j].cellSign =='X'&&game2.GameCells[i-2][j].cellSign =='X'&&game2.GameCells[i-3][j].cellSign !='O')
				{	
					return false;//UC TANE X IN YANAYANA OLUP LMADIGINI VE ONLARIN YANINDA O OLMADIGINI  KONTROL ETTIM ve UC TANE X YANAYANAYSA GAME1 KULLANICI ICIN DAHA IYIDIR
					//EGER DURUM BU SEKILDEYSE GAME1 DE OYUN BIR HAMKE SONRA BITER BU YUZDEN GAME2 DEN DAHA IYIDIR				
				}
				if(game2.GameCells[i][j].cellSign =='X'&&game2.GameCells[i-1][j-1].cellSign =='X'&&game2.GameCells[i-2][j-2].cellSign =='X'&&game2.GameCells[i-3][j-3].cellSign !='O')
				{
					return false;//UC TANE X IN YANAYANA OLUP LMADIGINI VE ONLARIN YANINDA O OLMADIGINI  KONTROL ETTIM ve UC TANE X YANAYANAYSA GAME1 KULLANICI ICIN DAHA IYIDIR
					//EGER DURUM BU SEKILDEYSE GAME1 DE OYUN BIR HAMKE SONRA BITER BU YUZDEN GAME2 DEN DAHA IYIDIR	
				}
				if(game2.GameCells[i][j].cellSign =='X'&&game2.GameCells[i-1][j+1].cellSign=='X'&&game2.GameCells[i-2][j+2].cellSign =='X'&&game2.GameCells[i-3][j+3].cellSign !='O')
				{
					return false;//UC TANE X IN YANAYANA OLUP LMADIGINI VE ONLARIN YANINDA O OLMADIGINI  KONTROL ETTIM ve UC TANE X YANAYANAYSA GAME1 KULLANICI ICIN DAHA IYIDIR
					//EGER DURUM BU SEKILDEYSE GAME1 DE OYUN BIR HAMKE SONRA BITER BU YUZDEN GAME2 DEN DAHA IYIDIR	
				}
			}
		}
	}	
