#include "Particle.h"

//--------------------------------------------------------------
Particle::Particle(float value) {

	this->radius = 230;
	this->small_radius = 50;
	this->deg = ofRandom(0, 360);
	this->small_deg = ofRandom(0, 360);
	this->deg_span = ofRandom(0.25, 1.5);
	this->small_deg_span = ofRandom(5, 10);
	this->body_color = ofColor(0);
	this->location = this->make_point(this->radius, this->small_radius, this->deg, this->small_deg);
}

//--------------------------------------------------------------
Particle::~Particle() { }

//--------------------------------------------------------------
void Particle::update() {

	this->deg += this->deg_span;
	this->small_deg += this->small_deg_span;
	this->location = this->make_point(this->radius, this->small_radius, this->deg, this->small_deg);
}

//--------------------------------------------------------------
void Particle::draw(const vector<unique_ptr<Particle>> &particles) {

	ofSetColor(this->body_color);
	ofDrawSphere(this->location, 1.5);

	for (int i = 0; i < particles.size(); i++) {

		float distance = this->location.distance(particles[i]->get_location());
		if (distance < 50) {

			ofSetColor(this->body_color, ofMap(distance, 0, 50, 255, 0));
			ofDrawLine(this->location, particles[i]->get_location());
		}
	}
}

//--------------------------------------------------------------
ofPoint Particle::make_point(float radius, float small_radius, float deg, float small_deg) {

	float x_1 = radius * cos(deg * DEG_TO_RAD);
	float y_1 = radius * sin(deg * DEG_TO_RAD);

	float x_2 = small_radius * cos(small_deg * DEG_TO_RAD) * cos(deg * DEG_TO_RAD);
	float y_2 = small_radius * cos(small_deg * DEG_TO_RAD) * sin(deg * DEG_TO_RAD);

	float x = x_1 + x_2;
	float y = y_1 + y_2;
	float z = small_radius * sin(small_deg * DEG_TO_RAD);

	return ofPoint(x, y, z);
}

//--------------------------------------------------------------
ofPoint Particle::get_location(){

	return this->location;
}