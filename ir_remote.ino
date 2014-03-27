/*
 * IRrecv_with_LED - simple demo using an IR receiver part and an IR remote
 *
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * (original)
 *
 * modified by Rolf W. for Workshop Weekend Arduino - Feb 2014
 *
 * most IR remote controls should work.  I used a JVC remote from a CD player.
 *
 * most IR receiver modules should work with the IRremote library.
 *
 * this sketch was tested with a Vishay TSOP4838 IR receiver module.
 * this part has 3 pins.
 * with the part plugged into a breadboard and the "bubble" facing you,
 * the pins are (from left to right) OUT, GND, +5V.
 * Connect +5V and GND as youwould expect.  the "OUT" pin is connected to Arduino pin 11.
 *
 * An LED is connected to pin 13 (through a resistor), and to GND.
 *
 *  note: sketch modified to detect a specific button on an IR remote,
 *    and toggle and LED on each press.
 *  
 */
 
#include <IRremote.h>

int RECV_PIN = 11;
int LED_PIN = 13;

IRrecv irrecv(RECV_PIN);

decode_results results;

byte toggle_led = 0;

void setup()
{
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  
  if (irrecv.decode(&results)) {
    //Serial.print(results.value, HEX);  // uncomment this line to see the actual value received

    if (results.value == 0xCD02) {    // this code indicates POWER button was pressed
      toggle_led = !toggle_led;
      
      if (toggle_led) {
        digitalWrite(LED_PIN, HIGH);
      } else {
        digitalWrite(LED_PIN, LOW);
      }

    }
    irrecv.resume(); // Receive the next value
  }
}


