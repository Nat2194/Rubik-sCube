/* C Rubik's Cube Solver by Max GUILBERT and Nathan CARLIER */

#include "functions.h"



int main() {
    T_FACE *rubiks;

    rubiks = create_rubiks();
    init_rubiks(rubiks);
    menu(rubiks);
    return 0;
}
