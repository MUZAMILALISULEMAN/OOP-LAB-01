#include<iostream>
float month_average(int AQI[4][4][7],int cityIndex) {

	float avg=0;

	for(int i=0; i<4; i++) {
		for(int j=0; j<7; j++) {
			avg+=AQI[cityIndex][i][j];
		}
	}

	return avg/28.0;

}

float improvement_calc(int AQI[4][4][7],int cityIndex) {
	float improvement =0;
	float weeks_avg[2] = {0};
	int weeks_index[2] = {0,3};
	for(int i=0; i<2; i++) {
		for(int j=0; j<7; j++) {
			improvement+=AQI[cityIndex][weeks_index[i]][j];
		}

		weeks_avg[i] = improvement/7.0;
		improvement = 0;
	}
	improvement = weeks_avg[0] - weeks_avg[1];
	if(improvement > 0){
	return improvement;
	}
	return 0;
}




using namespace std;
int main() {

	int AQI[4][4][7] = {
		{
			// City 1
			{0, 0, 0, 0, 0, 0, 0},  // Week 1
			{55, 53, 54, 52, 51, 56, 55},  // Week 2
			{50, 48, 49, 47, 46, 51, 50},  // Week 3
			{42, 40, 41, 39, 38, 43, 42}   // Week 4
		},
		{
			// City 2
			{80, 78, 79, 77, 76, 81, 80},  // Week 1
			{75, 73, 74, 72, 71, 76, 75},  // Week 2
			{70, 68, 69, 67, 66, 71, 70},  // Week 3

			{65, 63, 64, 62, 61, 66, 65}   // Week 4
		},
		{
			// City 3
			{45, 43, 44, 42, 41, 46, 45},  // Week 1
			{40, 38, 39, 37, 36, 41, 40},  // Week 2
			{35, 33, 34, 32, 31, 36, 35},  // Week 3
			{30, 28, 29, 27, 26, 31, 30}   // Week 4
		},
		{

			{100, 98, 99, 97, 96, 101, 100},
			{95, 93, 94, 92, 91, 96, 95},
			{90, 88, 89, 87, 86, 91, 90},
			{85, 83, 84, 82, 81, 86, 85}
		}
	};


//	for average of month

	for(int i=0; i<4; i++) {
		cout<<"AVERAGE AQI FOR CITY "<<i+1<<": "<<month_average(AQI,i)<<endl<<endl;
	}

//improved City

	cout<<improvement_calc(AQI,0);



	return 0;
}