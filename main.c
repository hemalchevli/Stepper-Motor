#include<avr/io.h> 
#include<util/delay.h> 
 
/*Macros definition*/ 

#define CHECKBIT(x,b) 	x&(1<<b)  	//Checks bit status 
#define SETBIT(x,b)	 	x|=(1<<b)   	//Sets the particular bit 
#define CLEARBIT(x,b) 	x&=~(1<<b) 	//Sets the particular bit 
#define TOGGLEBIT(x,b)	 x^=(1<<b) 	//Toggles the particular bit 
/************************HALF STEPS*****************/
/*Connect */
/*C0---->3---->yellow*/
/*C1---->4---->orange*/
/*C2---->1---->red*/
/*C3---->2---->brown*/

void s1 (void){
//PORTC |= 0x03;
SETBIT(PORTC,0);
SETBIT(PORTC,1);
CLEARBIT(PORTC,2);
CLEARBIT(PORTC,3);
}
void s2 (void){
//PORTC |= 0x06;
CLEARBIT(PORTC,0);
SETBIT(PORTC,1);
SETBIT(PORTC,2);
CLEARBIT(PORTC,3);
}
void s3 (void){
//PORTC |= 0x0C;
CLEARBIT(PORTC,0);
CLEARBIT(PORTC,1);
SETBIT(PORTC,2);
SETBIT(PORTC,3);
}
void s4 (void){
//PORTC |= 0x09;
SETBIT(PORTC,0);
CLEARBIT(PORTC,1);
CLEARBIT(PORTC,2);
SETBIT(PORTC,3);
}

void test (void){
CLEARBIT(PORTC,0);
CLEARBIT(PORTC,1);
CLEARBIT(PORTC,2);
SETBIT(PORTC,3);
}
/*************************FULL STEPS***********************/
void fs1 (void){
//PORTC |= 0x03;
SETBIT(PORTC,0);
CLEARBIT(PORTC,1);
CLEARBIT(PORTC,2);
SETBIT(PORTC,3);
}
void fs2 (void){
//PORTC |= 0x06;
CLEARBIT(PORTC,0);
CLEARBIT(PORTC,1);
SETBIT(PORTC,2);
SETBIT(PORTC,3);
}
void fs3 (void){
//PORTC |= 0x0C;
CLEARBIT(PORTC,0);
SETBIT(PORTC,1);
SETBIT(PORTC,2);
CLEARBIT(PORTC,3);
}
void fs4 (void){
//PORTC |= 0x09;
SETBIT(PORTC,0);
SETBIT(PORTC,1);
CLEARBIT(PORTC,2);
CLEARBIT(PORTC,3);
}
/////////////////////////////////////
void ccw (void){
		s1();
		_delay_ms(2);
		s2();
		_delay_ms(2);
		s3();
		_delay_ms(2);
		s4();
		_delay_ms(2);
}
void cw (void){
		fs1();
		_delay_ms(500);
		fs2();
		_delay_ms(500);
		fs3();
		_delay_ms(500);
		fs4();
		_delay_ms(500);
}

int main(void)
{
	int i;
	SETBIT(DDRC,0);	//motors
	SETBIT(DDRC,1);
	SETBIT(DDRC,2);
	SETBIT(DDRC,3);
	CLEARBIT(PORTC,0);
	CLEARBIT(PORTC,1);
	CLEARBIT(PORTC,2);
	CLEARBIT(PORTC,3);
	
	while(1)
		{
	
			ccw();
			
		}
	return(0);
}
