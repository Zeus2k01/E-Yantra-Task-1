//You are allowed to define your own function to fulfill the requirement of tasks
//Dont change the name of following functions

#include "CB_Task_1_Sandbox.h"
#include<conio.h>

#define BLACK 255
#define WHITE 0

int x = 255;

void feedback_line_sensor(int& left_sensor, int& middle_sensor, int& right_sensor) {
	left_sensor = ADC_Conversion(1);
	middle_sensor = ADC_Conversion(2);
	right_sensor = ADC_Conversion(3);
}

void correction() {
	int left_sensor, middle_sensor, right_sensor;
	do
	{
		feedback_line_sensor(left_sensor, middle_sensor, right_sensor);
		forward();
		velocity(x, x);
		//printf("%d\t%d\t%d\n", left_sensor, middle_sensor, right_sensor);
	} while (left_sensor != WHITE && right_sensor != WHITE);
	//forward();
	//_delay_ms(150);
}
/*
*
* Function Name: forward_wls
* Input: node
* Output: void
* Logic: Uses white line sensors to go forward by the number of nodes specified
* Example Call: forward_wls(2); //Goes forward by two nodes
*
*/
void forward_wls(unsigned char node)
{
	int node_passed = 0, flag = 0;
	int left_sensor, middle_sensor, right_sensor;
	while (node_passed < node) {
		feedback_line_sensor(left_sensor, middle_sensor, right_sensor);
		forward();
		if (middle_sensor == BLACK && left_sensor == WHITE && right_sensor == WHITE)
			velocity(255, 255);
		else if (left_sensor == BLACK && right_sensor == WHITE) {
			velocity(127, 255);
		}
		else if (left_sensor == WHITE && right_sensor == BLACK)
			velocity(255, 127);
		if (left_sensor == BLACK && middle_sensor == BLACK && right_sensor == BLACK) {
			if (flag == 0) {
				node_passed++;
				printf("Node %d detected\n", node_passed);
				flag = 1;
			}
		}
		else
			flag = 0;
		//printf("%d\t%d\t%d\n", left_sensor, middle_sensor, right_sensor);
	}
	correction();
	stop();
}
/*
*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until black line is encountered
* Example Call: left_turn_wls(); //Turns right until black line is encountered
*
*/
void left_turn_wls(void)
{
	int left_sensor, middle_sensor, right_sensor;
	do
	{
		feedback_line_sensor(left_sensor, middle_sensor, right_sensor);
		left();
		velocity(150, 150);
		//velocity(x, x);
		//printf("%d\t%d\t%d\n", left_sensor, middle_sensor, right_sensor);
	} while (!(left_sensor == WHITE && middle_sensor == BLACK && right_sensor == WHITE));
	stop();
}

/*
*
* Function Name: right_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn right until black line is encountered
* Example Call: right_turn_wls(); //Turns right until black line is encountered
*/
void right_turn_wls(void)
{
	int left_sensor, middle_sensor, right_sensor;
	do
	{
		feedback_line_sensor(left_sensor, middle_sensor, right_sensor);
		right();
		//velocity(x, x);
		//printf("%d\t%d\t%d\n", left_sensor, middle_sensor, right_sensor);
	} while (!(left_sensor == WHITE && middle_sensor == BLACK && right_sensor == WHITE));
	stop();
}

/*
*
* Function Name: e_shape
* Input: void
* Output: void
* Logic: Use this function to make the robot trace a e shape path on the arena
* Example Call: e_shape();
*/
void e_shape(void)
{
	forward_wls(1);
	right_turn_wls();
	forward_wls(2);
	right_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
}


/*
*
* Function Name: Task_1_1
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.1 logic
* Example Call: Task_1_1();
*/
void Task_1_1(void)
{
	// Write your task 1.1 Logic here
	forward_wls(1);
	left_turn_wls();
	forward_wls(4);
	right_turn_wls();
	int x = 5, alternate = -1;
	while (x--) {
		alternate *= -1;
		forward_wls(1);
		if (alternate == -1)
			left_turn_wls();
		else if (alternate == 1)
			right_turn_wls();
	}
	forward_wls(1);
	left_turn_wls();
	//forward()
}

/*
*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.2 logic
* Example Call: Task_1_2();
*/
void Task_1_2(void)
{
	//write your task 1.2 logic here
}