#include "ga_label.h"
#include "framework/ga_frame_params.h"
#include "ga_hardware.h"
#include "cpuinfo.cpp"
#include "cpuinfodelegate.cpp"
#include "systemcommand.cpp"
#include "systeminfo.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>


ga_hardware::ga_hardware() {

	
	//First make a delegate object that handles the cases where the computer has multiple CPUs
	std::unique_ptr<CPUInfoDelegate> cpuInfo = std::make_unique<CPUInfoDelegate>();

	//Then extract the separate CPUs into a vector (of CPUInfo objects)
	std::vector<CPUInfo> cpuInfoVector{ cpuInfo->cpuInfoVector() };

	//Print out the number of CPUs, directory from the delegate object
	std::cout << "This computer has " << cpuInfo->numberOfCPUInfoItems() << " CPU(s) installed" << std::endl;

	for (std::vector<CPUInfo>::const_iterator iter = cpuInfoVector.begin(); iter != cpuInfoVector.end(); iter++) {
		std::cout << "Information for CPU #" << iter->cpuNumber() + 1 << ": " << std::endl;
		std::cout << "CPU Name = " << iter->name() << std::endl;
		std::cout << "CPU Manufacturer = " << iter->manufacturer() << std::endl;
		std::cout << "Number of CPU Cores = " << iter->numberOfCores() << std::endl;
		std::cout << "Current CPU Clock Speed = " << iter->currentClockSpeed() << std::endl;
		std::cout << "CPU Architecture = " << iter->architecture() << std::endl;
		std::cout << "CPU L2 Cache Size = " << iter->L2CacheSize() << std::endl;
		std::cout << "CPU L3 Cache Size = " << iter->L3CacheSize() << std::endl;
		std::cout << "Current CPU Temperature = " << iter->currentTemperature() << std::endl;
		std::cout << std::endl;
		cpuName = iter->name();
		cpuNumber = cpuInfo->numberOfCPUInfoItems();
	}

	
};

 void ga_hardware::updateInformaiton(ga_frame_params* params)
{
	std::string st = "Here!" + cpuName;
	const char* cc = st.c_str();
	ga_label(cc, 0.0f, 15.0f, params);
	ga_label("The Button was pressed000!", 0.0f, 30.0f, params);
	ga_label("The Button was pressed111!", 0.0f, 45.0f, params);

}
