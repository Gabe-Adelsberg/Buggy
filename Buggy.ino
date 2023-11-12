//to-do:apply the Vx and Vy in the go funtion to move motors. 0 is the motor that will be off, 1 will move by Vx, and 2 will move by Vy
//for go function
float Vx;
float Vy;
float Joyx;
float Joyy;
//for joystick
const int SW_pin = 8;    //digital (might change)
const int Joyx_pin = 0;  //analog
const int Joyy_pin = 1;  //analog
int quad; //joystick quadrant

void setup() {
  // put your setup code here, to run once:

}
void loop() {
  // put your main code here, to run repeatedly:
  go(getSpd(),getDir());
}
float getSpd()
{return sqrt(abs(sq(getJoyX()))+abs(sq(getJoyY())));}
int getDir()
{return atan(getJoyX()/getJoyY());}
int getJoyX()
{return analogRead(Joyx_pin);}
int getJoyY()
{return analogRead(Joyy_pin);}

int getJoyQuad(){
  Joyx = getJoyX();
  Joyy = getJoyY();
  if(Joyx <= 512)
  {
  if(Joyy <= 512) // QII
  {return 2;}//Motor 2 is off, Motor 1 is Vx, Motor 3 is Vy
  else // QIII
  {return 3;}//Motor 3 is off, Motor 1 is Vx, Motor 2 is Vy
 }
 else if(Joyx > 512)
 {
  if(Joyy < 512)//QIV
  {return 4;}//Motor 2 is off, Motor 1 is Vx, Motor 3 is Vy
  else //QI
  {return 1;}//Motor 3 is off, Motor 1 is Vx, Motor 2 is Vy{  
}
}
void go(float spd, int dir) // spd is abs value of joystick from 0. Dir is angle that joystick vector makes with x and y axis
{
  Vx = spd*sin(dir);
  Vy = spd*cos(dir);
//movement based on joystick
 Joyx = getJoyX();
 Joyy = getJoyY();
 quad = getJoyQuad();
}