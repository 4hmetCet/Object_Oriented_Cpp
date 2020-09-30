#include<iostream>
#include"GTUSet.h"
using namespace std;
namespace ahmets_namespace {
	template<class T>
	GTUSet<T>::GTUSet(int max):maxSize(max),used(0){
		shared_ptr<T> array(new T[maxSize]);//BURADA SET OLUSUTURUDK
		P.operator=(array);
	}
	
	template<class T>
	GTUIterator<T> GTUSet<T>::end(){
	
	return GTUIterator<T>(&P.get()[used]);//USED = KULLANILAN SÝZE 
	//Return iterator to end
	
	}
	template<class T>
	GTUIterator<T> GTUSet<T>::begin(){
	return GTUIterator<T>(&P.get()[0]);
	//Return iterator to beginning
	}
	template<class T>
	int GTUSet<T>::count(const T& value)const{
	int ctrl=0;
	for(int i=0;i<used;i++){
		if(P.get()[i]==value)
			ctrl=1;
	}
	return ctrl;
	//eleman varsa 1 yoksa 0 döndürecek
	//Count elements with a specific value
	
	}
	template<class T>
	GTUIterator<T> GTUSet<T>::find(const T& value)const{
	for(int i=0;i<used;i++)	{
		if(P.get()[i] == value)//POINTERIN GOSTERDIGI TUM ELEMANLARI BAKARARAK ESIT OLANI BULDUGUMUZDA DONDURECEZ
			return GTUIterator<T>(& P.get()[i]);//REFERANS ALMASADA DÖNEBÝLÝR DENE 	
	}
	//Get iterator to element
	}
	template<class T>
	void GTUSet<T>::clear(){
	shared_ptr<T> newArray(new T[maxSize]);
	P.operator=(newArray);
	used=0;
	//Clear all content
	}
	template<class T>
	void GTUSet<T>::erase(const T& value){
	shared_ptr<T> tempArray(new T[maxSize]);
	for(int i=0;i<used;i++){
		if(P.get()[i]==value){
			P.get()[i]=0;	
		}
	}
	
	//P.operator=(tempArray);
	//used--;
	//YENÝ ARRAYA SILINMEK ISTENEN HARICINDEKI ELELEMANLARI ATAYACAZ
	//Erase element
	}
	template<class T>
	void GTUSet<T>::insert(const T& value){
	P.get() [used]=value;
	used++;
	//Insert element, throws exception std::bad_pafram if the element is already in the set
	}
	template<class T>
	int GTUSet<T>::max_size()const{
	//Return maximum size
	return maxSize;
	}
	template<class T>
	int GTUSet<T>::size()const{
	//Return container size
	return used;
	}
	template<class T>
	bool GTUSet<T>::empty()const{
	//Test whether container is empty
	if(used==0) return true;
	else return false;
	}


} /* namespace ahmets_namespace */
