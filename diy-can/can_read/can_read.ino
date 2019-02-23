// READ

#include <SPI.h>
#include "mcp_can.h"

const int SPI_CS_PIN = 10;  // Define the chip select pin
MCP_CAN CAN(SPI_CS_PIN);  // Create can with the correct pin

void setup()
{
    Serial.begin(115200);  // Init serial with highest baudrate

    while (CAN_OK != CAN.begin(CAN_500KBPS))  // While initialization fails
    {
        Serial.println("Initialization failed. Retying...");
        delay(100);
    }
    Serial.println("Initialized.");
    Serial.println("Sender ID\tByte 0\tByte1\tByte2\tByte3\tByte4\tByte5\tByte6\tByte7");
}


void loop()
{
    unsigned char len = 0;
    unsigned char buf[8];

    if(CAN_MSGAVAIL == CAN.checkReceive()) // If we have a message available
    {
        CAN.readMsgBuf(&len, buf);  // Read the message into our buffer
        unsigned long senderID = CAN.getCanId();  // Get the sender nodes ID

        Serial.print(senderID, HEX);  // Print out sender
        Serial.print("\t\t");

        for(int i = 0; i<len; i++)  // Print out the data bytes
        {
            Serial.print(buf[i], HEX);
            Serial.print("\t");
        }
        Serial.println();
    }
}
