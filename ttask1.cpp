#include<iostream>
using namespace std;
float average_week(int AQI[4][7],int cityIndex){
	float avg = 0;
	for(int i =0;i<7;i++){
		avg = avg +AQI[cityIndex][i];
	}
	return avg/7.0;
}
int main(){

int AQI[4][7]=
{
			{120, 150, 140, 135, 110, 145, 160}, // City 1, Week 1
			{100, 130, 125, 140, 155, 135, 145}, // City 1, Week 2
			{180, 200, 210, 190, 205, 175, 195}, // City 1, Week 3
			{220, 230, 250, 240, 260, 225, 235}  
};
//for(int i=0;i<4;i++){
//	cout<<endl<<"CITY "<<i+1<<": "<<endl;
//	for(int j=0;j<7;j++){
//		cout<<"DAY "<<j+1<<": ";
//		cin>>AQI[i][j];
//	}
//}
int week_averages[4] = {0};
for(int i=0;i<4;i++){
	cout<<"CITY "<<i+1<<" AVERAGE: "<<average_week(AQI,i)<<endl;
	week_averages[i] = average_week(AQI,i);
}
int maxAverageIndex = 0;
for(int i=0;i<4;i++){
	if(week_averages[maxAverageIndex]<week_averages[i]){
		maxAverageIndex = i;
	}
}
cout<<"HIGHEST AQI CITY : "<<maxAverageIndex+1;


return 0;
}
