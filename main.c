#include "parser.h"
#include "backend.h"
#include "error.h"

int main(int argc , char **argv) {
  nodo_AST *codigoi;
  if( !Analizar_programa(&codigoi) ) {
    Error("No hay expresión de nivel superior");
  }
  Procesar(codigoi);
}
