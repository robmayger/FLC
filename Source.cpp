// FLC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Fuzzy.h"
#include "Aria.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//Fuzzy Logic Controller

int main(int argc, char **argv)
{
	double ref_topology[3][3] = { { 0, 200, 400 },
	{ 300, 500, 700 },
	{ 600, 800, 5000 } };

	double oa_topology[3][3] = { { 0, 800, 1000 },
	{ 800, 1000, 1200 },
	{ 1000, 1200, 5000 } };

	Fuzzy right_edge_follow = Fuzzy(ref_topology);
	Fuzzy obstacle_avoid = Fuzzy(oa_topology);

	vector<double> inputs;
	double input;
	double lws;
	double rws;

	Aria::init();
	ArRobot robot;
	ArPose pose;

	ArArgumentParser argParser(&argc, argv);
	argParser.loadDefaultArguments();

	ArRobotConnector robotConnector(&argParser, &robot);

	if (robotConnector.connectRobot())
		cout << "Robot Connected!" << endl;

	robot.runAsync(false);
	robot.lock();
	robot.enableMotors();
	robot.unlock();

	ArSensorReading *sonarSensor[8];

	double sonarRange[8];
	double sumSonar[8];
	double count;

	while (true) {
		count = 0;
		for (int i = 0; i < 8; i++) {
			sumSonar[i] = 0;
		}
		while (count < 5) {
			for (int i = 0; i < 8; i++)
			{
				sonarSensor[i] = robot.getSonarReading(i);
				sonarRange[i] = sonarSensor[i]->getRange();
				sumSonar[i] += sonarRange[i];
			}
			count++;
		}
		inputs.push_back(sumSonar[7]/count);
		inputs.push_back(sumSonar[6]/count);

		cout << "Sonar 6: " << sumSonar[6]/count << "  Sonar 7: " << sumSonar[7]/count << "\n";

		right_edge_follow.set_inputs(inputs);
		right_edge_follow.fuzzify();
		right_edge_follow.apply_ref_rules();
		right_edge_follow.defuzzify();
		right_edge_follow.print_info();
		right_edge_follow.clear_data();
		inputs.clear();

		inputs.push_back(sumSonar[2]/ count);
		inputs.push_back(sumSonar[4]/ count);
		inputs.push_back(sumSonar[5]/ count);

		cout << "Sonar 2: " << sumSonar[2]/count << "  Sonar 3: " << sumSonar[3]/count << "  Sonar 5: " << sumSonar[5]/count << "\n";

		obstacle_avoid.set_inputs(inputs);
		obstacle_avoid.fuzzify();
		obstacle_avoid.apply_oa_rules();
		obstacle_avoid.defuzzify();
		obstacle_avoid.print_info();
		obstacle_avoid.clear_data();
		inputs.clear();

		if (obstacle_avoid.lws > 60 && obstacle_avoid.lws < 100 && obstacle_avoid.rws > 60 && obstacle_avoid.rws < 100) {
			lws = right_edge_follow.lws;
			rws = right_edge_follow.rws;
		}
		else {
			lws = right_edge_follow.lws * 0.35 + obstacle_avoid.lws * 0.65;
			rws = right_edge_follow.rws * 0.35 + obstacle_avoid.rws * 0.65;
		}

		cout << "LWS:  " << lws << "  RWS:  " << rws << "\n";

		robot.setVel2(lws, rws);
	}
}