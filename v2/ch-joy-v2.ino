
//
//  This variant is for the 8-wire version of the CH Combat Stick
//

#include <Bounce.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

bool key_val = false;
char kchar = 'a';
int key = 0;

//Keypad 0 is Trigger (yellow), B3 (white), B5 (pink), B4 (purple/blk)
char b_circuit_0[ROWS][COLS] = {
                                  {'R', 'r', '2', '3'},
                                  {'D', 'd', 'a', '1'},
                                  {'L', 'l', 'b', '5'},
                                  {'U', 'u', '4', 'T'}
                                  };
//byte b_row_pins_0[ROWS] = {0, 1, 2, 3};  //grey, purple, yellow, black
//byte b_col_pins_0[COLS] = {4, 5, 6, 7};  //orange, white, green, red
byte b_col_pins_0[ROWS] = {0, 1, 2, 3};  //grey, purple, yellow, black
byte b_row_pins_0[COLS] = {4, 5, 6, 7};  //orange, white, green, red
Keypad joy_keypad_0 = Keypad(makeKeymap(b_circuit_0), b_row_pins_0, b_col_pins_0, ROWS, COLS);

String msg;

void setup() {
  Serial.begin(9600); // USB is always 12 Mbit/sec
  Serial.println("setup...");
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

              kchar = joy_keypad_0.key[i].kchar;
              //Serial.print("Code: ");
              //Serial.print(kchar);
              //Serial.print(" ");
              //Serial.println(joy_keypad_0.key[i].kstate);
              switch (kchar){
                case 'T': Joystick.button(1, key_val); break;
                case '4': Joystick.button(2, key_val); break;
                case '3': Joystick.button(3, key_val); break;
                case '1': Joystick.button(4, key_val); break;
                case '2': Joystick.button(5, key_val); break;
                case '5': Joystick.button(6, key_val); break;
                case 'R': Joystick.button(7, key_val); break;
                case 'D': Joystick.button(8, key_val); break;
                case 'L': Joystick.button(9, key_val); break;
                case 'U': Joystick.button(10, key_val); break;
                case 'r': Joystick.button(11, key_val); break;
                case 'd': Joystick.button(12, key_val); break;
                case 'l': Joystick.button(13, key_val); break;
                case 'u': Joystick.button(14, key_val); break;
                
              }
            }
        }
    }
}

