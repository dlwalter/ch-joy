
//
//  This variant is for the 8-wire version of the CH Combat Stick
//

#include <Bounce.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

bool key_val = false;
char kcode = '';
int key = 0;

//Keypad 0 is Trigger (yellow), B3 (white), B5 (pink), B4 (purple/blk)
char b_circuit_0[ROWS0][COLS0] = {
                                  {'R', 'D', 'L', 'U'},  //Coolie Hat
                                  {'r', 'd', 'l', 'u'},  //Castle Hat
                                  {'2', 'a', 'b', '4'},  //B2 and B4
                                  {'3', '1', '5', 'T'},  //B3, B1, B5, T
                                  };
byte b_row_pins_0[ROWS0] = {0, 1, 2, 3};  //grey, purple, yellow, black
byte b_col_pins_0[COLS0] = {4, 5, 6, 7};  //orange, white, green, red
Keypad joy_keypad_0 = Keypad(makeKeymap(b_circuit_0), b_row_pins_0, b_col_pins_0, ROWS0, COLS0);

String msg;

void setup() {
//  Serial.begin(9600); // USB is always 12 Mbit/sec
}

void loop() {
  // Button 1: Trigger
  // Button 2: Side Thumb
  // Button 3: Pinky
  // Button 4: Side Index
  // Button 5: Thumb Low
  // Button 6: Thumb High
  // Button 7: Coolie R
  // Button 8: Coolie D
  // Button 9: Coolie L
  // Button 10: Coolie U
  // Button 11: Hat R
  // Button 12: Hat D
  // Button 13: Hat L
  // Button 14: Hat U

  if (joy_keypad_0.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( joy_keypad_0.key[i].stateChanged )   // Only find keys that have changed state.
            {
              // Set button to true if kstate is pressed or holding
              key_val = joy_keypad_0.key[i].kstate == PRESSED || joy_keypad_0.key[i].kstate == HOLD;
              kcode = joy_keypad_0.key[i].kcode
              switch (kcode){
                case 'T': Joystick.button(1, key_val);
                case '4': Joystick.button(2, key_val);
                case '3': Joystick.button(3, key_val);
                case '1': Joystick.button(4, key_val);
                case '2': Joystick.button(5, key_val);
                case '5': Joystick.button(6, key_val);
                case 'R': Joystick.button(7, key_val);
                case 'D': Joystick.button(8, key_val);
                case 'L': Joystick.button(9, key_val);
                case 'U': Joystick.button(10, key_val);
                case 'r': Joystick.button(11, key_val);
                case 'd': Joystick.button(12, key_val);
                case 'l': Joystick.button(13, key_val);
                case 'u': Joystick.button(14, key_val);
              }
            }
        }
    }
}

