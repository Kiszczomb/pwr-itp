#include <curses.h>
#include <stdio.h>
#include <string.h>

// Menu choices
char *choices[] = {
    "LAB03_TASK_1",
    "Settings (not available)",
    "Exit",
};
int n_choices = sizeof(choices) / sizeof(char *);

int main() {
    int row, col;
    int t_height = 24, t_width = 54;
    int w_height = 20, w_width = 50;
    int c;
    char welcome[] = " TITLE v.1.0 (^C to exit) ";

    initscr(); // NCURSES - Initialize and clear screen, allocates memory
    raw();     // Disable line buffering (alternative: cbreak())
    keypad(stdscr, TRUE);
    noecho();

    // wclear(win);

    while (1) {
        getmaxyx(stdscr, row, col);
        WINDOW *win = newwin(w_height, w_width, (row - w_height) / 2, (col - w_width) / 2);
        refresh();
        box(win, 0, 0);
        mvwprintw(win, 0, 1, welcome);
        mvwprintw(win, 1, 1, "ROW: %d, COL: %d", row, col);
        wrefresh(win);

        c = getch();
        clear();
        if (c == 3)
            break;
    }
    endwin(); // Deallocates memory and end ncurses
    return 0;
}
