#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>

#include "../../qbAPI/src/qbmove_communications.h"

#define STIFFNESS 0.4
#define HAND_CLOSURE 18000
#define QBMOVE_FILE "../../../qbadmin/conf_files/qbmove.conf"

std::map<int, std::vector<short int>> cube_pos;
std::map<int, short int> hand_pos;

double tick2rad(short int meas)
{
	return (double(meas)) * (2.0 * M_PI) / 32768.0;
}

short int compute_cube_motor_position(double eq, double stiff, short int& th1, short int& th2)
{
	th1 = (short int)((eq + stiff) * 32768.0 / (2* M_PI));
	th2 = (short int)((eq - stiff) * 32768.0 / (2* M_PI));
}

short int compute_hand_motor_position(double eq, short int& th1)
{
	th1 = (short int)(eq*HAND_CLOSURE);
}

void activate(comm_settings* cs, int id)
{
	commActivate(cs, id, 1);
	usleep(1000);
}

void deactivate(comm_settings* cs, int id)
{
	commActivate(cs, id, 0);
	usleep(1000);
}

int main(int argc, char **argv)
{
        // here set serial port and your device id(s)
  
	//put here your serial port
	std::string serial_port  =  "/dev/ttyUSB0";   //UNIX

	std::vector<int> cube_id = {15}; // = {1,2,3,4};
	std::vector<int> hand_id;       // = {5};
	
	FILE* file;
	file = fopen(QBMOVE_FILE, "w+");
	if (file == NULL)
	{
	    std::cout<<"ERROR: Cannot open qbmove.conf"<<std::endl;
	}
	fprintf(file,"serialport %s\n", serial_port.c_str());
	fclose(file);

	std::cout<<std::endl<<"Opened serial port: "<<serial_port<<std::endl;

	int us_sleep = 10000; // ~ 100 Hz
	short int inputs[2];
	short int measurements[3];

	comm_settings comm_settings_t;

	openRS485(&comm_settings_t, serial_port.c_str(), 2000000);
	usleep(500000);

	std::cout<<std::endl;
	std::cout<<"QB Device Handler"<<std::endl;
	
	if(cube_id.size()>0)
	{
	    std::cout<<" - Cubes ("<<cube_id.size()<<") = ";

	    for(auto id:cube_id)
	    {
		    cube_pos[id] = {0,0};
		    activate(&comm_settings_t,id);
		    std::cout<<id<<", ";
	    }
	}

	if(hand_id.size()>0)
	{
	    std::cout<<std::endl<<" - Hands ("<<hand_id.size()<<") = ";
	    for(auto id:hand_id)
	    {
		    hand_pos[id]=0;
		    activate(&comm_settings_t,id);
		    std::cout<<id<<", ";
	    }
	}
	
	std::cout<<std::endl<<std::endl;

	int count=0;

	while(1)
	{
		for(auto id:cube_id)
		{
			double cube_data=sin(count*0.01);
			count++;

		        compute_cube_motor_position(cube_data,STIFFNESS,cube_pos.at(id).at(0),cube_pos.at(id).at(1));

			inputs[0] = cube_pos[id].at(0);
			inputs[1] = cube_pos[id].at(1);

			commSetInputs(&comm_settings_t, id, inputs);
			usleep(100);
			commGetMeasurements(&comm_settings_t, id, measurements);
			usleep(100);
		}

		for(auto id:hand_id)
		{
		        double hand_data=sin(count*0.01);
			count++;

		        compute_hand_motor_position(hand_data,hand_pos[id]);

			inputs[0] = hand_pos[id];
			inputs[1] = 0;

			commSetInputs(&comm_settings_t, id, inputs);
			usleep(100);
			commGetMeasurements(&comm_settings_t, id, measurements);
			usleep(100);
		}

		usleep(us_sleep);

		if(count > 1000) break;
	}

	for(auto id:cube_id)
		deactivate(&comm_settings_t,id);
	for(auto id:hand_id)
		deactivate(&comm_settings_t,id);

	closeRS485(&comm_settings_t);
	usleep(1000);

	std::cout<<"Exiting..."<<std::endl<<std::endl;

	return 0;
}