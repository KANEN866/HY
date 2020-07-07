#include <stdio.h>
#include <stdlib.h>
#define infinity 1000000000
#define FALSE 0
#define TRUE 1
#define  CN 6               //city numbers 城市数量   
#define  destination 3      //目的地 

int shortestPath_DIJ(int a[][CN],int n,int x)  //最短路径Dijkstra算法 
{   n = CN;
    int shortestarray[n];   //顶点A分别到每个顶点的最短路径
    int visited[n];        //标记当前顶点是否被访问过，TRUE为访问过，FALSE为无 
    int i,j,k,min=0,min_num;
    for(i=0;i<n;i++){
        shortestarray[i]=a[0][i]; 
        visited[i]=FALSE;
    }
    
    visited[0] = TRUE;
    for(i=1;i<n;i++)
     {
        min_num = infinity;    //初始化最短路径为无穷大
        for(j=0;j<n;j++)
          {
            if(shortestarray[j]<min_num && visited[j]==0)
			{                                        //判断最短路径
                min_num = shortestarray[j];
                min = j;                                //存储最短路径的顶点
            }
        }
        visited[min]=TRUE;  //修改标记
        for(k=0;k<n;k++)
         {
            if(a[min][k]+shortestarray[min] < shortestarray[k] && k!=0 && visited[k] == 0)
			{ 
                shortestarray[k] = a[min][k]+shortestarray[min]; //更新最短路径及距离 
            }
         }

    }
   return (shortestarray[x]); //返回A到顶点D的最短路径

}
int main()
{
    FILE *f = fopen("lufei.txt","r"); //读入文件 
    int a[CN][CN];
    int i,j,tem3;
    char tem1,tem2;

    for(i=0;i<CN;i++)    //初始化 
        for(j=0;j<CN;j++)
           {
            a[i][j] = infinity;
           }
           
    fscanf(f,"%c",&tem1);  //转化文件信息 
    for(i=0;i<60;i++)
      {
        fgetc(f);         //读取空格
        fscanf(f,"%c",&tem2);
        fgetc(f);
        fscanf(f,"%d",&tem3);
        fgetc(f);        //读取换行符
        if(tem1 !=' '&&tem1 != '\n'&&tem2 !=' '&&tem2 !='\n')
		{
            a[tem1-65][tem2-65]=tem3; //存入矩阵
        }
        fscanf(f,"%c",&tem1);
    }
    fclose(f);

    printf("%d",shortestPath_DIJ(a,CN,destination)); 
}
