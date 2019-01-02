//Program used to interpret .sketch files and display.
#include "display.h"
#include "assert.h"
#include "stdlib.h"
#include "stdio.h"

//Define opcode  and PEN constants.
enum{ DX = 0, DY = 1, PEN = 3};
enum{ UP, DOWN};

//Define a State structure.
struct state{ int x, y, dx, pen; };
typedef struct state state;

//Create a new state.
state *newState(){
  state *s = malloc( sizeof( state));
  s->x = 0;
  s->y = 0;
  s->dx = 0;
  s->pen = UP;
  return s;
}

//Extract opcode from byte.
int opcode(int n){
  return (n >> 6);
}

//Extract operand from byte.
int operand(int n){
  int p = (n & 0x3F);
  if ( (p & 0x20) != 0) p = ( ~0U << 6) | p;
  return p;
}



//------------------------------------------------------------------------------
//Test and Main functions.

//Test opcode and operand extraction.
void opcode_tst(){
  int n = 0x03; // 0000 0011 = DX 3
  int m = 0x7d; // 0111 1101 = DY -3
  int o = 0xc0; // 1100 0000 = PEN
  int x = 0x20; // 0010 0000 = DX -32
  int y = 0x5F; // 0101 1111 = DY 31
  assert( opcode(n) == DX);
  assert( opcode(x) == DX);
  assert( opcode(m) == DY);
  assert( opcode(y) == DY);
  assert( opcode(o) == PEN);
  assert( operand(n) == 3);
  assert( operand(m) == -3);
  assert( operand(x) == -32);
  assert( operand(y) == 31);

}

//global test function.
void test(){
  opcode_tst();
  printf("All tests passed.\n");
}


int main(int argc, char const *argv[]) {
  test();
  return 0;
}
