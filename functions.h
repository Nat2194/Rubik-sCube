
typedef enum { FRONT, BACK, UP, DOWN, RIGHT, LEFT } T_SIDE;
typedef enum { G, B, W, Y, R, O, E } T_COLOR;

typedef struct {
    T_SIDE side;
    T_COLOR **cubies;
} T_FACE;

int select_color(T_COLOR);
int side_to_index(T_SIDE);
T_FACE* create_rubiks(void);
void init_rubiks(T_FACE*);
int change_color_text(T_COLOR);
void display_rubiks(T_FACE*);
void blank_rubiks(T_FACE*);
void AntiClockWise(T_SIDE, T_FACE*);
void ClockWise(T_SIDE, T_FACE*);
void BACK_clockwise(T_FACE*, int);
void BACK_anticlockwise(T_FACE*, int);
void DOWN_clockwise(T_FACE*, int);
void DOWN_anticlockwise(T_FACE*, int);
void FRONT_clockwise(T_FACE *, int);
void FRONT_anticlockwise(T_FACE*, int);
void LEFT_clockwise(T_FACE*, int);
void LEFT_anticlockwise(T_FACE*, int);
void RIGHT_clockwise(T_FACE*, int);
void RIGHT_anticlockwise(T_FACE*, int);
void UP_clockwise(T_FACE*, int);
void UP_anticlockwise(T_FACE*, int);
void horizontal_rotation(T_FACE*, int);
void vertical_rotation(T_FACE*);
void scramble_rubiks (T_FACE*);
void input_rubiks (T_FACE*);
void white_cross (T_FACE*);
T_SIDE color_to_side (T_COLOR);
void unknown_clockwise(T_FACE*, T_SIDE, int);
T_COLOR ask_color (int, int, int);
void fill_rubiks(T_FACE*);
void menu (T_FACE*);