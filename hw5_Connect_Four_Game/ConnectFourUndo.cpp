#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
#include"ConnectFourUndo.h"
#include"Cell.h"


namespace my_namespace{
	void ConnectFourUndo::write_to_file(){
		ofstream file;
		file.open(file_name.c_str());
		int k,i,j;
	for(k=0;k<columnSize;k++){//TABLOUN ÜSTÜNDEKÝ HARFLERÝ YAZDIRDIM
		char column_name='A'+k;
		file<<column_name;
		}
		file<<endl;
	for(i = 0; i < rowSize; i++)
	{
		for(j = 0; j < columnSize; j++)
		{
			file<< gameboard[i][j].sign;
		}
			file << endl;
	}
		file.close();
	}	
	void ConnectFourUndo::read_from_file(){
	std::ifstream load(file_name.c_str(), std::ifstream::in);
	int k;
	for(k=0;k<columnSize;k++){//TABLOUN ÜSTÜNDEKÝ HARFLERÝ OKUTTUM
		char column_name='A'+k;
		load>>column_name;
		}
	int m,n;
	for(m = 0; m <rowSize; m++)
	{
		for(n = 0; n <columnSize; n++)
		{
			char data;
			load>>data;
			gameboard[m][n].sign=data;//ALINAN CHAR TIPINDEKI DATA YI DZININ BUTUN ELEMANLARNA ATADIM
			if(data=='X'|| data=='O')
			gameboard[m][n].isFull=true;
		}
	}
	cout<<endl;
	load.close();//DOSYA KAPATILDI
		
	}
	int ConnectFourUndo::move(){
		int k=-2;//K DA DEGISIKLIK OLMAZSA HAMLE TEKRAR ALINACAK UNDO HARIC
				
				string komut;
		string  string_choice;
			do{
			cerr<<"Please Enter the Letter of Column:";
			cin>>string_choice;
				getline(cin,komut);
				string bosluk=" ";
				string my_string(komut);
				//BUARDAN SONRA PARSING YAPILACAK
				komut=my_string.substr(0,my_string.find_first_of(bosluk));
				file_name=my_string.substr(my_string.find_first_of(bosluk)+1);
					if(string_choice=="SAVE"){//s GIRILIRSE OYUN KAYDEDILECEK
					write_to_file();//OYUN KAYDEDILIYO...
					cout<<"file saved\n"; 
					undo=0;//BURADA UNDO OLMADIGI ANLAMINA GELIYOR DOLAYISIYLA HAMLE TEKRAR AYNI KULLANICIDAN ISTENECEK
					}
					
					else if(string_choice=="LOAD"){
						read_from_file();//KAYITLI OYUN DIZIYE ATANACAK
						cout<<"Loaded game\n";
						show_current_board();
					undo=0;//BURADA UNDO OLMADIGI ANLAMINA GELIYOR DOLAYISIYLA HAMLE TEKRAR AYNI KULLANICIDAN ISTENECEK
					}
					else if(string_choice=="UNDO"){
						play_undo();//GERI ALMA HAMLESI
						cout<<"HAMLE GERI ALINDI\n";
						show_current_board();
						undo=-1;//GERI ALMA OLDUYSA UNDO -1 OLACAK VE MOVE FONKSIYONU -1 DONECEK BOYLECE HAMLE YAPMADAN DIGER KULLNAICIYA GECMIS OLACAZ
						k=0;//BU k YAZILMAYACAK CUNKU BURADA UNDO -1 OLDUGU ICIN RETURN UNDO YAPACAK , WHILE DAN CIKMASI ICIN YAPTIM
					}
					else if(string_choice.length()==1){//EGER HAMLE UZUNLUGU 1 SE BU OYUN HAMLESI OLACAK
					char choice=string_choice[0];//VE O TEK HARF BIZIM HAMLEMIZ OLUR
					k=choice-'A';//CHAR I INT E CEVIRDIK
					undo=0;//BURADA UNDO OLMADIGI ANLAMINA GELIYOR 
						if(gameboard[0][k].isFull==true){
							cerr<<"This column is full ,enter a new column please:";
							k=-1;//DOLUYSA K YI -1 YAPTIM KI DONGUYE TEKRAR GIRSIN
						
						}
					}
			
			}while(k>columnSize-1|| k<0);//k YI KONTROL ETTÝM K ÝSTEDÝÐÝMÝZ GÝBÝ DEÐÝLSE TEKRAR ÝSTEYECEK
			if(undo!=-1){
			moves.push_back(k);	
	 		return k;
			}
			else {//EGER UNDO=-1 SE YANI UNDO YAPILDIYSA RETURN UNDO YAPACAK BOYLCE OYUNUN OYNANDIGI FONKSIYONA -1 DÖNECEK VE BU SAYEDE DIGER KULLANICI TAKRAR HAMLE YAPACAK
				return undo;
			}
}
	void ConnectFourUndo::show_current_board(){
			int k,i,j;
			for(k=0;k<columnSize;k++){//TABLOUN ÜSTÜNDEKÝ HARFLERÝ YAZDIRDIM
			char column_name='A'+k;
			cout<<column_name;
			}
		cout<<endl;
		
			for(int   i = 0 ; i < rowSize ; ++i){ 
				for(int j = 0 ; j <columnSize ; ++j)
    			{     
					if(gameboard[i][j].isFull==false)//HAMLE YAPILDIKTAN SONRA YÝNE ORAYA NOKTA KOYMASIN DÝYE BU KONTROLÜ KOYDUM
				 	gameboard[i][j].sign='.';
   					cout<<gameboard[i][j].sign;
				}
			cout<<endl;
		}
	}
	void ConnectFourUndo::play_undo(){//YAPILAN HAMLEYI GERI ALAN FONKSIYONDUR , BU HAMLE YAPILDIKTAN SONRA BOARD DA DEGISIKLIK YAPILMADAN DIGER KULLANICIA GECECEK
		int undo_move=moves[moves.size()-1];
		int i=0;	
			bool ctrl=false;
		 	do
			{
				if ( gameboard[i][undo_move].isFull == true)//BU NOKTANIN BOÞ OLUP OLMADIÐI KONTRL EDLÝR
				{
					gameboard[i][undo_move].sign ='.';//HMALEYÝ YAPAN PLAYER IN HARFÝ ATANIR BU NOKTAYA
					 gameboard[i][undo_move].isFull=false;
					ctrl=true;//HAMLE YAPILIRSA CONTROL TRUE OLUR VE BU DÖNGÜYE TEKRAR GÝRMEZ
				}
				else
					++i;//HAMLE YAPILMADIYSA BÝR ÜST SATIR A GEÇER //BURADA BU NESNEYE AIT ROW AZALDIGI ICIN ASAGIDA YDEKELDIGIMIZ DEGERI GERI ALDIK
			}while (  ctrl != true );// BU DÖNGÜ HERHNAGÝ BÝR YERE HAMLE YAPILANA KADAR DEVAM EDER*/
		moves.pop_back();	//GERI ALMA ISLEMI BITTIKTEN SONRA BU VEKTOR DIZISINDEKI EN SON ELEMANI SILECEK
		//BOYLECE HAMLE ISTENILEN MIKTARDA GERI ALINABIELCEK
		}

}
