#include <stdlib.h>
#include <stdio.h>
#include "lex.h"

static int car_blanco(int ch) {
  switch(ch) {
    case ' ':
    case '\t':
    case '\n':
      return 1;
    default:
      return 0;
  }
}

TipoToken token;

void obtener_siguiente_token(void) {
  int ch;
  do{
      /* Lectura desde teclado */
      ch = getchar();
      if( ch < 0 ){
        token.clase = EoF;
        token.repr = '#';
        return;
      }
  }while(car_blanco(ch));

  if('0' <= ch && ch <= '9') {
    token.clase = DIGITO;
  }else{
    token.clase = ch;
  }

  token.repr = ch;
}
