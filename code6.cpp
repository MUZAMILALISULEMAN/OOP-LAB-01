#include<iostream>
using namespace std;

int main(){

int AQI[4][7] = {
    {150, 180, 200, 170, 190, 210, 220}, // City 1
    {300, 320, 310, 290, 280, 330, 340}, // City 2
    {50,  70,  80,  60,  90,  85,  100}, // City 3
    {400, 420, 450, 430, 440, 460, 480}  // City 4
};
int stars;
for(int i=0;i<4;i++){
	cout<<endl<<endl<<"CITY "<<i+1<<": "<<endl;
	for(int j=0;j<7;j++){
		cout<<endl<<"DAY "<<j+1<<": ";
		stars = AQI[i][j]/50;
		for(int k=0;k<stars;k++){
			cout<<"*";
		}
	}
}





return 0;
}
