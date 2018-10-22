#include "Logger.h"
#include "Simulator.h"

static auto log = Logger("main");

int main(int argc, char **argv) {
	log(0, "(2.9) Simple Reflex Vacuum Cleaner Agent");
	auto dirts = new unordered_map<string, TrivialStatus>;
	auto a = make_pair("0, 0", TrivialStatus::dirty), b = make_pair("0, 1", TrivialStatus::dirty);

	auto sim = new Simulator(1, 2);
	sim->initialState = dirts;
	sim->addAgent(1, [] {
		return new Agent(1, [](Percept *p) {
			if (p->status == TrivialStatus::dirty)
				return TrivialAction::suck;
			else if (p->location->longitude == 0 && p->location->latitude == 0)
				return TrivialAction::right;
			else
				return TrivialAction::left;
		});
	});

	sim->run(1, 10);

	dirts->insert(a);
	sim->run(1, 10);

	dirts->clear();
	dirts->insert(b);
	sim->run(1, 10);

	dirts->insert(a);
	sim->run(1, 10);

	sim->removeAgent(1);

	log(0, "(2.10) Simple Reflex Vacuum Cleaner Agent with movement penalty");

	return 0;
}
