/*This programme is used to write PWm on beaglebone black*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
FILE *EXPO = NULL;
FILE *DIR = NULL;
char *PWM_P9 = "/sys/class/pwm/pwmchip3/export";
char *PWM_P8 = "/sys/class/pwm/pwmchip6/export";
char *PWM_P9_14 = "/sys/class/pwm/pwmchip3/pwm0";
char *PWM_P9_16 = "/sys/class/pwm/pwmchip3/pwm1";
char *PWM_P8_13 = "/sys/class/pwm/pwmchip6/pwm1";
char *PWM_P8_19 = "/sys/class/pwm/pwmchip6/pwm0";

int pin_export_P9(void){
EXPO = fopen(PWM_P9,"w");
if(EXPO == NULL)
{
perror("Failed to export the pin");
return -1;
}
fwrite("echo 0 | sudo tee export",1,25,EXPO);
fclose(EXPO);
return 0 ;
}

int pin_export_P8_pwm1(void){
EXPO = fopen(PWM_P8,"w");
if(EXPO == NULL)
{
perror("Failed to export the pin");
return -1;
}
fprintf(EXPO,"0");
fclose(EXPO);
return 0 ;
}

int pin_export_P8_pwm0(void){
EXPO = fopen(PWM_P8,"w");
if(EXPO == NULL)
{
perror("Failed to export the pin");
return -1;
}
fprintf(EXPO,"1");
fclose(EXPO);
return 0 ;
}

int pin_P8_13 (int  input,unsigned long long duty_cycle,unsigned long long period){
char path[128];
FILE *f;
system("config-pin P8_13 pwm");
/*Set Period*/
snprintf(path,sizeof(path),"%s/period",PWM_P8_13);
f = fopen(path,"w");
fprintf(f,"%llu",period);
fclose(f);
/*Duty_Cycle*/
snprintf(path,sizeof(path),"%s/duty_cycle",PWM_P8_13);
f = fopen(path,"w");
fprintf(f,"%llu",duty_cycle);
fclose(f);
/*Enable*/
snprintf(path,sizeof(path),"%s/enable",PWM_P8_13);
f = fopen(path,"w");
fprintf(f,"1");
fclose(f);
/*I will wait for 3 minutes for LED to close*/
sleep (180);
/*Disable the LED*/
snprintf(path,sizeof(path),"%s/enable",PWM_P8_13);
f = fopen(path,"w");
fprintf(f,"0");
fclose(f);
return 0;
}
int pin_P8_19 (int  input,unsigned long long duty_cycle,unsigned long long period){
char path[128];
FILE *f;
system("config-pin P8_19 pwm");
/*Set Period*/
snprintf(path,sizeof(path),"%s/period",PWM_P8_19);
f = fopen(path,"w");
fprintf(f,"%llu",period);
fclose(f);
/*Duty_Cycle*/
snprintf(path,sizeof(path),"%s/duty_cycle",PWM_P8_19);
f = fopen(path,"w");
fprintf(f,"%llu",duty_cycle);
fclose(f);
/*Enable*/
snprintf(path,sizeof(path),"%s/enable",PWM_P8_19);
f = fopen(path,"w");
fprintf(f,"1");
fclose(f);
/*I will wait for 3 minutes for LED to close*/
sleep (180);
/*Disable the LED*/
snprintf(path,sizeof(path),"%s/enable",PWM_P8_19);
f = fopen(path,"w");
fprintf(f,"0");
fclose(f);
return 0;
}

int main (void) {
int pin;
unsigned long long duty_cycle;
unsigned long long period;
printf("\n Welcome to this programme ! You can select a GPIO PIn with PWM and generate custom frequency !\n");
printf("\n For using P8_13 Select 1\n");
printf("\n For using P8_19 Select 2\n");
printf("\n For using P9_14 Select 3\n");
printf("\n For using P9_16 Select 4\n");
scanf("%d",&pin);
printf("\nKinldy enter the desired duty cycle in hz\t");
scanf("%llu",&duty_cycle);
printf("\nKindly enter the desired period\t");
scanf("%llu",&period);
switch (pin){
case 1 :
pin_export_P8_pwm0();
pin_P8_13(pin,duty_cycle,period);
break;
case 2 :
pin_export_P8_pwm1();
pin_P8_19(pin,duty_cycle,period);
break;
default :
printf("\nSorry wrong input pin , please retry\n");
}
return 0;
}
