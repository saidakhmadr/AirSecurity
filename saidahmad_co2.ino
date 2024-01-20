#include <DHT.h> // Автор  ADALFRUIT

#define dht_pin 5 //измените под себя. В моем случае я использую цифровой пин 5
DHT dht(dht_pin, DHT11); // Инициальзация датчика

void setup() {
  Serial.begin(57600);
  dht.begin() //Начинаем магию!
}

void loop() {
  delay(1000) 
  double temp = dht.readTemperature(); // Считывание температуры с пина 
  double hum = dht.readHumidity(); //Аналогично с температурой но это влажность

  if(isnan(temp) || isnan(hum)) {
    Serial.println("Ur dump!!");
    return;
  }
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C | ");
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println(" %");

}
