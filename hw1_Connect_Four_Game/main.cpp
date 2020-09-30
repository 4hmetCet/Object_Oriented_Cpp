//Ahmet ÇETÝNKAYA
//Connect 4 
#include <iostream>
using namespace std;
struct Game
{
	char playerSign;
};

void show_starting_board(char board[][21],int size);//show_board fonksiyonun içindeki kontrol den dolayý tablodan çýkan X ve O larý engellemek için yazdým 
void Show_Board ( char board[][21] ,int size);//oyun tablosunu göstereck
void move(char board[][21],int size,char choice,Game player);//girilen hamleyi alýp tablo üzerinde deðiþiklik yapacak
int finish(char board[][21],int size,Game player);//oyunun bitip bitmediðini kontrul edecek
int draw(char board[][21],int size);//tablonun dolup dolmadýðýný yani oyunun berabere bitip bitmediðini kontrol edecek
void cpu_move(char board[][21],int size,int cpu_choice,Game player);//cpu nun karar verdiði sütuna hamleyi yapacak ve bunu cpu_choice olarak alacak
int cpu_drop(char board[][21],int size);//cpu nun hamle yapcaðý sütunu geri döndürecek
void show_last_board(char board[][21],int size,Game player);//board u kontrol edip kazandýran dörtlüyü lower case yaptým

int main(int argc, char** argv)
{
	Game playerOne, playerTwo,cpu;
	char board[21][21]; 
	int tercih;

	cout << "Let's Play Connect 4" << endl ;
	int size;
	do{
	cout<< "Enter size between 4-20:"; cin>>size;
	}while(size>20||size<4||size%2!=0);//SÝZE I KONTROL ETTÝK HATALARI ELE ALDIM
	do{
	cout<<"CHOOSE GAME MOD "<<"TWO PLAYERS=(1) OR PLAYER-CPU=(2)"<<endl;
	cin>>tercih; 
	}while(tercih!=2&&tercih!=1);//hatalý giriþi ele aldým
	show_starting_board(board,size);
	if(tercih==1){
	playerOne.playerSign='O'; playerTwo.playerSign='X';
		while(1){
			char choice;
			int k;
			do{
			
			cout<<"PlayerOne Please Enter the Letter of Column:";
			cin>>choice;
			k=choice-'A';//ALDIÐIMIZ CHAR CHOÝCE U ÝNT E ÇEVÝRDÝM
			}while(k>size-1);//k YI KONTROL ETTÝM
			
			move(board,size,choice,playerOne);
			Show_Board( board , size);//HAMLEDEN SONRA YENÝ TABLOYU YAZDIRDIM
			int win=finish(board,size,playerOne);
				if (win==1){//KAZANAN OLUP OLMADIÐINI KONTROL ETTÞM
				cout<<"PLAYER ONE WÝN!!!\n";
				show_last_board( board , size,playerOne);//KAZANAN DÖRTLÜYÜ KÇÜLÜTÜP YAZDIRIDM
				break;//KAZANIRSA SONSUZ DÖNGÜDEN ÇIKAR
				}
				
		
			//AYNI HAMLEYÝ PLAYER TWO DA YAPACAK
			do{
			
			cout<<"PlayerTwo Please Enter the Letter of Column:";
			cin>>choice;
			k=choice-'A';//ALDIÐIMIZ CHAR CHOÝCE U ÝNT E ÇEVÝRDÝM
			}while(k>size-1);
			
			move(board,size,choice,playerTwo);
			Show_Board( board , size);//HAMLEDEN SINRA YENÝ TABLOYU YAZDIRDIM
			int win2=finish(board,size,playerTwo);
				if (win2==1){//KAZANAN OLUP OLMADIÐINI KONTROL ETTÝM
				cout<<"PLAYER TWO WÝN!!!\n";
				show_last_board( board , size,playerTwo);//OYUN BÝÝTTÝÐÝ ÝÇÝN KAZANAN DÖRTLÜYÜ KÜÇÜLTÜP TABLOYU TEKRAR YAZDIM
				break;
				}
		 
		 	int d=draw(board,size);//tablo kare olduðu için en son ikinci oyuncu oynadýktan sonra oyun berabere biter
				if(d==size){//D SÝZE A EÞÝT OLDUYSA EN SONDAKÝ SÜTUN A KADAR BTÜÜTN SÜTUNLAR DOLMUÞ DEMEKTÝR
				cout<<"Draw\n";
				Show_Board( board , size);//KAZANAN DÖRTLÜ OLAMDIÐI ÝÇÝN NORMAL TABLOYU YAZDIRDIM
				break;
				}
		}
	}

	else{cpu.playerSign='O';playerOne.playerSign='X'; 
					
			while(1){
			char choice;
			int k;
			do{
			
			cout<<"PlayerOne Please Enter the Letter of Column:";
			cin>>choice;
			k=choice-'A';//ALDIÐIMIZ CHAR CHOÝCE U ÝNT E ÇEVÝRDÝM
			}while(k>size-1);//k YI KONTROL ETTÝM K ÝSTEDÝÐÝMÝZ GÝBÝ DEÐÝLSE TEKRAR ÝSTEYECEK
			
			move(board,size,choice,playerOne);
			Show_Board( board , size);//HAMLEDEEN SONRAKÝ TABLOYU YAZDIM
			int win=finish(board,size,playerOne);//WÝN DEÐERÝNÝ ATADIM	
				if (win==1){//WÝN FONKSÝYONDAN 1 GELDÝYSE KAZANILMIÞTIR
				cout<<"CONGRULATÝONS YOU WÝN!!!\n";
				show_last_board( board , size,playerOne);
				break;//KAZANIRSA SONSUZ DÖNGÜDEN ÇIKAR
				}
			
			cout<<"CPU'S TURN\n";
			int cpu_ch=cpu_drop(board,size);//CPU_DROP DA KARAR VERDÝÐÝM HANLEYÝ ALDIM
			cpu_move(board,size,cpu_ch,cpu);//BUARDA KULLANDIM
			Show_Board( board , size);
			int win2=finish(board,size,cpu);
				if (win2==1){
				cout<<"YOU LOSE!!!\n";
				show_last_board( board , size,cpu);
				break;//KAZANIRSA SONSUZ DÖNGÜDEN ÇIKAR
				}
			int dr=draw(board,size);//tablo kare ollacaðý için en son cpu oynadýkta sonra draw olabilir
				if(dr==size){//DR SÝZE A EÞÝT OLDUYSA EN SONDAKÝ SÜTUN A KADAR BTÜÜTN SÜTUNLAR DOLMUÞ DEMEKTÝR
				cout<<"Draw\n";
				Show_Board( board , size);
				break;//BERABERLÝK OLURSA DÖNGÜDEN ÇIKAR
				}
		
			}
	}
	return 0;
}
	void show_starting_board(char board[][21],int size){
			int k,i;
	for(k=0;k<size;k++){//TABLONUN ÜSÜTNDEKÝ HARFLERÝ YAZDIRDIM
		char row_name='A'+k;
		cout<<row_name;
		}
		cout<<endl;
		for(int i = 0; i <= size-1; i++)
	{
		for(int j = 0; j <= size-1; j++)
		{
				board[i][j] = '.';
				cout << board[i][j];
		}
		cout << endl;
	}
	}

	void Show_Board ( char board[][21],int size)
{	
	int k,i;
	for(k=0;k<size;k++){//TABLOUN ÜSTÜNDEKÝ HARFLERÝ YAZDIRDIM
		char row_name='A'+k;
		cout<<row_name;
		}
		cout<<endl;
	int rows = size, columns = size,j;
	for(i = 1; i <= rows; i++)
	{
	
		for(j = 1; j <= columns; j++)
		{
			if(board[i][j] != 'X' && board[i][j] != 'O')//HAMLE YAPILDIKTAN SONRA YÝNE ORAYA NOKTA KOYMASIN DÝYE BU KONTROLÜ KOYDUM
				board[i][j] = '.';

			cout << board[i][j];
			
		}

		cout << endl;
	}
}

	void move(char board[][21],int size,char choice,Game player){
		bool control=false;
		int k=(choice-'A')+1;//ALDIÐIMIZ CHAR I ÝNT E ÇEVÝRÝP KULLANDIK 
			if(board[1][k]=='X'|| board[1][k]=='O'){
				cout<<"This column is full ,enter a new column please:";
				char c;
				cin>>c;//SÜTUN DOLUYSA YENÝ CHOÝCE ALIR
				k=(c-'A')+1;
			}
		do 
	{
		if ( board[size][k] != 'X' && board[size][k] != 'O' )//BU NOKTANIN BOÞ OLUP OLMADIÐI KONTRL EDLÝR
		{
			board[size][k] = player.playerSign;//HMALEYÝ YAPAN PLAYER IN HARFÝ ATANIR BU NOKTAYA
			control=true;//HAMLE YAPILIRSA CONTROL TRUE OLUR VE BU DÖNGÜYE TEKRAR GÝRMEZ
		}
		else
		--size;//HAMLE YAPILMADIYSA BÝR ÜST SATIR A GEÇER 
	}while (  control != true );// BU DÖNGÜ HERHNAGÝ BÝR YERE HAMLE YAPILANA KADAR DEVAM EDER

		
		
	}
	
	int finish(char board[][21],int size,Game player){
	
	int win=0;

	for( int i = size; i >= 0; --i )//BÜTÜN SATIR VE SÜTUNLAR TEK TEK KONTROL EDÝLECEK
	{
		for( int j = size; j >= 0; --j )
		{
		
			if( board[i][j] ==player.playerSign&& board[i][j-1] ==player.playerSign&&	board[i][j-2] ==player.playerSign &&	board[i][j-3] ==player.playerSign)
			{
				win = 1;//4 TANE YAN YANA GELEBÝLECEK X YA DA O LARI KONTROL ETTÝM
			}
			if( board[i][j] ==player.playerSign &&	board[i-1][j] ==player.playerSign&& board[i-2][j] ==player.playerSign&&  board[i-3][j] == player.playerSign)
			{	
				win = 1;//4 TANE ALT ALTA GELEBÝLCEK X YA DA O LARI KONTROL ETTÝM
			}
			if( board[i][j] ==player.playerSign && board[i-1][j-1] ==player.playerSign && board[i-2][j-2] ==player.playerSign && board[i-3][j-3] == player.playerSign)
			{
				win = 1;//4 TANE ÇAPARAZ OLARAK GELEBÝLCEK X VE O LARI KONTROL ETTÝM
			}
			if( board[i][j] ==player.playerSign &&	board[i-1][j+1] ==player.playerSign&&	board[i-2][j+2] == player.playerSign&&	board[i-3][j+3] ==player.playerSign)
			{
				win = 1;//4 TANE DÝÐER TARAFA ÇAPARAZ OLARAK GELEBÝLCEK X VE O LARI KONTROL ETTÝM
			}
		}
		
	}
return win;//KAZANAN VARSA WÝN =1 DEVAM EDÝYOSA WÝN =0
	}

	int draw(char board[][21],int size){
	int d=0;
	for(int i=1;i<=size;++i){
		if(board[1][i]!='.'){// HER SÜTUNDAKÝ EN ÜST SATIRI KONTROL EDER VE EÐER ORADA NOKTA YOKSA YANÝ X YA DA O VARSA SAYACI BÝR ARTTÝRIR SAYAC SÝZE A EÞÝT OLDUÐUNDA OYUN BERAEBRA BÝTMÝÞ DEMEKTÝR
			++d;
		}
	}   
	return d;	//SAYACI GERÝ DÖNDÜRÜR
	}
	
	void cpu_move(char board[][21],int size,int cpu_choice,Game player){//CPU_DROP FONSÝYONUNDA KARAR VERÝLEN CPU_CHOÝCE U BURDA KULLANDIM
		
	
		bool control=false;
	
		do //CPU NORMAL MOVE ÝÞLEMÝNÝ YAPAR
	{
		if ( board[size][cpu_choice] != 'X' && board[size][cpu_choice] != 'O' )//DÝZÝNÝN BU NOKTASININ DOLU OLUP OLMADIÐI KONTROL EDLÝLÝR
		{
			board[size][cpu_choice] = player.playerSign;//BU FONSÝYONU ÇALIÞTIRAN PLAYER IN HARF Ý BURAYA ATANIR
			control=true;
		}
		else
		--size;//EÐER HAMLE YAPILMADIYSA BÝ ÜST SATIR A BAKILIR
	}while (  control != true );	//HERHANGÝ BÝ NOKTYAA HAMLE YAPILDIÐINDA TEKRAR WHÝLE DÖNGÜSÜNE GÝRMEZ
	}

	
	
	int cpu_drop(char board[][21],int size){//BURDA CPU NUN YAPCAÐI HAMLEYÝ EN UYGUN YERE YAPMASI ÝÇÝN ,UYGUN SÜTUN U SEÇMEYE ÇALIÞTIM
		int drop;
		drop=size/2;//BAÞLANGIÇ HAMLEYÝ ORTADAN YAPMAK STRATEJÝK OLARAK MANTIKLI
			if(board[0][drop]!='.'){
			drop=drop+1;
			}
			
			for( int i = size; i >= 0; --i )
			{
				for( int j = size; j >= 0; --j )
				{
			
					if( board[i][j] == 'X'     &&//ÜÇ TANE X ÜST ÜSTEYSE BÝLGÝSAYAR OYUNUN KARÞI TARAF TARAFINDAN KAZANILMASINI ENGELLMEK ÝÇÝN O SÜTUNA HAMLE YAPR
						board[i-1][j] == 'X' &&
						board[i-2][j] == 'X' ){
						drop=j;	
						}
					 if( board[i][j] == 'O'&&//ÜÇ TANE O YÜST ÜSTEYSE BÝLGÝSAYAR OYUNU BÝTÝRMEK Ý.ÝN O SÜTUNA HAMLE YAPAR
						board[i-1][j] == 'O' &&
						board[i-2][j] == 'O'){
						drop=j;
						}
					 if(board[i][j] == 'X'&&//ÜÇ TANE X YAN YANAYSA BÝLGÝSAYAR OYUNUN KARÞI TARAF TARAFNINDAN KAZANILMASINI ENGELLEMEK ÝÇÝN O SATIR DA YAN SÜTUNA HAMLE YAPAR
						board[i][j+1] == 'X' &&
						board[i][j+2] == 'X'){	
						drop=j+3;			
						}
					  if(board[i][j] == 'X'&&//BÝR X BÝR BOÞLUK VE ÝKÝ X VARSA BÝLGÝSAYR ARAYA O YU KOYAR
						board[i][j+2] == 'X' &&
						board[i][j+3] == 'X'){	
						drop=j+1;			
						}
					  if(board[i][j] == 'X'&&//ÝKÝ X BÝR BOÞLUK VE BÝR X VARSA BÝLGÝSAYAR ARAYA O YU KOYAR
						board[i][j+1] == 'X' &&
						board[i][j+3] == 'X'){	
						drop=j+2;			
						}
					 if(board[i][j] == 'O'&&//ÜÇ TANE O YANYANAYSA BÝLGÝSAYAR KAZANMAK Ý.N DÖRDÜNCÜ O NUN OLMASI GEREKAN YERE HAMLE YAPR
						board[i][j+1] == 'O' &&
						board[i][j+2] == 'O'){
							drop=j+3;
						}
						
										
				}		
			}
			
		return drop;
	}
	
	void show_last_board(char board[][21],int size,Game player){//OYUNU KAZANDIRAN DÖRTLÜ OLUÞTUYSA AYNI O DÖRTLÜYÜ KÜÇÜK HARF YAPARAK TABLOYU TEKRAR YAZDIRIYO
			int k,i;
	for(k=0;k<size;k++){//E ÜSTTEKÝ HARFLERÝ YAZADIRDIM
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
	

