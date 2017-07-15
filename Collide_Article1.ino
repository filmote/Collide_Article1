#include <Arduboy2.h>
#include "Images.h"

Arduboy2 arduboy;  
Sprites sprites;

int16_t xA = -16, yA = 12, xB = 128, yB = 24; 
int16_t frame; 

void setup() {

  arduboy.begin();
  
}

void loop() {

  arduboy.clear();

  Serial.println("------------------------");
  Serial.print("A collides with circle : ");
  Serial.println(arduboy.collide( (Rect){xA, yA, 16, 16}, (Rect){24, 4, 16, 16} ));
  Serial.print("A collides with B : ");
  Serial.println(arduboy.collide( (Rect){xA, yA, 16, 16}, (Rect){xB, yB, 16, 16} ));
  Serial.print("A collides with dot : ");
  Serial.println(arduboy.collide( (Point){64, 20}, (Rect){xA, yA, 16, 16} ));
  Serial.print("B collides with square : ");
  Serial.println(arduboy.collide( (Rect){xB, yB, 16, 16}, (Rect){96, 32, 16, 16} ));
  Serial.print("B collides with dot : ");
  Serial.println(arduboy.collide( (Point){64, 32}, (Rect){xB, yB, 16, 16} ));

  arduboy.drawCircle(32, 12, 8, WHITE);
  arduboy.drawRect(96, 32, 16, 16, WHITE);
  arduboy.drawPixel(64, 20, WHITE);
  arduboy.drawPixel(64, 32, WHITE);

  sprites.drawOverwrite(xA, yA, squareA, frame);
  sprites.drawOverwrite(xB, yB, squareB, frame);

  xA++;  if (xA >= 128) { xA = 0; }
  xB--;  if (xB < -16)    { xB = 128; }
  
  arduboy.display();
  arduboy.delayShort(10);

  while (true) {

    if (arduboy.pressed(A_BUTTON)) { break; }
    arduboy.delayShort(20);  

  }

}

