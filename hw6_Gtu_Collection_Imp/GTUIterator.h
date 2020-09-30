#include <iostream>
#ifndef GTUITEROTAR_H_
#define GTUITERATOR_H_

using namespace std;
namespace ahmets_namespace {
	template<class T>
	class GTUIterator
	{
	protected: 
	  T* pointer;
	public:
	GTUIterator(T* x) :pointer(x) {}//CONSTRUCTOR//POINTER PARAMETRE OLARAK GIRILEN POITERI GOSTERECEK
  	GTUIterator(const GTUIterator& myit) : pointer(myit.pointer) {}//CONSTRUCTOR//POINTER PARAMEMTRE OLARAK GIRILEN ITERATORUN POINTERINI GOSTERECEK
  	GTUIterator& operator++() {++pointer;return *this;}//POINTER BI SONRAKI ADRESI GOSTERECEK
  	GTUIterator operator++(int) {GTUIterator tmp(*this); operator++(); return tmp;}
  	bool operator==(const GTUIterator& iterator)const{return pointer==iterator.pointer;}//PARAMETRE LERI KARSILASRIRACAK
  	bool operator!=(const GTUIterator& iterator)const{return pointer!=iterator.pointer;}
  	T& operator*() {return *pointer;}//POINTERI GERI DONDURECEK
	};
	
}
#endif
