#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct myClass{
	int m_x;
	void (*Func)(struct myClass *mc, int y);
};

void add(struct myClass *mc, int y){
	mc->m_x += y;
}

void XOOR(struct myClass *mc, int y){
	mc->m_x = mc->m_x ^ y;
}

struct extendingTest{
	struct myClass *mc;
	int y;
};

int main()
{
    
    
					int first = 2;
					
					struct myClass mc;
					
					mc.Func = add;
					
					mc.m_x = first;
					
					printf("mx is: %d\n", mc.m_x);

					int addNumber = 7;
					
					
					
	mc.Func(&mc.m_x , addNumber);
	printf("add %d. now mx is %d\n\n",addNumber, mc.m_x);
	
	printf("add %d. now mx is %d\n\n",addNumber, mc.m_x);


	printf("Overriding example : addNumber() function change to xor.--\n");
	
	
	mc.m_x = first;
	
	
	mc.Func = XOOR;
	
	
	printf("%d xor %d ", mc.m_x,addNumber);
	
	
	mc.Func(&mc.m_x , addNumber);
	
	
	printf("is: %d\n",mc.m_x);
	


	mc.m_x = first;
	
	
	mc.Func = add;
	
	
	printf("\n--Extending example : \n");
	
	
	struct extendingTest et;
	
	
	et.mc = &mc;
	
	
	et.y = addNumber;
	
	
	et.mc->Func(&mc.m_x, et.y);
	
	
	
	printf("in the new struct that save var y, %d plus %d is: %d\n", first, addNumber,et.mc->m_x);
	
	
	
	
	
	printf("y Saved, var y is : %d\n", et.y);

    return 0;
}
