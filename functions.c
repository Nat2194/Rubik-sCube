#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "conio.h"

int select_color(T_COLOR P_COLOR) {
    T_COLOR code_color = P_COLOR;
    return code_color;
}

int side_to_index(T_SIDE P_NAME) {
    T_SIDE pos = P_NAME;
    return pos;
}

T_SIDE color_to_side (T_COLOR P_COLOR) {
    int code;
    code = select_color(P_COLOR);
    T_SIDE pos = code;
    return pos;
}

T_FACE* create_rubiks(void) {
    int i, j;
    T_FACE *rubiks = (T_FACE *)malloc(6 * sizeof(T_FACE));
    rubiks->cubies = NULL;
    for (i=0; i<6; i++) {
        (rubiks+i)->cubies = (T_COLOR **) malloc(3 * sizeof(T_COLOR*));
        for (j=0; j<3; j++)
            *((rubiks+i)->cubies +j) = (T_COLOR *)malloc(3 * sizeof(T_COLOR));
    }
    return rubiks;
}

void init_rubiks(T_FACE *rubiks) {
    int i, j, k;

    for (i = 0; i < 6; i++) {
        T_COLOR COLOR = i;
        for (j = 0; j <  3; j++) {
            for (k = 0; k < 3; k++) {
                *(*((rubiks+i)->cubies+j)+k) = COLOR; // fills the cells
            }
        }
    }
}

// ask for a color value to put on a cubbie
T_COLOR ask_color (int i, int j, int k) {
    char *faces_str[6] = {"FRONT", "BACK", "UP", "DOWN", "RIGHT", "LEFT"}, color_str[10];

    printf("\nEnter a color for face %s, line %d, row %d \n", faces_str[i], j, k);
    scanf("%s", color_str);
    if (strcmp("GREEN", color_str)==0)
        return G;
    else if (strcmp("BLUE", color_str)==0)
        return B;
    else if (strcmp("RED", color_str)==0)
        return R;
    else if (strcmp("ORANGE", color_str)==0)
        return O;
    else if (strcmp("WHITE", color_str)==0)
        return W;
    else if (strcmp("YELLOW", color_str)==0)
        return Y;
    else{
            printf("\nError, wrong color\n");
            return ask_color (i, j, k);
    }
}
void fill_rubiks(T_FACE *rubiks) {
    int i, j, k;
    char color_str;
    T_COLOR color;

    for (i = 0; i < 6; i++) {
        for (j = 0; j <  3; j++) {
            for (k = 0; k < 3; k++) {
                *(*((rubiks+i)->cubies+j)+k) = ask_color (i, j, k); // fills the cells
            }
        }
    }
}

int change_color_text(T_COLOR cell) {
    cell = select_color(cell);
    switch(cell){
        case 0:
            cell = 2;
            break;
        case 1:
            cell = 1;
            break;
        case 2:
            cell = 15;
            break;
        case 3:
            cell = 14;
            break;
        case 4:
            cell = 4;
            break;
        case 5:
            cell = 6;
            break;
        case 6:
            cell = 7;
            break;
    }
    return cell;
}

void display_rubiks(T_FACE *rubiks) {
    char *enumStrings[7] = {"G", "B", "W", "Y", "R", "O", "E"};


    c_textcolor(change_color_text(*(*((rubiks+UP)->cubies))));
    printf("\n\n");
    printf("          %s ", enumStrings[select_color(*(*((rubiks+UP)->cubies)))]);
    c_textcolor(change_color_text(*(*((rubiks+UP)->cubies)+1)));
    printf("%s ", enumStrings[select_color((*(*((rubiks+UP)->cubies)+1)))]);
    c_textcolor(change_color_text(*(*((rubiks+UP)->cubies)+2)));
    printf("%s \n", enumStrings[select_color(*(*((rubiks+UP)->cubies)+2))]);
    c_textcolor(change_color_text(*(*((rubiks+UP)->cubies+1))));
    printf("          %s ", enumStrings[select_color(*(*((rubiks+UP)->cubies+1)))]);
    c_textcolor(change_color_text(*(*((rubiks+UP)->cubies+1)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+UP)->cubies+1)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+UP)->cubies+1)+2)));
    printf("%s \n", enumStrings[select_color(*(*((rubiks+UP)->cubies+1)+2))]);
    c_textcolor(change_color_text(*(*((rubiks+UP)->cubies+2))));
    printf("          %s ", enumStrings[select_color(*(*((rubiks+UP)->cubies+2)))]);
    c_textcolor(change_color_text(*(*((rubiks+UP)->cubies+2)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+UP)->cubies+2)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+UP)->cubies+2)+2)));
    printf("%s \n\n", enumStrings[select_color(*(*((rubiks+UP)->cubies+2)+2))]);


    c_textcolor(change_color_text(*(*((rubiks+LEFT)->cubies))));
    printf("  %s ", enumStrings[select_color(*(*((rubiks+LEFT)->cubies)))]);
    c_textcolor(change_color_text(*(*((rubiks+LEFT)->cubies)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+LEFT)->cubies)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+LEFT)->cubies)+2)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+LEFT)->cubies)+2))]);
    c_textcolor(change_color_text(*(*((rubiks+FRONT)->cubies))));
    printf("  %s ", enumStrings[select_color(*(*((rubiks+FRONT)->cubies)))]);
    c_textcolor(change_color_text(*(*((rubiks+FRONT)->cubies)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+FRONT)->cubies)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+FRONT)->cubies)+2)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+FRONT)->cubies)+2))]);
    c_textcolor(change_color_text(*(*((rubiks+RIGHT)->cubies))));
    printf("  %s ", enumStrings[select_color(*(*((rubiks+RIGHT)->cubies)))]);
    c_textcolor(change_color_text(*(*((rubiks+RIGHT)->cubies)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+RIGHT)->cubies)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+RIGHT)->cubies)+2)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+RIGHT)->cubies)+2))]);
    c_textcolor(change_color_text(*(*((rubiks+BACK)->cubies))));
    printf("  %s ", enumStrings[select_color((*(*((rubiks+BACK)->cubies))))]);
    c_textcolor(change_color_text(*(*((rubiks+BACK)->cubies)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+BACK)->cubies)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+BACK)->cubies)+2)));
    printf("%s \n", enumStrings[select_color(*(*((rubiks+BACK)->cubies)+2))]);

    c_textcolor(change_color_text(*(*((rubiks+LEFT)->cubies+1))));
    printf("  %s ", enumStrings[select_color(*(*((rubiks+LEFT)->cubies+1)))]);
    c_textcolor(change_color_text(*(*((rubiks+LEFT)->cubies+1)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+LEFT)->cubies+1)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+LEFT)->cubies+1)+2)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+LEFT)->cubies+1)+2))]);
    c_textcolor(change_color_text(*(*((rubiks+FRONT)->cubies+1))));
    printf("  %s ", enumStrings[select_color(*(*((rubiks+FRONT)->cubies+1)))]);
    c_textcolor(change_color_text(*(*((rubiks+FRONT)->cubies+1)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+FRONT)->cubies+1)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+FRONT)->cubies+1)+2)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+FRONT)->cubies+1)+2))]);
    c_textcolor(change_color_text(*(*((rubiks+RIGHT)->cubies+1))));
    printf("  %s ", enumStrings[select_color(*(*((rubiks+RIGHT)->cubies+1)))]);
    c_textcolor(change_color_text(*(*((rubiks+RIGHT)->cubies+BACK)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+RIGHT)->cubies+1)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+RIGHT)->cubies+1)+2)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+RIGHT)->cubies+1)+2))]);
    c_textcolor(change_color_text(*(*((rubiks+BACK)->cubies+1))));
    printf("  %s ", enumStrings[select_color(*(*((rubiks+BACK)->cubies+1)))]);
    c_textcolor(change_color_text(*(*((rubiks+BACK)->cubies+1)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+BACK)->cubies+1)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+BACK)->cubies+1)+2)));
    printf("%s \n", enumStrings[select_color(*(*((rubiks+BACK)->cubies+1)+2))]);

    c_textcolor(change_color_text(*(*((rubiks+LEFT)->cubies+2))));
    printf("  %s ", enumStrings[select_color(*(*((rubiks+LEFT)->cubies+2)))]);
    c_textcolor(change_color_text(*(*((rubiks+LEFT)->cubies+2)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+LEFT)->cubies+2)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+LEFT)->cubies+2)+2)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+LEFT)->cubies+2)+2))]);
    c_textcolor(change_color_text(*(*((rubiks+FRONT)->cubies+2))));
    printf("  %s ", enumStrings[select_color(*(*((rubiks+FRONT)->cubies+2)))]);
    c_textcolor(change_color_text(*(*((rubiks+FRONT)->cubies+2)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+FRONT)->cubies+2)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+FRONT)->cubies+2)+2)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+FRONT)->cubies+2)+2))]);
    c_textcolor(change_color_text(*(*((rubiks+RIGHT)->cubies+2))));
    printf("  %s ", enumStrings[select_color(*(*((rubiks+RIGHT)->cubies+2)))]);
    c_textcolor(change_color_text(*(*((rubiks+RIGHT)->cubies+2)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+RIGHT)->cubies+2)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+RIGHT)->cubies+2)+2)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+RIGHT)->cubies+2)+2))]);
    c_textcolor(change_color_text(*(*((rubiks+BACK)->cubies+2))));
    printf("  %s ", enumStrings[select_color(*(*((rubiks+BACK)->cubies+2)))]);
    c_textcolor(change_color_text(*(*((rubiks+BACK)->cubies+2)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+BACK)->cubies+2)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+BACK)->cubies+2)+2)));
    printf("%s \n\n", enumStrings[select_color(*(*((rubiks+BACK)->cubies+2)+2))]);


    c_textcolor(change_color_text(*(*((rubiks+DOWN)->cubies))));
    printf("          %s ", enumStrings[select_color(*(*((rubiks+DOWN)->cubies)))]);
    c_textcolor(change_color_text(*(*((rubiks+DOWN)->cubies)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+DOWN)->cubies)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+DOWN)->cubies)+2)));
    printf("%s \n", enumStrings[select_color(*(*((rubiks+DOWN)->cubies)+2))]);
    c_textcolor(change_color_text(*(*((rubiks+DOWN)->cubies+1))));
    printf("          %s ", enumStrings[select_color(*(*((rubiks+DOWN)->cubies+1)))]);
    c_textcolor(change_color_text(*(*((rubiks+DOWN)->cubies+1)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+DOWN)->cubies+1)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+DOWN)->cubies+1)+2)));
    printf("%s \n", enumStrings[select_color(*(*((rubiks+DOWN)->cubies+1)+2))]);
    c_textcolor(change_color_text(*(*((rubiks+DOWN)->cubies+2))));
    printf("          %s ", enumStrings[select_color(*(*((rubiks+DOWN)->cubies+2)))]);
    c_textcolor(change_color_text(*(*((rubiks+DOWN)->cubies+2)+1)));
    printf("%s ", enumStrings[select_color(*(*((rubiks+DOWN)->cubies+2)+1))]);
    c_textcolor(change_color_text(*(*((rubiks+DOWN)->cubies+2)+2)));
    printf("%s \n", enumStrings[select_color(*(*((rubiks+DOWN)->cubies+2)+2))]);

}

void blank_rubiks(T_FACE *rubiks) {
    int i, j, k;
    T_COLOR color = 6;

    for (i = 0; i < 6; i++) {

        for (j = 0; j <  3; j++) {

            for (k = 0; k < 3; k++) {
                if(j!=1 || k != 1)
                    *(*((rubiks+i)->cubies+j)+k) = color; //sets the cells to Grey state
            }

        }

    }
}


void AntiClockWise(T_SIDE SIDE, T_FACE *rubiks)
{   T_FACE* temp;
    int i,j, k;

    temp = create_rubiks();

    for (i = 0; i < 6; i++) {
        for (j = 0; j <  3; j++) {
            for (k = 0; k < 3; k++) {
                *(*((temp+i)->cubies+j)+k) = *(*((rubiks+i)->cubies+j)+k); // fills the cells
            }
        }
    }
    for (i=0; i< 3; i++) {
        for (j=0; j< 3; j++) {
            *(*((rubiks+SIDE)->cubies+i)+j) = *(*((temp+SIDE)->cubies+j)+2-i);

        }
    }
    free(temp);
}

void ClockWise(T_SIDE SIDE, T_FACE *rubiks)
{   T_FACE* temp;
    int i,j, k;

    temp = create_rubiks();

    for (i = 0; i < 6; i++) {
        for (j = 0; j <  3; j++) {
            for (k = 0; k < 3; k++) {
                *(*((temp+i)->cubies+j)+k) = *(*((rubiks+i)->cubies+j)+k); // fills the cells
            }
        }
    }
    for (i=0; i< 3; i++) {
        for (j=0; j< 3; j++) {
            *(*((rubiks+SIDE)->cubies+j)+2-i) = *(*((temp+SIDE)->cubies+i)+j);

        }
    }
    free(temp);
}

void BACK_clockwise(T_FACE *rubiks, int type)
{
    //Back face, clockwise rotation
    T_COLOR temp[3];
    int x; //counter

    //move the outer edges affected by the rotation
    for (x=0; x<3; x++)
    {
        temp[x] = *(*((rubiks+UP)->cubies)+x);
        *(*((rubiks+UP)->cubies)+x) = *(*((rubiks+RIGHT)->cubies+x)+2);
        *(*((rubiks+RIGHT)->cubies+x)+2) = *(*((rubiks+DOWN)->cubies+2)+2-x);
        *(*((rubiks+DOWN)->cubies+2)+2-x) =  *(*((rubiks+LEFT)->cubies+2-x));
        *(*((rubiks+LEFT)->cubies+2-x)) = temp[x];

    }

    //now rotate the face surface
    ClockWise(BACK, rubiks);

    //verify rotation type
    if (type == 2)
        BACK_clockwise(rubiks, 1);
}

void BACK_anticlockwise(T_FACE *rubiks, int type)
{
    //Back face, anticlockwise rotation
    T_COLOR temp[3];
    int x; //counter

    //move the outer edges affected by the rotation
    for (x=0; x<3; x++)
    {
        temp[x] = *(*((rubiks+UP)->cubies)+x);
        *(*((rubiks+UP)->cubies)+x) = *(*((rubiks+LEFT)->cubies+2-x));
        *(*((rubiks+LEFT)->cubies+2-x)) = *(*((rubiks+DOWN)->cubies+2)+2-x);
        *(*((rubiks+DOWN)->cubies+2)+2-x) = *(*((rubiks+RIGHT)->cubies+x)+2);
        *(*((rubiks+RIGHT)->cubies+x)+2) = temp[x];

    }

    //now rotate the face surface
    AntiClockWise(BACK, rubiks);

    //verify rotation type
    if(type==2)
        BACK_anticlockwise(rubiks,1);
}

void DOWN_clockwise(T_FACE *rubiks, int type)
{
    //  down face, clockwise rotation
    T_COLOR temp[3];
    int x; //counter

    //move the outer edges affected by the rotation
    for (x=0; x<3; x++)
    {
        temp[x] = *(*((rubiks+FRONT)->cubies+2)+x);
        *(*((rubiks+FRONT)->cubies+2)+x) = *(*((rubiks+LEFT)->cubies+2)+x);
        *(*((rubiks+LEFT)->cubies+2)+x) = *(*((rubiks+BACK)->cubies+2)+x);
        *(*((rubiks+BACK)->cubies+2)+x) = *(*((rubiks+RIGHT)->cubies+2)+x);
        *(*((rubiks+RIGHT)->cubies+2)+x) = temp[x];

    }

    //now rotate the face surface
    ClockWise(DOWN, rubiks);

    //verify rotation type
    if(type==2)
        DOWN_clockwise(rubiks,1);
}

void DOWN_anticlockwise(T_FACE *rubiks, int type)
{
    //  down face, anticlockwise rotation
    T_COLOR temp[3];
    int x; //counter

    //move the outer edges affected by the rotation
    for (x=0; x<3; x++)
    {
        temp[x] = temp[x] = *(*((rubiks+FRONT)->cubies+2)+x);
        *(*((rubiks+FRONT)->cubies+2)+x) = *(*((rubiks+RIGHT)->cubies+2)+x);
        *(*((rubiks+RIGHT)->cubies+2)+x) = *(*((rubiks+BACK)->cubies+2)+x);
        *(*((rubiks+BACK)->cubies+2)+x) = *(*((rubiks+LEFT)->cubies+2)+x);
        *(*((rubiks+LEFT)->cubies+2)+x) = temp[x];

    }

    //now rotate the face surface
    AntiClockWise(DOWN, rubiks);

    //verify rotation type
    if(type==2)
        DOWN_anticlockwise(rubiks,1);
}

void FRONT_clockwise(T_FACE *rubiks, int type)
{
    //  front face, clockwise rotation
    T_COLOR temp[3];
    int x; //counter

    //move the outer edges affected by the rotation
    for (x=0; x<3; x++)
    {
        temp[x] = temp[x] = *(*((rubiks+UP)->cubies+2)+x);
        *(*((rubiks+UP)->cubies+2)+x) = *(*((rubiks+LEFT)->cubies+2-x)+2);
        *(*((rubiks+LEFT)->cubies+2-x)+2) = *(*((rubiks+DOWN)->cubies)+2-x);
        *(*((rubiks+DOWN)->cubies)+2-x) = *(*((rubiks+RIGHT)->cubies+x));
        *(*((rubiks+RIGHT)->cubies+x)) = temp[x];

    }

    //now rotate the face surface
    ClockWise(FRONT, rubiks);

    //verify rotation type
    if(type==2)
        FRONT_clockwise(rubiks,1);
}

void FRONT_anticlockwise(T_FACE *rubiks, int type)
{
    //  front face, anticlockwise rotation
    T_COLOR temp[3];
    int x; //counter

    //move the outer edges affected by the rotation
    for (x=0; x<3; x++)
    {
        temp[x] = temp[x] = *(*((rubiks+UP)->cubies+2)+x);
        *(*((rubiks+UP)->cubies+2)+x) = *(*((rubiks+RIGHT)->cubies+x));
        *(*((rubiks+RIGHT)->cubies+x)) = *(*((rubiks+DOWN)->cubies)+2-x);
        *(*((rubiks+DOWN)->cubies)+2-x) = *(*((rubiks+LEFT)->cubies+2-x)+2);
        *(*((rubiks+LEFT)->cubies+2-x)+2) = temp[x];

    }

    //now rotate the face surface
    AntiClockWise(FRONT, rubiks);

    //verify rotation type
    if(type==2)
        FRONT_anticlockwise(rubiks,1);
}

void LEFT_clockwise(T_FACE *rubiks, int type)
{
    //  left face, clockwise rotation
    T_COLOR temp[3];
    int x; //counter

    //move the outer edges affected by the rotation
    for (x=0; x<3; x++)
    {
        temp[x] = temp[x] = *(*((rubiks+UP)->cubies+x));
        *(*((rubiks+UP)->cubies+x)) = *(*((rubiks+BACK)->cubies+2-x)+2);
        *(*((rubiks+BACK)->cubies+2-x)+2) = *(*((rubiks+DOWN)->cubies+x));
        *(*((rubiks+DOWN)->cubies+x)) = *(*((rubiks+FRONT)->cubies+x));
        *(*((rubiks+FRONT)->cubies+x)) = temp[x];

    }

    //now rotate the face surface
    ClockWise(LEFT, rubiks);

    //verify rotation type
    if(type==2)
        LEFT_clockwise(rubiks,1);
}

void LEFT_anticlockwise(T_FACE *rubiks, int type)
{
    //  left face, anticlockwise rotation
    T_COLOR temp[3];
    int x; //counter

    //move the outer edges affected by the rotation
    for (x=0; x<3; x++)
    {
        temp[x] = temp[x] = *(*((rubiks+UP)->cubies+x));
        *(*((rubiks+UP)->cubies+x)) = *(*((rubiks+FRONT)->cubies+x));
        *(*((rubiks+FRONT)->cubies+x)) = *(*((rubiks+DOWN)->cubies+x));
        *(*((rubiks+DOWN)->cubies+x)) = *(*((rubiks+BACK)->cubies+2-x)+2);
        *(*((rubiks+BACK)->cubies+2-x)+2) = temp[x];

    }

    //now rotate the face surface
    AntiClockWise(LEFT, rubiks);

    //verify rotation type
    if(type==2)
        LEFT_anticlockwise(rubiks,1);
}

void RIGHT_clockwise(T_FACE *rubiks, int type)
{
    //  right face, clockwise rotation
    T_COLOR temp[3];
    int x; //counter

    //move the outer edges affected by the rotation
    for (x=0; x<3; x++)
    {
        temp[x] = temp[x] = *(*((rubiks+UP)->cubies+x)+2);
        *(*((rubiks+UP)->cubies+x)+2) = *(*((rubiks+FRONT)->cubies+x)+2);
        *(*((rubiks+FRONT)->cubies+x)+2) = *(*((rubiks+DOWN)->cubies+x)+2);
        *(*((rubiks+DOWN)->cubies+x)+2) = *(*((rubiks+BACK)->cubies+2-x));
        *(*((rubiks+BACK)->cubies+2-x)) = temp[x];

    }

    //now rotate the face surface
    ClockWise(RIGHT, rubiks);

    //verify rotation type
    if(type==2)
        RIGHT_clockwise(rubiks,1);
}

void RIGHT_anticlockwise(T_FACE *rubiks, int type)
{
    //  right face, anticlockwise rotation
    T_COLOR temp[3];
    int x; //counter

    //move the outer edges affected by the rotation
    for (x=0; x<3; x++)
    {
        temp[x] = temp[x] = *(*((rubiks+UP)->cubies+x)+2);
        *(*((rubiks+UP)->cubies+x)+2) = *(*((rubiks+BACK)->cubies+2-x));
        *(*((rubiks+BACK)->cubies+2-x)) = *(*((rubiks+DOWN)->cubies+x)+2);
        *(*((rubiks+DOWN)->cubies+x)+2) = *(*((rubiks+FRONT)->cubies+x)+2);
        *(*((rubiks+FRONT)->cubies+x)+2) = temp[x];

    }

    //now rotate the face surface
    AntiClockWise(RIGHT, rubiks);

    //verify rotation type
    if(type==2)
        RIGHT_anticlockwise(rubiks,1);
}

void UP_clockwise(T_FACE *rubiks, int type)
{
    //  up face, clockwise rotation
    T_COLOR temp[3];
    int x; //counter

    //move the outer edges affected by the rotation
    for (x=0; x<3; x++)
    {
        temp[x] = temp[x] = *(*((rubiks+FRONT)->cubies)+x);
        *(*((rubiks+FRONT)->cubies)+x) = *(*((rubiks+RIGHT)->cubies)+x);
        *(*((rubiks+RIGHT)->cubies)+x) = *(*((rubiks+BACK)->cubies)+x);
        *(*((rubiks+BACK)->cubies)+x) = *(*((rubiks+LEFT)->cubies)+x);
        *(*((rubiks+LEFT)->cubies)+x) = temp[x];

    }

    //now rotate the face surface
    ClockWise(UP, rubiks);

    //verify rotation type
    if(type==2)
        UP_clockwise(rubiks,1);
}

void UP_anticlockwise(T_FACE *rubiks, int type)
{
    //  up face, clockwise rotation
    T_COLOR temp[3];
    int x; //counter

    //move the outer edges affected by the rotation
    for (x=0; x<3; x++)
    {
        temp[x] = temp[x] = *(*((rubiks+FRONT)->cubies)+x);
        *(*((rubiks+FRONT)->cubies)+x) = *(*((rubiks+LEFT)->cubies)+x);
        *(*((rubiks+LEFT)->cubies)+x) = *(*((rubiks+BACK)->cubies)+x);
        *(*((rubiks+BACK)->cubies)+x) = *(*((rubiks+RIGHT)->cubies)+x);
        *(*((rubiks+RIGHT)->cubies)+x) = temp[x];

    }

    //now rotate the face surface
    AntiClockWise(UP, rubiks);

    //verify rotation type
    if(type==2)
        UP_anticlockwise(rubiks,1);
}

void unknown_clockwise(T_FACE *rubiks, T_SIDE P_FACE, int type) {
    switch(P_FACE) {
        case UP:
            UP_clockwise(rubiks, type);
            break;
        case DOWN:
            DOWN_clockwise(rubiks, type);
            break;
        case LEFT:
            LEFT_clockwise(rubiks, type);
            break;
        case RIGHT:
            RIGHT_clockwise(rubiks, type);
            break;
        case FRONT:
            FRONT_clockwise(rubiks, type);
            break;
        case BACK:
            BACK_clockwise(rubiks, type);
            break;
    }
}

void horizontal_rotation(T_FACE *rubiks, int type)
{
    T_FACE temp_face;

    // BACK face becomes FRONT and the RIGHT face becomes LEFT
    temp_face = *(rubiks+LEFT);
    *(rubiks+LEFT) = *(rubiks+FRONT);
    *(rubiks+FRONT) = *(rubiks+RIGHT);
    *(rubiks+RIGHT) = *(rubiks+BACK);
    *(rubiks+BACK) = temp_face;
    ClockWise(UP, rubiks);
    AntiClockWise(DOWN, rubiks);

    //verify rotation type
    if(type==2)
        horizontal_rotation(rubiks,1);
}

void vertical_rotation(T_FACE *rubiks)
{   int i;
    T_FACE temp_face;

    // UP face becomes DOWN (and vice versa) and the FRONT face becomes BACK

    temp_face = *(rubiks+DOWN);
    *(rubiks+DOWN) = *(rubiks+UP);
    *(rubiks+UP) = temp_face;
    temp_face = *(rubiks+BACK);
    *(rubiks+BACK) = *(rubiks+FRONT);
    *(rubiks+FRONT) = temp_face;
    for (i = 0; i< 6 ; i++)
        unknown_clockwise(rubiks,i,2);
}

void scramble_rubiks (T_FACE *rubiks)
{
    int n_rand1, n_rand2, type, move, i;
    for(i=0; i < 30; i++) {
        n_rand1 = rand();
        n_rand2 = rand();
        type = n_rand2 % 2 + 1;
        move = n_rand1 % 12;
        switch(move) {
            case 0:
                BACK_clockwise(rubiks, type);
                break;

            case 1:
                BACK_anticlockwise(rubiks, type);
                break;

            case 2:
                DOWN_clockwise(rubiks, type);
                break;

            case 3:
                DOWN_anticlockwise(rubiks, type);
                break;

            case 4:
                FRONT_clockwise(rubiks, type);
                break;

            case 5:
                FRONT_anticlockwise(rubiks, type);
                break;

            case 6:
                LEFT_clockwise(rubiks, type);
                break;

            case 7:
                LEFT_anticlockwise(rubiks, type);
                break;

            case 8:
                RIGHT_clockwise(rubiks, type);
                break;

            case 9:
                RIGHT_anticlockwise(rubiks, type);
                break;

            case 10:
                UP_clockwise(rubiks, type);
                break;

            case 11:
                UP_anticlockwise(rubiks, type);
                break;
        }
    }
}

void input_rubiks (T_FACE *rubiks) {
    char action[5];

    printf("Enter the initial of the face and the type or rotation (' or 2)\n");
    scanf("%s", action);

    if (strcmp("F", action)==0)
        FRONT_clockwise(rubiks, 1);
    else if (strcmp("F'", action)==0)
        FRONT_anticlockwise(rubiks, 1);

    else if (strcmp("F2", action)==0 || strcmp("F2'", action)==0 || strcmp("2F", action)==0 || strcmp("2F'", action)==0\
    || strcmp("F'2", action)==0)
        FRONT_clockwise(rubiks, 2);


    else if (strcmp("L", action)==0)
        LEFT_clockwise(rubiks, 1);

    else if (strcmp("L'", action)==0)
        LEFT_anticlockwise(rubiks, 1);

    else if (strcmp("L2", action)==0 || strcmp("L2'", action)==0 || strcmp("2L", action)==0 || strcmp("2L'", action)==0\
    || strcmp("L'2", action)==0)
        LEFT_anticlockwise(rubiks, 2);


    else if (strcmp("B", action)==0)
        BACK_clockwise(rubiks, 1);

    else if (strcmp("B'", action)==0)
        BACK_anticlockwise(rubiks, 1);

    else if (strcmp("B2", action)==0 || strcmp("B2'", action)==0 || strcmp("2B", action)==0 || strcmp("2B'", action)==0\
    || strcmp("B'2", action)==0)
        BACK_anticlockwise(rubiks, 2);


    else if (strcmp("U", action)==0)
        UP_clockwise(rubiks, 1);

    else if (strcmp("U'", action)==0)
        UP_anticlockwise(rubiks, 1);

    else if (strcmp("U2", action)==0 || strcmp("U2'", action)==0 || strcmp("2U", action)==0 || strcmp("2U'", action)==0\
    || strcmp("U'2", action)==0)
        UP_anticlockwise(rubiks, 2);


    else if (strcmp("D", action)==0)
        DOWN_clockwise(rubiks, 1);

    else if (strcmp("D'", action)==0)
        DOWN_anticlockwise(rubiks, 1);

    else if (strcmp("D2", action)==0 || strcmp("D2'", action)==0 || strcmp("2D", action)==0 || strcmp("2D'", action)==0\
    || strcmp("D'2", action)==0)
        DOWN_anticlockwise(rubiks, 2);


    else if (strcmp("R", action)==0)
        RIGHT_clockwise(rubiks, 1);

    else if (strcmp("R'", action)==0)
        RIGHT_anticlockwise(rubiks, 1);

    else if (strcmp("R2", action)==0 || strcmp("R2'", action)==0 || strcmp("2R", action)==0 || strcmp("2R'", action)==0\
    || strcmp("R'2", action)==0)
        RIGHT_anticlockwise(rubiks, 2);
    else {

        printf("Wrong input\n");
        input_rubiks(rubiks);
    }
}

void menu (T_FACE *rubiks){
    int *ptr_run, run = 1, i,op;

    ptr_run = &run;

    printf("\n\n");
    c_textcolor(15);
    for(i=0; i<120; i++){
        printf("-");
    }
    c_textcolor(14);
    printf("1: Scramble");
    c_textcolor(15);
    printf("\t  2: Reset");
    c_textcolor(1);
    printf("\t  3: Blank");
    c_textcolor(2);
    printf("\t  4: Play");
    c_textcolor(4);
    printf("\t  5: Fill");
    c_textcolor(6);
    printf("\t  6: Solve");
    c_textcolor(5);
    printf("\t  7: Quit\n");

    c_textcolor(15);
    for(i=0; i<120; i++){
        printf("-");
    }
    do{
        printf("\nAction:\t");
        scanf("%d",&op);
        if (op<1 || op>7)
            printf("\nError you must choose an action between 1 and 6 \t");
    }while(op<1 || op>7);

    switch(op) {
        case 1:
            scramble_rubiks(rubiks);
            display_rubiks(rubiks);
            break;

        case 2:
            init_rubiks(rubiks);
            display_rubiks(rubiks);
            break;

        case 3:
            blank_rubiks(rubiks);
            display_rubiks(rubiks);
            break;

        case 4:
            input_rubiks(rubiks);
            display_rubiks(rubiks);
            break;
        case 5:
            fill_rubiks(rubiks);
            display_rubiks(rubiks);
            break;
        case 6:
            white_cross(rubiks);
            break;
        case 7:
            *(ptr_run)=0;
            break;

    }
    if (run == 1)
        menu(rubiks);

}

void white_cross (T_FACE* rubiks) {
    int cpt_white = 0, i, misplaced_cubies;
    T_SIDE new_face;


    // put the white face at the upper position
    if (*(*((rubiks + DOWN)->cubies + 1) + 1) == W)
        vertical_rotation(rubiks);

    // put the green face at the front
    while (*(*((rubiks + FRONT)->cubies + 1) + 1) != G) {
        horizontal_rotation(rubiks, 1);
    }

    // while there is a white cubie on the edges of the DOWN face
    for (i = 1; i < 8; i += 2)
        if (*(*((rubiks + DOWN)->cubies + i / 3) + i % 3) == W)
            cpt_white++;
    while (cpt_white > 0) {
        while (*(*((rubiks + DOWN)->cubies + 1) + 2) != W) { // put the cubie on the right of the DOWN face
            DOWN_clockwise(rubiks, 1);
        }
        while (*(*((rubiks + UP)->cubies + 1) + 2) == W) { // empty the right of the UP face
            UP_clockwise(rubiks, 1);
        }
        RIGHT_clockwise(rubiks, 2); //move it on the UP
        cpt_white = 0;
        for (i = 1; i < 8; i += 2)
            if (*(*((rubiks + DOWN)->cubies + i / 3) + i % 3) == W)
                cpt_white++;
    }
    // clean

    // while there is a white cubie on the edges of the BACK face
    for (i = 1; i < 8; i += 2)
        if (*(*((rubiks + BACK)->cubies + i / 3) + i % 3) == W) {
            cpt_white++;
        }
    while (cpt_white > 0) {
        while (*(*((rubiks + UP)->cubies + 1)) == W) { // while there is a white cubie on the emplacement we aim at
            UP_clockwise(rubiks, 1);
        }
        // verify that the move hasn't changed the number of white cubies on the face
        cpt_white = 0;
        for (i = 1; i < 8; i += 2) {
            if (*(*((rubiks + BACK)->cubies + i / 3) + i % 3) == W)
                cpt_white++;
        }
        while (*(*((rubiks + BACK)->cubies + 1) + 2) != W && cpt_white > 0) { // put the cubie on the right of the BACK face
            BACK_clockwise(rubiks, 1);
        }
        if (cpt_white > 0) {
            LEFT_clockwise(rubiks, 1); //move it on the UP
        }
        cpt_white = 0;
        for (i = 1; i < 8; i += 2) {
            if (*(*((rubiks + BACK)->cubies + i / 3) + i % 3) == W)
                cpt_white++;
        }
    // while there is a white cubie on the edges of the RIGHT face
    for (i = 1; i < 8; i += 2)
        if (*(*((rubiks + RIGHT)->cubies + i / 3) + i % 3) == W)
            cpt_white++;
    while (cpt_white > 0) {
        while (*(*((rubiks + UP)->cubies) + 1) == W) // if there is a white cubie on the emplacement we aim at
            UP_clockwise(rubiks, 1);
        // Verify that the move hasn't change the number of white cubies
        cpt_white = 0;
        for (i = 1; i < 8; i += 2) {
            if (*(*((rubiks + RIGHT)->cubies + i / 3) + i % 3) == W)
                cpt_white++;
        }
        while (*(*((rubiks + RIGHT)->cubies + 1) + 2) != W &&
               cpt_white > 0) // put the cubie on the right of the RIGHT face
            RIGHT_clockwise(rubiks, 1);
        BACK_clockwise(rubiks, 1); //move it on the UP
        cpt_white = 0;
        for (i = 1; i < 8; i += 2)
            if (*(*((rubiks + RIGHT)->cubies + i / 3) + i % 3) == W)
                cpt_white++;

    }

        // while there is a white cubie on the edges of the LEFT face
        for (i = 1; i < 8; i += 2)
            if (*(*((rubiks + LEFT)->cubies + i / 3) + i % 3) == W)
                cpt_white++;
        while (cpt_white > 0) {
            while (*(*((rubiks + UP)->cubies + 1)) == W) // if there is a white cubie on the emplacement we aim at
                UP_clockwise(rubiks, 1);
            // verify that the move hasn't changed the number of white cubies on the face
            cpt_white = 0;
            for (i = 1; i < 8; i += 2) {
                if (*(*((rubiks + BACK)->cubies + i / 3) + i % 3) == W)
                    cpt_white++;
            }
                while (*(*((rubiks + BACK)->cubies + 1) + 2) != W && cpt_white > 0) // put the cubie on the right of the LEFT face
                LEFT_clockwise(rubiks, 1);
            while (*(*((rubiks + UP)->cubies + 2) + 1) == W) // if there is a white cubie on the emplacement we aim at
                UP_clockwise(rubiks, 1);
            FRONT_clockwise(rubiks, 1); //move it on the UP
            cpt_white = 0;
            for (i = 1; i < 8; i += 2)
                if (*(*((rubiks + LEFT)->cubies + i / 3) + i % 3) == W)
                    cpt_white++;
        }
        cpt_white = 0;
        for (i = 1; i < 8; i += 2)
            if (*(*((rubiks + UP)->cubies + i / 3) + i % 3) == W)
                cpt_white++;
        if (cpt_white < 4)
            white_cross(rubiks);
        printf("white cross");
        display_rubiks(rubiks);
        // At this step we got a white cross, but it may not be a perfect cross yet

        // put the green face at the front
        while (*(*((rubiks + FRONT)->cubies + 1) + 1) != G) {
            horizontal_rotation(rubiks, 1);
        }

        // Align FRONT face's upper and middle cubies
            while (*(*((rubiks + FRONT)->cubies) + 1) != *(*((rubiks + FRONT)->cubies + 1) + 1))
                UP_clockwise(rubiks, 1);

            new_face = RIGHT;

        // Let's count the misplaced upper cubies of the faces
        misplaced_cubies = 0;
        for (i = 0; i < 4; i++) {
            if ((*(*((rubiks + FRONT)->cubies) + 1) != *(*((rubiks + FRONT)->cubies + 1) + 1)))
                misplaced_cubies++;
            horizontal_rotation(rubiks, 1);
        }

        // If there are misplaced cubies
        while (misplaced_cubies > 0) {

            printf("%d \n", side_to_index(new_face));
            // Check new face's upper and middle cubies alignment
            if (*(*((rubiks + new_face)->cubies) + 1) != *(*((rubiks + new_face)->cubies + 1) + 1)) {

                unknown_clockwise(rubiks, new_face, 2);
                display_rubiks(rubiks);

                // Check if there is white cubbie on DOWN face
                cpt_white = 0;
                for (i = 1; i < 8; i += 2)
                    if (*(*((rubiks + DOWN)->cubies + i / 3) + i % 3) == W)
                        cpt_white++;
                while (cpt_white > 0) {
                    // change the face we're looking for
                    printf("%d ", side_to_index(new_face));
                    new_face = color_to_side(*(*((rubiks + new_face)->cubies + 2) + 1));
                    printf("%d", side_to_index(new_face));
                    // Check new_face's lower and middle cubies alignment
                    while (*(*((rubiks + new_face)->cubies + 2) + 1) != *(*((rubiks + new_face)->cubies + 1) + 1))
                        DOWN_clockwise(rubiks, 1);
                    display_rubiks(rubiks);
                    unknown_clockwise(rubiks, new_face, 2);
                    display_rubiks(rubiks);
                    // Check if there is white cubbie on DOWN face
                    cpt_white = 0;
                    for (i = 1; i < 8; i += 2) {
                        if (*(*((rubiks + DOWN)->cubies + i / 3) + i % 3) == W)
                            cpt_white++;
                    }
                    misplaced_cubies = 0;
                }
            }
            else {
                switch (new_face) {
                    case FRONT:
                        new_face = RIGHT;
                        break;
                    case RIGHT:
                        new_face = BACK;
                        break;
                    case BACK:
                        new_face = LEFT;
                        break;
                    case LEFT:
                        new_face = FRONT;
                        break;
                }
            }
            display_rubiks(rubiks);
        }
    }
}