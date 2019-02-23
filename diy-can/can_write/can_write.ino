 //WRITE

#include <SPI.h>
#include <mcp_can.h>

const int SPI_CS_PIN = 10;  // Define chip select pin

MCP_CAN CAN(SPI_CS_PIN);  // Create 

void setup()
{
    Serial.begin(115200);  // Initialize serial at highest baudrate

    while (CAN_OK != CAN.begin(CAN_500KBPS))  // While initialization fails retry
    {
        Serial.println("Initialization failed. Retrying...");
        delay(100);
    }
    Serial.println("Initialized.");
}

unsigned char msgBuf[8] = {0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA};  // Use A-E for nodes 1-5
    
void loop()
{   
  Serial.println("Sending data...");
  CAN.sendMsgBuf(0x01, 0, 8, msgBuf);  // Update nodes ID (0x01 - 0x05)
  delay(random(250,1000));  // Wait some time before sending more
}
