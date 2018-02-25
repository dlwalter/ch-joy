
#include <Bounce.h>
#include <Keypad.h>

const byte ROWS0 = 1;
const byte COLS0 = 4;
const byte OFFSET = 4;

bool key_val = false;
int key = 0;

//Keypad 0 is Trigger (yellow), B3 (white), B5 (pink), B4 (purple/blk)
char b_circuit_0[ROWS0][COLS0] = {{'T', '3', '5', '4'}};
byte b_row_pins_0[ROWS0] = {0};
byte b_col_pins_0[COLS0] = {3, 4, 5, 10};
Keypad joy_keypad_0 = Keypad(makeKeymap(b_circuit_0), b_row_pins_0, b_col_pins_0, ROWS0, COLS0);

//Keypad 1 is B1, Hat, Coolie, B2
const byte ROWS1 = 1;
const byte COLS1 = 10;
char b_circuit_1[ROWS1][COLS1] = {{'1', '2', 'R', 'D', 'L', 'U', 'r', 'd', 'l', 'u'}};
byte b_row_pins_1[ROWS1] = {1};
byte b_col_pins_1[COLS1] = {2, 13, 6, 7, 8, 9, 11, 12, 14, 15};
Keypad joy_keypad_1 = Keypad(makeKeymap(b_circuit_1), b_row_pins_1, b_col_pins_1, ROWS1, COLS1);

String msg;

void setup() {
//  Serial.begin(9600); // USB is always 12 Mbit/sec
}

void loop() {
  // Button 0: Trigger
  // Button 1: Side Thumb
  // Button 2: Pinky
  // Button 3: Side Index
  // Button 4: Thumb Low
  // Button 5: Thumb High
  // Button 6: Coolie R
  // Button 7: Coolie D
  // Button 8: Coolie L
  // Button 9: Coolie U
  // Button 10: Hat R
  // Button 11: Hat D
  // Button 12: Hat L
  // Button 13: Hat U

  if (joy_keypad_0.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( joy_keypad_0.key[i].stateChanged )   // Only find keys that have changed state.
            {
              // Set button to true if kstate is pressed or holding
              key_val = joy_keypad_0.key[i].kstate == PRESSED || joy_keypad_0.key[i].kstate == HOLD;
              // increment key by 1 do to Joystick's 1 indexing
              key = joy_keypad_0.key[i].kcode+1;
              Joystick.button(key, key_val);
            }
        }
    }
    
  //Repeat for other button circuit
  if (joy_keypad_1.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( joy_keypad_1.key[i].stateChanged )   // Only find keys that have changed state.
            {
              key_val = joy_keypad_1.key[i].kstate == PRESSED || joy_keypad_1.key[i].kstate == HOLD;
              key = joy_keypad_1.key[i].kcode+1+OFFSET;
              Joystick.button(key, key_val);
            }

        }
    }
}

