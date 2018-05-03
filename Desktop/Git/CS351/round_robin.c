#include <stdio.h>
#include <stdlib.h>


//A round robin process scheduling program
int main(){
	int processes[] = {1,2,3,4,5};
	int burst[] = {8,6,1,9,3};
	int arrival[] = {0,2,2,1,3};
	int order[] = {0,0,0,0,0};
	int place = 0;
	int quantum_time;
	int time = 0;

	//set the quantum time
	printf("Please enter quantum time(1 or 2): ");
	scanf("%d", &quantum_time);
	
	//set the time that will be the limit for checking the processes for burst time
	while(time < 100){
		for(int i = 0; i < 5; i++){
			if(arrival[i] == time){
				for(int j = 0; j < 5; j++){
					if(order[j] == 0){
						order[j] = i + 1;
						break;	
					}
				}
			}
		}
		
		//Print the process if it is ready
		if(burst[order[place] - 1] >= 1){
			burst[order[place] - 1] = burst[order[place] - 1] - 1;
			printf("P%d ", order[place]);
		}	

		//Establish the remaining time depending on the quantum time
		if(quantum_time == 1){
			if(place <= 3){
				place++;
			}else{
				place = 0;
			}
		}else{
			if(time % 2 == 1){
				if(place <= 3){
					place++;
				}else{
					place = 0;
				}
			}
		}

		time++;
	} 
}
