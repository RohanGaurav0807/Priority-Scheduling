
#include<stdio.h> 
 
int main() 
{ 
      int i, number, total = 0, x, counter = 0, TIME_QUANTUM; 
      int sum=0,p;
	  
	  int WAIT = 0, TAT = 0, Arive[10], Burst[10], M[10],priority[20],m[20]; 
      	printf("************************WELCOME*****************************************\n\n");
      	
		  	
	  float AVG_WAIT, AVG_TAT;
      printf("\nEnter Total Number of Processes:"); 
      scanf("%d", &number); 
      x = number; 
      
      for(i = 0; i < number; i++) 
      {
      
            printf("\nEnter Details of Process[%d]\n", i + 1);
         
		    printf("Arrival Time:\t");
         
		    scanf("%d", &Arive[i]);
         
		    printf("Burst Time:\t");
         
		    scanf("%d", &Burst[i]);
			
			printf("Priority:\t");
            
			scanf("%d",&priority[i]); 
            
            sum= sum+Burst[i];
      }   
		
     
	
		
		p = sum/number;
		printf("AVG of Burst Time : %d\n",p);
		for(i=0;i<number;i++)
		{
			M[i]=Burst[i]%p;
		}
		
		
		
		
		TIME_QUANTUM=p;
		printf("Time Quantum is : %d\n\n",TIME_QUANTUM);
	
		printf("\nProcess ID\tArrival Time\t\tBurst Time\t Priority\t\t Turnaround Time\t Waiting Time\n");
      
	
	  for(total = 0, i = 0; x != 0;) 
      { 
     
           
		    if(M[i] <= TIME_QUANTUM && M[i] > 0) 
            { 
                  total = total + M[i]; 
                  M[i] = 0; 
                  counter = 1; 
            } 
            else if(M[i] > 0) 
            { 
                  M[i] = M[i] - TIME_QUANTUM; 
                  total = total + TIME_QUANTUM; 
            } 
            if(M[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t%d\t\t\t%d\t\t %d\t\t\t %d\t\t\t%d", i + 1,Arive[i], Burst[i],priority[i], total - Arive[i], total - Arive[i] - Burst[i]);
                  WAIT = WAIT + total - Arive[i] - Burst[i]; 
                  TAT = TAT + total - Arive[i]; 
                  counter = 0; 
            } 
            if(i == number - 1) 
            {
                  i = 0; 
            }
            else if(Arive[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
	
      AVG_WAIT = WAIT * 1.0 / number;
      
	  AVG_TAT = TAT * 1.0 / number;
      
	  printf("\n\nAVG Waiting Time:\t%f", AVG_WAIT); 
      
	  printf("\nAvg Turnaround Time:\t%f\n", AVG_TAT); 
      return 0; 
}
