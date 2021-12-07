/*
260607 - Kacper Jastrzebski
*/
#include <curses.h> // For NCurses
#include <stdio.h>  // Standard library
#include <unistd.h> // For sleep()
#include <string.h> // For strlen()

// Menu choices
char *menu_choices[] = {
    "Play", // menu_choices[0] = address of array of chars containing "Play\0"
    "Settings (not available)",
    "Exit",
};
// Title bar
char welcome[] = " PAC-MAN v.1.4 (^C to exit) ";

// Map of a level: 0 = empty, 1 = block, 2 = edible bean;
int map[20][26] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //1
            {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, //2
            {1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1}, //3
            {1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1}, //4
            {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, //5
            {1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1}, //6
            {1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1}, //7
            {1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1}, //8
            {1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1, 1, 1, 1}, //9
            {2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0}, //10
            {1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1, 1, 1, 1}, //11
            {1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1}, //12
            {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, //13
            {1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1}, //14
            {1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1}, //15
            {1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1}, //16
            {1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1}, //17
            {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1}, //18
            {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, //19
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  //20
        };

// Pacman "object": [0] position_y, [1] position_x, [2] direction (0 down, 1 up, 2 left, 3 right), [3] alive, [4] points, [5] last_y, [6] last_x;
int pacman[7] = {1, 1, 3, 1, 0, 1, 1};

int row, col, c;
int pac_row = 22, pac_col = 28;
int main_row = 30, main_col = 40;

// Prototypes of some functions
int menu();
void drawMap();
void drawChoices();
int getChoice();
int getPacmanSkin();

int main() {
    initscr();           // NCURSES - Initialize and clear screen, allocates memory
    cbreak();            // Disable line buffering (alternative: raw();)
    keypad(stdscr, TRUE);// Enable for function keys etc.
    noecho();            // Disable input echo
    curs_set(0);         // Disable cursor visibility
    
    // BEG of Central Loop
    while (TRUE) {
        getmaxyx(stdscr, row, col);
        if (row < main_row || col < main_col) {
            clear();
            mvprintw(0, 0, "Terminal window too small!");
            mvprintw(1, 0, "At least %d col x %d rows", main_col, main_row);
            c = getch();
            if (c == 3)
                break;
            continue;
        }
        mvprintw(1, 1, "ROW: %d, COL: %d", row, col);

        WINDOW *w_main = newwin(main_row, main_col, (row - main_row) / 2, (col - main_col) / 2);
        refresh();
        box(w_main, 0, 0);
        mvwprintw(w_main, 0, 1, welcome);
        wrefresh(w_main);

        // Call a menu() with 1st element highlighted
        int choice = menu(1);
        
        if (choice == 3 || choice == 2) {
            break;
        } else if (choice == 1) {

            WINDOW *w_pac = newwin(pac_row, pac_col, ((row - main_row) / 2) + 2, ((col - main_col) / 2) + ((main_col - pac_col) / 2));
            refresh();

            // Prepare new map array to work on

            int used_map[20][26] = {0};
            int *p_map = &map[0][0];
            int *p_used_map = &used_map[0][0];
            
            memcpy(p_used_map, p_map, 20*26*sizeof(*p_map));

            // DRAW LEVEL MAP

            drawMap(w_pac, used_map);

            // GAMEPLAY

            mvwaddch(w_pac, pacman[0] + 1, pacman[1] + 1, ACS_BLOCK);
            
            while (TRUE) {
                mvwprintw(w_main, main_row - 2, 1, "POINTS: %d", pacman[4]);
                mvwaddch(w_pac, pacman[0] + 1, pacman[1] + 1, getPacmanSkin(pacman[2]));
                pacman[5] = pacman[0];
                pacman[6] = pacman[1];
                wrefresh(w_main);
                wrefresh(w_pac);

                if (pacman[3] == 0) break;
                
                nodelay(stdscr, TRUE);
                pacman[2] = getch();

                switch (pacman[2]) {
                case KEY_DOWN:
                    pacman[2] = 0;
                    if (pacman[5] == 19) pacman[5] = 0;
                    else pacman[5]++;
                    break;
                case KEY_UP:
                    pacman[2] = 1;
                    if (pacman[5] == 0) pacman[5] = 19;
                    else pacman[5]--;
                    break;
                case KEY_LEFT:
                    pacman[2] = 2;
                    if (pacman[6] == 0) pacman[6] = 25;
                    else pacman[6]--;
                    break;
                case KEY_RIGHT:
                    pacman[2] = 3;
                    if (pacman[6] == 25) pacman[6] = 0;
                    else pacman[6]++;
                    break;
                case 24:
                    pacman[3] = 0;
                    break;
                default:
                    break;
                }
                
                switch (used_map[pacman[5]][pacman[6]]) {
                case 0:
                    used_map[pacman[0]][pacman[1]] = 0;
                    mvwaddch(w_pac, pacman[0] + 1, pacman[1] + 1, 32); // Put space in current position
                    pacman[0] = pacman[5];
                    pacman[1] = pacman[6];
                    break;
                case 1:
                    pacman[2] = 4;
                    wrefresh(w_main);
                    break;
                case 2:
                    pacman[4]++;
                    used_map[pacman[5]][pacman[6]] = 0;
                    used_map[pacman[0]][pacman[1]] = 0;
                    mvwaddch(w_pac, pacman[0] + 1, pacman[1] + 1, 32); // Put space in current position
                    pacman[0] = pacman[5];
                    pacman[1] = pacman[6];
                    break;
                default:
                    break;
                }
                usleep(150000);
            }
            nodelay(stdscr, FALSE);
            mvwprintw(w_main, main_row - 2, 1, "YOU ATE ALL %d BEANS!", pacman[4]);
            wrefresh(w_main);
            pacman[0] = 1;
            pacman[1] = 1;
            pacman[2] = 3;
            pacman[3] = 1;
            pacman[4] = 0;

            //int pacman[] = {1, 1, 3, 1, 0, 1, 1};

            c = getch();
            clear();
        } // END of if(choice == 1)
    } // END of Central Loop
    clrtoeol();
    refresh();
    endwin(); // Deallocates memory and end ncurses
    return 0;
} // END of main


void drawMap(WINDOW *w_pac, int used_map[20][26]) {
    box(w_pac, 0, 0);
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 26; x++) {
            switch (used_map[y][x]) {
            case 1:
                mvwaddch(w_pac, y + 1, x + 1, ACS_CKBOARD);
                break;
            case 2:
                mvwaddch(w_pac, y + 1, x + 1, ACS_BULLET);
                break;
            default:
                break;
            }
        }
    }
    wrefresh(w_pac);
}

int menu(int highlight) {
    // Dynamicaly define menu window size
    int n_choices = sizeof(menu_choices) / sizeof(char *);
    int menu_size[2] = {0};
    for (int i = 0; i < n_choices; i++) {
        int cur_max = strlen(menu_choices[i]);
        mvprintw( 2, 1, "%d", cur_max);
        if(cur_max > menu_size[1]) menu_size[1] = cur_max;
    }
    menu_size[0] = n_choices + 2;
    menu_size[1] = menu_size[1] + 2;

    // Prepare a window
    WINDOW *w_menu = newwin(menu_size[0], menu_size[1], ((row - main_row) / 2) + 12, ((col - main_col) / 2) + ((main_col - menu_size[1]) / 2));
    refresh();

    int choice = getChoice(w_menu, n_choices, highlight);
    
    return choice;
}


void drawChoices(WINDOW *w_menu, int highlight, int n_choices) {
    int x = 1, y = 1;
    box(w_menu, 0, 0);
    for (int i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) // High light the present choice
        {
            wattron(w_menu, A_REVERSE);
            mvwprintw(w_menu, y, x, "%s", menu_choices[i]);
            wattroff(w_menu, A_REVERSE);
        } else
            mvwprintw(w_menu, y, x, "%s", menu_choices[i]);
        y++;
    }
    wrefresh(w_menu);
}

int getChoice(WINDOW *w_menu, int n_choices, int highlight) {
    int choice = 0;
    drawChoices(w_menu, highlight, n_choices);
    while (TRUE) {
        c = getch();
        switch (c) {
        case KEY_UP:
            if (highlight == 1)
                highlight = n_choices;
            else
                highlight--;
            break;
        case KEY_DOWN:
            if (highlight == n_choices)
                highlight = 1;
            else
                highlight++;
            break;
        case 10:
            choice = highlight;
            break;
        default:
            break;
        }
        drawChoices(w_menu, highlight, n_choices);
        if (choice != 0)
            break;
    }
    return choice;
}

int getPacmanSkin(int direction) {
    int arrow;
    switch (direction) {
    case 0:
        arrow = ACS_DARROW;
        break;
    case 1:
        arrow = ACS_UARROW;
        break;
    case 2:
        arrow = ACS_LARROW;
        break;
    case 3:
        arrow = ACS_RARROW;
        break;
    default:
        arrow = ACS_BLOCK;
        break;
    }
    return arrow;
}