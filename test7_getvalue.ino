void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello,Serial!");
}

void loop() {
  while (Serial.available())
  {
  String inData = "";
  inData = Serial.readString();
  // put your main code here, to run repeatedly:
  String soil = getValue(inData, ',', 0);
  String rain = getValue(inData, ',', 1);
  
  Serial.print(soil.toFloat());
  }
}




//分割字符串用
String getValue(String data, char separator, int index) {
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
