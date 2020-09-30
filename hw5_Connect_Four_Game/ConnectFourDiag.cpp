#include<iostream>
using namespace std;
#include"Cell.h"
#include"ConnectFourDiag.h"
namespace my_namespace{
	void ConnectFourDiag::show_current_board(){
			int k,i,j;
			for(k=0;k<columnSize;k++){//TABLOUN �ST�NDEK� HARFLER� YAZDIRDIM
			char column_name='A'+k;
			cout<<column_name;
			}
		cout<<endl;
		
			for(int   i = 0 ; i < rowSize ; ++i){ 
				for(int j = 0 ; j <columnSize ; ++j)
    			{     
					if(gameboard[i][j].isFull==false)//HAMLE YAPILDIKTAN SONRA Y�NE ORAYA NOKTA KOYMASIN D�YE BU KONTROL� KOYDUM
				 	gameboard[i][j].sign='.';
   					cout<<gameboard[i][j].sign;
				}
			cout<<endl;
		}
	}
	void ConnectFourDiag::change_to_lower( char Sign){

	for( int i =0; i < rowSize; i++ )
	{
		for( int j =0; j < columnSize; j++ )
		{
			if( gameboard[i][j].sign ==Sign && gameboard[i-1][j-1].sign ==Sign && gameboard[i-2][j-2].sign ==Sign && gameboard[i-3][j-3].sign == Sign)
			{
			gameboard[i][j].sign =char(((int)Sign)+32); gameboard[i-1][j-1].sign =char(((int)Sign)+32); gameboard[i-2][j-2].sign =char(((int)Sign)+32); gameboard[i-3][j-3].sign=char(((int)Sign)+32);
			}
			if( gameboard[i][j].sign ==Sign  &&	gameboard[i-1][j+1].sign ==Sign && gameboard[i-2][j+2].sign == Sign &&  gameboard[i-3][j+3].sign ==Sign )
			{	
			gameboard[i][j].sign =char(((int)Sign)+32);	gameboard[i-1][j+1].sign =char(((int)Sign)+32); gameboard[i-2][j+2].sign =char(((int)Sign)+32); gameboard[i-3][j+3].sign =char(((int)Sign)+32);
			}
		
		}
	}
	}
	void ConnectFourDiag::endGame(char Sign){//SADECE D�AGONAL OLARAK YAN YANA GELDIGINDE OYUN KAZANILACAK SEKILDE OVERRIDE ETTIM
		
		int ctrl=0; 
		for(int i=0;i<columnSize;++i){
			if(gameboard[0][i].isFull==true){// HER S�TUNDAK� EN �ST SATIRI KONTROL EDER VE E�ER ORADA NOKTA YOKSA YAN� X YA DA O VARSA SAYACI B�R ARTT�RIR SAYAC S�ZE A E��T OLDU�UNDA OYUN BERAEBRA B�TM�� DEMEKT�R
				ctrl++;
			}
		} 
		
		if(ctrl==columnSize){//EGER CTRL COLUMN A ESIT OLDUYSA BUTUN SUTUNLAR DOLU DEMEKTIR
		 cout<<"Game is Draw\n"; //BUTUN SUTUNLAR DOLDUYSA OYUN BITER
		game_end=true;
		}

		int win=0;
		for( int i =0; i <rowSize; i++ )//B�T�N SATIR VE S�TUNLAR TEK TEK KONTROL ED�LECEK
		{
			for( int j =0 ; j <columnSize; j++ )
			{
				if(gameboard[i][j].sign ==Sign&&gameboard[i-1][j-1].sign ==Sign&&gameboard[i-2][j-2].sign ==Sign&&gameboard[i-3][j-3].sign ==Sign)
				{
					win = 1;//4 TANE �APARAZ OLARAK GELEB�LCEK X VE O LARI KONTROL ETT�M
				}
				if(gameboard[i][j].sign ==Sign&&gameboard[i-1][j+1].sign==Sign&&gameboard[i-2][j+2].sign ==Sign&&gameboard[i-3][j+3].sign ==Sign)
				{
					win = 1;//4 TANE D��ER TARAFA �APARAZ OLARAK GELEB�LCEK X VE O LARI KONTROL ETT�M
				}
			}
		}
		if(win==1){//WIN 1 OLDUYSA YUKARIDAKI KOSULLADAN HERHANGI BIRI GERCEKLESMISTIR
		change_to_lower(Sign);//OYUN KAZANILDIYSA KAZANAN DORTLUYU KUCULTUP BOARD U TEKRAR YAZDIRACAK
		 show_current_board();
		 if(game_mod=='P'){
		 		if(Sign=='X')
		 		cout<<"PLAYER ONE WON!!!!\n";
				else
				cout<<"PLAYER TWO WON!!!!\n";		 
		 }
		 else{
		 		if(Sign=='X')
		 		cout<<"PLAYER ONE WON!!!!\n";
				else
				cout<<"CPU WON!!!!\n";		 
		 }
			game_end=true;//BUNU TRUE YA		
		}
	 }
}
