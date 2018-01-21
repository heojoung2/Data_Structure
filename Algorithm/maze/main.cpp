#include "stack_linked_list.h"
#include "maze.h"

bool Is_road(int current_pos_x, int current_pos_y)
{
	if (maze[current_pos_x][current_pos_y] == 0 && 0<=current_pos_x && 0<=current_pos_y && current_pos_x<MAZE_WIDTH && current_pos_y<MAZE_HEIGHT)
		return true;
	return false;
}

void Maze_display()
{
	for (int i = 0; i < MAZE_HEIGHT; i++)
	{
		for (int j = 0; j < MAZE_WIDTH; j++)
		{
			switch (maze[i][j])
			{
			case 1:
				cout << "* ";
				break;
			case 2:
				cout << "o ";
				break;
			case 3:
				cout << "x ";
				break;
			default:
				break;
			}
			
		}
		cout << endl;
	}
}

int main()
{
	Stack stack;

	bool flag = false;
	int current_pos[2] = { 0,0 };

	maze[current_pos[0]][current_pos[1]] = 2;
	stack.Push(current_pos[0], current_pos[1]);

	while(!(current_pos[0]==MAZE_WIDTH-1 && current_pos[1]==MAZE_HEIGHT-1))
	{
		flag = false;
		for (int i = 0; i < DIRECTION; i++)
		{
			current_pos[0] += direction[i][0];
			current_pos[1] += direction[i][1];
			if (Is_road(current_pos[0], current_pos[1]))
			{
				stack.Push(current_pos[0], current_pos[1]);
				maze[current_pos[0]][current_pos[1]] = 2;
				flag = true;
				break;
			}
			else
			{
				current_pos[0] -= direction[i][0];
				current_pos[1] -= direction[i][1];
			}
		}

		if (flag == false)
		{
			maze[current_pos[0]][current_pos[1]] = 3;
			stack.Pop();
			current_pos[0] = stack.Peek().Get_pos()[0];
			current_pos[1] = stack.Peek().Get_pos()[1];
		}

		if (stack.Empty())
		{
			cout << "maze error" << endl;
			exit(1);
		}
	}
	Maze_display();

	return 0;
}

