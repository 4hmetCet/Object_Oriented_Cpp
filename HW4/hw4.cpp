#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class ConnectFour
{
	private:
		class Cell
		{
			private:
				int row;
				char column;
			public:
				void setPos(int& rowPos, char& clumnPos);
				int getRow();//CELL IN BULUNDUGU ROW U DONDURECEK
				char getColumn();//CELL IN BULUNDUGU COLUMN U DONDURECEK
				bool isFull=false;//HUCRENIN OLUSAN HER NESNESININ isFull DEGISKENI DEFAULT OLARAK FALSE OLACAK VE O HUCRE DOLDUGUNDA TRUE OLACAK
				char sign;
				bool operator !=(const Cell& c1);//IKI CELL IN SIGN INI KARSILASTIRACAK FARKLI ISE TRUE DONDURECEK
				bool operator ==(const Cell& c1);//IKI CELL IN SIGN INI KARSILASTIRACAK IKISIDE X VEYA IKISIDE O ISE TRUE DONDURECEK		
				void operator ++();
				void operator --();
				void operator <<(Cell& c);
				void operator >>(Cell& c);	
			
		};
		int rowSize;
		int columnSize;
		int game_mod;
		Cell ** gameboard;
		void setGameMod();
		void setRowSize();
		void setColumnSize();
		int getRowSize();
		int getColumnSize();
		ConnectFour();//SIZE =5*5
		void write_to_file();//BU NESNEYI FILE A YAZACAK
		void read_from_file();//FILE DAN OKUDUGU OYUN OYNANACAK
		void show_current_board();
		void play();//CPU HAMLE YAPACAK
		void play(int& position,char sign);//KULLNICIDAN ALDIGI POZISTON PARAMETRE  OLARAK KULLANILACAK VE KULLANICI HAMLE YAPACAAK
		int move();//KULLANICIDAN HAMLE ALACAK VE DONDURECEK
		void endGame(char Sign);
		bool operator ==(const ConnectFour& game1);
		bool operator !=(const ConnectFour& game1);
		bool game_end=false;//OYUN BIITIGINDE BU DEGISKEN TRUE OLACAK
		void one_object_game();
		void player2player();
		void player2cpu();
		void change_to_lower(char Sign);
	public:
		ConnectFour(int number_of_rows, int number_of_columns);
		void playGame();
};
		
int main(){
ConnectFour game1(7,7);
game1.playGame();
//game2.playGame();
}
	ConnectFour::ConnectFour(){
	rowSize=5;
	columnSize=5;		
	}
	ConnectFour::ConnectFour(int number_of_rows, int number_of_columns){
		rowSize=number_of_rows;
		columnSize=number_of_columns;
	}
	void ConnectFour::setRowSize(){
		cout<< "Enter row size :"; 
		cin>>rowSize;//BOARD IN SATIR SAYISINI ALDIK
	}
	void ConnectFour::setColumnSize(){
			cout<<"Enter column size :"; 
			cin>>columnSize;	//BOARDIN SUTUN SAYISINI ALDIK
	}
	void ConnectFour::setGameMod(){
			cout<<"CHOOSE GAME MOD "<<"TWO PLAYERS=(1) OR PLAYER-CPU=(2)"<<endl;
		cin>>game_mod; 
		if(game_mod!=2&&game_mod!=1){//GAME_MOD SARTLARA UYMAZSA BURAYA GIRER
			do{
	 		cerr<<"CHOOSE 1 OR 2 PLEASE:"; cin>>game_mod;
	 		}while(game_mod!=2&&game_mod!=1);//HATALI GIRISI ELE ALDIM
		}
	}
	void ConnectFour::playGame(){
		cout<<"TO SAVE GAME .....'s'"<<endl<<"TO LOAD GAME .....'l'"<<endl;
		setGameMod();
		if(!rowSize&&!columnSize){
		setRowSize();
		setColumnSize();
		}
		 gameboard = new Cell*[rowSize];
		 int i, j;
    	for (i = 0; i < rowSize; i++)
        	gameboard[i] = new Cell[columnSize];
        	
        	
	do{
	 if(game_end==false)
	 	one_object_game();	
	}while(game_end==false);
}
 	void ConnectFour::show_current_board(){
		int k,i,j;
	for(k=0;k<columnSize;k++){//TABLOUN �ST�NDEK� HARFLER� YAZDIRDIM
		char column_name='A'+k;
		cout<<column_name;
	}
		cout<<endl;
		
		for(int   i = 0 ; i < rowSize ; ++i){ 
			for(int j = 0 ; j <columnSize ; ++j)
    		{     
				if(gameboard[i][j].isFull==false)//HAMLE YAPILDIKTAN SONRA Y�NE ORAYA NOKTA KOYMASIN D�YE BU KONTROL� KOYDUM
				 gameboard[i][j].sign='.';
   				cout<<gameboard[i][j].sign;
			}
		cout<<endl;
		}
}
	int ConnectFour::move(){
				int k;
		char choice;
			do{
			cerr<<"Please Enter the Letter of Column:";
			cin>>choice;
			k=choice-'A';//ALDI�IMIZ CHAR CHO�CE U �NT E �EV�RD�M
					if(choice=='s'){//s GIRILIRSE OYUN KAYDEDILECEK
						write_to_file();//OYUN KAYDEDILIYO...
						cout<<"file saved\n"; 
					}
					
					else if(choice=='l'){
						read_from_file();//KAYITLI OYUN DIZIYE ATANACAK
						show_current_board();
					}
			}while(k>columnSize-1|| k<0);//k YI KONTROL ETT�M K �STED���M�Z G�B� DE��LSE TEKRAR �STEYECEK
				
		 	if(gameboard[0][k].isFull==true){
				cerr<<"This column is full ,enter a new column please:";
				char c;
				cin>>c;//S�TUN DOLUYSA YEN� CHO�CE ALIR
				k=(c-'A');
			}
	 return k;
}
	void ConnectFour::one_object_game(){
			if(game_mod==1){//EGER GAME_MOD 1 SE OYUN 2 PLAYER LA OYNANACAK
			show_current_board();//ILK BOARDU YAZDIRIDIM
			player2player();//BU FONKSIYONUN ICINDE IKI TAFARTANDA HAMLE ALINACAK
		
			}
	
		else{
			show_current_board();//ILK BOARDU YAZDIRIDIM
			player2cpu();//BU FONKSIYONDA ONCE KULLANICI SONRA DA CPU HAMLE YAPACAK
		}
}
	void ConnectFour::player2cpu(){
			
			int mov=move();
			play();//USER HAMLESI ALINACAK
			show_current_board();//HAMLDEEN SONRA OTUN BOARDU YAZDIRILACAK	
			endGame('X');//OYUNUN BITIP BITMEDIGI KONTROL EDILECEK
				
				if(game_end==false){//OYUN BITMEDIYSE CPU HAMLE YAPAPACK
			play();//CPU HAMLE YAPACAK
			show_current_board();//CPU NUN HAMLESINDEN SONRA OYUN BOARDU YAZDIRILACAK	
			endGame('O');//OYUNUN BITIP BITMEDIGI KONTROL EDILECEK
			}
	}
	void ConnectFour::player2player(){
		int mov=move();
		play(mov,'X');//USER HAMLESI ALINACAK
		show_current_board();//HAMLDEN SONRAKI BOARD U YAZDIRDIK
		endGame('X');//OYUN BITTIP BITMEDIGI KONTROL EDILDI 
			
			if(game_end==false){//OYUN HANLEDEN SONRA BITMEDIYSE KARSI TARAFIN HAMLESINE GECILCEK
		int mov2=move();
		play(mov2,'O');//USER HAMLESI ALINACAK
		show_current_board();
		endGame('O');//OYUNUN BITIP BITMEDIGI KONTROL EDILDI		
		}
	}		
	void ConnectFour::play(int& position,char sign){
		int r=rowSize;//GAME.ROW U YEDEKLEDIK CUNKU ASAGIDA GAME.ROW DEGERI DEGISTIKTEN SONRA TEKRAR BU DEGERE IHTIYACIMIZ OLACAK
		bool ctrl=false;
		 	do
			{
				if ( gameboard[rowSize-1][position].isFull != true)//BU NOKTANIN BO� OLUP OLMADI�I KONTRL EDL�R
				{
					gameboard[rowSize-1][position].sign = sign;//HMALEY� YAPAN PLAYER IN HARF� ATANIR BU NOKTAYA
					 gameboard[rowSize-1][position].isFull=true;
					ctrl=true;//HAMLE YAPILIRSA CONTROL TRUE OLUR VE BU D�NG�YE TEKRAR G�RMEZ
				}
				else
					--rowSize;//HAMLE YAPILMADIYSA B�R �ST SATIR A GE�ER //BURADA BU NESNEYE AIT ROW AZALDIGI ICIN ASAGIDA YDEKELDIGIMIZ DEGERI GERI ALDIK
			}while (  ctrl != true );// BU D�NG� HERHNAG� B�R YERE HAMLE YAPILANA KADAR DEVAM EDER*/
			rowSize=r;	 //FONSIYONA GIREN ROW SAYISINI GERI ALDIK
	
}	 
	void ConnectFour::endGame(char Sign){
		
		int ctrl=0; 
		for(int i=0;i<columnSize;++i){
			if(gameboard[0][i].isFull==true){// HER S�TUNDAK� EN �ST SATIRI KONTROL EDER VE E�ER ORADA NOKTA YOKSA YAN� X YA DA O VARSA SAYACI B�R ARTT�RIR SAYAC S�ZE A E��T OLDU�UNDA OYUN BERAEBRA B�TM�� DEMEKT�R
				ctrl++;
			}
		} 
		
		if(ctrl==columnSize){//EGER CTRL COLUMN A ESIT OLDUYSA BUTUN SUTUNLAR DOLU DEMEKTIR
		 cout<<"Game is Draw\n"; //BUTUN SUTUNLAR DOLDUYSA OYUN BITER
		game_end=true;
		}

		int win=0;
		for( int i =0; i <rowSize; i++ )//B�T�N SATIR VE S�TUNLAR TEK TEK KONTROL ED�LECEK
		{
			for( int j =0 ; j <columnSize; j++ )
			{
				if( gameboard[i][j].sign ==Sign&& gameboard[i][j-1].sign ==Sign&&	gameboard[i][j-2].sign ==Sign&&gameboard[i][j-3].sign ==Sign)
				{	
					win = 1;//4 TANE YAN YANA GELEB�LECEK X YA DA O LARI KONTROL ETT�M
				}
				if(gameboard[i][j].sign ==Sign && gameboard[i-1][j].sign ==Sign && gameboard[i-2][j].sign ==Sign && gameboard[i-3][j].sign ==Sign)
				{	
					win = 1;//4 TANE ALT ALTA GELEB�LCEK X YA DA O LARI KONTROL ETT�M
				}
				if(gameboard[i][j].sign ==Sign&&gameboard[i-1][j-1].sign ==Sign&&gameboard[i-2][j-2].sign ==Sign&&gameboard[i-3][j-3].sign ==Sign)
				{
					win = 1;//4 TANE �APARAZ OLARAK GELEB�LCEK X VE O LARI KONTROL ETT�M
				}
				if(gameboard[i][j].sign ==Sign&&gameboard[i-1][j+1].sign==Sign&&gameboard[i-2][j+2].sign ==Sign&&gameboard[i-3][j+3].sign ==Sign)
				{
					win = 1;//4 TANE D��ER TARAFA �APARAZ OLARAK GELEB�LCEK X VE O LARI KONTROL ETT�M
				}
			}
		}
		if(win==1){//WIN 1 OLDUYSA YUKARIDAKI KOSULLADAN HERHANGI BIRI GERCEKLESMISTIR
		// change_to_lower(Sign);//OYUN KAZANILDIYSA KAZANAN DORTLUYU KUCULTUP BOARD U TEKRAR YAZDIRACAK
		 show_current_board();
		 if(game_mod==1){
		 		if(Sign=='X')
		 		cout<<"PLAYER ONE WON!!!!\n";
				else
				cout<<"PLAYER TWO WON!!!!\n";		 
		 }
		 else{
		 		if(Sign=='X')
		 		cout<<"PLAYER ONE WON!!!!\n";
				else
				cout<<"CPU WON!!!!\n";		 
		 }
			game_end=true;//BUNU TRUE YA		
		}
	 }
	void ConnectFour::play(){//CPU HAMLE YAPACAK
	
 		cout<<"CPU'S TURN!!\n";
		 	int r=rowSize;
			 int drop;
		drop=columnSize/2;//BA�LANGI� HAMLEY� ORTADAN YAPMAK STRATEJ�K OLARAK MANTIKLI
			if(gameboard[1][drop].isFull==true){
			drop=drop+1;
			}
			
			for( int i = rowSize-1; i > 0; --i )
			{
				for( int j = columnSize-1; j > 0; --j )
				{
			
					if( gameboard[i][j].sign == 'X'     &&//�� TANE X �ST �STEYSE B�LG�SAYAR OYUNUN KAR�I TARAF TARAFINDAN KAZANILMASINI ENGELLMEK ���N O S�TUNA HAMLE YAPR
						gameboard[i-1][j].sign == 'X' &&
						gameboard[i-2][j].sign == 'X' ){
						drop=j;	
						}
					 else if( gameboard[i][j].sign == 'O'&&//�� TANE O Y�ST �STEYSE B�LG�SAYAR OYUNU B�T�RMEK �.�N O S�TUNA HAMLE YAPAR
						gameboard[i-1][j].sign == 'O' &&
						gameboard[i-2][j].sign == 'O'){
						drop=j;
						}
					 else if(gameboard[i][j].sign == 'X'&&//�� TANE X YAN YANAYSA B�LG�SAYAR OYUNUN KAR�I TARAF TARAFNINDAN KAZANILMASINI ENGELLEMEK ���N O SATIR DA YAN S�TUNA HAMLE YAPAR
						gameboard[i][j+1].sign == 'X' &&
						gameboard[i][j+2].sign == 'X'){	
						drop=j+3;			
						}
					  else if(gameboard[i][j].sign == 'X'&&//B�R X B�R BO�LUK VE �K� X VARSA B�LG�SAYR ARAYA O YU KOYAR
						gameboard[i][j+2].sign == 'X' &&
						gameboard[i][j+3].sign == 'X'){	
						drop=j+1;			
						}
					  else if(gameboard[i][j].sign == 'X'&&//�K� X B�R BO�LUK VE B�R X VARSA B�LG�SAYAR ARAYA O YU KOYAR
						gameboard[i][j+1].sign == 'X' &&
						gameboard[i][j+3].sign == 'X'){	
						drop=j+2;			
						}
					 else if(gameboard[i][j].sign == 'O'&&//�� TANE O YANYANAYSA B�LG�SAYAR KAZANMAK �.N D�RD�NC� O NUN OLMASI GEREKAN YERE HAMLE YAPR
						gameboard[i][j+1].sign == 'O' &&
						gameboard[i][j+2].sign == 'O'){
							drop=j+3;
						}
				}		
			}
		
		bool control=false;
	
			do //CPU NORMAL MOVE ��LEM�N� YAPAR
		{
			if ( gameboard[rowSize-1][drop].isFull != true )//D�Z�N�N BU NOKTASININ DOLU OLUP OLMADI�I KONTROL EDL�L�R
			{
				gameboard[rowSize-1][drop].sign = 'O';//BU FONS�YONU �ALI�TIRAN PLAYER IN HARF � BURAYA ATANIR
				gameboard[rowSize-1][drop].isFull = true;//BU NOKTANIN DOLU OLDUGUNU BELIRTMIS OLDUK
				control=true;
			}
			else
			--rowSize;//E�ER HAMLE YAPILMADIYSA B� �ST SATIR A BAKILIR
		}while (  control != true );	//HERHANG� B� NOKTYAA HAMLE YAPILDI�INDA TEKRAR WH�LE D�NG�S�NE G�RMEZ	
	 	rowSize=r;
	 }	 
	void ConnectFour::change_to_lower( char Sign){

	for( int i =0; i < rowSize; i++ )
	{
		for( int j =0; j < columnSize; j++ )
		{
			if( gameboard[i][j].sign ==Sign && gameboard[i+1][j+1].sign ==Sign && gameboard[i+2][j+2].sign ==Sign && gameboard[i+3][j+3].sign == Sign)
			{
			gameboard[i][j].sign =char(((int)Sign)+32); gameboard[i+1][j+1].sign =char(((int)Sign)+32); gameboard[i+2][j+2].sign =char(((int)Sign)+32); gameboard[i+3][j+3].sign=char(((int)Sign)+32);
			}
			if( gameboard[i][j].sign ==Sign   && gameboard[i][j+1].sign == Sign &&	gameboard[i][j+2].sign == Sign &&	gameboard[i][j+3].sign == Sign)
			{
			gameboard[i][j].sign =char(((int)Sign)+32); gameboard[i][j+1].sign =char(((int)Sign)+32);	gameboard[i][j+2].sign =char(((int)Sign)+32); gameboard[i][j+3].sign =char(((int)Sign)+32);
			}
			if( gameboard[i][j].sign ==Sign  &&	gameboard[i+1][j].sign ==Sign && gameboard[i+2][j].sign == Sign &&  gameboard[i+3][j].sign ==Sign )
			{	
			gameboard[i][j].sign =char(((int)Sign)+32);	gameboard[i+1][j].sign =char(((int)Sign)+32); gameboard[i+2][j].sign =char(((int)Sign)+32); gameboard[i+3][j].sign =char(((int)Sign)+32);
			}
			if( gameboard[i][j].sign ==Sign     &&	gameboard[i+1][j-1].sign == Sign &&	gameboard[i+2][j-2].sign ==Sign &&	gameboard[i+3][j-3].sign== Sign)
			{
			gameboard[i][j].sign =char(((int)Sign)+32);	gameboard[i+1][j-1].sign =char(((int)Sign)+32);	gameboard[i+2][j-2].sign =char(((int)Sign)+32);gameboard[i+3][j-3].sign =char(((int)Sign)+32);
			}
		
		}
	}
	}
	bool ConnectFour::Cell::operator ==(const Cell& c1){
		
		return(sign==c1.sign);
	}
	bool ConnectFour::Cell::operator!=(const Cell& c1){
		return (sign!=c1.sign);
	}
	bool ConnectFour::operator ==(const ConnectFour& game1){//IKI AYRI OBJENIN GAMEBOARD LARINI X VE O LARIN YERLERINE GORE KARSILASTIRACAK
	if((this->rowSize==game1.rowSize)&&(this->columnSize==game1.columnSize)){//KARSILASRIRILAN IKI OBJENIN ROW VW COLUMN SAYSISI AYNIYSA HUCRELERI KONTROL EDERIM 
		bool sonuc=true;//HERHANGI BI CELL IN FARKLI OLMASI BU OPERATOR UN FALSE OLMASI ICIN YETERLI
		for(int i=0;i<rowSize; i++){
			for(int j=0;j<columnSize; j++){
				if(this->gameboard[i][j]!=game1.gameboard[i][j]){//HER IKI OYUNUNDA TUM CELL LERINI KONTROL EDECEK VE EGER HERHANGI IKI CELL ESIT OLMAZSA SONUC FALSE OLAACAK TUM CELL LER ESITSE TRUE OLACAK
				//BURADA DAHA ONCE OVERLOAD ETTIGIMIZ CELL ICIN OLAN '!=' OPERATORUNU KULLNADIM 
					sonuc=false;
				}
			}
		}
	return sonuc;//SONUC DEGERINI DONDURECEK
	}
	else return false;//IF E GIRMEDIYSE YANI ROW VE COLUMN SAYISI FARKLIYSA D�REK FALSE DONDURUR
	}
	bool ConnectFour::operator !=(const ConnectFour& game1){//IKI AYRI OBJENIN GAMEBOARD LARINI X VE O LARIN YERLERINE GORE KARSILASTIRACAK
	if((this->rowSize==game1.rowSize)&&(this->columnSize==game1.columnSize)){//KARSILASRIRILAN IKI OBJENIN ROW VW COLUMN SAYSISI AYNIYSA HUCRELERI KONTROL EDERIM
		int count=0;//TUM CELLERIN KONTROL EDILMESI LAZIM 
		for(int i=0;i<rowSize; i++){
			for(int j=0;j<columnSize; j++){
				if(this->gameboard[i][j]==game1.gameboard[i][j]){//HER IKI OYUNUNDA TUM CELL LERINI KONTROL EDECEK VE EGER HERHANGI IKI CELL ESITSE COUNTER  BIR ARTAR 
				//DAHA ONCE OVERLOAD ETTIGIMIZ CELL ICIN OLAN '==' OPERATORUNU KULLANDIM O DA CELL IN SIGN LARINI KARSILASTIRACAK
					count++;
				}
			}
		}
				if(count==(rowSize*columnSize)) return false;//EGER COUNT BTUN HUCRELIRN TOPLAM SAYISINA ESITSE T�M HUCRELER AYNI DEMEKTIR
				else return true;//EGER BIR HUCRE BILE FARKLIYSA COUNT DEGERI FARKLI OLACAK BUDA IKI TABLONUN AYNI OLMADIGI ANLAMINA GELRI VE FALSE DONER
	}
	else return true;//KARSILASTIRILAN IKI OBJENIN ROW VE COLUMN SAYILARI FARKLIYSA ZATEN DIREK TRUE DONER
	}
	void ConnectFour::write_to_file(){
		ofstream file;
		file.open("Save File.txt");
	//	file<<row<<column<<game_mod<<endl;
		int k,i,j;
	for(k=0;k<columnSize;k++){//TABLOUN �ST�NDEK� HARFLER� YAZDIRDIM
		char column_name='A'+k;
		file<<column_name;
		}
		file<<endl;
	for(i = 0; i < rowSize; i++)
	{
		for(j = 0; j < columnSize; j++)
		{
			file<< gameboard[i][j].sign;
		}
			file << endl;
	}
		file.close();
	}	
	void ConnectFour::read_from_file(){
	std::ifstream load("Save File.txt", std::ifstream::in);
	//load>>row>>column>>game_mod;
	
	int k;
	for(k=0;k<columnSize;k++){//TABLOUN �ST�NDEK� HARFLER� OKUTTUM
		char column_name='A'+k;
		load>>column_name;
		}
	int m,n;
	for(m = 0; m <rowSize; m++)
	{
		for(n = 0; n <columnSize; n++)
		{
			char data;
			load>>data;
			gameboard[m][n].sign=data;//ALINAN CHAR TIPINDEKI DATA YI DZININ BUTUN ELEMANLARNA ATADIM
			if(data=='X'|| data=='O')
			gameboard[m][n].isFull=true;
		}
	}
	cout<<endl;
	load.close();//DOSYA KAPATILDI
		
	}
	
