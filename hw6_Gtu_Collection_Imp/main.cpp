#include<iostream>
#include<memory>
#include"GTUSet.cpp"
//#include"GTUMap.cpp"
using namespace std;
using namespace ahmets_namespace;
/*	template <class T>
	std::shared_ptr<GTUSetBase<T>> setIntersection<T>(const GTUSetBase <T>& temp, const GTUSetBase <T>& temp2){
	GTUSet<T> setIntersection(temp.used);//DONDURECEGIM SETI OLUSTUDUM ,MAXIMUM ALACAGI ELAMAN SAYISI DA PARAMETRE OLAN SETLERDEN BIRININ ELEMAN SAYISI OLABILIR
		for(GTUIterator<T> i=temp.begin();i != temp.end();i++)//ILK PARAMETRE UZERINDE DOLASAN FOR DONGUSU
		{
				for(GTUIterator<T> j=temp2.begin();j != temp2.end();j++)//IKINCI PARAMETRE UZERINDE DOLASAN FOR DONGUSU
			{
				if(*i==*j){
					setIntersection.insert(*i)
				}
			}	
		}
	return 
	}*/
int main(){
	GTUSet<int> set_int(100);//MAXIMUM 100 ELEMAN ALAN BI SET OLUSTURDUM
	for(int j=0;j<10;j++){
		set_int.insert(j);
	}
	set_int.insert(100);
	
	cout<<"int_set:";
	for(GTUIterator<int> i=set_int.begin();i != set_int.end();i++)
	{
		cout<<*i;
	}
	cout<<endl;
	cout<<"OLUSTURDUGUMUZ SET DE 5 VAR MI?"<<set_int.count(5)<<endl;
	if(set_int.empty()==false) cout<<"SET DOLU"<<endl;
	cout<<"SET SIZE:"<<set_int.size()<<endl;
	cout<<"MAX SIZE:"<<set_int.max_size()<<endl;
	cout<<"ARADIGIMIZ 4 SAYISINI BULANA KADAR OLAN SET:";
	for(GTUIterator<int> i=set_int.begin();i != set_int.find(4);i++)
	{
		cout<<*i;
	}
	cout<<endl;
	set_int.erase(7);
	cout<<"7 YI ERASE FONKSIYONU KULLNARAK SILDIK:";
	for(GTUIterator<int> i=set_int.begin();i != set_int.end();i++)
	{
		cout<<*i;
	}
	cout<<endl;
	
	set_int.clear();
		cout<<"CLEAR FONSIYONUNDAN SONRA int_set:";
	for(GTUIterator<int> i=set_int.begin();i != set_int.end();i++)
	{
		cout<<*i;
	}
	cout<<endl;
	
	
	GTUSet<int> set_numbers(10);
	set_numbers.insert(0);
	set_numbers.insert(2);
	set_numbers.insert(4);
	set_numbers.insert(6);
	set_numbers.insert(8);
	set_numbers.insert(10);
	
	

	//GTUMap<int,int> map_int(10);
	//map_int.insert(make_pair<5,6>);
	
}

