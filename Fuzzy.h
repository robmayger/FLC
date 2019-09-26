#pragma once

#include "Rule_Base.h"
#include <tuple>

class Fuzzy
{

public:

	Fuzzy(double(&topology)[3][3]);

	void set_inputs(vector<double> &inputs);

	void fuzzify();

	void apply_ref_rules();

	void apply_oa_rules();

	void apply_combiner_rules();

	void defuzzify();

	void clear_data();

	void print_info() const;

	double lws;
	double rws;

private:

	vector<double> inputs;

	double lowRange[3];
	double medRange[3];
	double highRange[3];

	double lowFireStrength[4] = { 0,0,0,0 };
	double medFireStrength[4] = { 0,0,0,0 };
	double highFireStrength[4] = { 0,0,0,0 };

	const double slowSpeed[3] = { 20, 40, 60 };
	const double medSpeed[3] = { 60, 80, 100 };
	const double fastSpeed[3] = { 150, 200, 250 };

	Rule_Base r;

	vector<tuple<char, double>> fire_strengths_lws;
	vector<tuple<char, double>> fire_strengths_rws;

	void membershipLow();
	void membershipMed();
	void membershipHigh();

	double calc_centre_of_gravity(char set) const;

};
