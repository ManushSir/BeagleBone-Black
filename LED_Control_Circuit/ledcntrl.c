/*In this program we will design the input pin to control the output.*/
#include <stdio.h>
#include<unistd.h>
FILE *GPIO = NULL;
FILE *LED = NULL;
char *GPIO_27 = "/sys/class/gpio/gpio27/value";
char *LED_60 = "/sys/class/gpio/gpio60/value";
int read_gpio_27 (){
char val=0;
   GPIO = fopen(GPIO_27,"r");
if (GPIO != NULL){
if( fread(&val,1,1,GPIO) != 1)
{
}
fclose(GPIO);
}
else {
perror("Failed to open GPIO_27");
}
   return val;
}
int gpio_60_on (void) {
LED = fopen(LED_60,"w");
if(LED == NULL){
perror("Failed to write on LED");
return -1;
}
fwrite("1",1,1,LED);
fclose(LED);
return 1;
}
int gpio_60_off () {
LED = fopen(LED_60,"w");
if(LED==NULL){
perror("Failed  to write on LED");
}
fwrite("0",1,1,LED);
fclose(LED);
return 0;
}
int main() {
    /* int num_reads = 200;
     int gpio;
printf("\nThis Programme provides output for the from any pin you desire");
printf("\n kindly select pin :");
scanf("%d",&gpio);
if(gpio = 27){
for(int i=0;i<=num_reads;i++){
    printf("The output is :%c\n",read_gpio_27());
usleep(2000000);
  }
}*/
  printf("\nIn this programme Shorting GPIO 27 will turn on LED Located on GPIO 60\n");
  printf("\nKinldy proceed to turn the button on\n ");
  printf("\nKindly press Cntrl+c to exit");
while(1){
int input = read_gpio_27();
  if(input == '1'){
    gpio_60_on();
  }
  else {
        gpio_60_off();
  }
usleep(200000);
}
    return 0;
}
