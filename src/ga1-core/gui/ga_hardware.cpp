#include "ga_label.h"
#include "framework/ga_frame_params.h"

#include "ga_hardware.h"
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
	info.push_back( "This computer has " + to_string( cpuInfo->numberOfCPUInfoItems())+ " CPU(s) installed" );

	for (std::vector<CPUInfo>::const_iterator iter = cpuInfoVector.begin(); iter != cpuInfoVector.end(); iter++) {
		info.push_back( "Information for CPU #" + to_string( iter->cpuNumber() + 1) + ": " );
		info.push_back( "CPU Name = " + iter->name() );
		info.push_back( "Number of CPU Cores = " + iter->numberOfCores() );
		info.push_back( "Current CPU Clock Speed = " + iter->currentClockSpeed() );
		info.push_back( "CPU Architecture = " + iter->architecture() );
		info.push_back( "CPU L2 Cache Size = " + iter->L2CacheSize() );
		info.push_back( "CPU L3 Cache Size = " + iter->L3CacheSize() );
		info.push_back( "Current CPU Temperature = " + iter->currentTemperature() );
		info.push_back("");
	}

	
	
	std::unique_ptr<RAMInfoDelegate> ramInfo = std::make_unique<RAMInfoDelegate>();
	std::vector<RAMInfo> ramInfoVector = ramInfo->ramInfoVector();
	info.push_back( "This computer has " +  to_string( ramInfo->numberOfRAMInfoItems()) + " RAM stick(s) installed" );

	for (std::vector<RAMInfo>::const_iterator iter = ramInfoVector.begin(); iter != ramInfoVector.end(); iter++) {
		info.push_back( "Information for RAM stick #" + to_string( iter->ramNumber() + 1 ) + ": " );
		info.push_back( "RAM Name = " + iter->name() );
		info.push_back( "RAM Capacity = " + iter->capacity() );
		info.push_back( "RAM Form Factor = " + iter->formFactor() );
		info.push_back( "RAM Clock Speed = " + iter->clockSpeed() );
		info.push_back("");
	}

	std::unique_ptr<GPUInfoDelegate> gpuInfo = std::make_unique<GPUInfoDelegate>();
	std::vector<GPUInfo> gpuInfoVector = gpuInfo->gpuInfoVector();
	info.push_back( "This computer has " + to_string( gpuInfo->numberOfGPUInfoItems()) + " GPU(s) installed" );
	for (std::vector<GPUInfo>::const_iterator iter = gpuInfoVector.begin(); iter != 
	gpuInfoVector.end(); iter++) {
		info.push_back( "Information for GPU #" + to_string( iter->gpuNumber() + 1 ) + ": " );
		info.push_back( "GPU Name = " + iter->name() );
		info.push_back( "GPU Adapter RAM = " + iter->adapterRAM() );
		info.push_back( "GPU Refresh Rate = " + iter->refreshRate() );
		info.push_back( "GPU Video Mode Description = " + iter->videoModeDescription() );
		info.push_back( "GPU Video Processor = " + iter->videoProcessor() );
		info.push_back("");
	}
	
	std::unique_ptr<OSInfoDelegate> osInfo = std::make_unique<OSInfoDelegate>();
	std::vector<OSInfo> osInfoVector = osInfo->osInfoVector();
	info.push_back( "This computer has " + to_string( osInfo->numberOfOSInfoItems()) + " OS(s) installed" );
	for (std::vector<OSInfo>::const_iterator iter = osInfoVector.begin(); iter != osInfoVector.end(); iter++) {
		info.push_back( "Information for OS #" + to_string( iter->osNumber() + 1 ) + ": " );
		info.push_back( "OS Name = " + iter->name() );
		info.push_back( "OS Version = " + iter->version() );
		info.push_back( "Total Virtual Memory = " + iter->totalVirtualMemory() );
		info.push_back( "Total Visible Memory = " + iter->totalVisibleMemory() );
		info.push_back( "Free Physical Memory = " + iter->freePhysicalMemory() );
		info.push_back( "Free Virtual Memory = " + iter->freeVirtualMemory() );
		info.push_back("");
	}
	float start_x = 0.0f;
	float start_y = 15.0f;
	for (int i = 0; i < info.size(); i++) {
		x.push_back(start_x);
		y.push_back(start_y);
		start_y += 15.0f;
		if (start_y >= 300.0f) {
			start_x += 100.0f;
			start_y = 15.0f;
		}
	}
	
};

void ga_hardware::ga_hardware_label(string information,ga_frame_params * params)
{
	/*
	const char* cc = information.c_str();
	y = y + 15.0f;
	if (y >= 300.0f) {
		x = x + 100.0f;
		y = 0.0f;
	}
	ga_label(cc, x, y, params);
	*/
}

 void ga_hardware::updateInformaiton(ga_frame_params* params)
{
	 for (int i = 0; i < 5; i++) {
		 ga_label(info[i].c_str(),x[i],y[i], params);
	}
	//ga_label("The Button was pressed000!", 0.0f, 30.0f, params);
	//ga_label("The Button was pressed111!", 0.0f, 45.0f, params);

}
