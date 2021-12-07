#include <curses.h>
#include <stdio.h>
#include <string.h>

// Menu choices
char *choices[] = {
    "LAB03_TASK_2 - Button Classifier (TUI)",
    "LAB03_TASK_3 - Christmas Tree (CLI)",
    "LAB04_TASK_2 - Integer Reversator (CLI)",
    "LAB05_TASK_1 - Real Number Storage Vault (CLI)",
    "Exit",
};
int n_choices = sizeof(choices) / sizeof(char *);

// Prepare prototypes of menu drawing functions
void drawMenu(WINDOW *w_menu, int highlight);
int getChoice(WINDOW *w_menu);

// Prepare prototypes of functions-subprograms
void buttonClassifier();
void christmasTree();
void integerReversator();
void meanSquareError();

// RUN: run super-program or exit in safe way;
int RUN = 1;

int main() {
    int row, col;
    int c;
    char welcome[] = " SUPER-PROGRAM v.1.0 (^C to exit) ";

    // BEG of Central Loop
    while (RUN) {
        initscr();            // NCURSES - Initialize and clear screen, allocates memory
        cbreak();             // Disable line buffering (alternative: raw())
        keypad(stdscr, TRUE); // Enable to get the functions keys, arrow keys etc.
        noecho();             // Disable input echo
        curs_set(0);          // Disable cursor visibility

        getmaxyx(stdscr, row, col); // Get terminal size: rows and columns
        clear();
        WINDOW *w_menu = newwin(n_choices + 2, col - 4, (row - n_choices - 2) / 2, (4) / 2);
        mvprintw(0, 0, "ROW: %d, COL: %d", row, col);
        refresh();
        box(w_menu, 0, 0);
        mvwprintw(w_menu, 0, 1, welcome);
        wrefresh(w_menu);
        c = getch();
        int choice = getChoice(w_menu);

        switch (choice) {
        case 1:
            buttonClassifier();
            break;
        case 2:
            endwin(); // Following program does not use ncurses, exit to prompt.
            christmasTree();
            printf("Any key to exit:\n");
            c = getch();
            break;
        case 3:
            endwin(); // Following program does not use ncurses, exit to prompt.
            integerReversator();
            printf("Any key to exit:\n");
            c = getch();
            break;
        case 4:
            endwin(); // Following program does not use ncurses, exit to prompt.
            meanSquareError();
            printf("Any key to exit:\n");
            c = getch();
            break;
        case 5:
            RUN = 0;
            break;

        default:
            break;
        }
    } // END of Central Loop
    clrtoeol();
    refresh();
    endwin(); // Deallocates memory and end ncurses
    return 0;
}

void drawMenu(WINDOW *w_menu, int highlight) {
    int x = 1, y = 1;
    box(w_menu, 0, 0);
    for (int i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) // High light the present choice
        {
            wattron(w_menu, A_REVERSE);
            mvwprintw(w_menu, y, x, "%s", choices[i]);
            wattroff(w_menu, A_REVERSE);
        } else
            mvwprintw(w_menu, y, x, "%s", choices[i]);
        y++;
    }
    wrefresh(w_menu);
}

int getChoice(WINDOW *w_menu) {
    int c;
    int highlight = 1;
    int choice = 0;
    drawMenu(w_menu, highlight);
    while (TRUE) {
        c = getch();
        switch (c) {
        case KEY_UP:
            if (highlight == 1)
                highlight = n_choices;
            else
                --highlight;
            break;
        case KEY_DOWN:
            if (highlight == n_choices)
                highlight = 1;
            else
                ++highlight;
            break;
        case 10:
            choice = highlight;
            break;
        default:
            break;
        }
        drawMenu(w_menu, highlight);
        if (choice != 0)
            break;
    }
    return choice;
}

// LAB 03 TASK 02
void buttonClassifier() {
    int row, col;
    int cont = 2, wheight = 8, wwidth = 50;
    int c;
    char message[100];
    char welcome[] = " BUTTON CLASIFIER v.1.1 (^X to exit) ";

    getmaxyx(stdscr, row, col);
    WINDOW *win = newwin(wheight, wwidth, (row - wheight) / 2, (col - wwidth) / 2);
    refresh();

    while (cont != 0) {
        int oldrow = row, oldcol = col;
        getmaxyx(stdscr, row, col);
        if (row != oldrow || col != oldcol) {
            clear();
            win = newwin(wheight, wwidth, (row - wheight) / 2, (col - wwidth) / 2);
            refresh();
            cont = 2;
        } else {
            wrefresh(win);
        }

        if (cont == 1) {
            c = getch();
            wclear(win);
        }

        box(win, 0, 0);
        mvwprintw(win, 0, 1, welcome);
        mvwprintw(win, 2, (wwidth - 13) / 2, "Enter a key: ");
        if (cont == 2) {
            cont = 1;
            wrefresh(win);
            continue;
        }
        mvwprintw(win, 4, 1, "ASCII code : %d", c);
        mvwprintw(win, 5, 1, "Classification:");

        switch (c) {
        case 10:
            strcpy(message, "You pressed ENTER key!");
            break;
        case 24:
            cont = 0;
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
}

// LAB 03 TASK 03
void christmasTree() {
    int c;
    printf("CHRISTMAS TREE v1.0\n\n");

    int height;
    printf("Provide a height of a tree (a positive integer): ");
    scanf("%d", &height);

    for (int i = 0; i < height; i++) {
        int space;
        for (space = height - i; space > 0; space--) {
            printf(" ");
        }

        for (int stars = 1; stars <= (2 * i) + 1; stars++) {
            printf("*");
        }
        printf("\n");
    }
    for (int space = 0; space < height; space++) {
        printf(" ");
    }
    printf("#\n\nHO! HO! HO! MERRY CHRISTMAS!\n");
}

// LAB 04 TASK 02

int power(int num, int pow) {
	int begin = num;
	if(pow == 0) return 1;
	if(pow == 1) return num;
	while(pow>1) {
        //printf("BEGIN: %d NUM: %d POW: %d\n", begin, num, pow);
		num *= begin;
		pow--;
    }
	return num;
}

void integerReversator() {
	int num, revers = 0, pow = 0;	
	printf("INTEGER REVERSATOR v1.0\n\n");
	printf("Provide a multi-digit positive number: "); scanf("%d", &num);

	while(power(10,pow+1) < num) {
        pow++;
    }

	while(num > 0) {
		revers += (num % 10)*power(10, pow);
		num /= 10;
		pow--;
	}
	printf("Reversed: %d\n", revers);

}

// LAB 05 TASK 01

void meanSquareError() {
    printf("REAL NUMBER STORAGE VAULT v1.0\n\n");

    int nsize;
    printf("[QST] How many real numbers would you like to store? : "); scanf("%d", &nsize);
    float tab[nsize];

    for(int i = 0; i < nsize; i++) {
        printf("Tab[%d] = ", i+1); 
        scanf("%f", &tab[i]);
    }

    printf("[INF] You provided %d values. The table contain followin data:\n", nsize);
    float sumy = 0, sumx = 0;
    int min = 0, max = 0;

    for(int i = 0; i < nsize; i++) {
        printf(" Tab[%d] = %f\n", i+1, tab[i]);
        if(tab[i] < tab[min]) min = i;
        else if(tab[i] > tab[max]) max = i;
        sumy += tab[i];
        sumx += i+1;

    }
    printf("[INF] In reverse order:\n");

    for(int i = nsize; i > 0; i--) {
        printf(" Tab[%d] = %f\n", i, tab[i-1]);
    }

    float meany = sumy/nsize;
    float meanx = sumx/nsize;
    printf("[INF] Mean - arithmetic average value: %f \n", meany);

    printf("[INF] Extremes: \n");
    printf(" - maximum: Tab[%d] = %f\n", max+1, tab[max]);
    printf(" - minimum: Tab[%d] = %f\n", min+1, tab[min]);

    // Calculating slope of line of best fit: mslope = Σ((Xi-meanX)*(Yi-meanY)) / Σ((Xi-meanX)^2)
    float mnumer = 0, mdenom = 0;
    for(int i = 0; i < nsize; i++) {
        mnumer += (i+1-meanx) * (tab[i]-meany);
        mdenom += (i+1-meanx) * (i+1-meanx);
    }
    // Slope of line of best fit;
    float mslope = mnumer/mdenom; 

    // yintercept -> b in y=a*x+b
    float yintercept = meany - (mslope * meanx);

    // Mean Square Error formula = (1/n) * Σ(actual – forecast)^2;
    // msum -> Σ(actual – forecast)^2;
    float msesum = 0;
    for(int i = 0; i < nsize; i++) {
        msesum += (tab[i] - (((i+1)*mslope)+yintercept))*(tab[i] - (((i+1)*mslope)+yintercept));
        // DEBUGING nr 1:
        // printf("x: %d, actual: %f, forecast: %f, msesum: %f \n", i+1, tab[i], ((i+1)*mslope)+yintercept, msesum);
    }
    float mse = msesum / nsize;
    printf("[INF] Line of Best Fit calculated as: y = (%.2f) * x + (%.2f)\n", mslope, yintercept);
    printf("[INF] Mean Squared Error (population variance): %f\n", mse);
    // DEBUGING nr 2:
    // printf("meanx = %f\n", meanx);
    // printf("meany = %f\n", meany);
    // printf("sumx = %f\n", sumx);
    // printf("sumy = %f\n", sumy);
    // printf("mslope = %f\n", mslope);
    // printf("yintercept = %f\n", yintercept);
    // printf("msesum = %f\n", msesum);
}