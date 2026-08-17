#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
FILE *DIR = NULL;
char *pin_33 = "/sys/bus/iio/devices/iio:device0/in_voltage4_raw";
int main(){
int db;
float volt;
while (1){
DIR = fopen(pin_33,"r");
if(DIR == NULL){
printf("error reading file");
return 1;
}
else{
fscanf(DIR,"%d",&db);
volt = (db*1.8)/4095;
printf("\nThe input voltage is: %0.2f\n",volt);
fclose(DIR);
sleep(2);
}
}
return 0;
}

