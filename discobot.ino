#include <Button.h>

const int ball_pin = 3;
const int lights_pin = 2;

const int gp1_pin = 4;
const int gp2_pin = 5;
const int gp3_pin = 6;
const int gp4_pin = 7;
const int gp5_pin = 8;
const int gp6_pin = 9;
const int gp7_pin = 10;
const int gp8_pin = 14;
const int gp9_pin = 15;
const int gp10_pin = 16;

Button button1;
Button button2;
Button button3;
Button button4;
Button button5;
Button button6;
Button button7;
Button button8;
Button button9;
Button button10;

void setup() {

  pinMode(ball_pin, OUTPUT);
  pinMode(lights_pin, OUTPUT);
  
  // input pints with internal pull-ups
  pinMode(gp1_pin, INPUT_PULLUP);
  pinMode(gp2_pin, INPUT_PULLUP);
  pinMode(gp3_pin, INPUT_PULLUP);
  pinMode(gp4_pin, INPUT_PULLUP);
  pinMode(gp5_pin, INPUT_PULLUP);
  pinMode(gp6_pin, INPUT_PULLUP);
  pinMode(gp7_pin, INPUT_PULLUP);
  pinMode(gp8_pin, INPUT_PULLUP);
  pinMode(gp9_pin, INPUT_PULLUP);
  pinMode(gp10_pin, INPUT_PULLUP);
  
  // buttons
  button1.initialize(gp1_pin);
  button2.initialize(gp2_pin);
  button3.initialize(gp3_pin);
  button4.initialize(gp4_pin);
  button5.initialize(gp5_pin);
  button6.initialize(gp6_pin);
  button7.initialize(gp7_pin);
  button8.initialize(gp8_pin);
  button9.initialize(gp9_pin);
  button10.initialize(gp10_pin);
  
  // set up serial and wait for it to become ready
  Serial.begin(115200);
  while (!Serial);
  Serial.println("DISCOBOT READY");

}

void loop() {
  byte cmd;
  byte val;
  char buf[17];

  if (Serial.available()) {
    cmd = Serial.read();
    switch (cmd) {
      case 0x01:
        // Lights
        val = Serial.read();
        if (val==0) {
          digitalWrite(lights_pin, LOW);
        } else {
          digitalWrite(lights_pin, HIGH);
        }
        break;
      case 0x02:
        // Disco Ball
        val = Serial.read();
        analogWrite(ball_pin, val);
        break;
      case 0x03:
        // Report Input Status
        button1.update();
        button2.update();
        button3.update();
        button4.update();
        button5.update();
        button6.update();
        button7.update();
        button8.update();
        button9.update();
        button10.update();
        if (button1.isDown())
          Serial.println("BUTTON1_ON");
        else
          Serial.println("BUTTON1_OFF");
        if (button2.isDown())
          Serial.println("BUTTON2_ON");
        else
          Serial.println("BUTTON2_OFF");
        if (button3.isDown())
          Serial.println("BUTTON3_ON");
        else
          Serial.println("BUTTON3_OFF");
        if (button4.isDown())
          Serial.println("BUTTON4_ON");
        else
          Serial.println("BUTTON4_OFF");
        if (button5.isDown())
          Serial.println("BUTTON5_ON");
        else
          Serial.println("BUTTON5_OFF");
        if (button6.isDown())
          Serial.println("BUTTON6_ON");
        else
          Serial.println("BUTTON6_OFF");
        if (button7.isDown())
          Serial.println("BUTTON7_ON");
        else
          Serial.println("BUTTON7_OFF");
        if (button8.isDown())
          Serial.println("BUTTON8_ON");
        else
          Serial.println("BUTTON8_OFF");
        if (button9.isDown())
          Serial.println("BUTTON9_ON");
        else
          Serial.println("BUTTON9_OFF");
        if (button10.isDown())
          Serial.println("BUTTON10_ON");
        else
          Serial.println("BUTTON10_OFF");
        break;
    }
  }

  button1.update();
  if (button1.isPressed()) {
    Serial.println("BUTTON1_ON");
  } else if (button1.isReleased()) {
    Serial.println("BUTTON1_OFF");
  }

  button2.update();
  if (button2.isPressed()) {
    Serial.println("BUTTON2_ON");
  } else if (button2.isReleased()) {
    Serial.println("BUTTON2_OFF");
  }

  button3.update();
  if (button3.isPressed()) {
    Serial.println("BUTTON3_ON");
  } else if (button3.isReleased()) {
    Serial.println("BUTTON3_OFF");
  }

  button4.update();
  if (button4.isPressed()) {
    Serial.println("BUTTON4_ON");
  } else if (button4.isReleased()) {
    Serial.println("BUTTON4_OFF");
  }

  button5.update();
  if (button5.isPressed()) {
    Serial.println("BUTTON5_ON");
  } else if (button5.isReleased()) {
    Serial.println("BUTTON5_OFF");
  }

  button6.update();
  if (button6.isPressed()) {
    Serial.println("BUTTON6_ON");
  } else if (button6.isReleased()) {
    Serial.println("BUTTON6_OFF");
  }
  
  button7.update();
  if (button7.isPressed()) {
    Serial.println("BUTTON7_ON");
  } else if (button7.isReleased()) {
    Serial.println("BUTTON7_OFF");
  }
  
  button8.update();
  if (button8.isPressed()) {
    Serial.println("BUTTON8_ON");
  } else if (button8.isReleased()) {
    Serial.println("BUTTON8_OFF");
  }
  
  button9.update();
  if (button9.isPressed()) {
    Serial.println("BUTTON9_ON");
  } else if (button9.isReleased()) {
    Serial.println("BUTTON9_OFF");
  }
  
  button10.update();
  if (button10.isPressed()) {
    Serial.println("BUTTON10_ON");
  } else if (button10.isReleased()) {
    Serial.println("BUTTON10_OFF");
  }
  
}

