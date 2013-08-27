


int CurrentStep;
int EndStep; 
int Speed;
int Delay;
int LastDelay;
int Direction;
boolean Switch1;
boolean Switch2;

void Step()
 {
  //Set the direction pin
  if (Direction==3)
  {
    digitalWrite(6,LOW);
  }
  else
  {
    digitalWrite(6,HIGH);
  };
  digitalWrite(7,HIGH);
  delay(Delay/4);
  digitalWrite(7,LOW);
 };

void setup() 
 {
  pinMode(13,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
  pinMode(7,OUTPUT);//Step
  pinMode(6,OUTPUT);//Direction
  pinMode(5,OUTPUT);//Ready
  Speed=30;//Rotations per minute
  CurrentStep=0;//Current Step
  Delay=60L * 1000L / 400 / Speed;//delay between steps in milliseconds
  EndStep=0;//Goal step
  Serial.begin(9600);
 };

void loop() 
 {
  Switch1=digitalRead(13);
  if (Switch1==false)
  {
   EndStep=100;
  }
  else
  {
   EndStep=0;
  };
  if (millis()-LastDelay >= Delay)
  {
   LastDelay=millis();
   if (CurrentStep!=EndStep)
   {
    digitalWrite(5,LOW);
    if (CurrentStep>EndStep)
    {
     Direction=3;
    }
    else
    {
     Direction=1;
    };
    CurrentStep=CurrentStep + 2 - Direction;
    Step();
   }
   else
   {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
   };
  };
  Serial.println(CurrentStep);
 };
