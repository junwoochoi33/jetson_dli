#include <SimpleDHT.h>
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(115200);
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  
  if (dht11.read(&temperature, &humidity, NULL) == SimpleDHTErrSuccess) {
    int temp = (int)temperature;
    int humid = (int)humidity;
    
    // 유효한 범위인지 확인
    if (temp >= 0 && temp <= 50 && humid >= 0 && humid <= 100) {
      Serial.print(temp);
      Serial.print(",");
      Serial.println(humid);
    }
  }
  
  delay(2000);  // 2초 대기
}
