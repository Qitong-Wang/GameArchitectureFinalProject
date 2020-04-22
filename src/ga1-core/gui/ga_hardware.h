#include <iostream>
#include "ga_label.h"
#include "framework/ga_frame_params.h"
using namespace std;

class ga_hardware
{
private:
	vector<float> x;
	vector<float> y;
	vector<string> info;
public:
	
	ga_hardware();
	void ga_hardware_label(string information, ga_frame_params* params);
	void updateInformaiton(ga_frame_params* params);
	


};