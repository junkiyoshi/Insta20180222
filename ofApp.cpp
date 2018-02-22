#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofSetLineWidth(1.2);

	for (int i = 0; i < 512; i++) {

		std::unique_ptr<Particle> particle(new Particle(i * 0.5));
		this->particles.push_back(std::move(particle));
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	for (int i = 0; i < this->particles.size(); i++) {

		this->particles[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (int i = 0; i < this->particles.size(); i++) {

		this->particles[i]->draw(this->particles);
	}
		
	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}