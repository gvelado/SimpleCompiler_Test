# Compilador
Ejemplo de un compilador sencillo, que servirá como recurso para reconocer las fases de un compilador
## Objetivos
  * Reconocer de forma practica los componentes de un compilador
  * Utilizar análisis descendente recursivo
## Gramática
expresion --> digito | '(' expresion operador expresion ')'
operador --> '+' | '\*'
digito --> '0' | '1' | '2' | '3' | '4' | '5'  | '6' | '7' | '8'  | '9'
