#include<stdio.h>
#include<conio.h>
struct process
{
    int id;
    int arrival;
    int burst;
    int rem;
    int wait;
    int finish;
    int ti;
    int turnaround;
    float ratio;
    int avg;
}p1[10];
int no,k;
int checkp1(int s)
{
 int i;
 for(i = 1; i <= s; i++)
 {
  if(p1[i].rem != 0)
   return 1;
 }
 return 0;
}
int nextp1(int k)
{
 int i;
 i=k+1;
 while(checkp1(i) && i!=k)
 {
  if(p1[i].rem != 0)
   return i;
   else
   i=(i+1)%no;
 }
}
int main()
{
 int i,j,t,time = 0,n;
 struct process temp;
 int nextp1(int);
 printf("\n \n Enter the number of process: ");
 scanf("%d", &n);
 printf("\n \n Enter the time quantum: ");
 scanf("%d", &t);
 for(i = 1; i <= n; i++)
 {
  p1[i].id = i;
  printf("\n\nEnter the arrival time for p1 %d: ", i);
  scanf("%d", &(p1[i].arrival));
  printf("\nEnter the burst time for p1 %d: ", i);
  scanf("%d", &(p1[i].burst));
  p1[i].rem = p1[i].burst;
  p1[i].ti=0;
  p1[i].wait=0;
  p1[i].finish=0;
 }
 for(i = 1; i <= n; i++)
 {
  for(j = i + 1; j <= n; j++)
  {
   if(p1[i].arrival > p1[j].arrival)
   {
   	temp = p1[i];
    p1[i] = p1[j];
    p1[j] = temp;
   }
  }
 }

 no = 0;
 j = 1;

 while(checkp1(n) == 1)
 {
  if(p1[no + 1].arrival == time)
   no++;
  if((p1[j].ti<=t)&&(p1[j].rem !=0))
  {
   p1[j].rem--;
   p1[j].ti++;
   for(i = 1; i <= no; i++)
   {
    if((i!=j) && (p1[i].rem != 0))
     p1[i].wait++;
   }
  }
  if(p1[j].rem==0)
   p1[j].finish=time;
  if((p1[j].ti >= t)||(p1[j].rem==0))
  {
   p1[j].ti = 0;
   j=nextp1(j);
  }
  time++;
  }
 p1[n].finish = time;
 printf("\n\n p1  Arrival  Burst   Waiting  Finishing turnaround  Tr/Tb \n");
 printf("%5s %9s %7s %10s %8s %9s\n\n", "id", "time", "time", "time", "time", "time");
 for(i = 1; i <= n; i++)
 {
  p1[i].turnaround = p1[i].wait + p1[i].burst;
  p1[i].ratio = (float)p1[i].turnaround / (float)p1[i].burst;
  printf("%5d %8d %7d  %8d %10d %9d %10.1f ", p1[i].id, p1[i].arrival,
                          p1[i].burst,
                          p1[i].wait, p1[i].finish,
                          p1[i].turnaround, p1[i].ratio);

  printf("\n\n");
 }
 float avg,avg1,sum=0,sum1=0;
for(i=1;i<=n;i++)
{
	sum=sum+p1[i].turnaround;
	sum1=sum1+p1[i].wait;
}
avg=sum/n;
avg1=sum1/n;
printf("\naverage turnaround time is %f",avg);
printf("\naverage waiting time is %f",avg1);
 getch();
}
