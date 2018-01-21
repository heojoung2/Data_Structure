#define MAZE_WIDTH 8
#define MAZE_HEIGHT 8 

#define DIRECTION 4

int maze[MAZE_WIDTH][MAZE_HEIGHT] = {		//0 : road, 1 : wall
	{0,0,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,1},
	{1,1,1,0,1,1,1,1},
	{1,1,1,0,1,1,1,1},
	{1,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,0}
};

int direction[DIRECTION][2] = { {0,1},{1,0},{0,-1},{ -1,0 }};	//right, down, left, up
