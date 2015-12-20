/*

Problem Link - http://www.spoj.com/problems/HERDING/

This problem can be solved using the Flood Fill Algorithm. Flood fill algorithm is the algorithm used
in the "color replacement tool" of any photo editting software like MS-Paint or Adobe Photoshop
to replace the pixels containing a target color with a replacement color
The Algorithm of Flood Fill algorithm goes like this :


void Flood_Fill(node,target color,replacement color)
-if node color is not equal to target color then return
-else
 * replace target color by replacement color
 * Flood-fill (one step to the west of node, target color, replacement color)
 * Flood-fill (one step to the east of node, target color, replacement color)
 * Flood-fill (one step to the north of node, target color, replacement color)
 * Flood-fill (one step to the south of node, target color, replacement color)
 * Return

*/
#include<cstdio>
using namespace std;

char grid[1000][1000];
int flag[1000][1001]={0};
int r,c,count=0,prev=0;

int flood_fill(int i,int j)
{
    //Applying Flood fill Algorithm
    if((i>=0)&&(j>=0) && (i<r)&&(j<c))
    {
        if(flag[i][j]==0)
        {
            flag[i][j]=count;
            switch(grid[i][j])
            {
                case 'N' : flood_fill(i-1,j);break;
                case 'S' : flood_fill(i+1,j);break;
                case 'E' : flood_fill(i,j+1);break;
                case 'W' : flood_fill(i,j-1);break;
            }
            flag[i][j]=count;
        }
        else
        {
            count=flag[i][j];
            return 0;
        }
    }
}

int main()
{
    scanf("%d %d",&r,&c);
    int i,j;
    for(i=0;i<r;i++)
    {
        scanf("%s",grid[i]);
    }
    //pa();
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(flag[i][j]==0)
            {
                //call Flood Fill
                //count++;
                count=prev+1;
                //printf("count is %d\n",count);
                flood_fill(i,j);
                if( prev<count )
                {
                    prev++;
                }
                //pa();
            }
        }
    }
    printf("%d\n",prev);
    return 0;
}
