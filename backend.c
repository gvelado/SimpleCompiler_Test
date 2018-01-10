#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "backend.h"

static void Gen_codigo_expresion(Expresion *expr) {
	switch(expr->tipo) {
    	case 'D':
      		printf("PUSH %d\n",expr->valor);
      		break;
    	case 'P':
	    	Gen_codigo_expresion(expr->izquierda);
	    	Gen_codigo_expresion(expr->derecha);
	    	switch (expr->oper) {
        		case '+':
          			printf("ADD\n");
          		break;
        		case '-':
          			printf("MULT\n");
          		break;
      		}
      break;
  	}
}

static void Gen_Iterprete(Expresion *expr) {
	switch(expr->tipo) {
    	case 'D':
      		printf("PUSH %d\n",expr->valor);
      		break;
    	case 'P':
	    	Gen_Iterprete(expr->izquierda);
	    	Gen_Iterprete(expr->derecha);
	    	int res = 0;
	    	switch (expr->oper) {
        		case '+':
        			res = expr->izquierda->valor + expr->derecha->valor; 
          			printf("Expresión: (%d + %d)", expr->izquierda, expr->derecha);
          			printf("Resultado: %d\n", res);
          		break;
        		case '-':
        			res = expr->izquierda->valor * expr->derecha->valor;
        			printf("Expresión: (%d * %d)", expr->izquierda, expr->derecha);
          			printf("Resultado: %d\n", res);
          		break;
      		}
      break;
  	}
}



void Procesar(nodo_AST *codigoi){
  	//Gen_codigo_expresion(codigoi);
  	Gen_Iterprete(codigoi);
  	printf("PRINT\n");
}
