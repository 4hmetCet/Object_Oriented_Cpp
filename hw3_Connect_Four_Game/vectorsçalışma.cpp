#include<iostream>
#include<vector>
using namespace std;
class ahmet{
public:
	int k;
	char sign;
};
int main(){
ahmet ah;
std::vector< std::vector<ahmet> > a;

  	 int m = 7, n = 7;
        a.resize(m);
    for(int i = 0 ; i < m ; ++i)
    {
        a[i].resize(n);
    }
    
for(int i = 0 ; i < m ; ++i)
{
    for(int j = 0 ; j < n ; ++j)
    {	ahmet ah[i];
        ah[i].sign='A';
    	a[i][j]=ah[i];  
    	cout<<a[i][j].sign;
	}
cout<<endl;
}
	a[0][0].k=11;
	cout << a[0][0].k;
}
