/*In this program we will design the input pin to control the output LED.
This is by far the best version of program written. This program  ensures the input pin is exported to become input and output pin is exported to output. After that it also asks user to provide input and output pin. 
However, This program requires some beautification. */
#include <stdio.h>
#include<unistd.h>
FILE *GPIO = NULL;
FILE *LED = NULL;
FILE *EXPO = NULL;
FILE *DIR_IN = NULL;
char *GPIO_IN = "/sys/class/gpio/gpio%d/value";
char *LED_OUT = "/sys/class/gpio/gpio60/value";
char *LED_EXPO = "/sys/class/gpio/gpio60/direction";
int read_gpio_in (int inpin){
char val=0;
char path[50];
char direction[50];
sprintf(path,"/sys/class/gpio/gpio%d/value",inpin);
sprintf(direction,"/sys/class/gpio/gpio%d/direction",inpin);
DIR_IN = fopen(direction,"w");
fwrite("in",1,2,DIR_IN);
fclose(DIR_IN);
GPIO = fopen(path,"r");
if (GPIO != NULL){
if( fread(&val,1,1,GPIO) != 1)
{
}
fclose(GPIO);
}
else {
perror("Failed to open input pin");
}
   return val;
}
int gpio_out_on (int oppin) {
char path[50];
char direction[50];
sprintf(path,"/sys/class/gpio/gpio%d/value",oppin);/*This command helps to enter the GPIO pin by end user.*/
sprintf(direction,"/sys/class/gpio/gpio%d/direction",oppin);
EXPO =fopen(direction,"w");
fwrite("out",1,3,EXPO);
fclose(EXPO);
LED = fopen(path,"w");
if(LED == NULL){
perror("Failed to write on LED");
return -1;
}
fwrite("1",1,1,LED);
fclose(LED);
return 1;
}
int gpio_out_off (int oppin) {
char direction[50];
sprintf(direction,"/sys/class/gpio/gpio%d/value",oppin);
LED = fopen(direction,"w");
if(LED==NULL){
perror("Failed  to write on LED");
}
fwrite("0",1,1,LED);
fclose(LED);
return 0;
}
int main() {
int inpin;
int oppin;
printf("\nIn this program you will select desired input pin and output pin to turn on LED\n");
printf("\n Please select input pin:");
Ascanf("%d",&inpin);
printf("\nPlease select ouput pin:");
scanf("%d",&oppin);
printf("\nThe input button is GPIO_%d & output LED is on GPIO_%d",inpin,oppin);
printf("\n Kindly press 'Cntrl+c' to exit ");
while(1){
int input = read_gpio_in(inpin);
  if(input == '1'){
    gpio_out_on(oppin);
  }
  else {
        gpio_out_off(oppin);
  }
usleep(200000);
}
    return 0;
}
