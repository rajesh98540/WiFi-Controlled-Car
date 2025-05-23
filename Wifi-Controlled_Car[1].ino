

#define BLYNK_TEMPLATE_ID "TMPL3ryPfjapV"
#define BLYNK_TEMPLATE_NAME "WiFi Controlled Car"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>



#define ENA D0
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENB D5


int x = 50;
int y = 50;
int Speed;


char auth[] = "IH3qRho-x8em09UpCj8bzIDFdqMEIBQB"; 
char ssid[] = "lalala"; 
char pass[] = "rajesh4321"; 


void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
 
    pinMode(ENB, OUTPUT);
    
  
    
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

BLYNK_WRITE(V0) {
  x = param[0].asInt();
}
BLYNK_WRITE(V1) {
  y = param[0].asInt();
}
BLYNK_WRITE(V2) {
  Speed = param.asInt();
}





void smartcar() {
  if (y > 70) {
    carForward();
   
    Serial.println("carForward");
  } else if (y < 30) {
    carBackward();
   
    Serial.println("carBackward");
  } else if (x < 30) {
    carLeft();
    
    Serial.println("carLeft");
  } else if (x > 70) {
    carRight();
    
    Serial.println("carRight");
  } else {
    carStop();
    
    Serial.println("carstop");
  }

}
void loop() {
  Blynk.run()
  smartcar();
}


void carForward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carBackward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carLeft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void carRight() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}


