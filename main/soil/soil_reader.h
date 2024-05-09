const int sensor_pin = A0; // Connect Soil moisture analog sensor pin to A0 of NodeMCU
const int AirValue = 650;  // you need to replace this value with Value_1
const int WaterValue = 310;
void initSoilReader()
{
}

int getSoilHumidity()
{
    delay(500); // Wait for 5 seconds
    int soilMoistureValue;
    soilMoistureValue = analogRead(sensor_pin);
    Serial.println(String(soilMoistureValue));
    int percent = map(soilMoistureValue, 0, 1023, 100, 0);
    Serial.print("Soil Moisture(in Percentage) = ");
    Serial.print(percent);
    Serial.println("%");
    delay(1000);
    return percent;
}