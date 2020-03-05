// RECIEVER CODE

//NOTE :- THIS RECEIVER CODE IS USED WHEN YOU WANT TO CONTROL THE ROBOT VIA THE COMPUTER

#include <VirtualWire.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  Serial.begin(9600);  // Debugging only
  Serial.println("setup");
  // Initialise the IO and ISR
  vw_setup(2000);  // Bits per sec
  vw_set_rx_pin(7);//Receiver at Digital Pin 2
  vw_rx_start();// Start the receiver PLL running
lcd.begin(16, 2);

  /*
    This is basically what the for loop does :-
    pinMode(en1, OUTPUT);
    pinMode(en2, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(en1o2, OUTPUT);
    pinMode(en2o2, OUTPUT);
    pinMode(in1o2, OUTPUT);
    pinMode(in2o2, OUTPUT);
    pinMode(in3o2, OUTPUT);
    pinMode(in4o2, OUTPUT);
  */

}//close setup

void loop()
{



  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    int i;

    digitalWrite(13, true); // Flash a light to show received good message
    // Message with a good checksum received, dump it.

    for (i = 0; i < buflen; i++)
    {
      Serial.print(buf[i]);
      if (buf[i] == 'f')
      {
        Serial.print("OK");
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Soldier is okay");
      }   
      if (buf[i] == 't')
      {
        Serial.print("Help");
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Soldier is injured");
      }
    }
      

    }//close for loop

  }
