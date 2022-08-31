#include <string>
#include<stdio.h>
#include<stdbool.h>
#include<GL/glut.h>
#include<stdlib.h>
#define INFINITY 999
#define MAX 10

int u,dest;
int arr[5],cost[MAX][MAX];

void dijkstra(int G[MAX][MAX],int startnode,int dest)
{
int distance[MAX],pred[MAX];
int visited[MAX],count,mindistance,nextnode,i,j,n=5,k;
//pred[] stores the predecessor of each node
//count gives the number of nodes seen so far
//create the cost matrix

for(i=0;i<5;i++)
    arr[i]=555;


        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

    /*cost[MAX][MAX]= 0 6 999 1 999
                    6 0 5 2 2
                    999 5 0 999 5
                    1 2 999 0 1
                    999 2 5 1 0*/
    //initialize pred[],distance[] and visited[]
        for(i=0;i<n;i++)
        {
            distance[i]=cost[startnode][i];
            pred[i]=startnode;
            visited[i]=0;
        }
        distance[startnode]=0;
        visited[startnode]=1;
        count=1;

        while(count<n-1)
        {
            mindistance=INFINITY;
            //nextnode gives the node at minimum distance
            for(i=0;i<n;i++)
                if(distance[i]<mindistance&&!visited[i])
                {
                    mindistance=distance[i];
                    nextnode=i;
                }
            //check if a better path exists through nextnode
            visited[nextnode]=1;
            for(i=0;i<n;i++)
            if(!visited[i])
            if(mindistance+cost[nextnode][i]<distance[i])
            {
                distance[i]=mindistance+cost[nextnode][i];
                pred[i]=nextnode;
            }
                count++;
        }

        //print the path and distance of each node

        k=1;
        for(i=0;i<n;i++)
        if(i==dest)
        if(i!=startnode)
        {
            j=i;
            arr[0]=i;
            do
            {
                j=pred[j];
                arr[k]=j;
                k++;
            }while(j!=startnode);
        }
}

void drawline1()
{

glEnable(GL_LINE_STIPPLE);
glColor3f(0.0,1.0,0.0);
glLineStipple(2,0x00FF);
glLineWidth(3.0);
glBegin(GL_LINES);
glVertex2d(50,100);
glVertex2d(50,200);
glEnd();
glDisable(GL_LINE_STIPPLE);

}

void drawline2()
{
glEnable(GL_LINE_STIPPLE);
glColor3f(0.0,1.0,0.0);
glLineStipple(2,0x00FF);
glLineWidth(3.0);
glBegin(GL_LINES);
glVertex2d(100,50);
glVertex2d(200,50);
glEnd();
glDisable(GL_LINE_STIPPLE);
}

void drawline3()
{
glEnable(GL_LINE_STIPPLE);
glColor3f(0.0,1.0,0.0);
glLineStipple(2,0x00FF);
glLineWidth(3.0);
glBegin(GL_LINES);
glVertex2d(100,250);
glVertex2d(200,250);
glEnd();
glDisable(GL_LINE_STIPPLE);
}

void drawline4()
{
glEnable(GL_LINE_STIPPLE);
glColor3f(0.0,1.0,0.0);
glLineStipple(2,0x00FF);
glLineWidth(3.0);
glBegin(GL_LINES);
glVertex2d(100,75);
glVertex2d(220,200);
glEnd();
glDisable(GL_LINE_STIPPLE);
}

void drawline5()
{
glEnable(GL_LINE_STIPPLE);
glColor3f(0.0,1.0,0.0);
glLineStipple(2,0x00FF);
glLineWidth(3.0);
glBegin(GL_LINES);
glVertex2d(240,200);
glVertex2d(240,100);
glEnd();
glDisable(GL_LINE_STIPPLE);
}

void drawline6()
{
glEnable(GL_LINE_STIPPLE);
glColor3f(0.0,1.0,0.0);
glLineStipple(2,0x00FF);
glLineWidth(3.0);
glBegin(GL_LINES);
glVertex2d(250,225);
glVertex2d(430,180);
glEnd();
glDisable(GL_LINE_STIPPLE);
}

void drawline7()
{
glEnable(GL_LINE_STIPPLE);
glColor3f(0.0,1.0,0.0);
glLineStipple(2,0x00FF);
glLineWidth(3.0);
glBegin(GL_LINES);
glVertex2d(250,75);
glVertex2d(430,130);
glEnd();
glDisable(GL_LINE_STIPPLE);
}

void drawlines()
{
    int i;
    for(i=0;i<5;i++)
   {
    if((arr[i]==3 && arr[i+1]==0)||(arr[i+1]==3 && arr[i]==0))
    {
        drawline1();
        glFlush();
    }

    else if((arr[i]==4 && arr[i+1]==3)||(arr[i+1]==4 && arr[i]==3))
    {
        drawline2();
    }


    else if((arr[i]==1 && arr[i+1]==0)||(arr[i+1]==1 && arr[i]==0))
    {
        drawline3();
    }


    else if((arr[i]==1 && arr[i+1]==3)||(arr[i+1]==1 && arr[i]==3))
    {
        drawline4();
    }

    else if((arr[i]==4 && arr[i+1]==1)||(arr[i+1]==4 && arr[i]==1))
    {
        drawline5();
    }


    else if((arr[i]==2 && arr[i+1]==1)||(arr[i+1]==2 && arr[i]==1))
    {
        drawline6();
    }


    else if((arr[i]==2 && arr[i+1]==4)||(arr[i+1]==2 && arr[i]==4))
    {
        drawline7();
    }


    else break;
   }
}

void glPushmatrix();

void drawText (const char *text, int length, int x, int y)
{
glMatrixMode(GL_PROJECTION);
double *matrix = new double[16];
glGetDoublev(GL_PROJECTION_MATRIX, matrix);
glLoadIdentity();
glOrtho(0,800,0,600,-5,5);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
//g1PushMatrix();
glLoadIdentity();
glRasterPos2i(x, y);
    for (int i=0; i<length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)text[i]);
    }
glPopMatrix();
glMatrixMode(GL_PROJECTION);
glLoadMatrixd(matrix);
glMatrixMode(GL_MODELVIEW);
}

void addweights()
{
    int n=5,i,j;
    char ln1,ln2,ln3,ln4,ln5,ln6,ln7;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0 && j==3)
            {
                ln1=cost[i][j]+'0';

            }
            else if(i==0 && j==1)
            {
                ln3=cost[i][j]+'0';
            }
            else if(i==1 && j==3)
            {
                ln4=cost[i][j]+'0';
            }
            else if(i==1 && j==4)
            {
               ln5=cost[i][j]+'0';
            }
            else if(i==1 && j==2)
            {
                ln6=cost[i][j]+'0';
            }
            else if(i==3 && j==4)
            {
                ln2=cost[i][j]+'0';
            }
             else if(i==4 && j==2)
            {
                ln7=cost[i][j]+'0';
            }
        }
    }

std::string l1;
l1=ln1;
glColor3f(1,0,1);
drawText(l1.data(), l1.size(),130,175);

std::string l2;
l2=ln2;
glColor3f(1,0,1);
drawText(l2.data(), l2.size(),220,100);

std::string l3;
l3=ln3;
glColor3f(1,0,1);
drawText(l3.data(), l3.size(),220,250);

std::string l4;
l4=ln4;
glColor3f(1,0,1);
drawText(l4.data(), l4.size(),235,195);

std::string l5;
l5=ln5;
glColor3f(1,0,1);
drawText(l5.data(), l5.size(),370,175);

std::string l6;
l6=ln6;
glColor3f(1,0,1);
drawText(l6.data(), l6.size(),475,240);

std::string l7;
l7=ln7;
glColor3f(1,0,1);
drawText(l7.data(), l7.size(),475,150);

}

void display()
{

glClear(GL_COLOR_BUFFER_BIT);
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(50, 50);
glVertex2f(100, 50);
glVertex2f(100, 100);
glVertex2f(50, 100);
glEnd();

glClearColor(1.0,1.0,1.0,1.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(200, 200);
glVertex2f(250, 200);
glVertex2f(250, 250);
glVertex2f(200, 250);
glEnd();

glClearColor(1.0,1.0,1.0,1.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(50, 200);
glVertex2f(100, 200);
glVertex2f(100, 250);
glVertex2f(50, 250);
glEnd();

glClearColor(1.0,1.0,1.0,1.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(200, 50);
glVertex2f(250, 50);
glVertex2f(250, 100);
glVertex2f(200, 100);
glEnd();

glClearColor(1.0,1.0,1.0,1.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(400, 130);
glVertex2f(450, 130);
glVertex2f(450, 180);
glVertex2f(400, 180);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2d(75,200);
glVertex2d(75,100);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2d(100,75);
glVertex2d(200,75);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2d(100,225);
glVertex2d(200,225);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2d(100,100);
glVertex2d(200,200);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2d(225,100);
glVertex2d(225,200);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2d(250,200);
glVertex2d(400,170);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2d(250,100);
glVertex2d(400,130);
glEnd();

drawlines();

std::string t0;
t0="NODE-0";
glColor3f(0,1,1);
drawText(t0.data(), t0.size(),80,310);

std::string t1;
t1="NODE-1";
glColor3f(0,1,1);
drawText(t1.data(), t1.size(),330,310);

std::string t2;
t2="NODE-2";
glColor3f(0,1,1);
drawText(t2.data(), t2.size(),635,235);

std::string t3;
t3="NODE-3";
glColor3f(0,1,1);
drawText(t3.data(), t3.size(),80,40);

std::string t4;
t4="NODE-4";
glColor3f(0,1,1);
drawText(t4.data(), t4.size(),330,40);

addweights();

glFlush();
}

void myinit()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,499.0,0.0,499.0);
}

int main(int argc, char** argv)
{
    int G[MAX][MAX],i,j,n=5,u,dest;
glutInit(&argc, argv);
printf("\nEnter the adjacency matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&G[i][j]);
printf("\nEnter the starting node:");
scanf("%d",&u);
printf("Enter the destination vertex");
scanf("%d",&dest);
dijkstra(G,u,dest);

printf("Path from source node %d to destination node %d is:",u,dest);
if(arr[4]!=555)
printf("%d",arr[4]);
for(i=3;i>=0;--i)
{
   if(arr[i]!=555)
   printf("->%d",arr[i]);
}
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Dijkastras Algorithm");
glutDisplayFunc(display);
myinit();
glutMainLoop();
}





