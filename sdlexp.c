//A program to experiment with the display functions.
#include "display.h"

typedef struct display display;

int main(int argc, char const *argv[]) {

  display *canvas = newDisplay("can", 64, 64);
  line(canvas, (int) 0,(int) 0,(int) 32, (int) 32);
  end(canvas);

  return 0;
}
