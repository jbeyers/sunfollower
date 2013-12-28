#include <Servo.h> 
 
// Create the servo objects
Servo azimuth;
Servo elevation;
 
// 3 ldr inputs. Seen from the direction of the illumination, they are at top
// left, top right, bottom left.

int topleft = A0 // Top left ldr pin
int topright = A1 // Top right ldr pin
int bottomleft = A2 // Bottom left ldr pin

acc_max = 1000;
servo_min = 20;
servo_max = 160;

double pos = 0; // Position incrementer
float spd = 0.005; // This value seems to work for reasonable speed.
float facter = 1.0; // Ratio between azimuth and elevation periods.
float starter = 0; // Starting position offset between the servos.
int adjx = 90; // Position of azimuth
int adjy = 90; // Position of elevation
float decay = 60000; // Gives the amount of steps to run on. Higher gives a slower decay.
 
void setup() 
{ 
  azimuth.attach(9);  // attaches the servo on pin 9 to the servo object 
  elevation.attach(10);  // attaches the servo on pin 10 to the servo object 
  azimuth_acc == acc_max/2;
  elevation_acc == acc_max/2;
} 
 
 
void loop() 
{ 

  if ( topleft > topright )
  {
    azimuth_acc += 1;
    if ( azimuth_acc == acc_max )
    {
      if ( azimuth < servo_max )
      {
          azimuth += 1;

      
  } else {
    azimuth_acc -= 1;
  } 

  // Return to center after drawing.
  azimuth.write(90);
  elevation.write(90);
}

