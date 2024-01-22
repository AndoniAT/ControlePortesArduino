#include <Servo.h>
#define SWITCH_PIN 3
Servo myservo;  // Créez un objet servo pour contrôler le HS-311

int pos = 0;    // Variable pour stocker la position du servo
int servoPin = 9;   // La broche où votre servo est connecté
volatile bool mIsClicked = false;


bool a = false;
// Cette fonction est exécutée une fois au démarrage de l'Arduino
void setup() {
  Serial.begin(9600);
   attachInterrupt(digitalPinToInterrupt( SWITCH_PIN ), click, RISING );
 pinMode( SWITCH_PIN, INPUT );
  myservo.attach(servoPin);  // Attachez le servo à la bonne broche sur l'Arduino
 // pinMode(buttonPin, INPUT_PULLUP);  // Configurez la broche du bouton comme entrée avec résistance pull-up
}

// Cette fonction boucle indéfiniment après le démarrage
void loop() {


  if( mIsClicked ) {
   Serial.println("Click");
   mIsClicked = false;
    //myservo.write(160);
    //delay( 2500 );
    //myservo.write(90);
    myservo.write(160); 
  }
  else {
    myservo.write(90);  // Dites au servo d'aller à la position 'pos'

  }
  delay(2500);
}

void click() {
    mIsClicked = true;
}