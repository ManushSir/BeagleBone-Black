/*This program blinks the LED on GPIO 60 on and off in temporal pattern for 10 times*/
#include <stdio.h>
#include<unistd.h>
int main (){
FILE *GPIO = NULL;
char *GPIO_60 = "/sys/class/gpio/gpio60/value";
for (int i=0;i<10;i++){
for (int i=0;i<3;i++){
if(GPIO = fopen(GPIO_60,"w")){
fwrite("1",1,1,GPIO);
fclose(GPIO);
usleep(500000);
}
if(GPIO = fopen(GPIO_60,"w")){
fwrite("0",1,1,GPIO);
fclose(GPIO);
usleep(500000);
}
}
usleep(1500000);
}
return 0;
}
