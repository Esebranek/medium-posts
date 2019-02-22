//WRITE

#include <SPI.h>
#include <mcp_can.h>

const int SPI_CS_PIN = 10;  // Define chip select pin

MCP_CAN CAN(SPI_CS_PIN);  // Create 

void setup()
{
    Serial.begin(115200);  // Initialize serial at highest baudrate

    while (CAN_OK != CAN.begin(CAN_500KBPS))  // While initialization fails
    {
        Serial.println("Initialization failed. Retrying...");
        delay(100);
    }
    Serial.println("Initialized.");
}

unsigned char msgBuf[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    
void loop()
{   
  Serial.println("Sending data...");
  CAN.sendMsgBuf(0x01, 0, 8, msgBuf);
  delay(random(250,1000);
}