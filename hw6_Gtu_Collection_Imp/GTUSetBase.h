#include <iostream>
#ifndef GTUSETBASE_H_
#define GTUSETBASE_H_
#include"GTUIterator.h"
using namespace std;
namespace ahmets_namespace {
template<class T>
class GTUSetBase {
public:
	virtual GTUIterator<T> end()=0;//Return iterator to end
	virtual GTUIterator<T> begin()=0;//Return iterator to beginning
	virtual int count(const T& value)const=0;//Count elements with a specific value
	virtual GTUIterator<T> find(const T& value)const =0;//Get iterator to element
	virtual void clear()=0;//Clear all content
	virtual void erase(const T& value)=0;//Erase element
	virtual void insert(const T& value)=0;//Insert element, throws exception std::bad_pafram if the element is already in the set
	virtual int max_size()const=0;//Return maximum size
	virtual int size()const=0;//Return container size
	virtual bool empty()const=0;//Test whether container is empty
};

} /* namespace ahmets_namespace */

#endif /* GTUSETBASE_H_ */
