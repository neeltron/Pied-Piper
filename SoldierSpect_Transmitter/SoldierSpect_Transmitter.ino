// TRANSMITTER CODE

//NOTE :- THIS CODE IS USED WHEN YOU WANT TO CONTROL THE ROBOT VIA THE COMPUTER!!!!

#include <VirtualWire.h>
const int xpin = A0; // x-axis of the accelerometer
int temp = 0;
void setup()
{
    Serial.begin(9600);    // Debugging only
    Serial.println("setup");

    // Initialise the IO and ISR
     
    vw_setup(2000);  // Bits per sec
        vw_set_tx_pin(7); //Transmitter Data Pin to Digital Pin 3
          pinMode(10, INPUT_PULLUP);

}//close setup

void loop()
{
  int x = random(0,100);
    
    
    int isButtonPressed = !digitalRead(10);
  if (isButtonPressed) {
    temp+=1;
  }
  if(temp%2==0) {
    char *msg2 = "t";
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
  else
    { 
    char *msg2 = "f";
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
    }
     
    
   } 
