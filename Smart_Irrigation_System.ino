//Smart Irrigation System for a small indoor garden
int sensor = A0; // Defining variable
int output ;
int output1 ;
int threshold=50;
int PIN=8;
void setup() {
  Serial.begin(9600); // Sets data rate transmission speed
  pinMode(sensor,INPUT);
  pinMode(PIN,OUTPUT);
  Serial.println("Reading From the Sensor ...");// Prints the given line on screen
  delay(2000);
  }
void loop() {
  output= analogRead(sensor);// Receives data from A0 Pin as Analog
  output1 = map(output,1017,310,0,100); // Maps the range of values 1017-310 onto range 0-100%
  Serial.print("Moisture sensor output : ");
  
  Serial.print(output1);
  Serial.println("%");
  if( output1>threshold) { digitalWrite(PIN,HIGH);Serial.println("The pump is OFF");} 
  else { digitalWrite(PIN,LOW);Serial.println("The pump is ON");}// Relay is active Low
  delay(1000);
  }
