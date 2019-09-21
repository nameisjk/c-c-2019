#include<iostream>
#include<math.h>
using namespace std;

/* 
a–关节i与关节i-1之间的转角 （度） 
b–e为0时，关节转交的幅值（度） 
c–关节转角频率（PI/S） 
d–相位差（度） 
e–整个关节系统的偏转角（度） 
f–拟合速度 
i–关节数 
*/  
class Snake  
{    
    //a=b*sin(c*t+i*d)+e  
    //a=b*(1-E^(-f*t))*sin(c*t+i*d)+e加入无限趋近于零的函数
	public:
    	float b;  
   		float c;  
   	 	float d;  
   		float e;   
    	float t; 
    	
	void print_ang(float *buf)  
	{  
   	 	for (int i = 0; i < 12; i++)  
   	 	{  
        	cout << "ang" << i << "= " << *(buf + i) << "\t";  
    	}  
    cout << "  "<< endl;  
	}  	
	 
}; 
 
 
float get_ang(Snake snake, int i, float t)  
{  
    return snake.b * sin(snake.c*t + i*snake.d) + snake.e;//三角函数  
} 




int main()  
{  
    Snake snake;  
    snake.b = 120;      
    snake.c = 1.5;        //a=b*sin(c*t+i*d)+e  
    snake.d = 1;    
    snake.e = 0;  
    snake.t = 0.1;  
    float ang[12] = { 0,0,0,0,0,0,0,0,0,0,0 };  
    for (float t = 0; t < 100;t++)  
    {  
        for (int i = 0; i < 12; i++)  
        {  
            ang[i] = get_ang(snake, i + 1, t);  
        }  
        t += snake.t;  
        snake.print_ang(ang);  
    }  
    return 0;  
}  
