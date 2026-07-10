#include <stdio.h>                                                                                                                     #include<unistd.h>
FILE *GPIO = NULL;
char *GPIO_60 = "/sys/class/leds/beaglebone:green:usr2/brightness";                                                                     int ledon(){ 
(GPIO = fopen(GPIO_60,"w"));                                                                                                            fwrite("1",1,1,GPIO);
fclose(GPIO);                                                                                                                             }
int ledoff(){
GPIO = fopen(GPIO_60,"w");
fwrite("0",1,1,GPIO);
fclose(GPIO);
}
int alert(){
printf("The system is playing Alert Tone");
for (int i=0;i<10;i++){
ledon(); 
usleep(500000);
ledoff();
usleep(2500000);
}                                                                                                                                         }                                                                                                                                        int tempo(){                                                                                                                             printf("\nThe system is playing Temporal Tone\n");
for (int i=0;i<10;i++){                                                                                                                   for (int i=0;i<3;i++){
ledon();                                                                                                                                 usleep(500000);
ledoff(); 
usleep(500000);
}
usleep(1500000);
}
}
int california(int b){
printf("\nThe system is playing California Code\n");
for(int i=0;i<10;i++){
ledon();                                                                                                                                  
usleep(5000000);
ledoff();
usleep(10000000);}
} 
int march(int d){
printf(" The system is playing March Code ");
for(int i=0;i<10;i++){
if(GPIO = fopen(GPIO_60,"w")){                                                                                                           fwrite("1",1,1,GPIO);
fclose(GPIO);                                                                                                                            usleep(500000);                                                                                                                          }                                                                                                                                      if(GPIO = fopen(GPIO_60,"w")){
fwrite("0",1,1,GPIO);
fclose(GPIO);                                                                                                                            usleep(500000);
}
}                                                                                                                                        } 
int main() {
int c;                                                                                                                                  
printf("\nThis Programme runs LED's as per your command\n");                                                                             printf("\nPlease Enter \n 1 for Temporal Code \n 2 for California Code\n 3 for March Code\n 4 for Alert Code\n");                       
scanf("%d",&c);                                                                                                                          
switch (c)
{                                                                                                                   
case 1:                                                                                                                                 
tempo(c);                                                                                                                      
break;
case 2:                                                                                                                                  california(c);                                                                                                                          break;                                                                                                                             
case 3:
march(c);
break;                                                                                                                                  case 4:                                                                                                                              alert(c);                                                                                                                            break;
default:
printf("\nSorry, Wrong Input. Please try again.");
break;
}                                                                                                                                      return 0;
}           

