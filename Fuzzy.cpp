
#include "Fuzzy.h"
#include <iostream>
#include <tuple>

using namespace std;

Fuzzy::Fuzzy(double(&topology)[3][3])
{
	lowRange[0] = topology[0][0]; lowRange[1] = topology[0][1], lowRange[2] = topology[0][2];
	medRange[0] = topology[1][0]; medRange[1] = topology[1][1]; medRange[2] = topology[1][2];
	highRange[0] = topology[2][0]; highRange[1] = topology[2][1]; highRange[2] = topology[2][2];
	r = Rule_Base();
}

void Fuzzy::set_inputs(vector<double> &inputs) {
	this->inputs = inputs;
	r.set_num_inputs(inputs.size());
}

void Fuzzy::membershipLow()
{
	for (int i = 0; i < inputs.size(); i++) {
		if (inputs.at(i) > lowRange[0] && inputs.at(i) <= lowRange[1])
		{
			lowFireStrength[i] = 1;
		}
		else if (inputs.at(i) > lowRange[1] && inputs.at(i) < lowRange[2])
		{
			lowFireStrength[i] = (lowRange[2] - inputs.at(i)) / (lowRange[2] - lowRange[1]);
		}
	}
}

void Fuzzy::membershipMed()
{
	for (int i = 0; i < inputs.size(); i++) {
		if (inputs.at(i) > medRange[0] && inputs.at(i) < medRange[1])
		{
			medFireStrength[i] = (inputs.at(i) - medRange[0]) / (medRange[1] - medRange[0]);
		}
		else if (inputs.at(i) >= medRange[1] && inputs.at(i) < medRange[2])
		{
			medFireStrength[i] = (medRange[2] - inputs.at(i)) / (medRange[2] - medRange[1]);
		}
	}
}

void Fuzzy::membershipHigh()
{
	for (int i = 0; i < inputs.size(); i++) {
		if (inputs.at(i) > highRange[0] && inputs.at(i) < highRange[1])
		{
			highFireStrength[i] = (inputs.at(i) - highRange[0]) / (highRange[1] - highRange[0]);
		}
		else if (inputs.at(i) >= highRange[1] && inputs.at(i) <= highRange[2])
		{
			highFireStrength[i] = 1;
		}
	}
}

void Fuzzy::fuzzify()
{
	cout << "Fuzzifying" << "\n";
	membershipLow();
	membershipMed();
	membershipHigh();
}

void Fuzzy::print_info() const
{
	cout << "\n";
	cout << "Low Firing Strength Output1: " << lowFireStrength[0] << " Low Firing Strength Output2: "
		<< lowFireStrength[1] << " Low Firing Strength Output3: " << lowFireStrength[2] << "\n";
	cout << "Med Firing Strength Output1: " << medFireStrength[0] << " Med Firing Strength Output2: "
		<< medFireStrength[1] << " Med Firing Strength Output3: " << medFireStrength[2] << "\n";
	cout << "High Firing Strength Output1: " << highFireStrength[0] << " High Firing Strength Output2: "
		<< highFireStrength[1] << " High Firing Strength Output3: " << highFireStrength[2] << "\n";
	cout << "LWS: " << lws << "         RWS: " << rws << "\n\n";
}

void Fuzzy::apply_ref_rules()
{
	r.right_edge_follow(lowFireStrength, medFireStrength, highFireStrength);
	fire_strengths_lws = r.get_fire_strengths_lws();
	fire_strengths_rws = r.get_fire_strengths_rws();
}

void Fuzzy::apply_oa_rules()
{
	r.obstacle_avoid(lowFireStrength, medFireStrength, highFireStrength);
	fire_strengths_lws = r.get_fire_strengths_lws();
	fire_strengths_rws = r.get_fire_strengths_rws();
}

void Fuzzy::apply_combiner_rules()
{
	r.combine(lowFireStrength, medFireStrength, highFireStrength);
	fire_strengths_lws = r.get_fire_strengths_lws();
	fire_strengths_rws = r.get_fire_strengths_rws();
}

double Fuzzy::calc_centre_of_gravity(char set) const {
	if (set == 'S') {
		return (slowSpeed[0] + slowSpeed[1] + slowSpeed[2]) / 3;
	}
	else if (set == 'M') {
		return (medSpeed[0] + medSpeed[1] + medSpeed[2]) / 3;
	}
	else if (set == 'F') {
		return (fastSpeed[0] + fastSpeed[1] + fastSpeed[2]) / 3;
	}
	else {
		cout << "___ERROR IN DEFUZZIFICATION___";
		return -1;
	}

}

void Fuzzy::defuzzify()
{
	double numerator = 0;
	double denominator = 0;
	for (int i = 0; i < fire_strengths_rws.size(); i++) {
		numerator += get<1>(fire_strengths_rws.at(i)) * calc_centre_of_gravity(get<0>(fire_strengths_rws.at(i)));
		denominator += get<1>(fire_strengths_rws.at(i));
	}
	rws = numerator / denominator;
	numerator = 0;
	denominator = 0;
	for (int i = 0; i < fire_strengths_lws.size(); i++) {
		numerator += get<1>(fire_strengths_lws.at(i)) * calc_centre_of_gravity(get<0>(fire_strengths_lws.at(i)));
		denominator += get<1>(fire_strengths_lws.at(i));
	}
	lws = numerator / denominator;
}

void Fuzzy::clear_data() {
	fire_strengths_lws.clear();
	fire_strengths_rws.clear();
	lowFireStrength[0] = lowFireStrength[1] = lowFireStrength[2] = 0;
	medFireStrength[0] = medFireStrength[1] = medFireStrength[2] = 0;
	highFireStrength[0] = highFireStrength[1] = highFireStrength[2] = 0;
	r.clear_data();
}