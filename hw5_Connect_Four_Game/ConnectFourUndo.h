#ifndef CONNECTFOURUNDO_H
#define CONNECTFOURUNDO_H
#include"ConnectFourAbstract.h"
#include"ConnectFourPlus.h"
#include<vector>
using namespace std;
namespace my_namespace{

	class ConnectFourUndo : public ConnectFourPlus{
	protected:
		int move();
		void show_current_board();//BOARD U YAZIDRACAK FONKSIYON
		void read_from_file() ;//BU FONSIYON KAYITLI OYUNU DOSYADAN OKUYACAK
		void write_to_file();//BU FONSIYON OYUN U FILE A YAZACAK
		void play_undo();//MOVES VECTORUNDEN HAMLELERI OKUYARAK HAMLELERI GERI ALACAK
	};
	
}
#endif
