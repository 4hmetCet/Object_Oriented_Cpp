//Ahmet �ET�NKAYA
//Connect 4 
#include <iostream>
#include<fstream>
#include<string>
using namespace std;
struct Game
{
	char playerSign;
};
int enter_size();///BU FONSIYONDA OLUSTUTULACAK TABLONUN BOYUTUNU KULLANICIDAN ALIP GERI DONDURECEK
int enter_game_mod();//BU FONKSIYON OYUNUN HANGI MODDA OYANANCGINI KULLANICIYA SORUP GERI DONDURECEK
void show_starting_board(char board[][21],const int& size);//show_board fonksiyonun i�indeki kontrol den dolay� tablodan ��kan X ve O lar� engellemek i�in yazd�m 
//CONSTANT PARAMETER BY REFERENCE I KULLNADIK �UNKU BURDA BELILEDIGIMIZ SIZE HIC DEGISMEYECEK
void Show_Board ( char board[][21] ,const int& size);//oyun tablosunu g�stereck
//CONSTANT PARAMETER BY REFERENCE I KULLNADIK �UNKU BURDA BELILEDIGIMIZ SIZE HIC DEGISMEYECEK
void move(char board[][21],int size,char& choice,Game player);//girilen hamleyi al�p tablo �zerinde de�i�iklik yapacak
// BU fonksiyonda call by reference parametreleri kulland�m
int finish(char board[][21],int size,Game player);//oyunun bitip bitmedi�ini kontrul edecek
int draw(char board[][21],int size);//tablonun dolup dolmad���n� yani oyunun berabere bitip bitmedi�ini kontrol edecek
void cpu_move(char board[][21],int size,int cpu_choice,char sign='O');//cpu nun karar verdi�i s�tuna hamleyi yapacak ve bunu cpu_choice olarak alacak
//BU FONSIYONDA CPU NUN YZACAGI ISARETI DEFAULT OLARAK BELIRLEDIK
int cpu_drop(char board[][21],int size);//cpu nun hamle yapca�� s�tunu geri d�nd�recek
void show_last_board(char board[][21],int size,Game player);//board u kontrol edip kazand�ran d�rtl�y� lower case yapt�m
void saveFile(char board[][21],int size,int game_mod);//BU FONSIYON PARAMETRE OLARAK ALDIGI BOARD U size I ve game_mod u farkl� dosyalara kaydedeck //BU FONKSIYON MOVE FAONSIYONUNUN I�INDE OLACAK
void loadFile(char board[][21],int size);///DAHA ONCEDEEN KAYTILI TABLOYU ALIP EKRANA YAZDIRACAK VE OYUN KALDIGI YERDEN DEVAM EDECEEK
int loaded_game_size(char board[][21]);//SAVEFILE DOSYASININ KAYDETTIGI SIZE I O DOSYADAN OKUYACAK VE DONDURECEK
int loaded_game_mod(char board[][21]);//SAVEFILE DOSYASININ KAYDETTIGI GAME_MOD U DOSYADAN OKUYACAK VE DONDURECEK
int main(int argc, char** argv)
{
	Game playerOne; 
	decltype(playerOne) playerTwo,cpu;//playerOne NE OLARAK TANIMLANDIYSA playerTwo ve cpu AYNISI OLMALI
	char board[21][21]; //MAX BOYUTLARDA BI CIFT BOYUTLU DIZI TANIMLADIM
	int game_mod,size;
	cout << "Let's Play Connect 4" << endl ;
		cout<<"TO SAVE GAME .....'s'"<<endl<<"TO LOAD GAME .....'l'"<<endl;
	cout<<"Do You Contineu From Loaded Game"<<endl<<"Yes=1 or No=2"<<endl;
	int cont_loaded; cin>>cont_loaded;///KULLANICININ GIRDIGI DEGERE GORE OYUN YA KAYITLI OYUNDAN BASLAYCAK YA BASTAN BASLAYCAK
	if(cont_loaded!=1&& cont_loaded!=2){
		do{
		cerr<<"1 or 2 please.....:";///KULLANICI 1  YA DA 1 DISINDA BI SAYI GIRERSE 1 YA DA 2 GIRENE KADAR HATA ISTEYECEK
		cin>>cont_loaded;
		}while(cont_loaded!=1&& cont_loaded!=2);
	}
	if(cont_loaded==1){//EGER 1 SE KAYITLI OYUNDAN DEVAM EDECEK
		size=loaded_game_size(board);//BU FONKSIYONUN DOSYADAN OKUDUGU DEGERI SIZE A ATAYACAK
		game_mod= loaded_game_mod(board);//BU FONKSIYONUN DOSYADAN OKUDUGU DEGERI GAME_MOD A ATAYACAK
		 loadFile(board,size);//KAYITLI OYUN DIZIYE ATANACAK
		Show_Board( board , size);//KAYITLI OYUN GOSTERILECEK
	}
	else{//EGER KULLANICI 2 GIRDIYSE OYUN NIRMAL OYNANACAK
	size=enter_size();//BU FONKSIYONLA KULLANICIDAN ALINAN SIZE  size A ATANDI
	game_mod=enter_game_mod();//BU FONKSIYONLA KULLANICIDAN ALINAN GAME MOD BELIRLENCEK
	show_starting_board(board,size);
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//BURDAN SONRA OYUN BASLAYACAK VE ILK HMALEYI PLAYER ONE YAPACAK
	if(game_mod==1){playerOne.playerSign='O'; playerTwo.playerSign='X';
		while(1){//OYUN SONSUZ DINGUDE CALISACAK VE KAZANAN OLDUGU ANDA BREAK YAPACAK EGER KAZANAN OLMAZSADA BUTUN SATUR VE SUTUNLAR DOLDUGUNDA OYUN BERABERE BITCEK
			char choice;
			int k;
			cout<<"PlayerOne Please Enter the Letter of Column:";
			cin>>choice;	k=choice-'A';//GIRILEN HARF INT E DONUSTURULDU
				if(choice=='s'){//s GIRILIRSE OYUN KAYDEDILECEK
				saveFile(board,size,game_mod);//OYUN KAYDEDILIYO...
				cout<<"file saved\n"; 
			}
				else if(choice=='l'){
						size=loaded_game_size(board);//BU FONKSIYONUN DOSYADAN OKUDUGU DEGERI SIZE A ATAYACAK
						game_mod= loaded_game_mod(board);//BU FONKSIYONUN DOSYADAN OKUDUGU DEGERI GAME_MOD A ATAYACAK
						loadFile(board,size);//KAYITLI OYUN DIZIYE ATANACAK
						Show_Board( board , size);//KAYITLI OYUN GOSTERILECEK
				}
			if(k>size-1){//CHOICE SARTLARA UYMAZSA BURAYA GIRER
			do{
			cerr<<"PlayerOne Please Enter Correct Letter of Column:";//HATAYI CERR KULLANRARK YAZDIM
			cin>>choice;
					if(choice=='s'){//HATALI BI GIRI� OLDUKTAN SONRADA OYUN KAYDEDILMESI I�IN BURAYA DA YAZDIM
				saveFile(board,size,game_mod);//OYUN KAYDEDILIYO
				cout<<"file saved\n"; 
			}
					else if(choice=='l'){
						size=loaded_game_size(board);//BU FONKSIYONUN DOSYADAN OKUDUGU DEGERI SIZE A ATAYACAK
						game_mod= loaded_game_mod(board);//BU FONKSIYONUN DOSYADAN OKUDUGU DEGERI GAME_MOD A ATAYACAK
						loadFile(board,size);//KAYITLI OYUN DIZIYE ATANACAK
						Show_Board( board , size);//KAYITLI OYUN GOSTERILECEK
					}
			k=choice-'A';//ALDI�IMIZ CHAR CHO�CE U �NT E �EV�RD�M
			}while(k>size-1);//k YI KONTROL ETT�M
			}
		
			move(board,size,choice,playerOne);//PLAYER ONE HAMLE YAPTI
			Show_Board( board , size);//HAMLEDEN SONRA YEN� TABLOYU YAZDIRDIM
			
			
			auto win=finish(board,size,playerOne);//FINISH FONSIYONUNDAN RETUR EDILEN DEGERI AUTO ILE TANIMLADIK 
				if (win==1){//KAZANAN OLUP OLMADI�INI KONTROL ETT�M
				cout<<"PLAYER ONE W�N!!!\n";
				show_last_board( board , size,playerOne);//KAZANAN D�RTL�Y� K��L�T�P YAZDIRIDM
				break;//KAZANIRSA SONSUZ D�NG�DEN �IKAR
				}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////				
		//////PLAYER TO PLAYER OYUNUN ICINDE PLAYER TWO HAMLE YAPCAK
			//AYNI HAMLEY� PLAYER TWO DA YAPACAK
			cout<<"PlayerTwo Please Enter the Letter of Column:";
			cin>>choice;	k=choice-'A';//GIRILEN HARF INT E CEVRILDI
				if(choice=='s'){//EGER s GIRILIRSE OYUN KAYDEDILECEK
				saveFile(board,size,game_mod);//OYUN KAYDEDILECEK
				cout<<"file saved\n"; //OYUNUN KAYDEDILDIGI KULLANICIYA BIKDIRIKECEK
			}
			if(k>size-1){
			do{
			cerr<<"PlayerTwo Please Enter Correct Letter of Column:";//EGER KULLANICI SUTUN LARIN BASINDAI HARFLERDEN BIRINI GIRMEZSE HATALI GIRIS IOLDUGU KULLANICIYA BILDIRILECEK
			cin>>choice;
				if(choice=='s'){//EGER HATALI GIRIS YAPTKTAN SONRADA OYUN KAYYDEDILMEK ISTENIRSE OYUN KAYDEDILEBILCEK
				saveFile(board,size,game_mod);//OYUN KAYDEDILCEK
				cout<<"file saved\n"; 
			}
					else if(choice=='l'){
						size=loaded_game_size(board);//BU FONKSIYONUN DOSYADAN OKUDUGU DEGERI SIZE A ATAYACAK
						game_mod= loaded_game_mod(board);//BU FONKSIYONUN DOSYADAN OKUDUGU DEGERI GAME_MOD A ATAYACAK
						loadFile(board,size);//KAYITLI OYUN DIZIYE ATANACAK
						Show_Board( board , size);//KAYITLI OYUN GOSTERILECEK
				}
			k=choice-'A';//ALDI�IMIZ CHAR CHO�CE U �NT E �EV�RD�M
			}while(k>size-1);
			}
			move(board,size,choice,playerTwo);
			Show_Board( board , size);//HAMLEDEN SINRA YEN� TABLOYU YAZDIRDIM
			auto win2=finish(board,size,playerTwo);
				if (win2==1){//KAZANAN OLUP OLMADI�INI KONTROL ETT�M
				cout<<"PLAYER TWO W�N!!!\n";
				show_last_board( board , size,playerTwo);//OYUN B��TT��� ���N KAZANAN D�RTL�Y� K���LT�P TABLOYU TEKRAR YAZDIM
				break;
				}
		 
		 	auto d=draw(board,size);//tablo kare oldu�u i�in en son ikinci oyuncu oynad�ktan sonra oyun berabere biter
				if(d==size){//D S�ZE A E��T OLDUYSA EN SONDAK� S�TUN A KADAR BT��TN S�TUNLAR DOLMU� DEMEKT�R
				cout<<"Draw\n";
				Show_Board( board , size);//KAZANAN D�RTL� OLAMDI�I ���N NORMAL TABLOYU YAZDIRDIM
				break;
				}
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////PLAYER TO CPU OYNANACAK VE ILK HAMLEYI PLAYER ONE YAPACAK
	else{cpu.playerSign='O';playerOne.playerSign='X'; 
					
			while(1){
			char choice;
			int k;
			cout<<"PlayerOne Please Enter the Letter of Column:";
			cin>>choice;	k=choice-'A';//GIRILEN HARFI INT E CEVIRDIK
				if(choice=='s'){//s GRILIRSE OYUN KAYDEDILECK
				saveFile(board,size,game_mod);
				cout<<"file saved\n"; 
			}
			if(k>size-1){//CHOICE SARTLARA UYMAZSA BURAYA GIRER
			do{
			cerr<<"PlayerOne Please Enter Correct Letter of Column:";//HATAYI CERR KULLANRARK YAZDIM
			cin>>choice;
				if(choice=='s'){
				saveFile(board,size,game_mod);
				cout<<"file saved\n"; 
			}
			k=choice-'A';//ALDI�IMIZ CHAR CHO�CE U �NT E �EV�RD�M
			}while(k>size-1);//k YI KONTROL ETT�M
			}
			
			move(board,size,choice,playerOne);
			Show_Board( board , size);//HAMLEDEEN SONRAK� TABLOYU YAZDIM
			auto win=finish(board,size,playerOne);//W�N DE�ER�N� ATADIM	
				if (win==1){//W�N FONKS�YONDAN 1 GELD�YSE KAZANILMI�TIR
				cout<<"CONGRULAT�ONS YOU W�N!!!\n";
				show_last_board( board , size,playerOne);
				break;//KAZANIRSA SONSUZ D�NG�DEN �IKAR
				}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
			/////CPU HAMLE YAPACAK////////////////
			cout<<"CPU'S TURN\n";
			int cpu_ch=cpu_drop(board,size);//CPU_DROP DA KARAR VERD���M HANLEY� ALDIM
			cpu_move(board,size,cpu_ch);//BUARDA KULLANDIM//CHAR SIGN I YAZMADIK �UNKU YUKARDA DEFAULT OLARAK TANIMLAMISTIK
			Show_Board( board , size);
			auto win2=finish(board,size,cpu);
				if (win2==1){
				cout<<"YOU LOSE!!!\n";
				show_last_board( board , size,cpu);
				break;//KAZANIRSA SONSUZ D�NG�DEN �IKAR
				}
			auto dr=draw(board,size);//tablo kare ollaca�� i�in en son cpu oynad�kta sonra draw olabilir
				if(dr==size){//DR S�ZE A E��T OLDUYSA EN SONDAK� S�TUN A KADAR BT��TN S�TUNLAR DOLMU� DEMEKT�R
				cout<<"Draw\n";
				Show_Board( board , size);
				break;//BERABERL�K OLURSA D�NG�DEN �IKAR
				}
		
			}
	}
	return 0;
}	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int enter_game_mod(){
	int tercih;
	cout<<"CHOOSE GAME MOD "<<"TWO PLAYERS=(1) OR PLAYER-CPU=(2)"<<endl;
	cin>>tercih; 
	if(tercih!=2&&tercih!=1){//TERCIH SARTLARA UYMAZSA BURAYA GIRER
	do{
	 cerr<<"CHOOSE 1 OR 2 PLEASE:"; cin>>tercih;
	 }while(tercih!=2&&tercih!=1);//hatal� giri�i ele ald�m
	}
	return tercih;
	}
	int enter_size(){
	int size;	
	cout<< "Enter size between 4-20:"; cin>>size;
	if(size>20||size<4||size%2!=0){//SIZE SARTLARA UYMAZSA BURAYA GIRER
	do{
	cerr<< "Enter correct size:"; cin>>size;//HATAYI CERR KULLANRARK YAZDIM
	}while(size>20||size<4||size%2!=0);//S�ZE I KONTROL ETT�K HATALARI ELE ALDIM
	}
	return size;	
	}	
	void show_starting_board(char board[][21],const int& size){
			int k,i;
	for(k=0;k<size;k++){//TABLONUN �S�TNDEK� HARFLER� YAZDIRDIM
		char row_name='A'+k;
		cout<<row_name;
		}
		cout<<endl;
		for(int i = 1; i <= size; i++)
	{
		for(int j = 1; j <= size; j++)
		{
				board[i][j] = '.';//DIZIDEKI BUTUN SATIR VE SUTUNLARA '.' ATANDI
				cout << board[i][j];// VE BUTUN SATUR VE SUTUNLAR YAZDIRILDI
		}
		cout << endl;//SATIR BITIKTTEN SONRA YENI SATIR A GECILDI
	}
	}
	void Show_Board ( char board[][21],const int& size){	
	int k,i;
	for(k=0;k<size;k++){//TABLOUN �ST�NDEK� HARFLER� YAZDIRDIM
		char row_name='A'+k;
		cout<<row_name;
		}
		cout<<endl;
	int rows = size, columns = size,j;
	for(i = 1; i <= rows; i++)
	{
	
		for(j = 1; j <= columns; j++)
		{
			if(board[i][j] != 'X' && board[i][j] != 'O')//HAMLE YAPILDIKTAN SONRA Y�NE ORAYA NOKTA KOYMASIN D�YE BU KONTROL� KOYDUM
				board[i][j] = '.';

			cout << board[i][j];//BUTUN SATIR VE SUTUNLAR YAZDIRILDI
			
		}

		cout << endl;
	}
}
	void move(char board[][21],int size,char& choice,Game player){
		bool control=false;
		int k=(choice-'A')+1;//ALDI�IMIZ CHAR I �NT E �EV�R�P KULLANDIK 
			if(board[1][k]=='X'|| board[1][k]=='O'){
				cerr<<"This column is full ,enter a new column please:";
				char c;
				cin>>c;//S�TUN DOLUYSA YEN� CHO�CE ALIR
				k=(c-'A')+1;
			}
		do 
	{
		if ( board[size][k] != 'X' && board[size][k] != 'O' )//BU NOKTANIN BO� OLUP OLMADI�I KONTRL EDL�R
		{
			board[size][k] = player.playerSign;//HMALEY� YAPAN PLAYER IN HARF� ATANIR BU NOKTAYA
			control=true;//HAMLE YAPILIRSA CONTROL TRUE OLUR VE BU D�NG�YE TEKRAR G�RMEZ
		}
		else
		--size;//HAMLE YAPILMADIYSA B�R �ST SATIR A GE�ER 
	}while (  control != true );// BU D�NG� HERHNAG� B�R YERE HAMLE YAPILANA KADAR DEVAM EDER

		
		
	}	
	int finish(char board[][21],int size,Game player){
	
	int win=0;

	for( int i = size; i >= 0; --i )//B�T�N SATIR VE S�TUNLAR TEK TEK KONTROL ED�LECEK
	{
		for( int j = size; j >= 0; --j )
		{
		
			if( board[i][j] ==player.playerSign&& board[i][j-1] ==player.playerSign&&	board[i][j-2] ==player.playerSign &&	board[i][j-3] ==player.playerSign)
			{
				win = 1;//4 TANE YAN YANA GELEB�LECEK X YA DA O LARI KONTROL ETT�M
			}
			if( board[i][j] ==player.playerSign &&	board[i-1][j] ==player.playerSign&& board[i-2][j] ==player.playerSign&&  board[i-3][j] == player.playerSign)
			{	
				win = 1;//4 TANE ALT ALTA GELEB�LCEK X YA DA O LARI KONTROL ETT�M
			}
			if( board[i][j] ==player.playerSign && board[i-1][j-1] ==player.playerSign && board[i-2][j-2] ==player.playerSign && board[i-3][j-3] == player.playerSign)
			{
				win = 1;//4 TANE �APARAZ OLARAK GELEB�LCEK X VE O LARI KONTROL ETT�M
			}
			if( board[i][j] ==player.playerSign &&	board[i-1][j+1] ==player.playerSign&&	board[i-2][j+2] == player.playerSign&&	board[i-3][j+3] ==player.playerSign)
			{
				win = 1;//4 TANE D��ER TARAFA �APARAZ OLARAK GELEB�LCEK X VE O LARI KONTROL ETT�M
			}
		}
		
	}
return win;//KAZANAN VARSA W�N =1 DEVAM ED�YOSA W�N =0
	}
	int draw(char board[][21],int size){
	int d=0;
	for(int i=1;i<=size;++i){
		if(board[1][i]!='.'){// HER S�TUNDAK� EN �ST SATIRI KONTROL EDER VE E�ER ORADA NOKTA YOKSA YAN� X YA DA O VARSA SAYACI B�R ARTT�RIR SAYAC S�ZE A E��T OLDU�UNDA OYUN BERAEBRA B�TM�� DEMEKT�R
			++d;
		}
	}   
	return d;	//SAYACI GER� D�ND�R�R
	}	
	void cpu_move(char board[][21],int size,int cpu_choice,char sign){//CPU_DROP FONS�YONUNDA KARAR VER�LEN CPU_CHO�CE U BURDA KULLANDIM
		
		bool control=false;
	
		do //CPU NORMAL MOVE ��LEM�N� YAPAR
	{
		if ( board[size][cpu_choice] != 'X' && board[size][cpu_choice] != 'O' )//D�Z�N�N BU NOKTASININ DOLU OLUP OLMADI�I KONTROL EDL�L�R
		{
			board[size][cpu_choice] = sign;//BU FONS�YONU �ALI�TIRAN PLAYER IN HARF � BURAYA ATANIR
			control=true;
		}
		else
		--size;//E�ER HAMLE YAPILMADIYSA B� �ST SATIR A BAKILIR
	}while (  control != true );	//HERHANG� B� NOKTYAA HAMLE YAPILDI�INDA TEKRAR WH�LE D�NG�S�NE G�RMEZ
	}	
	int cpu_drop(char board[][21],int size){//BURDA CPU NUN YAPCA�I HAMLEY� EN UYGUN YERE YAPMASI ���N ,UYGUN S�TUN U SE�MEYE �ALI�TIM
		int drop;
		drop=size/2;//BA�LANGI� HAMLEY� ORTADAN YAPMAK STRATEJ�K OLARAK MANTIKLI
			if(board[0][drop]!='.'){
			drop=drop+1;
			}
			
			for( int i = size; i >= 0; --i )
			{
				for( int j = size; j >= 0; --j )
				{
			
					if( board[i][j] == 'X'     &&//�� TANE X �ST �STEYSE B�LG�SAYAR OYUNUN KAR�I TARAF TARAFINDAN KAZANILMASINI ENGELLMEK ���N O S�TUNA HAMLE YAPR
						board[i-1][j] == 'X' &&
						board[i-2][j] == 'X' ){
						drop=j;	
						}
					 if( board[i][j] == 'O'&&//�� TANE O Y�ST �STEYSE B�LG�SAYAR OYUNU B�T�RMEK �.�N O S�TUNA HAMLE YAPAR
						board[i-1][j] == 'O' &&
						board[i-2][j] == 'O'){
						drop=j;
						}
					 if(board[i][j] == 'X'&&//�� TANE X YAN YANAYSA B�LG�SAYAR OYUNUN KAR�I TARAF TARAFNINDAN KAZANILMASINI ENGELLEMEK ���N O SATIR DA YAN S�TUNA HAMLE YAPAR
						board[i][j+1] == 'X' &&
						board[i][j+2] == 'X'){	
						drop=j+3;			
						}
					  if(board[i][j] == 'X'&&//B�R X B�R BO�LUK VE �K� X VARSA B�LG�SAYR ARAYA O YU KOYAR
						board[i][j+2] == 'X' &&
						board[i][j+3] == 'X'){	
						drop=j+1;			
						}
					  if(board[i][j] == 'X'&&//�K� X B�R BO�LUK VE B�R X VARSA B�LG�SAYAR ARAYA O YU KOYAR
						board[i][j+1] == 'X' &&
						board[i][j+3] == 'X'){	
						drop=j+2;			
						}
					 if(board[i][j] == 'O'&&//�� TANE O YANYANAYSA B�LG�SAYAR KAZANMAK �.N D�RD�NC� O NUN OLMASI GEREKAN YERE HAMLE YAPR
						board[i][j+1] == 'O' &&
						board[i][j+2] == 'O'){
							drop=j+3;
						}
						
										
				}		
			}
			
		return drop;
	}	
	void show_last_board(char board[][21],int size,Game player){//OYUNU KAZANDIRAN D�RTL� OLU�TUYSA AYNI O D�RTL�Y� K���K HARF YAPARAK TABLOYU TEKRAR YAZDIRIYO
			int k,i;
	for(k=0;k<size;k++){//E �STTEK� HARFLER� YAZADIRDIM
		char row_name='A'+k;
		cout<<row_name;
		}
		cout<<endl;
		
	for( int i =1; i <= size; i++ )
	{
		for( int j =1; j <= size; j++ )
		{
			if( board[i][j] ==player.playerSign && board[i+1][j+1] ==player.playerSign && board[i+2][j+2] ==player.playerSign && board[i+3][j+3] == player.playerSign)
			{
			board[i][j] =char(((int)player.playerSign)+32); board[i+1][j+1] =char(((int)player.playerSign)+32); board[i+2][j+2] =char(((int)player.playerSign)+32); board[i+3][j+3]=char(((int)player.playerSign)+32);
			}
			if( board[i][j] ==player.playerSign   && board[i][j+1] == player.playerSign &&	board[i][j+2] == player.playerSign &&	board[i][j+3] == player.playerSign)
			{
			board[i][j] =char(((int)player.playerSign)+32); board[i][j+1] =char(((int)player.playerSign)+32);	board[i][j+2] =char(((int)player.playerSign)+32); board[i][j+3] =char(((int)player.playerSign)+32);
			}
			if( board[i][j] ==player.playerSign  &&	board[i+1][j] ==player.playerSign && board[i+2][j] == player.playerSign &&  board[i+3][j] ==player.playerSign )
			{	
			board[i][j] =char(((int)player.playerSign)+32);	board[i+1][j] =char(((int)player.playerSign)+32); board[i+2][j] =char(((int)player.playerSign)+32); board[i+3][j] =char(((int)player.playerSign)+32);
			}
			if( board[i][j] ==player.playerSign     &&	board[i+1][j-1] == player.playerSign &&	board[i+2][j-2] ==player.playerSign &&	board[i+3][j-3] == player.playerSign)
			{
			board[i][j] =char(((int)player.playerSign)+32);	board[i+1][j-1] =char(((int)player.playerSign)+32);	board[i+2][j-2] =char(((int)player.playerSign)+32);board[i+3][j-3] =char(((int)player.playerSign)+32);
			}
			if ( board[i][j] == player.playerSign   && board[i][j+1] == player.playerSign &&	 board[i][j+2] == player.playerSign &&  board[i][j+3] == player.playerSign )
			{
			board[i][j] =char(((int)player.playerSign)+32); board[i][j+1] =char(((int)player.playerSign)+32); board[i][j+2] =char(((int)player.playerSign)+32); board[i][j+3] =char(((int)player.playerSign)+32); 
			}
			cout<<board[i][j];
		
		}
		cout<<endl;
	}
	}
	void saveFile(char board[][21],int size,int game_mod){
		ofstream file,sizefile,modfile;
		file.open("Save File.txt");
	//	file<<size<<endl;
		int k,i;
	for(k=0;k<size;k++){//TABLOUN �ST�NDEK� HARFLER� YAZDIRDIM
		char row_name='A'+k;
		file<<row_name;
		}
		file<<endl;
	
	int rows = size, columns = size,j;
	for(i = 1; i <= rows; i++)
	{
	
		for(j = 1; j <= columns; j++)
		{

			file<< board[i][j];
			
		}

		file << endl;
	}
	
		file.close();
		sizefile.open("SizeFile.txt");//SIZE DEGERINI BU DOSYAYA YAZDIRDIM
		sizefile<<size;
		sizefile.close();//VE DOSYA KAPANDI
		
		modfile.open("ModFile.txt");//GAME_MOD DEGERINI BU DOSYAYA YAZDIRDIM
		modfile<<game_mod;
		modfile.close();
	}
	void loadFile(char board[][21],int size){
		std::ifstream load("Save File.txt", std::ifstream::in);
	int k;
	for(k=0;k<size;k++){//TABLOUN �ST�NDEK� HARFLER� OKUTTUM
		char row_name='A'+k;
		load>>row_name;
		}
	int m,n;
	for(m = 1; m <=size; m++)
	{
	
		for(n = 1; n <=size; n++)
		{
			char data;
			load>>data;
			board[m][n]=data;//ALINAN CHAR TIPINDEKI DATA YI DZININ BUTUN ELEMANLARNA ATADIM
			
		}
	
	}
	cout<<endl;
	load.close();//DOSYA KAPATILDI
		
	}
	int loaded_game_size(char board[][21]){//SizeFile DOSYASINDAKI DEGERI RETURN EDEN FONKSIYON
		std::ifstream load("SizeFile.txt", std::ifstream::in);
		int data;
		load>>data;//DOSYADAKI DEGERI OKUYACAK
		return data;
	}
	 int loaded_game_mod(char board[][21]){//ModFile DOSYASINDAKI DEGERI RETURN EDEN FONSYON
	 	std::ifstream load("ModFile.txt", std::ifstream::in);
		int data;	 
	 	load>>data;//DOSYADAKI DEGERI OKUYACAK
	 	return data;
	 }
	

