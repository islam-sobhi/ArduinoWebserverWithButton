#include <SPI.h>
#include <Ethernet.h>
#include <Client.h>


// MAC address 
byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192,168,0,50 };
byte server[] = { 192,168,0,100 }; // mio computer

Client client(server, 80);
// pin button:
const int button2Pin = 2;     // the number of the pushbutton pin
const int button3Pin = 3;

// variables will change:
int button2State = 0;     
int button2StateOld = 0; // variable for reading the pushbutton status
int button3State = 0;     
int button3StateOld = 0; // variable for reading the pushbutton status





void setup() {

  
  // initialize the pushbutton pin as an input:
  pinMode(button2Pin, INPUT); 
  pinMode(button3Pin, INPUT);  
    // start the Ethernet connection:
 Ethernet.begin(mac, ip);
  // initialize serial:
  Serial.begin(9600);
  // initialize ethernet:
  delay(1000);
  Serial.println("connecting...");
  // if connect show on serial:
  if (client.connect()) 
  Serial.println("connected"); 
   
else {
  // if not connect:
  Serial.println("connection failed");
  }
}


void loop ()
{
  loop1 ();
  loop2 ();
}


void loop1 ()
{
        button2StateOld=button2State;
        button2State = digitalRead(button2Pin);
  
    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH:
    if (button2State != button2StateOld)  {
                  if (button2State == HIGH){
                           client.connect(); 
                           Serial.println("pin2 high Button 2 clicked");
                           client.println("POST /link1.php");
                           client.println();
                           client.stop();} 
                    } 

      
          delay (500);//end delay before loop starts again 
}
void loop2 ()
{
        button3StateOld=button3State;
        button3State = digitalRead(button3Pin);
  
    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH:
    if (button3State != button3StateOld)  {
                  if (button3State == HIGH){
                           client.connect(); 
                           Serial.println("pin3 high Button 3 clicked"); 
                           client.println("POST /link2.php");
                           client.println();
                           client.stop();} 
                    } 

      
          delay (500);//end delay before loop starts again 
}
