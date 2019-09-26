#pragma once

#include <vector>

using namespace std;

class Rule_Base
{
public:

	Rule_Base();

	void set_num_inputs(int num);

	void right_edge_follow(double(&low)[4], double(&med)[4], double(&high)[4]);
	void obstacle_avoid(double(&low)[4], double(&med)[4], double(&high)[4]);
	void combine(double(&low)[4], double(&med)[4], double(&high)[4]);

	vector<tuple<char, double>> &get_fire_strengths_lws();
	vector<tuple<char, double>> &get_fire_strengths_rws();

	void clear_data();



private:



	void low_low(vector<double> &vals);
	void low_med(vector<double> &vals);
	void low_high(vector<double> &vals);
	void med_low(vector<double> &vals);
	void med_med(vector<double> &vals);
	void med_high(vector<double> &vals);
	void high_low(vector<double> &vals);
	void high_med(vector<double> &vals);
	void high_high(vector<double> &vals);

	void low_low_low(vector<double> &vals);
	void low_low_med(vector<double> &vals);
	void low_low_high(vector<double> &vals);
	void low_med_low(vector<double> &vals);
	void low_med_med(vector<double> &vals);
	void low_med_high(vector<double> &vals);
	void low_high_low(vector<double> &vals);
	void low_high_med(vector<double> &vals);
	void low_high_high(vector<double> &vals);
	void med_low_low(vector<double> &vals);
	void med_low_med(vector<double> &vals);
	void med_low_high(vector<double> &vals);
	void med_med_low(vector<double> &vals);
	void med_med_med(vector<double> &vals);
	void med_med_high(vector<double> &vals);
	void med_high_low(vector<double> &vals);
	void med_high_med(vector<double> &vals);
	void med_high_high(vector<double> &vals);
	void high_low_low(vector<double> &vals);
	void high_low_med(vector<double> &vals);
	void high_low_high(vector<double> &vals);
	void high_med_low(vector<double> &vals);
	void high_med_med(vector<double> &vals);
	void high_med_high(vector<double> &vals);
	void high_high_low(vector<double> &vals);
	void high_high_med(vector<double> &vals);
	void high_high_high(vector<double> &vals);

	void slow_slow(vector<double> &vals);
	void slow_med(vector<double> &vals);
	void slow_fast(vector<double> &vals);
	void med_slow(vector<double> &vals);
	void med__med(vector<double> &vals);
	void med_fast(vector<double> &vals);
	void fast_slow(vector<double> &vals);
	void fast_med(vector<double> &vals);
	void fast_fast(vector<double> &vals);

	double min(vector<double> &vals);

	int numInputs;
	vector<tuple<char, double>> fire_strengths_lws;
	vector<tuple<char, double>> fire_strengths_rws;
};

