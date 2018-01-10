#ifndef _ARBOL_
#define _ARBOL_
  typedef int Operador;

  typedef struct _expresion {
    char tipo;
    int valor;
    struct _expresion *izquierda, *derecha;
    Operador oper;
  } Expresion;

  typedef Expresion nodo_AST;

  extern int Analizar_programa(nodo_AST **);
#endif
