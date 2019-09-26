#include "Robot.h"
#include "Aria.h"

#include <iostream>

using namespace std;

Robot::Robot(int argc, char **argv)
{
	Aria::init();

	ArArgumentParser argParser(&argc, argv);
	argParser.loadDefaultArguments();

	ArRobotConnector robotConnector(&argParser, &robot);

	if (robotConnector.connectRobot())
		cout << "Robot Connected!" << endl;

	robot.runAsync(false);
	robot.lock();
	robot.enableMotors();
	robot.unlock();
}

void Robot::sonar()
{
	for (int i = 0; i < 8; i++)
	{
		sonarSensor[i] = robot.getSonarReading(i);
		sonarRange[i] = sonarSensor[i]->getRange();
	}
}

double Robot::get_sonar_reading(int sensor)
{
	return sonarRange[sensor];
}


