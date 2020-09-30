#include <iostream>
#include<memory>
#include"GTUSet.h"
using namespace std;
namespace ahmets_namespace {
	
	template<class K,class V >
	class GTUMap : public GTUSet<std::pair< K,V > >
	{
	protected:
		int used;
		int maxSize;//MAXIMUM SIZE
		shared_ptr<K> P;
	public:
		GTUMap(int max);
	};
	template<class K,class V>
	GTUMap<K,V>::GTUMap(int max):maxSize(max),used(0){
		shared_ptr<K> mapArray(new K[maxSize]);//BURADA SET OLUSUTURUDK
		P.operator=(mapArray);
	}
	
}
