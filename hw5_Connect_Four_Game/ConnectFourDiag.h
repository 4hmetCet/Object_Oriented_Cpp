#ifndef CONNECTFOURDIAG_H
#define CONNECTFOURDIAG_H
#include"ConnectFourAbstract.h"
using namespace std;
namespace my_namespace
{
	
	class ConnectFourDiag : public ConnectFourAbstract{
			private:
			void endGame(char sign);//OYUN BU FONKSÝYOLA BÝTECEK KAZANAN VARSA VEYA BERABERLÝK VARSA BÝLDÝRECEK
			void show_current_board();
			void change_to_lower( char Sign);
	};

}
#endif
