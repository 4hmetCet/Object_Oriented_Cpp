#include<iostream>
using namespace std;
#include"Cell.h"
namespace my_namespace{


		void Cell::setPos(int& rowPos, char& columnPos){//GIRILEN DEGERLER ROW VE COLUMN A ATANACAK
		row=rowPos;
		column=columnPos;
		//CELL IN POZISYONUNU BELIRLEYECEK FONKSIYON
		}
		int Cell::getRow(){
		return row;
		}//CELL IN BULUNDUGU ROW U DONDURECEK
		char Cell::getColumn(){
		return column;
		}//CELL IN BULUNDUGU COLUMN U DONDURECEK
}
