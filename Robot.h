#pragma once
#include "Aria.h"


class Robot
{
	
public:
	Robot(int argc, char **argv);

	void sonar();

	double get_sonar_reading(int sensor);

private:
	
	ArRobot robot;
	ArPose pose;
	ArSensorReading *sonarSensor[8];

	double sonarRange[8];

};