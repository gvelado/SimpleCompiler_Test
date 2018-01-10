#include <stdio.h>

#define EoF 256
#define DIGITO 257

typedef struct {
  int clase;
  char repr;
} TipoToken;

extern TipoToken token;
extern void obtener_siguiente_token(void);
