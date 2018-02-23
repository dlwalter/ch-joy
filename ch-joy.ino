/* Buttons to USB Joystick Example

   You must select Joystick from the "Tools > USB Type" menu

   This example code is in the public domain.
*/
#include <Bounce.h>
#include <Keypad.h>

const byte ROWS0 = 1;
const byte COLS0 = 4;
//Keypad 0 is Trigger (yellow), B3 (white), B5 (pink), B4 (purple/blk)
char b_circuit_0[ROWS0][COLS0] = {{'T', '3', '5', '4'}};
byte b_row_pins_0[ROWS0] = {0};
byte b_col_pins_0[COLS0] = {3, 4, 5, 10};
Keypad joy_keypad_0 = Keypad(makeKeymap(b_circuit_0), b_row_pins_0, b_col_pins_0, ROWS0, COLS0);

//Keypad 1 is B1, Hat, Coolie, B2
const byte ROWS1 = 1;
const byte COLS1 = 10;
char b_circuit_1[ROWS1][COLS1] = {{'1', 'R', 'D', 'L', 'U', 'r', 'd', 'l', 'u', '2'}};
byte b_row_pins_1[ROWS1] = {1};
byte b_col_pins_1[COLS1] = {2, 6, 7, 8, 9, 11, 12, 14, 15, 13};
Keypad joy_keypad_1 = Keypad(makeKeymap(b_circuit_1), b_row_pins_1, b_col_pins_1, ROWS1, COLS1);

String msg;

void setup() {
  Serial.begin(9600); // USB is always 12 Mbit/sec
}

void loop() {
  if (joy_keypad_0.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( joy_keypad_0.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (joy_keypad_0.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    msg = " PRESSED.";
                break;
                    case HOLD:
                    msg = " HOLD.";
                break;
                    case RELEASED:
                    msg = " RELEASED.";
                break;
                    case IDLE:
                    msg = " IDLE.";
                }
                Serial.print("Key ");
                Serial.print(joy_keypad_0.key[i].kchar);
                Serial.println(msg);
            }
        }
    }

  if (joy_keypad_1.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( joy_keypad_1.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (joy_keypad_1.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    msg = " PRESSED.";
                break;
                    case HOLD:
                    msg = " HOLD.";
                break;
                    case RELEASED:
                    msg = " RELEASED.";
                break;
                    case IDLE:
                    msg = " IDLE.";
                }
                Serial.print("Key ");
                Serial.print(joy_keypad_1.key[i].kchar);
                Serial.println(msg);
            }
        }
    }
 
}

