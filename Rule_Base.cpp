
#include "Rule_Base.h"
#include <vector>
#include <tuple>

Rule_Base::Rule_Base() {}

void Rule_Base::set_num_inputs(int num) {
	numInputs = num;
}

void Rule_Base::right_edge_follow(double(&low)[4], double(&med)[4],
	double(&high)[4])
{
	vector<double> memberships;
	if (low[0] > 0 && low[1] > 0) {
		memberships = { low[0], low[1] };
		low_low(memberships);
	}
	if (low[0] > 0 && med[1] > 0) {
		memberships = { low[0], med[1] };
		low_med(memberships);
	}
	if (low[0] > 0 && high[1] > 0) {
		memberships = { low[0], high[1] };
		low_high(memberships);
	}
	if (med[0] > 0 && low[1] > 0) {
		memberships = { med[0], low[1] };
		med_low(memberships);
	}
	if (med[0] > 0 && med[1] > 0) {
		memberships = { med[0], med[1] };
		med_med(memberships);
	}
	if (med[0] > 0 && high[1] > 0) {
		memberships = { med[0], high[1] };
		med_high(memberships);
	}
	if (high[0] > 0 && low[1] > 0) {
		memberships = { high[0], low[1] };
		high_low(memberships);
	}
	if (high[0] > 0 && med[1] > 0) {
		memberships = { high[0], med[1] };
		high_med(memberships);
	}
	if (high[0] > 0 && high[1] > 0) {
		memberships = { high[0], high[1] };
		high_high(memberships);
	}
}

void Rule_Base::obstacle_avoid(double(&low)[4], double(&med)[4],
	double(&high)[4])
{
	vector<double> memberships;
	if (low[0] > 0 && low[1] > 0 && low[2] > 0) {
		memberships = { low[0], low[1], low[2] };
		low_low_low(memberships);
	}
	if (low[0] > 0 && low[1] > 0 && med[2] > 0) {
		memberships = { low[0], low[1], med[2] };
		low_low_med(memberships);
	}
	if (low[0] > 0 && low[1] > 0 && high[2] > 0) {
		memberships = { low[0], low[1], high[2] };
		low_low_high(memberships);
	}
	if (low[0] > 0 && med[1] > 0 && low[2] > 0) {
		memberships = { low[0], med[1], low[2] };
		low_med_low(memberships);
	}
	if (low[0] > 0 && med[1] > 0 && med[2] > 0) {
		memberships = { low[0], med[1], med[2] };
		low_med_med(memberships);
	}
	if (low[0] > 0 && med[1] > 0 && high[2] > 0) {
		memberships = { low[0], med[1], high[2] };
		low_med_high(memberships);
	}
	if (low[0] > 0 && high[1] > 0 && low[2] > 0) {
		memberships = { low[0], high[1], low[2] };
		low_high_low(memberships);
	}
	if (low[0] > 0 && high[1] > 0 && med[2] > 0) {
		memberships = { low[0], high[1], med[2] };
		low_high_med(memberships);
	}
	if (low[0] > 0 && high[1] > 0 && high[2] > 0) {
		memberships = { low[0], high[1], high[2] };
		low_high_high(memberships);
	}
	if (med[0] > 0 && low[1] > 0 && low[2] > 0) {
		memberships = { med[0], low[1], low[2] };
		med_low_low(memberships);
	}
	if (med[0] > 0 && low[1] > 0 && med[2] > 0) {
		memberships = { med[0], low[1], med[2] };
		med_low_med(memberships);
	}
	if (med[0] > 0 && low[1] > 0 && high[2] > 0) {
		memberships = { med[0], low[1], high[2] };
		med_low_high(memberships);
	}
	if (med[0] > 0 && med[1] > 0 && low[2] > 0) {
		memberships = { med[0], med[1], low[2] };
		med_med_low(memberships);
	}
	if (med[0] > 0 && med[1] > 0 && med[2] > 0) {
		memberships = { med[0], med[1], med[2] };
		med_med_med(memberships);
	}
	if (med[0] > 0 && med[1] > 0 && high[2] > 0) {
		memberships = { med[0], med[1], high[2] };
		med_med_high(memberships);
	}
	if (med[0] > 0 && high[1] > 0 && low[2] > 0) {
		memberships = { med[0], high[1], low[2] };
		med_high_low(memberships);
	}
	if (med[0] > 0 && high[1] > 0 && med[2] > 0) {
		memberships = { med[0], high[1], med[2] };
		med_high_med(memberships);
	}
	if (med[0] > 0 && high[1] > 0 && high[2] > 0) {
		memberships = { med[0], high[1], high[2] };
		med_high_high(memberships);
	}
	if (high[0] > 0 && low[1] > 0 && low[2] > 0) {
		memberships = { high[0], low[1], low[2] };
		high_low_low(memberships);
	}
	if (high[0] > 0 && low[1] > 0 && med[2] > 0) {
		memberships = { high[0], low[1], med[2] };
		high_low_med(memberships);
	}
	if (high[0] > 0 && low[1] > 0 && high[2] > 0) {
		memberships = { high[0], low[1], high[2] };
		high_low_high(memberships);
	}
	if (high[0] > 0 && med[1] > 0 && low[2] > 0) {
		memberships = { high[0], med[1], low[2] };
		high_med_low(memberships);
	}
	if (high[0] > 0 && med[1] > 0 && med[2] > 0) {
		memberships = { high[0], med[1], med[2] };
		high_med_med(memberships);
	}
	if (high[0] > 0 && med[1] > 0 && high[2] > 0) {
		memberships = { high[0], med[1], high[2] };
		high_med_high(memberships);
	}
	if (high[0] > 0 && high[1] > 0 && low[2] > 0) {
		memberships = { high[0], high[1], low[2] };
		high_high_low(memberships);
	}
	if (high[0] > 0 && high[1] > 0 && med[2] > 0) {
		memberships = { high[0], high[1], med[2] };
		high_high_med(memberships);
	}
	if (high[0] > 0 && high[1] > 0 && high[2] > 0) {
		memberships = { high[0], high[1], high[2] };
		high_high_high(memberships);
	}
}

void Rule_Base::combine(double(&low)[4], double(&med)[4], double(&high)[4])
{

}

void Rule_Base::low_low(vector<double> &vals)
{
	//TOO CLOSE TO WALL -> TURN LEFT
	//RIGHT WHEEL MEDIUM, LEFT WHEEL SLOW
	slow_med(vals);
}
void Rule_Base::low_med(vector<double> &vals)
{
	//MOVING AWAY FROM WALL -> LEVEL OUT
	//RIGHT WHEEL SLOW, LEFT WHEEL MEDIUM
	med_slow(vals);
}
void Rule_Base::low_high(vector<double> &vals)
{
	//APPROACHING A CORNER -> SHARP TURN RIGHT
	//RIGHT WHEEL SLOW, LEFT WHEEL FAST
	fast_slow(vals);
}
void Rule_Base::med_low(vector<double> &vals)
{
	//APPROACHING OBSTACLE ON RIGHT SIDE -> SLOW TURN LEFT
	//RIGHT WHEEL MEDIUM, LEFT WHEEL SLOW
	slow_med(vals);
}
void Rule_Base::med_med(vector<double> &vals)
{
	//AT THE CORRECT DISTANCE -> NO NEED FOR ADJUSTMENT
	//RIGHT WHEEL MED, LEFT WHEEL MED
	med__med(vals);
}
void Rule_Base::med_high(vector<double> &vals)
{
	//MOVING AWAY FROM THE WALL OR FOUND A CORNER -> SHARP TURN RIGHT
	//RIGHT WHEEL SLOW, LEFT WHEEL FAST
	fast_slow(vals);
}
void Rule_Base::high_low(vector<double> &vals)
{
	//APPROACHING OBSTACLE ON RIGHT SIDE -> SLOW TURN LEFT
	//RIGHT WHEEL MEDIUM, LEFT WHEEL SLOW
	slow_med(vals);
}
void Rule_Base::high_med(vector<double> &vals)
{
	//APPROACHING WALL -> SLOW TURN LEFT TO LEVEL OUT
	//RIGHT WHEEL MEDUIM, LEFT WHEEL SLOW
	slow_med(vals);
}
void Rule_Base::high_high(vector<double> &vals)
{
	//FAR FROM WALL -> TURN RIGHT
	//RIGHT WHEEL MEDIUM, LEFT WHEEL FAST
	fast_med(vals);
}

void Rule_Base::low_low_low(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE -> SHARP TURN LEFT
	slow_fast(vals);
}
void Rule_Base::low_low_med(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE ON LEFT -> SLOW TURN RIGHT
	med_slow(vals);
}
void Rule_Base::low_low_high(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE ON LEFT -> SHARP TURN RIGHT
	fast_slow(vals);
}
void Rule_Base::low_med_low(vector<double> &vals)
{
	//OBSTACLES ON ALL SIDES -> SHARP TURN LEFT
	slow_fast(vals);
}
void Rule_Base::low_med_med(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE ON LEFT -> SLOW TURN RIGHT
	med_slow(vals);
}
void Rule_Base::low_med_high(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE ON LEFT -> FAST TURN RIGHT
	high_med(vals);
}
void Rule_Base::low_high_low(vector<double> &vals)
{
	//OBSTACLES VERY CLOSE ON EITHER SIDE -> FAST ADVANCE
	fast_fast(vals);
}
void Rule_Base::low_high_med(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE ON LEFT -> SLOW TURN RIGHT
	med_slow(vals);
}
void Rule_Base::low_high_high(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE ON LEFT -> SHARP TURN RIGHT
	fast_slow(vals);
}
void Rule_Base::med_low_low(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE ON RIGHT -> SHARP TURN LEFT
	slow_fast(vals);
}
void Rule_Base::med_low_med(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE IN FRONT -> SLOW TURN LEFT
	slow_med(vals);
}
void Rule_Base::med_low_high(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE IN FRONT -> SLOW TURN RIGHT
	med_slow(vals);
}
void Rule_Base::med_med_low(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE ON RIGHT -> SLOW TURN LEFT
	slow_med(vals);
}
void Rule_Base::med_med_med(vector<double> &vals)
{
	//OBSTACLES ON ALL SIDES -> SLOW TURN LEFT
	slow_med(vals);
}
void Rule_Base::med_med_high(vector<double> &vals)
{
	//OBSTACLES ON LEFT -> ADJUST RIGHT
	med_fast(vals);
}
void Rule_Base::med_high_low(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE ON RIGHT -> ADJUST LEFT
	slow_med(vals);
}
void Rule_Base::med_high_med(vector<double> &vals)
{
	//OBSTACLES ON EITHER SIDE -> FAST ADVANCE
	fast_fast(vals);
}
void Rule_Base::med_high_high(vector<double> &vals)
{
	//OBSTACLE ON LEFT -> ADJUST RIGHT
	fast_med(vals);
}
void Rule_Base::high_low_low(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE ON RIGHT -> SHARP TURN LEFT
	slow_fast(vals);
}
void Rule_Base::high_low_med(vector<double> &vals)
{
	//OBSTACLE IN FRONT -> SHARP TURN LEFT
	slow_fast(vals);
}
void Rule_Base::high_low_high(vector<double> &vals)
{
	//OBSTACLE IN FRONT -> SHARP TURN RIGHT
	fast_slow(vals);
}
void Rule_Base::high_med_low(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE ON RIGHT -> SHARP TURN LEFT
	slow_fast(vals);
}
void Rule_Base::high_med_med(vector<double> &vals)
{
	//OBSTACLES ON RIGHT -> SHARP LEFT
	slow_fast(vals);
}
void Rule_Base::high_med_high(vector<double> &vals)
{
	//OBSTACLE IN FRONT -> ADJUST LEFT
	slow_med(vals);
}
void Rule_Base::high_high_low(vector<double> &vals)
{
	//OBSTACLE VERY CLOSE ON RIGHT -> SHARP TURN LEFT
	slow_fast(vals);
}
void Rule_Base::high_high_med(vector<double> &vals)
{
	//OBSTACLE IN FRONT -> ADJUST LEFT
	med_fast(vals);
}
void Rule_Base::high_high_high(vector<double> &vals)
{
	//NO NEARBY OBSTRUCTIONS -> FAST ADVANCE
	fast_fast(vals);
}

void Rule_Base::slow_slow(vector<double> &vals)
{
	fire_strengths_lws.push_back(make_tuple('S', min(vals)));
	fire_strengths_rws.push_back(make_tuple('S', min(vals)));
}
void Rule_Base::slow_med(vector<double> &vals)
{
	fire_strengths_lws.push_back(make_tuple('S', min(vals)));
	fire_strengths_rws.push_back(make_tuple('M', min(vals)));
}
void Rule_Base::slow_fast(vector<double> &vals)
{
	fire_strengths_lws.push_back(make_tuple('S', min(vals)));
	fire_strengths_rws.push_back(make_tuple('F', min(vals)));
}
void Rule_Base::med_slow(vector<double> &vals)
{
	fire_strengths_lws.push_back(make_tuple('M', min(vals)));
	fire_strengths_rws.push_back(make_tuple('S', min(vals)));
}
void Rule_Base::med__med(vector<double> &vals)
{
	fire_strengths_lws.push_back(make_tuple('M', min(vals)));
	fire_strengths_rws.push_back(make_tuple('M', min(vals)));
}
void Rule_Base::med_fast(vector<double> &vals)
{
	fire_strengths_lws.push_back(make_tuple('M', min(vals)));
	fire_strengths_rws.push_back(make_tuple('F', min(vals)));
}
void Rule_Base::fast_slow(vector<double> &vals)
{
	fire_strengths_lws.push_back(make_tuple('F', min(vals)));
	fire_strengths_rws.push_back(make_tuple('S', min(vals)));
}
void Rule_Base::fast_med(vector<double> &vals)
{
	fire_strengths_lws.push_back(make_tuple('F', min(vals)));
	fire_strengths_rws.push_back(make_tuple('M', min(vals)));
}
void Rule_Base::fast_fast(vector<double> &vals)
{
	fire_strengths_lws.push_back(make_tuple('F', min(vals)));
	fire_strengths_rws.push_back(make_tuple('F', min(vals)));
}

double Rule_Base::min(vector<double> &vals) {
	double lowest = 1;
	for (int i = 0; i < vals.size(); i++) {
		if (vals.at(i) < lowest) {
			lowest = vals.at(i);
		}
	}
	return lowest;
}

vector<tuple<char, double>> &Rule_Base::get_fire_strengths_lws()
{
	return fire_strengths_lws;
}
vector<tuple<char, double>> &Rule_Base::get_fire_strengths_rws()
{
	return fire_strengths_rws;
}

void Rule_Base::clear_data() {
	fire_strengths_lws.clear();
	fire_strengths_rws.clear();
}