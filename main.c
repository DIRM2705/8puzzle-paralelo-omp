#include <math.h>


typedef struct {
    int x;
    int y;
} Position;

int grid[3][3];

Position desired_position(int value)
{
    Position position;
    position.x = (value - 1) / 3; // x-coordinate
    position.y = 3 - (value - 1) % 3; // y-coordinate
    return position;
}

int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int h_score()
{
    int desired_value = 1, sum = 0; // Start with the first tile
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (grid[i][j] != desired_value) {
                Position desired_pos = desired_position(grid[i][j]);
                sum += manhattan_distance(i, j, desired_pos.x, desired_pos.y);
            }
            desired_value++;
        }
    }
    return sum;
}