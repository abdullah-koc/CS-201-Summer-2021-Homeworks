#include <iostream>
#include "AlgebraicExpression.h"

int main() {


    AlgebraicExpression algebraicExpression;
    cout << algebraicExpression.infix2postfix("(2-3+4)*(5+6*7)") << endl;
    cout << algebraicExpression.evaluatePostfix(algebraicExpression.infix2postfix("(2-3+4)*(5+6*7)") )<< endl << endl << endl;



    return 0;
}
