#include <stdlib.h>
#include <stdio.h>
#include "lex.h"
#include "error.h"
#include "parser.h"

static Expresion *nueva_expresion(void) {
    return (Expresion *) malloc(sizeof(Expresion));
}

static void liberar_expresion(Expresion *expr) {
    free((void *) expr);
}

static int Analizar_operador(Operador *oper) {
    if( token.clase == '+'){
        *oper = '+';
        obtener_siguiente_token();
        return 1;
    }

    if( token.clase == '*'){
        *oper = '*';
        obtener_siguiente_token();
        return 1;
    }

    return 0;
}

static int Analizar_expresion(Expresion **p_expr) {
    Expresion *expr = *p_expr = nueva_expresion();

    if(token.clase == DIGITO) {
        expr->tipo = 'D';
        expr->valor = token.repr - '0';
        obtener_siguiente_token();
        return 1;
    }

    if(token.clase == '(') {
        expr->tipo = 'P';
        obtener_siguiente_token();
        if(!Analizar_expresion(&expr->izquierda)) {
            Error("Falta expresión");
        }
        if(!Analizar_operador(&expr->oper)) {
            Error("Falta operador");
        }
        if(!Analizar_expresion(&expr->derecha)) {
            Error("Falta expresión");
        }
        if(token.clase != ')') {
            Error("Falta )");
        }

        obtener_siguiente_token();
        return 1;
    }

    liberar_expresion(expr);
    return 0;
}


int Analizar_programa(nodo_AST **p_codigoi){
    Expresion *expr;

    obtener_siguiente_token();
    if(Analizar_expresion(&expr)) {
        if(token.clase != EoF){
            Error("Hay Basura despues de código fuente del programa");
        }
        *p_codigoi = expr;
        return 1;
    }
    return 0;
}
