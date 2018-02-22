#pragma once
#include "ofMain.h"

class Particle {
public:

	Particle(float value);
	~Particle();

	void update();
	void draw(const vector<unique_ptr<Particle>> &particles);

	ofPoint make_point(float radius, float small_radius, float deg, float small_deg);
	ofPoint get_location();
private:

	float radius;
	float small_radius;
	float deg;
	float small_deg;
	float deg_span;
	float small_deg_span;

	ofColor body_color;
	ofPoint location;
};