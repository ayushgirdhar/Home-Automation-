  #include <Servo.h>
  #include <LiquidCrystal.h>
  LiquidCrystal lcd(8, 12, 4, 5, 6, 7);
const int ledPin = 9;// the pin that the LED is attached to ORANGE
const int fanPin = 11;
const int water = A1;
const int level =13;
int l;
int LDR = A0; // select the input pin for ldr
int LDRValue = 0;
int val,waterlevel;
  byte serialA ;
Servo myservo; //Servo name
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  myservo.attach(10);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  // make the pushbutton's pin an input:
  pinMode(ledPin,OUTPUT);
  pinMode(fanPin,OUTPUT);
  pinMode(water,OUTPUT);
  pinMode(level,INPUT);
}

// the loop routine runs over and over again forever:
void loop()  
{
  delay(100);
  if (Serial.available()) 
  {
    serialA = Serial.read();  
    if((serialA>='a' && serialA <='z') || serialA==' ' || (serialA>='A' && serialA <='Z') || (serialA>='0' && serialA <='9'))
    {
      lcd.write(serialA);
    }
    else if(serialA=='/')
    {
      lcd.clear();
    }
    else if(serialA=='&')
    {
      digitalWrite(ledPin, HIGH);         //Sets LED on
    }
    else if(serialA=='*')
    {
      digitalWrite(ledPin, LOW); //Sets LED off
    }
    else if(serialA=='$')           //
    {
      digitalWrite(fanPin, LOW);         //Sets fan of
    }
    else if(serialA=='!')           //Fan speed 1
    {
      analogWrite(fanPin,82);           
    }
    else if(serialA=='@')           //Fan speed 2
    {
      analogWrite(fanPin, 168);           
    }
    else if(serialA=='#')           //Fan speed 3
    {
      digitalWrite(fanPin, HIGH);      
    }
    else if(serialA=='(')
    {
      myservo.write(110);                  // sets the servo position according to the scaled value
    }
    else if(serialA==')')
    {
      myservo.write(20);                  // sets the servo position according to the scaled value
    }
    else if(serialA=='^')
    {
      waterlevel=digitalRead(level);
      Serial.print(waterlevel);
      }
  }
    LDRValue = analogRead(LDR); // read the value from the sensor
  //Serial.println(LDRValue);//prints the values coming from the sensor on the screen
    val = map(LDRValue, 1020, 50, 0, 255);
    if(LDRValue<50)
          analogWrite(ledPin,0);
    else
          analogWrite(ledPin,val);
}

}
