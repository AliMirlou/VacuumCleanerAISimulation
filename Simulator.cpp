//
// Created by Ali Mirlou on 10/6/2018.
//

#include "Logger.h"
#include "Simulator.h"

static auto log = Logger("Simulator");

pair<int, int> parsePosition(string s) {
	int lon = 0, lat = 0;
	bool first = true;
	for (char i : s) {
		switch (i) {
			case ',':
			case ' ':
				first = false;
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if (first) lon = (lon * 10) + (i - 48);
				else lat = (lat * 10) + (i - 48);
			default:
				break;
		}
	}
	return make_pair(lon, lat);
}

bool Simulator::putAgent(Agent *agent, int longitude, int latitude) {
	if (environment->isValidPosition(longitude, latitude)) {
		agent->location = environment->world[longitude][latitude];
		return true;
	}
	return false;
}

bool Simulator::isDone() {
	return aliveAgentsCount == 0;
}

void Simulator::step() {
	string actionLog;
	for (auto agentPair: agents) {
		auto agent = agentPair.second;
		log(3, vformat("Agent %d is perceiving the environment...", agent->id));
		log(3, vformat("Agent %d is deciding...", agent->id));
		switch (agent->act(environment->percept(agent))) {
			case TrivialAction::left:
				actionLog = "went left";
				putAgent(agent, 0, 0);
				break;
			case TrivialAction::right:
				putAgent(agent, 0, 1);
				actionLog = "went right";
				break;
			case TrivialAction::suck:
				if (agent->location->status == TrivialStatus::dirty) {
					dirts.erase(agent->location); // TODO performance measure
				}
				agent->location->status = TrivialStatus::clean;
				actionLog = "sucked the dirt";
				break;
			case TrivialAction::no_op:
				actionLog = "decided to do nothing";
				break;
			case TrivialAction::no_battery:
				actionLog = "is out of battery";
				--aliveAgentsCount;
				break;
		}
		log(3, vformat("Agent %d %s", agent->id, actionLog.c_str()));
	}
}

Simulator::Simulator(int length, int width) {
	log(0, "Creating Environment...");
	environment = new Environment(length, width);
	log(0, "Environment created");
}

void Simulator::addAgent(int id, const function<Agent *()> &agentFactory) {
	auto agent = agentFactory();
	agents.insert(make_pair(id, agent));
}

void Simulator::removeAgent(int id) {
	delete (agents.extract(id).mapped());
}

void Simulator::initialize() {
	environment->initializeWorld();
	for (auto p: *initialState) {
		auto position = parsePosition(p.first);
		auto square = environment->world[position.first][position.second];
		square->status = p.second;
		dirts.insert(make_pair(square, true));
	}
	aliveAgentsCount = 0;
	for (auto agentPair: agents) {
		Agent *agent = agentPair.second;
		agent->reset();
		++aliveAgentsCount;
		putAgent(agent, 0, 0);
	}
}

void Simulator::run(unsigned int runs, unsigned int steps) {
	if (runs < 1 || steps < 1) {
		log(0, "Step or run cannot be less than one!");
		return;
	}
	log(0, "Starting Simulation...");
	unsigned int runCount = 0, stepCount;
	while (runCount++ < runs) {
		log(1, vformat("Simulation run No. %d...", runCount));
		log(2, "Initializing simulation...");
		initialize();
		log(2, "Running simulation...");
		stepCount = 0;
		while (stepCount++ < steps) {
			if (isDone()) {
				log(2, "Simulation ended sooner because no agents are alive anymore!");
				return;
			}
			log(2, vformat("Time step (%d):", stepCount));
			step();
		}
		log(0, "Simulation ended");
	}
}
