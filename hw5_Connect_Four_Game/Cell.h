#ifndef CELL_H
#define CELL_H
#include<iostream>
using namespace std;
namespace my_namespace
{
class Cell{
			private:
				int row;
				char column;
			public:
				void setPos(int& rowPos, char& columnPos);
				int getRow();//CELL IN BULUNDUGU ROW U DONDURECEK
				char getColumn();//CELL IN BULUNDUGU COLUMN U DONDURECEK
				bool isFull=false;//HUCRENIN OLUSAN HER NESNESININ isFull DEGISKENI DEFAULT OLARAK FALSE OLACAK VE O HUCRE DOLDUGUNDA TRUE OLACAK
				char sign;

};

}
#endif
