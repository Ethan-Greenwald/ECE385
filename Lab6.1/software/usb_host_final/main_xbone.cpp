#include "include/hidboot.h"
#include "include/usbhub.h"

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include "include/SPI.h"
#include "include/XBOXONE.h"
#include "include/xboxenums.h"
#include "include/controllerEnums.h"

void xbox_loop();
void xbox_setup();
void print_hex(int v, int num_places);

/* USB Host Shield 2.0 board quality control routine */
/* To see the output set your terminal speed to 115200 */
/* for GPIO test to pass you need to connect GPIN0 to GPOUT7, GPIN1 to GPOUT6, etc. */
/* otherwise press any key after getting GPIO error to complete the test */
/**/

/* variables */
uint8_t rcode;
uint8_t usbstate;
uint8_t laststate;
//uint8_t buf[sizeof(USB_DEVICE_DESCRIPTOR)];
USB_DEVICE_DESCRIPTOR buf;

/* objects */
USB Usb;
XBOXONE Xbox(&Usb);
//USBHub hub(&Usb);



/*
 Example sketch for the Xbox ONE USB library - by guruthree, based on work by
 Kristian Lauszus.
 */

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void xbox_setup() {
	if (Usb.Init() == -1)
		printf ("Error\n\r");
	printf ("USB Started\n\r");
}


void xbox_loop() {
  Usb.Task();

  if (Xbox.XboxOneConnected) {
	Xbox.setRumbleOff();
    if (Xbox.getAnalogHat(LeftHatX) > 7500 || Xbox.getAnalogHat(LeftHatX) < -7500 || Xbox.getAnalogHat(LeftHatY) > 7500 || Xbox.getAnalogHat(LeftHatY) < -7500 || Xbox.getAnalogHat(RightHatX) > 7500 || Xbox.getAnalogHat(RightHatX) < -7500 || Xbox.getAnalogHat(RightHatY) > 7500 || Xbox.getAnalogHat(RightHatY) < -7500) {
      if (Xbox.getAnalogHat(LeftHatX) > 7500 || Xbox.getAnalogHat(LeftHatX) < -7500) {
        printf("LeftHatX: ");
        printf("%d   ",Xbox.getAnalogHat(LeftHatX));
      }
      if (Xbox.getAnalogHat(LeftHatY) > 7500 || Xbox.getAnalogHat(LeftHatY) < -7500) {
          printf("LeftHatY: ");
          printf("%d   ",Xbox.getAnalogHat(LeftHatY));
      }
      if (Xbox.getAnalogHat(RightHatX) > 7500 || Xbox.getAnalogHat(RightHatX) < -7500) {
          printf("RightHatX: ");
          printf("%d   ",Xbox.getAnalogHat(RightHatX));
      }
      if (Xbox.getAnalogHat(RightHatY) > 7500 || Xbox.getAnalogHat(RightHatY) < -7500) {
          printf("RightHatY: ");
          printf("%d   ",Xbox.getAnalogHat(RightHatY));
      }
      printf("\n\r");
    }

    if (Xbox.getButtonPress(L2) > 0 || Xbox.getButtonPress(R2) > 0) {
      if (Xbox.getButtonPress(L2) > 0) {
        printf("L2: ");
        printf("%d   ",Xbox.getButtonPress(L2));
        }
      if (Xbox.getButtonPress(R2) > 0) {
         printf("R2: ");
         printf("%d   ",Xbox.getButtonPress(R2));
        }
      printf("\n\r");
    }

    // Set rumble effect
    static uint16_t oldL2Value, oldR2Value;
    if (Xbox.getButtonPress(L2) != oldL2Value || Xbox.getButtonPress(R2) != oldR2Value) {
      oldL2Value = Xbox.getButtonPress(L2);
      oldR2Value = Xbox.getButtonPress(R2);
      uint8_t leftRumble = map(oldL2Value, 0, 1023, 0, 255); // Map the trigger values into a byte
      uint8_t rightRumble = map(oldR2Value, 0, 1023, 0, 255);
     if (leftRumble > 0 || rightRumble > 0)
        Xbox.setRumbleOn(leftRumble, rightRumble, leftRumble, rightRumble);
     else
        Xbox.setRumbleOff();
    }

    if (Xbox.getButtonClick(UP))
      printf("Up\n\r");
    if (Xbox.getButtonClick(DOWN))
      printf("Down\n\r");
    if (Xbox.getButtonClick(LEFT))
      printf("Left\n\r");
    if (Xbox.getButtonClick(RIGHT))
      printf("Right\n\r");

    if (Xbox.getButtonClick(START))
      printf("Start\n\r");
    if (Xbox.getButtonClick(BACK))
      printf("Back\n\r");
    if (Xbox.getButtonClick(XBOX))
      printf("Xbox\n\r");
    if (Xbox.getButtonClick(SYNC))
      printf("Sync\n\r");

    if (Xbox.getButtonClick(L1))
      printf("L1\n\r");
    if (Xbox.getButtonClick(R1))
      printf("R1\n\r");
    if (Xbox.getButtonClick(L2))
      printf("L2\n\r");
    if (Xbox.getButtonClick(R2))
      printf("R2\n\r");
    if (Xbox.getButtonClick(L3))
      printf("L3\n\r");
    if (Xbox.getButtonClick(R3))
      printf("R3\n\r");


    if (Xbox.getButtonClick(A))
      printf("A\n\r");
    if (Xbox.getButtonClick(B))
      printf("B\n\r");
    if (Xbox.getButtonClick(X))
      printf("X\n\r");
    if (Xbox.getButtonClick(Y))
      printf("Y\n\r");
  }
  delay(1);
}

int main() {
        xbox_setup();
        while (1) {
        	xbox_loop();
        }
}


/* prints hex numbers with leading zeroes */
void print_hex(int v, int num_places) {
        int mask = 0, n, num_nibbles, digit;

        for(n = 1; n <= num_places; n++) {
                mask = (mask << 1) | 0x0001;
        }
        v = v & mask; // truncate v to specified number of places

        num_nibbles = num_places / 4;
        if((num_places % 4) != 0) {
                ++num_nibbles;
        }
        do {
                digit = ((v >> (num_nibbles - 1) * 4)) & 0x0f;
                printf("%x\n", digit);
        } while(--num_nibbles);
}


