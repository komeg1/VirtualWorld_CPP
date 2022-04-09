#include "GameFunctions.h"
#include "World.h"
#define worldX 19
#define worldY 19
using namespace std;
enum directions{
    NORTH =1,
    EAST,
    SOUTH,
    WEST
};
pair<int, int> RandomCoords(pair<int, int> coords)
{
    int randomNum = (rand() % 4) + 1;
    bool av_dir[5];
    bool flag = 0;
    CheckDir(av_dir, coords);
    while (flag == 0)
    {
        if (randomNum == NORTH && av_dir[NORTH] && coords.second!=0)
        {
            coords.second--;
            flag = 1;
        }
        else if (randomNum == EAST && av_dir[EAST] && coords.first != worldY)
        {
            coords.first++;
            flag = 1;
        }
        else if (randomNum == SOUTH && av_dir[SOUTH] && coords.second != worldX)
        {
            coords.second++;
            flag = 1;
        }
        else  if (randomNum == WEST && av_dir[WEST] && coords.first !=0)
        {
            coords.first--;
            flag = 1;
        }

        randomNum = (rand() % 4) + 1;
    }


    return coords;
}

void CheckDir(bool dir[],pair<int,int> coords) {
    if (coords.first != 0)
        dir[WEST] = true;
    else
        dir[WEST] = false;

    if (coords.first != worldX)
        dir[EAST] = true;
    else
        dir[EAST] = false;

    if (coords.second != 0)
        dir[NORTH] = true;
    else
        dir[NORTH] = false;

    if (coords.first != worldY)
        dir[SOUTH] = true;
    else
        dir[SOUTH] = false;
}


