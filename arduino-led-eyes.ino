    /*
    LED Googles using a Adafruit Trinket Pro
    Copyright (c) 2016 - mgroseman - Mike Roseman
    Licensed under the MIT License

    This is to run a manually created LED light ring with 8 lights per eye.  
    The Left and Right eyes are linked, so each each lit LED is the same in both eyes.
    Button cycles through modes

    Blog describing this project will be forthcoming.  I'll add link here when written.
    
    */

    int led_int = 13; // pin 1 - AKA the built in red LED
    // Needed
    //  Array of seq
    //  Define degree vars and up/down/left/right
    int button = 8;
    int delay_spin = 40; 
    int delay_spin_dual = 70; 
    int mode = 1; //current mode
    int maxmode = 5; //# of modes
     
    // the setup routine runs once when you press reset:
    void setup() {
    // initialize the digital pins as output.
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(3, OUTPUT);  
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(button, INPUT);
    // setting input pins to high means turning on internal pull-up resistors
    digitalWrite(button, HIGH);
    // remember, the buttons are active-low, they read LOW when they are not pressed
 
    }


   void spin_dual() {
    digitalWrite(6, HIGH);
    digitalWrite(12, HIGH);
    delay(5);
    digitalWrite(9, LOW);
    digitalWrite(3, LOW);
    delay(delay_spin_dual);
    digitalWrite(5, HIGH);
    digitalWrite(11, HIGH);
    delay(5);
    digitalWrite(6, LOW);
    digitalWrite(12, LOW);
    delay(delay_spin_dual);
    digitalWrite(4, HIGH);
    digitalWrite(10, HIGH);
    delay(5);
    digitalWrite(5, LOW);
    digitalWrite(11, LOW);
    delay(delay_spin_dual);
    digitalWrite(3, HIGH);
    digitalWrite(9, HIGH);
    delay(5);
    digitalWrite(4, LOW);
    digitalWrite(10, LOW);
    delay(delay_spin_dual);
   }

   void spin() {
    digitalWrite(6, HIGH);
    delay(5);
    digitalWrite(9, LOW);
    delay(delay_spin);
    digitalWrite(5, HIGH);
    delay(5);
    digitalWrite(6, LOW);
    delay(delay_spin);
    digitalWrite(4, HIGH);
    delay(5);
    digitalWrite(5, LOW);
    delay(delay_spin);
    digitalWrite(3, HIGH);
    delay(5);
    digitalWrite(4, LOW);
    delay(delay_spin);
    digitalWrite(12, HIGH);
    delay(5);
    digitalWrite(3, LOW);
    delay(delay_spin);
    digitalWrite(11, HIGH);
    delay(5);
    digitalWrite(12, LOW);
    delay(delay_spin);
    digitalWrite(10, HIGH);
    delay(5);
    digitalWrite(11, LOW);
    delay(delay_spin);
    digitalWrite(9, HIGH);
    delay(5);
    digitalWrite(10, LOW);
    delay(delay_spin);
   }

   void allon() {
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(9, HIGH);
   }

   void alloff() {
          digitalWrite(6, LOW);
          digitalWrite(5, LOW);
          digitalWrite(4, LOW);
          digitalWrite(3, LOW);
          digitalWrite(12, LOW);
          digitalWrite(11, LOW);
          digitalWrite(10, LOW);
          digitalWrite(9, LOW);
   }

void pulse() {
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(9, HIGH);
        delay(1200);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
        digitalWrite(9, LOW);
        delay(1200);
}

void random1() {
  //This isn't really random and need to rewrite with a random() or similar function
        int delay_random1 = 120;
        digitalWrite(12, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(5, HIGH);
        delay(delay_random1);
        digitalWrite(4, HIGH);
        digitalWrite(6, LOW);
        delay(delay_random1);
        digitalWrite(12, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(11, HIGH);
        delay(delay_random1);
        digitalWrite(4, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(9, HIGH);
        delay(delay_random1);
        digitalWrite(11, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(9, LOW);
        delay(delay_random1);
   }


    // the loop routine runs over and over again forever:
    void loop() {
    if (digitalRead(button) == HIGH){  //If button unpressed
      if (mode == 1) {
        allon();
      }
      if (mode == 2) {
        spin();
      }
      if (mode == 3) {
        spin_dual();
      }
      if (mode == 4) {
        random1();
      }
      if (mode == 5)  {
        alloff();
      }
    }    
      
    if (digitalRead(button) == LOW) //Button press.  interate mode
     {
      digitalWrite(led_int, HIGH);
      delay(600);
      digitalWrite(led_int, LOW);
      mode = mode + 1;
      if (mode > maxmode) {  //cycle from beginning
        mode = 1;
      }
     } 
    }

