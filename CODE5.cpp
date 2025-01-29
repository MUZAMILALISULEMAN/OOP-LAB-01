#include<iostream>
using namespace std;
float weekly_avg(int AQI[4][4][7],int cityIndex,int weekIndex) {
	float avg = 0;
	for(int i=0; i<7; i++) {
		avg+=AQI[cityIndex][weekIndex][i];
	}
	return avg/7.0;

}
void minmax(int AQI[4][4][7],int minmaxValues[2]) {
	int max = AQI[0][0][0];
	int min = max;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			for(int k=0; k<7; k++) {
				if(max < AQI[i][j][k]) {
					max = AQI[i][j][k];
				}
				if(min > AQI[i][j][k]) {
					min = AQI[i][j][k];
				}
			}
		}
	}

	minmaxValues[0] = min;
	minmaxValues[1] = max;


}
int main() {

	int AQI[4][4][7] = {
		{
			{120, 150, 140, 135, 110, 145, 160}, // City 1, Week 1
			{100, 130, 125, 140, 155, 135, 145}, // City 1, Week 2
			{180, 200, 210, 190, 205, 175, 195}, // City 1, Week 3
			{220, 230, 250, 240, 260, 225, 235}  // City 1, Week 4
		},
		{
			{310, 305, 320, 315, 300, 325, 330}, // City 2, Week 1
			{280, 290, 275, 285, 295, 305, 310}, // City 2, Week 2
			{250, 240, 260, 255, 270, 245, 265}, // City 2, Week 3
			{200, 215, 220, 230, 210, 225, 235}  // City 2, Week 4
		},
		{
			{50, 60, 70, 55, 65, 75, 80},        // City 3, Week 1
			{100, 90, 85, 95, 105, 110, 115},    // City 3, Week 2
			{150, 140, 130, 145, 155, 160, 165}, // City 3, Week 3
			{180, 190, 185, 200, 195, 205, 210}  // City 3, Week 4
		},
		{
			{400, 410, 405, 420, 415, 430, 440}, // City 4, Week 1
			{380, 370, 375, 360, 365, 355, 390}, // City 4, Week 2
			{340, 335, 345, 330, 325, 310, 320}, // City 4, Week 3
			{290, 285, 295, 300, 305, 275, 280}  // City 4, Week 4
		}
	};

	for(int i=0; i<4; i++) {
			cout<<endl<<"CITY "<<i+1<<":"<<endl;
		for(int j=0; j<4; j++) {
			for(int  k=0; k<7; k++) {
				cout<<"DAY "<<7*j+(k+1)<<": ";
				cin>>AQI[i][j][k];5
				
			}
		}

	}

	cout<<endl<<"\t====WEEKLY AVERAGE===="<<endl;
	for(int i=0; i<4; i++) {
		cout<<endl<<"CITY "<<i+1<<":"<<endl;
		for(int j=0; j<4; j++) {
			cout<<"WEEK "<<j+1<<": "<<weekly_avg(AQI,i,j)<<endl;
		}
	}
	cout<<endl<<"\t====CRTIICAL POLLUTION DAYS====="<<endl;
	for(int i=0; i<4; i++) {
		cout<<endl<<"CITY "<<i+1<<":"<<endl<<endl;
		for(int j=0; j<4; j++) {
			for(int k=0; k<7; k++) {
				if(AQI[i][j][k] > 150) {
					cout<<"DAY "<<7*j+(k+1)<<": "<< AQI[i][j][k]<<endl;
				}
			}
		}
	}
	int minmaxValues[2] = {0};
	minmax(AQI,minmaxValues);
	cout<<"MINIMUM FOR MONTH: "<<minmaxValues[0]<<endl;
	cout<<"MAXIMUM FOR MONTH: "<<minmaxValues[1]<<endl;


	return 0;
}
