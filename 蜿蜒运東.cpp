#include<iostream>
#include<math.h>
using namespace std;

/* 
a�C�ؽ�i��ؽ�i-1֮���ת�� ���ȣ� 
b�CeΪ0ʱ���ؽ�ת���ķ�ֵ���ȣ� 
c�C�ؽ�ת��Ƶ�ʣ�PI/S�� 
d�C��λ��ȣ� 
e�C�����ؽ�ϵͳ��ƫת�ǣ��ȣ� 
f�C����ٶ� 
i�C�ؽ��� 
*/  
class Snake  
{    
    //a=b*sin(c*t+i*d)+e  
    //a=b*(1-E^(-f*t))*sin(c*t+i*d)+e����������������ĺ���
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
    return snake.b * sin(snake.c*t + i*snake.d) + snake.e;//���Ǻ���  
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
