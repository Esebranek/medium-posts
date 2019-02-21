// DIY CAN Read
#include <SPI.h>
#include <mcp_can.h>
#include <mcp_can_dfs.h>


const int SPI_CS_PIN = 10;  // CS is connected to digital 10 on arduino

MCP_CAN CAN(SPI_CS_PIN);  // MCP CAN with the Chip Select Pin

unsigned long timestamp;  // time message is received
long unsigned int senderId;  // sender node id
unsigned char len = 0;  // length of the message
unsigned char buf[8];  // buffer for 8byte message

void setup() {
 Serial.begin(115200);  // Begin serial with highest baud

 while (CAN_OK != CAN.begin(CAN_250KBPS)) {  // Try to init CAN
  Serial.println("Failed to initialize. Retrying...";
  delay(500);  // Wait half a second if CAN initialization fails
 }

 Serial.println("CAN node initialized");
 Serial.println("Receive time\tSenderID\tMessage (Hex)")  // Table header
}

void loop() {
  if (CAN_MSGAVAIL == CAN.checkReceive()) { . // If there is a message available
    timestamp = millis();
    CAN.readMsgBuf(&len, buf);
    senderId = CAN.getCanId();

    Serial.print(timestamp);
    Serial.print(/t);
    Serial.print("0x");
    Serial.print(senderId, HEX);
    Serial.print("\t");

    for (int i = 0; i < len; i++) {
      if (buf[i] > 15) {
        Serial.print(buf[i], HEX);
      } else {
        Serial.print("0");
        Serial.print(buf[i], HEX);
      }
      Serial.print(" ");
    }
    Serial.println();
  }
}
