#include <iostream>
#include<memory>
#include"GTUSetBase.h"
using namespace std;
namespace ahmets_namespace {
	
	template<class T>
	class GTUSet : public GTUSetBase<T>
	{
	protected:
		int maxSize;//MAXIMUM SIZE
		int used;//KULLANILAN SIZE
		shared_ptr<T> P;
	public:
	GTUIterator<T> end();	//Return iterator to end
	GTUIterator<T> begin();	//Return iterator to beginning
	int count(const T& value)const;	//Count elements with a specific value
	GTUIterator<T> find(const T& value) const;//Get iterator to element
	void clear();//Clear all content
	void erase(const T& value);//Erase element
	void insert(const T& value);//Insert element
	int max_size()const;//Return maximum size
	int size()const;//Return container size
	bool empty() const;//Test whether container is empty
	GTUSet(int max);
	};

	
}

