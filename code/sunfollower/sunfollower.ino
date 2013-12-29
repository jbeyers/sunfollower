#include <Servo.h> 

// Create the servo objects
Servo azimuth_servo;
Servo elevation_servo;

// 3 ldr inputs. Seen from the direction of the illumination, they are at top
// left, top right, bottom left.



int acc_max = 1000;
int servo_min = 20;
int servo_max = 160;
int azimuth = 90;
int elevation = 90;
int azimuth_acc = acc_max/2; 
int elevation_acc = acc_max/2;

void setup() 
{ 
    azimuth_servo.attach(9);  // attaches the servo on pin 9 to the servo object 
    elevation_servo.attach(10);  // attaches the servo on pin 10 to the servo object 
    Serial.begin(9600);

} 


void loop()
    {
    int topleft = analogRead(A0); // Top left ldr pin
    int topright = analogRead(A1); // Top right ldr pin
    int bottomleft = analogRead(A2); // Bottom left ldr pin
    //Serial.println("Val");
    //Serial.println(topleft);
    //Serial.println(topright);
    //Serial.println(bottomleft);
    
    if ( topleft > topright ) 
    {
        azimuth_acc += 1;
        if ( azimuth_acc == acc_max )
        {
            azimuth_acc = acc_max/2;
            if ( azimuth < servo_max )
            {
                azimuth += 1;
            }
        }
    } else {
        azimuth_acc -= 1;
        if ( azimuth_acc == 0 )
        {
            azimuth_acc = acc_max/2;
            if ( azimuth > servo_min )
            {
                azimuth -= 1;
            }
        }
    } 
    if ( topleft < bottomleft ) 
    {
        elevation_acc += 1;
        if ( elevation_acc == acc_max )
        {
            elevation_acc = acc_max/2;
            if ( elevation < servo_max )
            {
                elevation += 1;
            }
        }
    } else {
        elevation_acc -= 1;
        if ( elevation_acc == 0 )
        {
            elevation_acc = acc_max/2;
            if ( elevation > servo_min )
            {
                elevation -= 1;
            }
        }
    }
    azimuth_servo.write(azimuth);
    elevation_servo.write(elevation);
}

