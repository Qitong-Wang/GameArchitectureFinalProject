#include <iostream>
#include "ga_label.h"
#include "framework/ga_frame_params.h"
using namespace std;

class ga_hardware
{
private:
	int cpuNumber;
	string cpuName;
public:
	
	ga_hardware();
	void updateInformaiton(ga_frame_params* params);
	


};