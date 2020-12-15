//LEDs and button PINs
const int ledRed = 12;
const int ledYellow = 11;
const int ledGreen = 10;
const int button = 2;

void setup()
{
    pinMode(ledRed, OUTPUT);
    pinMode(ledYellow, OUTPUT);
    pinMode(ledGreen, OUTPUT);
    pinMode(button, INPUT);

	//using interruption
  	attachInterrupt(digitalPinToInterrupt(button), changeTrafficLightsCondition, RISING);
}

int trafficLightsCondition = 0;
int redLedCondition = LOW;
int yellowLedCondition = LOW;
int greenLedCondition = LOW;
int time = 0;

void changeTrafficLightsCondition()
{
  	trafficLightsCondition = !trafficLightsCondition;
}

void startTrafficLights()
{
  	digitalWrite(ledRed, redLedCondition);
    digitalWrite(ledYellow, yellowLedCondition);
    digitalWrite(ledGreen, greenLedCondition);
}

void stopTrafficLights()
{
  	digitalWrite(ledRed, LOW);
  	digitalWrite(ledYellow, LOW);
  	digitalWrite(ledGreen, LOW);
    redLedCondition = LOW;
 	yellowLedCondition = LOW;
    greenLedCondition = LOW;
}


void loop()
{
	if(trafficLightsCondition)
    {	
      	time += 50;
      	time %= 8000;
     	redLedCondition = (time <= 3000);
      	yellowLedCondition = (time > 3000 && time <= 5000);
      	greenLedCondition = (time > 5000 && time <= 8000);
      	startTrafficLights();
    } 
  	else 
    {
     	stopTrafficLights();
      	time = 0;
    }
  	delay(50);
}