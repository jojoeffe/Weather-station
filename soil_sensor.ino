//soil moisture sensor Fundiuno 
//https://www.fecegypt.com/uploads/dataSheet/1480854383_water%20and%20soil.pdf
//pin A0 instead of A5
//connected with 3.3V and 5V and didn't seem to fry it (some of the sensors are 3.3V)
//calibration would probably be required, although most of my plants prefer to get dry for a bit and then be watered rather than remain damp. 
//wouldn't need to check so often, probably twice a day, but this delay was fine for testing. 

int sensorPin = A0; 


void setup() {
Serial.begin(9600);
}

void loop()   {
if(analogRead(0) <300){
  Serial.println("Analog Value : ");
  Serial.println("i'm dry");
}

if(analogRead(0) >300 && analogRead(0) <500){
  Serial.println("Analog Value : ");
  Serial.println("i'm feeling fine");
}
if(analogRead(0) >500){
  Serial.println("Analog Value : ");
  Serial.println("i'm feeling soggy");
}

delay(3000); 
}
