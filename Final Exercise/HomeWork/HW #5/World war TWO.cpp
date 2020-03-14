#include <stdio.h>
#include <string.h>

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

char map[100][100];
char actions[100]={};
int coin_amount = 0;

// tank's initial direction
char init_dir;
// tank's direction now
int dir_now;
// tank's center x and y
int center_x, center_y;

void decide_initial_direction()
{
    /// Decide tank's initial direction
    /// Using init_dir
    /// To determine dir_now
	if(init_dir == 'E') dir_now = 0;
	else if(init_dir == 'S') dir_now = 1;
	else if(init_dir == 'W') dir_now = 2;
	else dir_now = 3;
}

void take_a_step()
{
    if (dir_now == 3){
        if ( (map[center_x-2][center_y -1]=='#') || (map[center_x-2][center_y]=='#') || (map[center_x-2][center_y +1]=='#')) return;
        
        else if ( (map[center_x-2][center_y -1]=='^') || (map[center_x-2][center_y]=='^') || (map[center_x-2][center_y+1]=='^') ) return;
        
        else
            center_x -= 1;
    }
    else if (dir_now == 1){
        if ((map[center_x+2][center_y +1]=='#')||(map[center_x+2][center_y ]=='#')||(map[center_x+2][center_y -1]=='#') ) return;
        
        else if ((map[center_x+2][center_y +1]=='^')||(map[center_x+2][center_y ]=='^')||(map[center_x+2][center_y -1]=='^')) return;
        
        else
            center_x += 1;
    }
    else if (dir_now == 0){
        if ((map[center_x +1][center_y+2]=='#')||(map[center_x][center_y+2]=='#')||(map[center_x -1][center_y+2]=='#') ) return;
        
        else if ((map[center_x +1][center_y+2]=='^')||(map[center_x ][center_y+2]=='^')||(map[center_x -1][center_y+2]=='^')) return;
        
        else
            center_y += 1;
    }
    else if (dir_now == 2){
        if ((map[center_x ][center_y-2]=='#')||(map[center_x -1][center_y-2]=='#')||(map[center_x +1][center_y-2]=='#') ) return;
        
        else if ((map[center_x -1][center_y-2]=='^')||(map[center_x ][center_y-2]=='^')||(map[center_x +1][center_y-2]=='^')) return;
        
        else
            center_y -= 1;
    }
}

void pick_the_coins()
{
    int j, k;
    for (j = center_x - 1; j <= center_x + 1; j++){
        for (k = center_y - 1; k <= center_y + 1; k++){
            /// determine whether there are coins under the tank
			if(map[j][k]=='$'){
				coin_amount++;
				map[j][k] = '=';
			} 
        }
    }
}

void turn_right()
{
    /// Change direction depending on dir_now
    dir_now = (dir_now+1)%4;
}

 

void turn_left()
{
    /// Change direction depending on dir_now
    dir_now = (dir_now+3)%4;
}

int main()
{
    int i, j, k, rows, cols;
    int actions_number;
    int component = 0;
    int tmp;

    /// Raed problem's input
    scanf("%d %d %d %c", &rows, &cols, &actions_number, &init_dir);
    while (getchar() != '\n');
    for (i = 0; i < actions_number; i++){
        scanf("%c", &actions[i]);
    }

    /// Read map
    for (i = 1; i <= rows; i++){
        while (getchar() != '\n');
        for (j = 1; j <= cols; j++){
            scanf("%c", &map[i][j]);
            /// Find tank's center x and y
            if (((map[i][j]) == 'x') || ((map[i][j]) == 'o') || ((map[i][j]) == 'O')){
                component++;
                if (component == 5){
                    center_x = i;
                    center_y = j;
                }
            }
        }
    }

    decide_initial_direction();

    for (i = 0; i < actions_number; i++){
        if (actions[i] == 'F'){
            take_a_step();
            pick_the_coins();
        }

        else if (actions[i] == 'J'){
           /* TODO : Implement the instruction "J" here */
           if(dir_now==1 || dir_now==3) k=center_x;
           else k = center_y;
           
           tmp = coin_amount;
           
		   take_a_step();
           pick_the_coins();
           take_a_step();
           pick_the_coins();
           
           if(dir_now==1 || dir_now==3){
           	if(center_x - k == 1 || center_x - k == -1){
           		center_x = k;
				coin_amount = tmp; 
			   }
		   }
		   else{
		   	if(center_y-k==1 || center_y-k==-1){
		   		center_y = k;
		   		coin_amount = tmp;
			   }
		   }
       }         
        else{
            if (actions[i] == 'R'){
                turn_right();
            }
            if (actions[i] == 'L'){
                turn_left();
            }
        }
    }

    printf("%d\n", coin_amount);

    return 0;
}
