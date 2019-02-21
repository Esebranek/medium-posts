// CAN Write
#include <SPI.h>
#include <mcp_can.h>
#include <mcp_can_dfs.h>

const int SPI_CS_PIN = 10;  // CS is connected to digital 10 on arduino

long unsigned int senderID = 0x00000001;  // Update this for each device

MCP_CAN CAN(SPI_CS_PIN);

void setup() {
  Serial.begin(115200);

  int attempt = 1;
  while (CAN_OK != CAN.begin(CAN_250KBPS)) {
    Serial.println("Failed to initialize.");
    Serial.print("Retrying. Attempt: ");
    Serial.print(attempt);
    Serial.println();
  }
  Serial.print("CAN initialized");
}


void loop() {
  Serial.println("Sending data over CAN");

  unsigned char msgBuf[8] = {random(0,255), random(0,255), random(0,255), random(0,255), random(0,255), random(0,255), random(0,255), random(0,255)};

  CAN.sendMsgBuf(senderID, 1, 8, msgBuf);
  delay(random(100, 1000);
  
}
