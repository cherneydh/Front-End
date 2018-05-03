#include <stdio.h>
#include <stdlib.h>

int main(){
	int available[4];
	int processes[5][4];
	int allocation[5][4];
	int needed[5][4];
	int order[5] = {-1, -1, -1, -1, -1};
	int good = 0;
	int free;
	int occupied = 0;

	printf("Enter the integers for available:\n");
	for(int i = 0; i < 4; i++){
		scanf("%d", &available[i]);
	}

	printf("Enter the max of available processes: \n");
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 4; j++){
			scanf("%d", &processes[i][j]);
		}
	} 	

	printf("Enter the allocation for each process: \n");
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 4; j++){
			scanf("%d", &allocation[i][j]);
		}
	}
	
	printf("Enter the needed amount for processes: \n");
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 4; j++){
			scanf("%d", &needed[i][j]);
		}
	}
	
	//Loop over the processes 5 times for proper order
	for(int i = 0; i < 5; i++){
		//Loop over each individual process
		for(int j = 0; j < 5; j++){
			//Loop over each different thread
			for(int k = 0; k < 4; k++){
				free = available[k] + allocation[j][k];
				if(free >= needed[j][k]){
					good++;
				} 
			}
			//If all the processes in the thread are good, continue
			if(good == 4){
				for(int k = 0; k < 5; k++){
					if(order[k] == j){
						occupied = 1;	
						//To prevent redundant process listing
					}
				}

				//Set the process order
				for(int k = 0; k < 5; k++){
					if(order[k] == -1){
						if(occupied == 0){
							order[k] = j;
							break;
						}
					}
				}
				//set the available to unreachable so theyll be ignored
				for(int p = 0; p < 4; p++){
					available[p] += allocation[j][p];
					needed[j][p] = 999;
				}
			}

			good = 0;
			occupied = 0;
		}
	}

	//If all the process slots are filled
	for(int i = 0; i < 5; i++){
		if(order[i] == -1){
			printf("There is no safe order\n");
			exit(1);
		}
	}
	
	//If there is a safe sequence
	printf("The safe sequence for these processes are:\n");
	for(int i = 0; i < 5; i++){
		printf("P%d\t", order[i]);
	}	
}
