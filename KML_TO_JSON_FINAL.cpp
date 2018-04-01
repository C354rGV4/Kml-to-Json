//  Created by Cesar guillermo vazquez alvarez on 03/31/18.
//  Copyright © 2018 C354rGV4. All rights reserved.
//
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
	string entrada;
	string line,s;
	cout<<"Upload your KML"<<endl;
	cin>>entrada;
	ifstream myfile (entrada);
	ofstream file;
	cout<<endl;
	unsigned int cont = 0;
	char firstClean[99999];
	char secondClean[99999];
	int varenc = 0;
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			for (char & x : line) {
				firstClean[cont] = x;
				cont++;
			}
		
			for(int i = 0; i < cont ; i++){
				if(firstClean[i] == 'c' && firstClean[i+1] == 'o' && firstClean[i+2] == 'o' &&  firstClean[i+3] == 'r' &&  firstClean[i+4] == 'd' &&  firstClean[i+5] == 'i' &&  firstClean[i+6] == 'n' &&  firstClean[i+7] == 'a' &&  firstClean[i+8] == 't' &&  firstClean[i+9] == 'e' &&  firstClean[i+10] == 's'){
					varenc = i;
					break;
				}
			}	
		}
		myfile.close();
	}
	else{
		cout<<"I can't find";
		return 0;
	}
	for(int j = 16; j < (cont - varenc)-60 ;j++){
		secondClean[j-16] = firstClean[j+varenc];
		s += secondClean[j-16]; 
	} 
	string a;
	int i = 0,j = 0;
	string y [99999];
	for (char & c : s) {
		i++;
		if (c != ','){
			a = a+c;
		}else {
			j++;
			string myWord = a;
			char myArray[myWord.size()+1];//as 1 char space for null is also required
			strcpy(myArray, myWord.c_str());
			if(myArray[0] != '0'){
				y[j] = a;
			}
			else {
				int tamaño = sizeof(myArray) / sizeof(myArray[0]);
				for(int i = 0; i<tamaño-2;i++){
					y[j] += myArray[i+2];
					
				}
				
			}
			a.erase (0 , i);
			
		}
	}
	cout<<endl<<"["<<endl;
	
	for(int c = 0; c<j; c++){
		if(c%2 == 0){
			 cout<<"{"<<endl<<'"'<<"mLatitud"<<'"'<<" : "<<y[c+2]<<","<<endl<<'"'<<"mLongitud"<<'"'<<" : "<<y[c+1]<<endl<<"}";
			if(c!=j-2){
				cout<<",";
			}
			cout<<endl;
		}
	}
	cout<<"]";
}

