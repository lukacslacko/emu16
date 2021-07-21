#include <algorithm>
#include <utility>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class sim {
public:
	virtual ~sim(){}
	sim(std::string);
	virtual std::string load(std::string)=0;
	void step();
	bool setinput(std::string, bool);
	bool getoutput(std::string, bool*);
	std::vector<std::string> getinputs();
	std::vector<std::string> getoutputs();
private:
	std::vector<std::pair<std::string, bool>> inputs;
	std::vector<std::pair<std::string, bool>> outputs;
};
sim::sim(std::string filename) {
	
}
void sim::step() {
	
}
std::vector<std::string> sim::getinputs() {
	std::vector<std::string> v;
	v.reserve(inputs.size());
	for (std::string s : inputs) {
		v.push_back(s);
	}
	return v;
}
std::vector<std::string> sim::getoutputs() {
	std::vector<std::string> v;
	v.reserve(outputs.size());
	for (std::string s : outputs) {
		v.push_back(s);
	}
	return v;
}
bool sim::setinput(std::string input, bool v) {
	std::vector<std::pair<std::string, bool>>::iterator i=std::find(inputs.begin(), inputs.end(), input);
	if(i==inputs.end()) {
		return false;
	}
	*i=v;
	return true;
}
bool sim::setoutput(std::string output, bool* v) {
	std::vector<std::pair<std::string, bool>>::iterator i=std::find(outputs.begin(), outputs.end(), output);
	if(i==outputs.end()) {
		return false;
	}
	*v=*i;
	return true;
}
