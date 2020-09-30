#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include"ConnectFourAbstract.h"	
#include"Cell.h"
using namespace std;
namespace my_namespace
{
	const void ConnectFourAbstract::setGameMod(){
			cout<<"CHOOSE GAME MOD "<<"TWO PLAYERS=(P) OR PLAYER-CPU=(C)"<<endl;
		cin>>game_mod; 
		if(game_mod!='P'&&game_mod!='C'){//GAME_MOD SARTLARA UYMAZSA BURAYA GIRER
			do{
	 		cerr<<"CHOOSE P OR C PLEASE:"; cin>>game_mod;
	 		}while(game_mod!='P'&&game_mod!='C');//HATALI GIRISI ELE ALDIM
		}
	}
	void ConnectFourAbstract::playGame(){
		setRowSize();//ROW SSIZE KULLANICIDAN ALINDI
		setColumnSize();//COLUMN SIZE KULLANICIDAN ALINDI
		setGameMod();//GAME MOD KULLANICIDAN ALINDI
		gameboard = new Cell*[rowSize];
		 int i, j;
    	for (i = 0; i < rowSize; i++)
        	gameboard[i] = new Cell[columnSize];
        //BURADA KULLANACAGIMIZ DIZIYI OLUSTURDUK
        	
		do{
	 	if(game_end==false)
	 		one_object_game();	//OYUN BU FONSIYONUN ICINDE OYNANACAK
		}while(game_end==false);//OYUN BITENE KADAR OYUN OYNANACAK
		
		}
	void ConnectFourAbstract::show_current_board(){
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
	const void ConnectFourAbstract::setRowSize(){
	bool valid = false;
	while (!valid)
	{
		valid = true; //DOGRUYSA TRUE OLACAK.
		cout << "Enter row size: " << endl;
		cin >> rowSize;
		if(cin.fail()) //EGER TYPE DORU DEGILSE BURAYA GIRECEK
		{
			cin.clear();
			cin.ignore(); 
			cout << "Please enter an Integer only." << endl;
			valid = false; //TYPE DOGRU DEGIL TEKRAR GIR
		}

	}

	}
	const void ConnectFourAbstract::setColumnSize(){
		bool valid = false;
	while (!valid)
	{
		valid = true; //DOGRUYSA TRUE OLACAK.
		cout << "Enter column size: " << endl;
		cin >> columnSize;
		if(cin.fail()) //EGER TYPE DORU DEGILSE BURAYA GIRECEK
		{
			cin.clear();
			cin.ignore(); 
			cout << "Please enter an Integer only." << endl;
			valid = false; //TYPE DOGRU DEGIL TEKRAR GIR
		}

	}

	}
	void ConnectFourAbstract::write_to_file(){
		ofstream file;
		file.open(file_name.c_str());
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
	void ConnectFourAbstract::read_from_file(){
	std::ifstream load(file_name.c_str(), std::ifstream::in);//GIRILEN KOMUTA GORE DEGISEN FILE_NAME DEGISKENININ ADI OLDUGU DOSYA OKUNUR
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
	int ConnectFourAbstract::move(){
		int k=-2;
				string komut;
		string  string_choice;
			do{
			cerr<<"Please Enter the Letter of Column:";
			cin>>string_choice;
				getline(cin,komut);
				string bosluk=" ";
				string my_string(komut);
				komut=my_string.substr(0,my_string.find_first_of(bosluk));
				file_name=my_string.substr(my_string.find_first_of(bosluk)+1);
				
					if(string_choice=="SAVE"){//s GIRILIRSE OYUN KAYDEDILECEK
					write_to_file();//OYUN KAYDEDILIYO...
					cout<<"file saved\n"; 
					}
					
					else if(string_choice=="LOAD"){
						read_from_file();//KAYITLI OYUN DIZIYE ATANACAK
						show_current_board();
						cout<<"Loaded game\n";
					}
					else if(string_choice.length()==1){
					char choice=string_choice[0];
					k=choice-'A';
						if(gameboard[0][k].isFull==true){//EN UST DATIR DOLUYSA
							cerr<<"This column is full ,enter a new column please:";
							k=-1;//DOLUYSA K YI -1 YAPTIM KI DONGUYE TEKRAR GIRSIN
						}
					}
			
			}while(k>columnSize-1|| k<0);//k YI KONTROL ETT�M K �STED���M�Z G�B� DE��LSE TEKRAR �STEYECEK
				
		 
	 return k;
}
	const void ConnectFourAbstract::one_object_game(){
			if(game_mod=='P'){//EGER GAME_MOD 1 SE OYUN 2 PLAYER LA OYNANACAK
			show_current_board();//ILK BOARDU YAZDIRIDIM
			player2player();//BU FONKSIYONUN ICINDE IKI TAFARTANDA HAMLE ALINACAK
		
			}
	
		else{
			show_current_board();//ILK BOARDU YAZDIRIDIM
			player2cpu();//BU FONKSIYONDA ONCE KULLANICI SONRA DA CPU HAMLE YAPACAK
		}
}
	void ConnectFourAbstract::player2cpu(){
			
			int mov=move();
			if(mov!=-1){//UNDO OLMADIYSA
			play(mov,'X');//USER HAMLESI ALINACAK
			show_current_board();//HAMLDEEN SONRA OTUN BOARDU YAZDIRILACAK	
			endGame('X');//OYUNUN BITIP BITMEDIGI KONTROL EDILECEK
				}
				if(game_end==false){//OYUN BITMEDIYSE CPU HAMLE YAPAPACK
			play();//CPU HAMLE YAPACAK
			show_current_board();//CPU NUN HAMLESINDEN SONRA OYUN BOARDU YAZDIRILACAK	
			endGame('O');//OYUNUN BITIP BITMEDIGI KONTROL EDILECEK
			}
		
	}
	void ConnectFourAbstract::player2player(){
		int mov=move();
		if(mov!=-1){//YANI UNDO OLMADIYSA
		play(mov,'X');//USER HAMLESI ALINACAK
		show_current_board();//HAMLDEN SONRAKI BOARD U YAZDIRDIK
		endGame('X');//OYUN BITTIP BITMEDIGI KONTROL EDILDI 
		}
			if(game_end==false){//OYUN HANLEDEN SONRA BITMEDIYSE KARSI TARAFIN HAMLESINE GECILCEK
		int mov2=move();
		if(mov2!=-1){//YANI UNDO OLMADIYSA
		play(mov2,'O');//USER HAMLESI ALINACAK
		show_current_board();
		endGame('O');//OYUNUN BITIP BITMEDIGI KONTROL EDILDI		
		}
		}
	}		
	void ConnectFourAbstract::play(int& position,char sign){
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
	 void ConnectFourAbstract::endGame(char Sign){
		//BU FONKSIYON OYUN BITIRME FONKSIYONU ALT SINIFLAR ICIN OVERR�DE EDILMISTIR
	 }
	void ConnectFourAbstract::play(){//CPU HAMLE YAPACAK
	
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
		moves.push_back(drop);//BILGISAYAR HAMLE YAPTIKTAN SONRADA MOVES DIZISINE KAYDEDECEK BOYLECE BILGISAYRIN HAMLESI GERI ALINABILCEK
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
	void ConnectFourAbstract::change_to_lower( char Sign){

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
	const int ConnectFourAbstract::currentwidth(){
		return columnSize;//COLUMN GERI DONECEK
	}
	const int ConnectFourAbstract::currentheight(){
		return rowSize;//ROW GERI DONECEK
	}
	
}

