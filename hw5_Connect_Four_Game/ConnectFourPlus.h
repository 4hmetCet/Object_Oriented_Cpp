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
			  void endGame(char sign);//OYUN BU FONKS�YOLA B�TECEK KAZANAN VARSA VEYA BERABERL�K VARSA B�LD�RECEK
			  void change_to_lower( char Sign);
				
	};

}
#endif
