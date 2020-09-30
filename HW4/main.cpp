#include<iostream>
#include<vector>
#include<fstream>
#include<string.h>
using namespace std;

class ConnectFour
{	
	private:
		class Cell{
			private:
				int row;//HUCRENIN BULUNDUGU SATIRI TUTACAK	
				char column;//HUCRENIN POZISYONUNU TUTACAK(A,B,C,D,.....)
			public:	
				Cell();
				Cell(char sign);
				char cellSign;//BU DEGER X VEYA O OLACAK
				bool isFull=false;//BU CELLIN CELLSIGNI EGER X VEYA O OLURSA BU DEGER TRUE OLACAK VE O CELL E BI DAHA HAMLE YAPILAMAYACAK
				void setPos(int& rowPos,char& columnPos);//this function will set position of Cell
				const int getRow();
				const char getColumn ();
				friend bool operator !=(const Cell& c1);
				bool operator ==(const Cell& c1);//IKI CELL IN SIGN INI KARSILASTIRACAK IKISIDE X VEYA IKISIDE O ISE TRUE DONDURECEK		
				Cell operator ++();//prefiks vresiyonu
				Cell operator ++(int ignore);//postfiks versiyonu
				Cell operator --();//prefiks versiyonu
				Cell operator --(int ignore);//postfiks versiyonu
				ostream& operator <<(Cell& c);
				istream& operator >>(Cell& c);	
			
				
		};	
	
		void play();//that plays computer
		void play(int& position,char sign);//that plAYS USER
		void endedGame(char sign);//OYUN BU FONKSÝYOLA BÝTECEK KAZANAN VARSA VEYA BERABERLÝK VARSA BÝLDÝRECEK
		void display_last_board(char Sign);//BU FONKSIYON OYUN BITTIKTEN SONRA KAZANAN DORTLUYU KUCULTUP YAZDIRACAK
		int move();//KULLANICIDAN HAMLE ALACAK VE DUNDURECEK
		int row;//SATIR SAYISI
		int column;//SUTUN SAYISI
		void readFile() ;//BU FONSIYON KAYITLI OYUNU DOSYADAN OKUYACAK
		void writeFile();//BU FONSIYON OYUN U FILE A YAZACAK
		void player2player();//BU FONSIYON PLAYER TO PLAYER OYUNU OYNAYACAK
		void player2cpu();//BU FONKSIYON PLAYER TO CPU OYUNU PYNAYACAK
		int game_mod;//GAME MOD DEGISKENI	
		inline void displayCurrentBoard();//HAMLELER YAPILDIKTAN SONRADA YENI TABLOYU YAZDIRAN FONKSIYON
	public:
		Cell** gameBoard;
		bool endGame=false;//OYUN BITTIYSE BU DEGISKEN TRUE OLACAK 
		void one_object_game();//BU FOKNSIYONDA SADECE PALYERONE VE PLAYERTWO O OBJECT ICIN BIRER HAMLE YAPACAK 
		void playGame();//KULLANICIDAN SIZE VE GAME MOD ALINACAK VE OYUN OYNANCAK//BU FONSIYONUN ICINDE PLAYER2PLAYER VE PLAYER2CPU FONKSIYONLARI CALISACAK
		ConnectFour();//bu fonkiyon nesne oluþtupunda çalýþacak VE PLAYGAME FONKSIYONU DA BUNUN ICINDE CALISACAK
		//PLAYGAME OLUSTURULAN  NESNEYE GORE CALISACAK
	 	friend bool operator ==(const ConnectFour& game1);
		friend bool operator !=(const ConnectFour& game1{
			  
		return(cellSign==c1.cellSign);
	}
	bool ConnectFour::Cell::operator!=(const Cell& c1){
		return (cellSign!=c1.cellSign);
	}
	bool ConnectFour::operator ==(const ConnectFour& game1){//IKI AYRI OBJENIN GAMEBOARD LARINI X VE O LARIN YERLERINE GORE KARSILASTIRACAK
	if((this->row==game1.row)&&(this->column==game1.column)){//KARSILASRIRILAN IKI OBJENIN ROW VW COLUMN SAYSISI AYNIYSA HUCRELERI KONTROL EDERIM 
		bool sonuc=true;//HERHANGI BI CELL IN FARKLI OLMASI BU OPERATOR UN FALSE OLMASI ICIN YETERLI
		for(int i=0;i<row; i++){
			for(int j=0;j<column; j++){
				if(this->gameBoard[i][j]!=game1.gameBoard[i][j]){//HER IKI OYUNUNDA TUM CELL LERINI KONTROL EDECEK VE EGER HERHANGI IKI CELL ESIT OLMAZSA SONUC FALSE OLAACAK TUM CELL LER ESITSE TRUE OLACAK
				//BURADA DAHA ONCE OVERLOAD ETTIGIMIZ CELL ICIN OLAN '!=' OPERATORUNU KULLNADIM 
					sonuc=false;
				}
			}
		}
	return sonuc;//SONUC DEGERINI DONDURECEK
	}
	else return false;//IF E GIRMEDIYSE YANI ROW VE COLUMN SAYISI FARKLIYSA DÝREK FALSE DONDURUR
	}
	bool ConnectFour::operator !=(const ConnectFour& game1){//IKI AYRI OBJENIN GAMEBOARD LARINI X VE O LARIN YERLERINE GORE KARSILASTIRACAK
	if((this->row==game1.row)&&(this->column==game1.column)){//KARSILASRIRILAN IKI OBJENIN ROW VW COLUMN SAYSISI AYNIYSA HUCRELERI KONTROL EDERIM
		int count=0;//TUM CELLERIN KONTROL EDILMESI LAZIM 
		for(int i=0;i<row; i++){
			for(int j=0;j<column; j++){
				if(this->gameBoard[i][j]==game1.gameBoard[i][j]){//HER IKI OYUNUNDA TUM CELL LERINI KONTROL EDECEK VE EGER HERHANGI IKI CELL ESITSE COUNTER  BIR ARTAR 
				//DAHA ONCE OVERLOAD ETTIGIMIZ CELL ICIN OLAN '==' OPERATORUNU KULLANDIM O DA CELL IN SIGN LARINI KARSILASTIRACAK
					count++;
				}
			}
		}
				if(count==(row*column)) return false;//EGER COUNT BTUN HUCRELIRN TOPLAM SAYISINA ESITSE TÜM HUCRELER AYNI DEMEKTIR
				else return true;//EGER BIR HUCRE BILE FARKLIYSA COUNT DEGERI FARKLI OLACAK BUDA IKI TABLONUN AYNI OLMADIGI ANLAMINA GELRI VE FALSE DONER
	}
	else return true;//KARSILASTIRILAN IKI OBJENIN ROW VE COLUMN SAYILARI FARKLIYSA ZATEN DIREK TRUE DONER
	}
	ostream& ConnectFour::Cell::operator <<(Cell& c){
		
	}
	istream& ConnectFour::Cell::operator >>(Cell& c){
		
		
	}
	ConnectFour::Cell ConnectFour::Cell::operator++(){
		if(cellSign=='.') {cellSign='X'; this->isFull=true;}//EMPTY ISE USER1 YAPACAK
		if(cellSign=='x') cellSign='O';//USER1 ISE GAMEMOD A BAGLI OLARAK USER2 VEYA CPU OLUR
		if(cellSign=='O') {cellSign='.'; this->isFull=false;}//USER2 VEYA CPU ISE EMPTY OLUR
		return Cell(cellSign) ;
	}
	ConnectFour::Cell ConnectFour::Cell::operator++(int ignore){
		char tempSign=cellSign;
		if(cellSign=='.') {cellSign='X'; this->isFull=true;}//EMPTY ISE USER1 YAPACAK
		if(cellSign=='x') cellSign='O';//USER1 ISE GAMEMOD A BAGLI OLARAK USER2 VEYA CPU OLUR
		if(cellSign=='O') {cellSign='.'; this->isFull=false;}//USER2 VEYA CPU ISE EMPTY OLUR
		return Cell(tempSign);
	}
	ConnectFour::Cell ConnectFour::Cell::operator--(){
		if(cellSign=='O') cellSign='X';
		if(cellSign=='X') {cellSign='.'; this->isFull=false;}
		if(cellSign=='.') {cellSign='O'; this->isFull=true;}
		return Cell(cellSign);
		}
	ConnectFour::Cell ConnectFour::Cell::operator--(int ignore){
		char tempSign=cellSign;
		if(cellSign=='O') cellSign='X';
		if(cellSign=='X') {cellSign='.'; this->isFull=false;}
		if(cellSign=='.') {cellSign='O'; this->isFull=true;}
		return Cell(tempSign);	
	}
	
	
	
	
