//https://www.codechef.com/problems/DIGJUMP
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<queue>

using namespace std;

bool visited[1000004];
int d[1000004];

vector<int> g[10];
queue<int> q;

int main()
{

    string s;
    cin>>s;  //Storing the input in a string s

    int u,i,length;
    length=s.size(); // the length of the input
    memset(visited, false, sizeof visited);
    //Creating the graph
    for(i=1;i<length;i++)
    {
        int value=s[i]-'0';  // converting character to integer
        g[value].push_back(i);  // storing the position (index) of each node
    }
    visited[0]=true;  // INDEX 0 is visited
    d[0]=0;   // INDEX 0 is at a distance 0
    q.push(0); // pushing the INDEX 0 in the queue
    while(!q.empty())
    {
        int index=q.front();//the first INDEX from the queue
        if(index==(length-1)) //if index = last index
        {
            break;
        }
        q.pop();  //removing the first element from the queue


        int value=s[index]-'0'; // Extracting the value from the index and converting to integer
        int vsize=g[value].size(); // Finding the size of the value from the graph. i.e. we are checking if there are
        //repeatation of the same number (value) in the input. if not then vsize = 0
        //This part is for the repeatating numbers in the input
        for(i=0;i<vsize;i++)   // accessing each INDEX having the same number and visiting them
        {

            u=g[value][i];  // Storing the INDEX (having the same "value") in u

            if(!visited[u])   // if it the index is not visited
            {
                visited[u]=true;  // marking as visited
                d[u]=d[index]+1;  // setting the correct distance (one more than the "index")
                q.push(u);     // pushing the index in the queue
            }
        }

        g[value].clear();  // clearing the value
        //This part is for visiting the  INDEX before the current index
        if(index-1>=0 && !visited[index-1]) // if the current index is not 0 and it is not visited
        {
            visited[index-1]=true;  // marking as visited
            d[index-1]=d[index]+1;  //setting the correct distance(one more than distance of "index")
            q.push(index-1);        //pushing the previous index in the queue
        }
        //This part is for visiting the INDEX after the current index
        if(index+1<length && !visited[index+1])
        {
            visited[index+1]=true; // marking as visited
            d[index+1]=d[index]+1;  // setting the correct index (one more than distance of "index")
            q.push(index+1);   // pushing the index in the queue
        }
    }

    cout<<d[length-1]<<endl;

    return 0;
}
