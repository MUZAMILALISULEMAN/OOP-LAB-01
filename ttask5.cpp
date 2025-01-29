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

	int AQI[4][4][7];

	for(int i=0; i<4; i++) {
			cout<<endl<<"CITY "<<i+1<<":"<<endl;
		for(int j=0; j<4; j++) {
			for(int  k=0; k<7; k++) {
				cout<<"DAY "<<7*j+(k+1)<<": ";
				cin>>AQI[i][j][k];
				
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
