#ifndef CONNECTFOURPLUS_H
#define CONNECTFOURPLUS_H
#include"ConnectFourAbstract.h"
using namespace std;

namespace my_namespace
{

	class ConnectFourPlus : public ConnectFourAbstract
	{
			private:
			  void show_current_board();
			  void endGame(char sign);//OYUN BU FONKSÝYOLA BÝTECEK KAZANAN VARSA VEYA BERABERLÝK VARSA BÝLDÝRECEK
			  void change_to_lower( char Sign);
				
	};

}
#endif
