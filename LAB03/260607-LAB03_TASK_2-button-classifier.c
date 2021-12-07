/*
260607
*/
#include <curses.h>
#include <stdio.h>
#include <string.h>


int main() {
    int row, col;
	int cont = 2, wheight = 8, wwidth = 50;
	int c;
	char message[100];
	char welcome[] = " BUTTON CLASIFIER v.1.1 (^C to exit) ";

    initscr(); // NCURSES - Initialize and clear screen, allocates memory
    raw(); // Disable line buffering
	//cbreak();
    keypad(stdscr, TRUE);
    noecho();
	
	getmaxyx(stdscr, row, col);
	WINDOW * win = newwin(wheight, wwidth, (row-wheight)/2, (col-wwidth)/2);
	refresh();

    while(cont != 0) {
		int oldrow = row, oldcol = col;
        getmaxyx(stdscr, row, col);
		if(row != oldrow || col != oldcol) {
			clear();
			win = newwin(wheight, wwidth, (row-wheight)/2, (col-wwidth)/2);
			refresh();
			cont = 2;
		} else {
			wrefresh(win);
		}

		if(cont == 1) {
			c = getch();
			wclear(win);
		}
		
		box(win, 0, 0);
    	mvwprintw(win, 0, 1, welcome);
    	mvwprintw(win, 2, (wwidth - 13) / 2, "Enter a key: ");
		if(cont == 2) {
			cont = 1;
			wrefresh(win);
			continue;
		}
        mvwprintw(win, 4, 1, "ASCII code : %d", c);
        mvwprintw(win, 5, 1, "Classification:");
        

		
		switch (c)
		{
		case 3:
			cont = 0;
			break;
		case 10:
			strcpy(message, "You pressed ENTER key!");
			break;		
		case 27:
			strcpy(message, "You pressed ESC key!");
			break;
		case 48 ... 58:
			strcpy(message, "You entered a digit [0-9]!");
			break;
		case 65 ... 90:
			strcpy(message, "You entered an uppercase letter [A-Z]!");
			break;
		case 97 ... 122:
			strcpy(message, "You entered a lowercase letter [a-z]!");
			break;
		case 260:
			strcpy(message, "You pressed LEFT ARROW key!");
			break;
		case 261:
			strcpy(message, "You pressed RIGHT ARROW key!");
			break;
		case 263:
			strcpy(message, "You pressed BACKSPACE key!");
			break;
		case 265:
			strcpy(message, "You pressed F1 key!");
			break;
		default:
			strcpy(message, "<unrecognized key>");
			break;
		}
        mvwprintw(win, 6, ((wwidth - strlen(message)) / 2), "%s", message);
		wrefresh(win);
		
    }
    endwin(); // Deallocates memory and end ncurses
    return 0;
}
