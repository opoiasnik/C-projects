#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>


void draw_start();
void draw_end2();
void draw_end1();
void moving_arrow(int size_x, int size_y,char field[size_x][size_y], int popitka);
void draw1(int size_x, int size_y, char field[size_x][size_y]);
void draw2(int size_x, int size_y, char field[size_x][size_y]);
void run_out_of_tries();
int main(){
    initscr();
    
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    
    curs_set(FALSE);
   
    nodelay(stdscr, TRUE);
    int size_x = 90;
int size_y = 30;
    
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
     init_pair(2, COLOR_GREEN, COLOR_BLACK);
     init_pair(3, COLOR_RED, COLOR_BLACK);
     init_pair(4, COLOR_CYAN, COLOR_BLACK);
      init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
      int popitka = 0;
     char field[size_x][size_y];
    draw_start();
     draw1(size_x, size_y, field);
    
     
  
 
   
    moving_arrow(size_x, size_y, field, popitka);      
    
    endwin();
    

}
void draw2(int size_x, int size_y, char field[size_x][size_y]){
    refresh();
    attron( COLOR_PAIR(5) );
    for(int i = 0; i<size_y; i++) {
        for(int j = 0; j<size_x; j++) {
            if(i == 0 || i == size_y-1) {
                field[j][i] = '-';
                 
             } else if(j == 0 || j == size_x-1) {
                //field[j][i] = '';
               field[j][i] = '|';
             } else {
                //field[j][i] = i*10+j;
                 field[j][i] = ' ';
             }
              printw("%c", field[j][i]);
        }
         printw("\n");
      
    }


    //draw a labirint--------------------------------------

    //under level------------------
    for(int i = 1; i<17; i++){
         field[i][12] = '-'; 
        mvprintw(12,i,"-");
    }
     for(int i = 1; i<17; i++){
         field[i][14] = '-'; 
        mvprintw(14,i,"-");
    }
    
    for(int i = 15;i<18;i++){
        field[16][i] = '|';
         mvprintw(i,16,"|");
    }
    for(int i = 15;i<24;i++){
        field[18][i] = '|';
         mvprintw(i,18,"|");
    }
    for(int i = 16;i>=1;i--){
        field[i][18] = '-';
         mvprintw(18,i,"-");
    }
    
     for(int i = 16;i>8;i--){
        field[i][20] = '-';
         mvprintw(20,i,"-");
    }
    for(int i = 7;i>=1;i--){
        field[i][20] = '-';
         mvprintw(20,i,"-");
    }
    for(int i = 21;i<24;i++){
        field[9][i] = '|';
         mvprintw(i,9,"|");
    }
     for(int i = 21;i<29;i++){
        field[7][i] = '|';
         mvprintw(i,7,"|");
    }
    for(int i = 10;i<49;i++){
        field[i][23] = '-';
         mvprintw(23,i,"-");
    }
     for(int i = 10;i<59;i++){
        field[i][25] = '-';
         mvprintw(25,i,"-");
    }
     for(int i = 10;i<61;i++){
        field[i][27] = '-';
         mvprintw(27,i,"-");
    }
    for(int i = 23;i>16;i--){
        field[49][i] = '|';
         mvprintw(i,49,"|");
    }
    for(int i = 24;i>18;i--){
        field[51][i] = '|';
         mvprintw(i,51,"|");
    }
     for(int i = 51;i<60;i++){
        field[i][18] = '-';
         mvprintw(18,i,"-");
    }
     for(int i = 49;i<62;i++){
        field[i][16] = '-';
         mvprintw(16,i,"-");
    }
    for(int i = 19;i<26;i++){
        field[59][i] = '|';
         mvprintw(i,59,"|");
    }
    for(int i = 17;i<28;i++){
        field[61][i] = '|';
         mvprintw(i,61,"|");
    }
     for(int i = 20;i<29;i++){
        field[63][i] = '|';
         mvprintw(i,63,"|");
    }
    for(int i = 63;i<69;i++){
        field[i][19] = '-';
         mvprintw(19,i,"-");
    }
     for(int i = 62;i<71;i++){
        field[i][17] = '-';
         mvprintw(17,i,"-");
    }
    for(int i = 20;i<29;i++){
        field[68][i] = '|';
         mvprintw(i,68,"|");
    }
     for(int i = 18;i<28;i++){
        field[70][i] = '|';
         mvprintw(i,70,"|");
    }
    for(int i = 71;i<88;i++){
        field[i][27] = '-';
         mvprintw(27,i,"-");
    }
     for(int i = 18;i<28;i++){
        field[87][i] = '|';
         mvprintw(i,87,"|");
    }
     for(int i = 86;i>84;i--){
        field[i][19] = '-';
         mvprintw(19,i,"-");
    }
     for(int i = 18;i>=15;i--){
        field[84][i] = '|';
         mvprintw(i,84,"|");
    }
    for(int i = 84;i<89;i++){
        field[i][15] = '-';
         mvprintw(15,i,"-");
    }


    //upper levels-------------


     for(int i = 11;i>=8;i--){
        field[16][i] = '|';
         mvprintw(i,16,"|");
    }
    for(int i = 11;i>=6;i--){
        field[18][i] = '|';
         mvprintw(i,18,"|");
    }
     for(int i = 16;i>=1;i--){
        field[i][7] = '-';
         mvprintw(7,i,"-");
    }
     for(int i = 18;i>=7;i--){
        field[i][5] = '-';
         mvprintw(5,i,"-");
    }
     for(int i = 4;i>3;i--){
        field[7][i] = '|';
         mvprintw(i,7,"|");
    }
    for(int i = 4;i>3;i--){
        field[5][i] = '|';
         mvprintw(i,5,"|");
    }
    for(int i = 5;i>1;i--){
        field[i][5] = '-';
         mvprintw(5,i,"-");
    }
     
    for(int i = 4;i>2;i--){
        field[2][i] = '|';
         mvprintw(i,2,"|");
    }
    for(int i = 2;i<79;i++){
        field[i][2] = '-';
         mvprintw(2,i,"-");
    }
     for(int i = 8;i<30;i++){
        field[i][4] = '-';
         mvprintw(4,i,"-");
    }
     for(int i = 5;i<11;i++){
        field[29][i] = '|';
         mvprintw(i,29,"|");
    }
     for(int i = 3;i<9;i++){
        field[31][i] = '|';
         mvprintw(i,31,"|");
    }
     for(int i = 8;i<30;i++){
        field[i][4] = '-';
         mvprintw(4,i,"-");
    }
     for(int i = 29;i<42;i++){
        field[i][11] = '-';
         mvprintw(11,i,"-");
    }
     for(int i = 31;i<40;i++){
        field[i][9] = '-';
         mvprintw(9,i,"-");
    }
     for(int i = 4;i<9;i++){
        field[39][i] = '|';
         mvprintw(i,39,"|");
    }
    for(int i = 6;i<11;i++){
        field[41][i] = '|';
         mvprintw(i,41,"|");
    }
     for(int i = 41;i<66;i++){
        field[i][5] = '-';
         mvprintw(5,i,"-");
    }
    for(int i = 39;i<68;i++){
        field[i][3] = '-';
         mvprintw(3,i,"-");
    }
     for(int i = 6;i<15;i++){
        field[65][i] = '|';
         mvprintw(i,65,"|");
    }
     for(int i = 4;i<13;i++){
        field[67][i] = '|';
         mvprintw(i,67,"|");
    }
     for(int i = 65;i<79;i++){
        field[i][15] = '-';
         mvprintw(15,i,"-");
    }
     for(int i = 67;i<79;i++){
        field[i][13] = '-';
         mvprintw(13,i,"-");
    }
    for(int i = 3;i<18;i++){
        field[78][i] = '|';
         mvprintw(i,78,"|");
    }
     for(int i = 1;i<16;i++){
        field[80][i] = '|';
         mvprintw(i,80,"|");
    }
    for(int i = 78;i<84;i++){
        field[i][18] = '-';
         mvprintw(18,i,"-");
    }
    for(int i = 80;i<84;i++){
        field[i][16] = '-';
         mvprintw(16,i,"-");
    }


     for(int i = 18;i<29;i++){
        field[i][12] = '-';
         mvprintw(12,i,"-");
    }
     for(int i = 18;i<27;i++){
        field[i][14] = '-';
         mvprintw(14,i,"-");
    }
    for(int i = 15;i<19;i++){
        field[26][i] = '|';
         mvprintw(i,26,"|");
    }
     for(int i = 15;i<17;i++){
        field[28][i] = '|';
         mvprintw(i,28,"|");
    }
      for(int i = 26;i<49;i++){
        field[i][19] = '-';
         mvprintw(19,i,"-");
    }
    for(int i = 28;i<49;i++){
        field[i][17] = '-';
         mvprintw(17,i,"-");
    }
     for(int i = 14;i>=13;i--){
        field[28][i] = '|';
         mvprintw(i,28,"|");
    }
    attroff( COLOR_PAIR(4) );

    //add color to block-moving sign-----------------

     attron( COLOR_PAIR(1) );
    field[49][18] = '|';
    mvprintw(18,49,"|");
    attroff( COLOR_PAIR(1) );


    attron( COLOR_PAIR(1) );
    field[78][14] = '|';
    mvprintw(14,78,"|");
    attroff( COLOR_PAIR(1) );


     attron( COLOR_PAIR(1) );
    field[84][17] = '|';
    mvprintw(17,84,"|");
    attroff( COLOR_PAIR(1) );


     attron( COLOR_PAIR(1) );
    field[62][23] = '-';
    mvprintw(23,62,"-");
    attroff( COLOR_PAIR(1) );

     attron( COLOR_PAIR(1) );
    field[1][4] = '-';
    mvprintw(4,1,"-");
    attroff( COLOR_PAIR(1) );

     attron( COLOR_PAIR(1) );
    field[8][21] = '-';
    mvprintw(21,8,"-");
    attroff( COLOR_PAIR(1) );

    // field[9][3] = '*';
    //  mvprintw(3,9,"*");
    //  field[11][21] = '*';
    //  mvprintw(21,11,"*");
      field[11][22] = 'r';
      attron( COLOR_PAIR(4) );
     mvprintw(22,11,"r");
     attroff( COLOR_PAIR(4) );
    //      field[60][17] = '*';

    //  mvprintw(17,60,"*");
    //    field[88][21] = '*';
    //  mvprintw(21,88,"*");
      field[85][18] = 'O';
      attron( COLOR_PAIR(2) );
     mvprintw(18,85,"O");
     attroff( COLOR_PAIR(2) );


     field[1][19] = '?';
     attron( COLOR_PAIR(3) );
      mvprintw(19,1,"?");
      attroff( COLOR_PAIR(3) );
      field[2][19] = '|';
      attron( COLOR_PAIR(4) );
      mvprintw(19,2,"|");
      attroff( COLOR_PAIR(4) );
    refresh();
}
void draw_start(){
    clear();
    char intro[12][59] = {
        {"                                           "},
        {"  ----WELCOME-----"},
        {" -----TO GAME-----"},
        {"      THE X"},
        {"Rules: you cant do no more than 650 moves,"},
        {"       1 move = 1 press on button"},
        {"       ? - lose/teleport/change moves"},
        {"       * - teleport                                   "},
        {"       ? will be open after 200 moves                  "},
        {"       r - restart game             "},
         {"       You have 2 tries             "},
        

        
        
        {"Good luck!)"}
        
    };

    int center = COLS/2 - strlen(intro[0])/2 ;

    int target = 10;
    for( int row_count = 1; row_count <= 11; row_count++ ){

        for( int y = 20; y >= target; y-- ){
            move(y, center);
            attron( COLOR_PAIR(3) );
            printw("%s", intro[row_count]);
            attroff( COLOR_PAIR(3) );
            refresh();
            usleep( 1 * 100000 );

            // clear
            move(y,center);
            printw(intro[0]);
        }
        if(row_count == 3){
            usleep( 3 * 1000000 );
        }

        move(target,center);
         attron( COLOR_PAIR(4) );
        printw(intro[row_count]);
         attroff( COLOR_PAIR(4) );

        target++;
    }
    usleep( 5 * 1000000 );
    clear();
}
void draw_end1(){
    clear();
    char intro[3][44] = {
        {"                                           "},
        {"  Sorry, you LOST!"},
        {"PLease try again.."},
   
      
        
    };

    int center = COLS/2 - strlen(intro[0])/2;

    int target = 15;
    for( int row_count = 1; row_count <= 2; row_count++ ){

        for( int y = 20; y >= target; y-- ){
            move(y, center);
            attron( COLOR_PAIR(3) );
            printw("%s", intro[row_count]);
            attroff( COLOR_PAIR(3) );
            refresh();
            usleep( 1 * 100000 );

            // clear
            move(y,center);
              attron( COLOR_PAIR(3) );
            printw(intro[0]);
            
            attroff( COLOR_PAIR(3));
        }
       

        move(target,center);
        attron( COLOR_PAIR(3) );
        printw(intro[row_count]);
          attroff( COLOR_PAIR(3) );

        target++;
    }
    usleep( 3 * 1000000 );
    clear();
}
void again(){
    clear();
    char intro[4][44] = {
        {"                                           "},
        {"  Okay....."},
        {"Lets try again.."},
        {"Tries left: 1"}
   
      
        
    };

    int center = COLS/2 - strlen(intro[0])/2;

    int target = 15;
    for( int row_count = 1; row_count <= 3; row_count++ ){

        for( int y = 20; y >= target; y-- ){
            move(y, center);
            attron( COLOR_PAIR(3) );
            printw("%s", intro[row_count]);
            attroff( COLOR_PAIR(3) );
            refresh();
            usleep( 1 * 100000 );

            // clear
            move(y,center);
              attron( COLOR_PAIR(3) );
            printw(intro[0]);
            
            attroff( COLOR_PAIR(3));
        }
       

        move(target,center);
        attron( COLOR_PAIR(3) );
        printw(intro[row_count]);
          attroff( COLOR_PAIR(3) );

        target++;
    }
    usleep( 3 * 1000000 );
    clear();
}
void draw_end2(){
    clear();
    char intro[3][44] = {
        {"                                           "},
        {"  Congratulations!!!"},
        {"     YOU WON!!"},
      
        
    };

    int center = COLS/2 - strlen(intro[0])/2;

    int target = 15;
    for( int row_count = 1; row_count <= 2; row_count++ ){

        for( int y = 20; y >= target; y-- ){
            move(y, center);
            attron( COLOR_PAIR(2) );
            printw("%s", intro[row_count]);
            attroff( COLOR_PAIR(2) );
            refresh();
            usleep( 1 * 100000 );

            // clear
            move(y,center);
            printw(intro[0]);
        }
        if(row_count == 3){
            usleep( 3 * 1000000 );
        }

        move(target,center);
         attron( COLOR_PAIR(2) );
        printw(intro[row_count]);
         attroff( COLOR_PAIR(2) );

        target++;
    }
    usleep( 3 * 1000000 );
    clear();
}
void run_out_of_tries(){
    clear();
    char intro[3][44] = {
        {"                                           "},
        {"  Sorry, that was the last try"},
        {"     YOU LOSE!!"},
      
        
    };

    int center = COLS/2 - strlen(intro[0])/2;

    int target = 15;
    for( int row_count = 1; row_count <= 2; row_count++ ){

        for( int y = 20; y >= target; y-- ){
            move(y, center);
            attron( COLOR_PAIR(3) );
            printw("%s", intro[row_count]);
            attroff( COLOR_PAIR(3) );
            refresh();
            usleep( 1 * 100000 );

            // clear
            move(y,center);
            printw(intro[0]);
        }
        if(row_count == 3){
            usleep( 3 * 1000000 );
        }

        move(target,center);
         attron( COLOR_PAIR(3) );
        printw(intro[row_count]);
         attroff( COLOR_PAIR(3) );

        target++;
    }
    usleep( 3 * 1000000 );
    clear();
}
void draw1(int size_x, int size_y, char field[size_x][size_y]) {
   // printw("%c", "c");
    refresh();
    attron( COLOR_PAIR(5) );
    for(int i = 0; i<size_y; i++) {
        for(int j = 0; j<size_x; j++) {
            if(i == 0 || i == size_y-1) {
                field[j][i] = '-';
                 
             } else if(j == 0 || j == size_x-1) {
                //field[j][i] = '';
               field[j][i] = '|';
             } else {
                //field[j][i] = i*10+j;
                 field[j][i] = ' ';
             }
              printw("%c", field[j][i]);
        }
         printw("\n");
      
    }


    //draw a labirint--------------------------------------

    //under level------------------
    for(int i = 1; i<17; i++){
         field[i][12] = '-'; 
        mvprintw(12,i,"-");
    }
     for(int i = 1; i<17; i++){
         field[i][14] = '-'; 
        mvprintw(14,i,"-");
    }
    
    for(int i = 15;i<18;i++){
        field[16][i] = '|';
         mvprintw(i,16,"|");
    }
    for(int i = 15;i<24;i++){
        field[18][i] = '|';
         mvprintw(i,18,"|");
    }
    for(int i = 16;i>=1;i--){
        field[i][18] = '-';
         mvprintw(18,i,"-");
    }
    
     for(int i = 16;i>8;i--){
        field[i][20] = '-';
         mvprintw(20,i,"-");
    }
    for(int i = 7;i>=1;i--){
        field[i][20] = '-';
         mvprintw(20,i,"-");
    }
    for(int i = 21;i<24;i++){
        field[9][i] = '|';
         mvprintw(i,9,"|");
    }
     for(int i = 21;i<29;i++){
        field[7][i] = '|';
         mvprintw(i,7,"|");
    }
    for(int i = 10;i<49;i++){
        field[i][23] = '-';
         mvprintw(23,i,"-");
    }
     for(int i = 10;i<59;i++){
        field[i][25] = '-';
         mvprintw(25,i,"-");
    }
     for(int i = 10;i<61;i++){
        field[i][27] = '-';
         mvprintw(27,i,"-");
    }
    for(int i = 23;i>16;i--){
        field[49][i] = '|';
         mvprintw(i,49,"|");
    }
    for(int i = 24;i>18;i--){
        field[51][i] = '|';
         mvprintw(i,51,"|");
    }
     for(int i = 51;i<60;i++){
        field[i][18] = '-';
         mvprintw(18,i,"-");
    }
     for(int i = 49;i<62;i++){
        field[i][16] = '-';
         mvprintw(16,i,"-");
    }
    for(int i = 19;i<26;i++){
        field[59][i] = '|';
         mvprintw(i,59,"|");
    }
    for(int i = 17;i<28;i++){
        field[61][i] = '|';
         mvprintw(i,61,"|");
    }
     for(int i = 20;i<29;i++){
        field[63][i] = '|';
         mvprintw(i,63,"|");
    }
    for(int i = 63;i<69;i++){
        field[i][19] = '-';
         mvprintw(19,i,"-");
    }
     for(int i = 62;i<71;i++){
        field[i][17] = '-';
         mvprintw(17,i,"-");
    }
    for(int i = 20;i<29;i++){
        field[68][i] = '|';
         mvprintw(i,68,"|");
    }
     for(int i = 18;i<28;i++){
        field[70][i] = '|';
         mvprintw(i,70,"|");
    }
    for(int i = 71;i<88;i++){
        field[i][27] = '-';
         mvprintw(27,i,"-");
    }
     for(int i = 18;i<28;i++){
        field[87][i] = '|';
         mvprintw(i,87,"|");
    }
     for(int i = 86;i>84;i--){
        field[i][19] = '-';
         mvprintw(19,i,"-");
    }
     for(int i = 18;i>=15;i--){
        field[84][i] = '|';
         mvprintw(i,84,"|");
    }
    for(int i = 84;i<89;i++){
        field[i][15] = '-';
         mvprintw(15,i,"-");
    }


    //upper levels-------------


     for(int i = 11;i>=8;i--){
        field[16][i] = '|';
         mvprintw(i,16,"|");
    }
    for(int i = 11;i>=6;i--){
        field[18][i] = '|';
         mvprintw(i,18,"|");
    }
     for(int i = 16;i>=1;i--){
        field[i][7] = '-';
         mvprintw(7,i,"-");
    }
     for(int i = 18;i>=7;i--){
        field[i][5] = '-';
         mvprintw(5,i,"-");
    }
     for(int i = 4;i>3;i--){
        field[7][i] = '|';
         mvprintw(i,7,"|");
    }
    for(int i = 4;i>3;i--){
        field[5][i] = '|';
         mvprintw(i,5,"|");
    }
    for(int i = 5;i>1;i--){
        field[i][5] = '-';
         mvprintw(5,i,"-");
    }
     
    for(int i = 4;i>2;i--){
        field[2][i] = '|';
         mvprintw(i,2,"|");
    }
    for(int i = 2;i<79;i++){
        field[i][2] = '-';
         mvprintw(2,i,"-");
    }
     for(int i = 8;i<30;i++){
        field[i][4] = '-';
         mvprintw(4,i,"-");
    }
     for(int i = 5;i<11;i++){
        field[29][i] = '|';
         mvprintw(i,29,"|");
    }
     for(int i = 3;i<9;i++){
        field[31][i] = '|';
         mvprintw(i,31,"|");
    }
     for(int i = 8;i<30;i++){
        field[i][4] = '-';
         mvprintw(4,i,"-");
    }
     for(int i = 29;i<42;i++){
        field[i][11] = '-';
         mvprintw(11,i,"-");
    }
     for(int i = 31;i<40;i++){
        field[i][9] = '-';
         mvprintw(9,i,"-");
    }
     for(int i = 4;i<9;i++){
        field[39][i] = '|';
         mvprintw(i,39,"|");
    }
    for(int i = 6;i<11;i++){
        field[41][i] = '|';
         mvprintw(i,41,"|");
    }
     for(int i = 41;i<66;i++){
        field[i][5] = '-';
         mvprintw(5,i,"-");
    }
    for(int i = 39;i<68;i++){
        field[i][3] = '-';
         mvprintw(3,i,"-");
    }
     for(int i = 6;i<15;i++){
        field[65][i] = '|';
         mvprintw(i,65,"|");
    }
     for(int i = 4;i<13;i++){
        field[67][i] = '|';
         mvprintw(i,67,"|");
    }
     for(int i = 65;i<79;i++){
        field[i][15] = '-';
         mvprintw(15,i,"-");
    }
     for(int i = 67;i<79;i++){
        field[i][13] = '-';
         mvprintw(13,i,"-");
    }
    for(int i = 3;i<18;i++){
        field[78][i] = '|';
         mvprintw(i,78,"|");
    }
     for(int i = 1;i<16;i++){
        field[80][i] = '|';
         mvprintw(i,80,"|");
    }
    for(int i = 78;i<84;i++){
        field[i][18] = '-';
         mvprintw(18,i,"-");
    }
    for(int i = 80;i<84;i++){
        field[i][16] = '-';
         mvprintw(16,i,"-");
    }


     for(int i = 18;i<29;i++){
        field[i][12] = '-';
         mvprintw(12,i,"-");
    }
     for(int i = 18;i<27;i++){
        field[i][14] = '-';
         mvprintw(14,i,"-");
    }
    for(int i = 15;i<19;i++){
        field[26][i] = '|';
         mvprintw(i,26,"|");
    }
     for(int i = 15;i<17;i++){
        field[28][i] = '|';
         mvprintw(i,28,"|");
    }
      for(int i = 26;i<49;i++){
        field[i][19] = '-';
         mvprintw(19,i,"-");
    }
    for(int i = 28;i<49;i++){
        field[i][17] = '-';
         mvprintw(17,i,"-");
    }
     for(int i = 14;i>=13;i--){
        field[28][i] = '|';
         mvprintw(i,28,"|");
    }
    for(int i = 81; i<89; i++){
        field[i][6] = '-';
    mvprintw(6,i,"-");
    }
    for(int i = 81; i<89; i++){
        field[i][8] = '-';
    mvprintw(8,i,"-");
    }
    attroff( COLOR_PAIR(4) );

    //add color to block-moving sign-----------------

     attron( COLOR_PAIR(1) );
    field[49][18] = '|';
    mvprintw(18,49,"|");
    attroff( COLOR_PAIR(1) );
    attron( COLOR_PAIR(4) );
     field[80][7] = '|';
    mvprintw(7,80,"|");
    attroff( COLOR_PAIR(4) );
    attron( COLOR_PAIR(3) );
    field[88][7] = '?';
    mvprintw(7,88,"?");
    attroff( COLOR_PAIR(3) );


    attron( COLOR_PAIR(1) );
    field[78][14] = '|';
    mvprintw(14,78,"|");
    attroff( COLOR_PAIR(1) );


     attron( COLOR_PAIR(1) );
    field[84][17] = '|';
    mvprintw(17,84,"|");
    attroff( COLOR_PAIR(1) );


     attron( COLOR_PAIR(1) );
    field[62][23] = '-';
    mvprintw(23,62,"-");
    attroff( COLOR_PAIR(1) );

     attron( COLOR_PAIR(1) );
    field[1][4] = '-';
    mvprintw(4,1,"-");
    attroff( COLOR_PAIR(1) );

     attron( COLOR_PAIR(1) );
    field[8][21] = '-';
    mvprintw(21,8,"-");
    attroff( COLOR_PAIR(1) );

    field[9][3] = '*';
     mvprintw(3,9,"*");
     field[11][21] = '*';
     mvprintw(21,11,"*");
      field[11][22] = 'r';
      attron( COLOR_PAIR(4) );
     mvprintw(22,11,"r");
     attroff( COLOR_PAIR(4) );
         field[60][17] = '*';

     mvprintw(17,60,"*");
       field[88][21] = '*';
     mvprintw(21,88,"*");
      field[85][18] = 'O';
      attron( COLOR_PAIR(2) );
     mvprintw(18,85,"O");
     attroff( COLOR_PAIR(2) );


     field[1][19] = '?';
     attron( COLOR_PAIR(3) );
      mvprintw(19,1,"?");
      attroff( COLOR_PAIR(3) );
      field[2][19] = '|';
      attron( COLOR_PAIR(4) );
      mvprintw(19,2,"|");
      attroff( COLOR_PAIR(4) );
    refresh();
    
    
  
}
void moving_arrow(int size_x, int size_y,char field[size_x][size_y], int popitka){
   srand(time(NULL));
   int tries1 = 0;
    int tries2 = 0;
     int tries3 = 0;
      int tries4 = 0;
       int tries5 = 0;
        int tries6 = 0;
    int block1 = 0;
    int block2 = 0;
     int block3 = 0;
      int block4 = 0;
       int block5 = 0;
        int block6 = 0;
        int moves = 0;
    
        


     
   int y = 13;
    int x = 1;
    int random = 0;
    int position = 0;

  
    char player = '>', previous = ' ';
    mvprintw(y, x, "%c", player);
    refresh();
    int c;
    do{
        
        c = getch();
       // previous = (y == size_y - 1 && x < 34) ? buffer[x] : ' ';
        if(c == KEY_LEFT || c == KEY_RIGHT || c == KEY_UP || c == KEY_DOWN){
            mvprintw(y, x, "%c", previous);
        }
        mvprintw(0, 0, "Moves:%d", moves);
        switch(c){
            case KEY_LEFT: 
                player = '<';
                moves = moves+1;
                
                if(x<=0){
                    break;
                }
                if(field[x-1][y] != ' ' && field[x-1][y]!='!' && field[x-1][y]!='*' && field[x-1][y]!='O' && field[x-1][y]!='?' && field[x-1][y]!='r'){
                    break;
                }
                if(field[x][y] == '!'){
                    field[x][y] = ' ';
                }
                x--;
                 if(x-1==49 && y==18 && tries3 ==0 && field[49][18]=='|'){
                    random = rand()%6;
                    if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                    tries3++;
                    block3=1;
                }  
                if(x-1==78 && y==14 && tries1 == 0 && field[78][14]=='|'){
                    random = rand()%6;
                    if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                      tries1++;
                      block1=1;
                }  
                break;
            case KEY_RIGHT: 
                player = '>';
                moves = moves+1;
               
                 if(x>=size_x){
                    break;
                }
                if(field[x+1][y] != ' ' && field[x+1][y]!='!' && field[x+1][y]!='*' && field[x+1][y]!='O' && field[x+1][y]!='r' && field[x+1][y]!='?'){
                    break;
                }
                 if(field[x][y] == '!'){
                    field[x][y] = ' ';
                }
                if(field[x][y]=='*'){
                    position = rand()%4;
                    if(position == 1){
                        field[1][13] = player;
                        mvprintw(13,1,"%c", player);
                        field[9][3] = ' ';
                        mvprintw(3,9,"%c", ' ');
                        x = 1;
                        y = 13;

                        break;
                    }
                     if(position == 2){
                         field[12][21] = player;
                        mvprintw(21,12,"%c", player);
                         field[9][3] = ' ';
                        mvprintw(3,9,"%c", ' ');
                        x = 12;
                        y = 21;

                        break;
                    }
                     if(position == 3){
                        
                         field[9][3] = ' ';
                        mvprintw(3,9,"%c", ' ');
                        mvprintw(17,83,"%c", player);
                         
                        x = 83;
                        y = 17;

                      

                        break;
                    }
                     if(position == 4){
                        
                         field[9][3] = ' ';
                        mvprintw(3,9,"%c", ' ');
                         mvprintw(13,1,"%c", player);
                         
                       
                        x = 1;
                        y = 13;
                        
                       

                        break;
                    }
                }
                x++;
                //tu
                  if(x+1==78 && y==14 && tries1 == 0 && field[78][14]=='|'){
                    random = rand()%6;
                     if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                      tries1++;
                      block1=1;
                } 
                //tu 
                if(x+1==84 && y==17 && tries2 == 0 && field[84][17]=='|'){
                    random = rand()%6;
                     if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                    tries2++;
                    block2=1;
                }   
                //tu
                if(x+1==49 && y==18 && tries3 ==0 && field[49][18]=='|'){
                    random = rand()%6;
                     if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                    tries3++;
                    block3=1;
                }  
                break;
            case KEY_UP: 
                player = '^';
                moves = moves+1;
              
                 if(y<=0){
                    break;
                }
                if(field[x][y-1] != ' ' &&field[x][y-1]!='!' &&field[x][y-1]!='*' &&field[x][y-1]!='O' && field[x][y-1]!='r'){
                    break;
                }
                 if(field[x][y] == '!'){
                    field[x][y] = ' ';
                }
                if(field[x][y]=='*'){
                    position = rand()%4;
                    if(position == 1){
                        
                        mvprintw(13,1,"%c", player);
                        field[88][21] = ' ';
                        mvprintw(21,88,"%c", ' ');
                        x = 1;
                        y = 13;

                        break;
                    }
                     if(position == 2){
                         
                        mvprintw(6,1,"%c", player);
                         field[88][21] = ' ';
                        mvprintw(21,88,"%c", ' ');
                        field[1][5] = ' ';
                        mvprintw(5,1,"%c", ' ');
                        x = 1;
                        y = 6;

                        break;
                    }
                     if(position == 3){
                        
                        mvprintw(6,1,"%c", player);
                         field[88][21] = ' ';
                        mvprintw(21,88,"%c", ' ');
                        x = 1;
                        y = 6;

                      

                        break;
                    }
                     if(position == 4){
                        
                        mvprintw(6,1,"%c", player);
                         field[88][21] = ' ';
                        mvprintw(21,88,"%c", ' ');
                        x = 1;
                        y = 6;

                        break;
                    }
                }
                y--;
                 if(x==8 && y-1==21 && tries6 == 0 && field[8][21]=='-'){
                    random = rand()%6;
                    if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                    tries6++;
                    block6=1;
                }  
                //tu
                if(x+1==49 && y==18 && tries3 ==0 && field[49][18]=='|'){
                    random = rand()%6;
                     if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                    tries3++;
                    block3=1;
                }  
                if(x==62 && y-1==23 && tries4 == 0 && field[62][23]=='-'){
                    random = rand()%6;
                    if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                    tries4++;
                    block4=1;
                }  
                //tu
                if(x+1==49 && y==18 && tries3 ==0 && field[49][18]=='|'){
                    random = rand()%6;
                     if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                    tries3++;
                    block3=1;
                }  
                 if(x==1 && y-1==4 && tries5 == 0 && field[1][4]=='-'){
                    random = rand()%6;
                     if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                    tries5++;
                    block5=1;
                }  
                //tu
                if(x+1==49 && y==18 && tries3 ==0 && field[49][18]=='|'){
                    random = rand()%6;
                     if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                    tries3++;
                    block3=1;
                }  
                break;
            case KEY_DOWN: 
               player = 'v';
               moves = moves+1;
                
                 
                if(y>=size_y){
                   break;
                } else if(field[x][y+1] != ' '&& field[x][y+1]!='!' && field[x][y+1]!='O' && field[x][y+1]!='r'){
                   
                    break;
                }
                 if(field[x][y] == '!'){
                    field[x][y] = ' ';
                }
                y++;
                if(x==1 && y+1==4 && tries5 == 0 && field[1][4]=='-'){
                    random = rand()%6;
                     if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                    tries5++;
                    block5=1;
                }  
                //tu
                if(x+1==49 && y==18 && tries3 ==0 && field[49][18]=='|'){
                    random = rand()%6;
                      if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                       
                     } 
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                    tries3++;
                    block3=1;
                } 
                 if(x==8 && y+1==21 && tries6 == 0 && field[8][21]=='-'){
                    random = rand()%6;
                   if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                    tries6++;
                    block6=1;
                }  
                //tu
                if(x+1==49 && y==18 && tries3 ==0 && field[49][18]=='-'){
                    random = rand()%6;
                     if(random == 1){
                        if( field[49][18] == '-' || field[49][18] == '|'){
                            field[49][18] = '!';
                            attron( COLOR_PAIR(2) );
                            mvprintw(18,49,"!");
                            attroff( COLOR_PAIR(2) );
                        }
                    }
                     if(random == 2){
                         if(  field[78][14] == '-' || field[78][14] == '|'){
                         field[78][14] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(14,78,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 3){
                         if(  field[84][17] == '-' || field[84][17] == '|'){
                         field[84][17] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(17,84,"!");
                         attroff( COLOR_PAIR(2) );
                        }
                     }
                     if(random == 4){
                         if( field[62][23] == '-' || field[62][23] == '|'){
                         field[62][23] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(23,62,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 5){
                         if(field[1][4] == '-' || field[1][4] == '|'){
                         field[1][4] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(4,1,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }
                     if(random == 6){
                         if(  field[8][21] == '-' || field[8][21] == '|'){
                         field[8][21] = '!';
                         attron( COLOR_PAIR(2) );
                         mvprintw(21,8,"!");
                         attroff( COLOR_PAIR(2) );
                         }
                    }else{
                            random--;
                        }
                    tries3++;
                    block3=1;
                }  
                break;
           
        }
        if(x==60 && y==17 && field[60][17]!=' '){
            position = rand()%4;
                    if(position == 1){
                        
                        mvprintw(1,13,"%c", player);
                        field[60][17] = ' ';
                        mvprintw(17,60,"%c", ' ');
                        x = 13;
                        y = 1;

                        
                    }
                     if(position == 2){
                         
                        mvprintw(13,1,"%c", player);
                         field[60][17] = ' ';
                        mvprintw(17,60,"%c", ' ');
                       
                        x = 1;
                        y = 13;

                       
                    }
                     if(position == 3){
                        
                        mvprintw(17,83,"%c", player);
                         field[60][17] = ' ';
                        mvprintw(17,60,"%c", ' ');
                        x = 83;
                        y = 17;

                      

                        
                    }
                     if(position == 4){
                        
                        mvprintw(17,83,"%c", player);
                         field[60][17] = ' ';
                        mvprintw(17,60,"%c", ' ');
                        x = 83;
                        y = 17;

                        
        }
        }
        if(x==11 && y==21 && field[11][21]!=' '){
            position = rand()%7;
                    if(position == 1){
                        
                        mvprintw(26,11,"%c", player);
                        field[11][21] = ' ';
                        mvprintw(21,11,"%c", ' ');
                        x = 11;
                        y = 26;

                        
                    }
                     if(position == 2){
                         
                        mvprintw(21,62,"%c", player);
                         field[11][21] = ' ';
                        mvprintw(21,11,"%c", ' ');
                       
                        x = 62;
                        y = 21;

                       
                    }
                     if(position == 3){
                        
                        mvprintw(13,1,"%c", player);
                         field[11][21] = ' ';
                        mvprintw(21,11,"%c", ' ');
                        x = 1;
                        y = 13;

                      

                        
                    }
                     if(position == 4){
                        
                        mvprintw(17,83,"%c", player);
                         field[11][21] = ' ';
                        mvprintw(21,11,"%c", ' ');
                        x = 83;
                        y = 17;

                        
        }
        }
        if(x==11&&y==22){
            clear();
            popitka++;
            if(popitka<2){

            again();
            draw2(size_x, size_y, field);
    
     
  
 
   
    moving_arrow(size_x, size_y, field, popitka);
            }else{
                run_out_of_tries();
            }
    break;
        }
        if(moves==200){
        field[2][19] = ' ';
        mvprintw(19,2," ");
       
   
        }
        if(moves==400){
 field[80][7] = ' ';
    mvprintw(7,80," ");
        }
        int tp = 0;
        if(field[x][y] == '?'){
            if(x==1&&y==19){
                tp = rand()%6;
            if(tp ==1){
                
                
                        mvprintw(22,88,"%c", player);
                         field[88][22] = ' ';
                        mvprintw(22,88,"%c", ' ');
                         field[1][19] = ' ';
                        mvprintw(19,1,"%c", ' ');
                        x = 88;
                        y = 22;

                      

                        
            }
            if(tp==2){
               
                
                        mvprintw(1,1,"%c", player);
                         field[1][1] = ' ';
                        mvprintw(1,1,"%c", ' ');
                        field[1][19] = ' ';
                        mvprintw(19,1,"%c", ' ');
                        x = 1;
                        y = 1;
            }
            if(tp ==3){
                
                moves = moves+100;
                         field[1][19] = ' ';
                        mvprintw(19,1,"%c", ' ');
                      
            }
            if(tp ==4){
                moves = 100;
                         field[1][19] = ' ';
                        mvprintw(19,1,"%c", ' ');
                      
            }
            if(tp==5){
                draw_end1();
                break;
            }
            }else{
                tp = rand()%6;
            if(tp ==1){
                
                
                        mvprintw(22,88,"%c", player);
                         field[88][22] = ' ';
                        mvprintw(22,88,"%c", ' ');
                         field[88][7] = ' ';
                        mvprintw(7,88,"%c", ' ');
                        x = 88;
                        y = 22;

                      

                        
            }
            if(tp==2){
               
                
                        mvprintw(1,1,"%c", player);
                         field[1][1] = ' ';
                        mvprintw(1,1,"%c", ' ');
                         field[88][7] = ' ';
                        mvprintw(7,88,"%c", ' ');
                        x = 1;
                        y = 1;
            }
            if(tp ==3){
                
                moves = moves+100;
                          field[88][7] = ' ';
                        mvprintw(7,88,"%c", ' ');
                      
            }
            if(tp ==4){
                moves = 100;
                         field[88][7] = ' ';
                        mvprintw(7,88,"%c", ' ');
                      
            }
            if(tp==5){
                draw_end1();
                break;
            }
            }
             
        }
        
        mvprintw(y, x, "%c", player);
        
        
         if(moves == 650){
      
        draw_end1();
    }if(moves<650&&field[x][y] == 'O'){
         draw_end2();
    }
    //mvprintw(30,90, "%d , %d, %d, %d, %d, %d", block1, block2, block3, block4, block5, block6);
    if(block1 == 1 && block2 == 1 && block3 == 1 && block4 == 1 && block5 == 1 && block6 == 1 ){
        draw_end1();
    }
    refresh();
    } while(field[x][y]!='O' && moves<=650);
   
}
