//Declaring and initializing some variables
int sensorValue1 = 0;
int sensorValue2 = 0;
int count = 0;

//constant variable(buzzer)- pin (9)
const int buzz = 9; 

//setup Function for declaring the pinmode
void setup()
{
  // Set SensorValue - pin A0 as an input
  pinMode(A0, INPUT);
  // Set LED(Yellow) - pin 6 as an output
  pinMode(6, OUTPUT);
  // Set SensorValue1 - pin A1 as an input
  pinMode(A1, INPUT);
  // Set LED(White) - pin 11 as an output
  pinMode(11, OUTPUT);
  // Set buzzer - pin 9 as an output
  pinMode(buzz, OUTPUT); 
  Serial.begin(9600);
}

void loop()
{
  // read the value from the sensor
  sensorValue1 = analogRead(A0);
  sensorValue2 = analogRead(A1);
  
  // print the sensor reading so you know its range
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue1);
  Serial.print("Sensor Value1: ");
  Serial.println(sensorValue2);
  Serial.print("Counter: ");
  Serial.println(count);
 
  // map the sensor reading to a range for the LED
  analogWrite(11, map(sensorValue1, 0, 1023, 0, 255));
  delay(1000); // Wait for 100 millisecond(s)
  analogWrite(6, map(sensorValue2, 0, 1023, 0, 255));
  delay(1000);


  if(sensorValue1 > 0 && sensorValue1 <= 20)
  {
    count++;
  }
  if(sensorValue2 >0 && sensorValue2 <=80)
  {
    count--;
  }
  
  delay(1000);

//check if the counter is greater than 5 or not
  if(count>5)
  {
   Serial.println("Alarm is on");
   Serial.println("The room is full");
   for( int i = 0; i<6;i++)
   {
    // Send 1KHz sound signal for 1 sec
    tone(buzz, 1000); 
    delay(1000);

    //Stop the sound for 1 sec
    noTone(buzz);     
    delay(1000);        
   }
    exit(1);
           
  }
  else
  {
    // Stop the sound
    noTone(buzz);     
    
  }
  if(count<=0)
  {
    Serial.print("The room is empty \n");
    count = 0;
  }  
}
