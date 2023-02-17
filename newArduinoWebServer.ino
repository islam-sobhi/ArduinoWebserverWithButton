#include <SPI.h>
#include <Ethernet.h>

/******************** ETHERNET SETTINGS ********************/

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x85, 0xD9 };	 //physical mac address
byte ip[] = { 192, 168, 0, 112 };                   // ip in lan
byte subnet[] = { 255, 255, 255, 0 };              //subnet mask
byte gateway[] = { 192, 168, 0, 1 };              // default gateway
EthernetServer server(80);                       //server port


void setup()
{
Ethernet.begin(mac,ip,gateway,subnet);   	 // initialize Ethernet device
server.begin();                       			   // start to listen for clients
pinMode(8, INPUT);                    			  // input pin for switch
}

void loop()
{
EthernetClient client = server.available(); 	 // look for the client

// send a standard http response header

client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connnection: close");
client.println();

client.println("&lt;!DOCTYPE html&gt;"); //web page is made using HTML

client.println("&lt;html&gt;");

client.println("&lt;head&gt;");

client.println("&lt;title&gt;Ethernet Tutorial&lt;/title&gt;");

client.println("&lt;meta http-equiv=\"refresh\" content=\"1\"&gt;");

client.println("&lt;/head&gt;");

client.println("&lt;body&gt;");

client.println("&lt;h1&gt;A Webserver Data &lt;/h1&gt;");

client.println("&lt;h2&gt;Observing State Of Switch&lt;/h2&gt;");

client.print("&lt;h2&gt;Switch is:  &lt;/2&gt;");

if (digitalRead(8))

{

client.println("&lt;h3&gt;ON&lt;/h3&gt;");

}

else

{

client.println("&lt;h3&gt;OFF&lt;/h3&gt;");
  delay(1);
          //stopping client
          client.stop();

}


client.println("&lt;/body&gt;");

client.println("&lt;/html&gt;");

}
