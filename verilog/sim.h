#include <algorithm>
#include <utility>
#include <string>
#include <unordered_set>
#include <vector>
#include "parse.h"
class sim {
public:
	virtual ~sim(){}
	sim(){}
	bool init(std::string);
	virtual std::string load(std::string)=0;
	void step();
	bool setinput(std::string, bool);
	bool getoutput(std::string, bool*);
	std::vector<std::string> getinputs();
	std::vector<std::string> getoutputs();
	std::string debug() const { return parse_debug; }
	std::vector<std::string> gettokens() {return tokens;}
private:
	std::vector<std::pair<std::string, bool>> inputs;
	std::vector<std::pair<std::string, bool>> outputs;
	std::string parse_debug;
	std::vector<std::string> tokens;
};
bool sim::init(std::string filename) {
	std::string np = load(filename);
	std::string p;
	std::unordered_set<std::string> i={filename};
	while(true){
		Parse* par = parse(tokenize(np));
		if(!par->ok()) {
			parse_debug = par->debug();
			tokens=tokenize(np);
			delete par;
			return false;
		}
		p+=np;
		np="";
		bool hi=false;
		for(Parse* c : par->children()) {
			if(c->kind()==INCLUDE) {
				if(!i.count(c->children()[0]->payload())) {
					hi=true;
					i.insert(c->children()[0]->payload());
					np+=load(c->children()[0]->payload());
				}
			}
		}
		if(!hi) {
			p+=np;
			break;
		}
	}
	Parse* par=parse(tokenize(p));
	parse_debug = par->debug();
	tokens=tokenize(p);
	if(!par->ok()) {
		delete par;
		return false;
	}
	delete par;
	return true;
}
void sim::step() {
	
}
std::vector<std::string> sim::getinputs() {
	std::vector<std::string> v;
	v.reserve(inputs.size());
	for (std::pair<std::string, bool> s : inputs) {
		v.push_back(s.first);
	}
	return v;
}
std::vector<std::string> sim::getoutputs() {
	std::vector<std::string> v;
	v.reserve(outputs.size());
	for (std::pair<std::string, bool> s : outputs) {
		v.push_back(s.first);
	}
	return v;
}
bool sim::setinput(std::string input, bool v) {
	std::vector<std::pair<std::string, bool>>::iterator i=std::find_if(inputs.begin(), inputs.end(), [input](std::pair<std::string, bool> p){return p.first==input;});
	if(i==inputs.end()) {
		return false;
	}
	i->second=v;
	return true;
}
bool sim::getoutput(std::string output, bool* v) {
	std::vector<std::pair<std::string, bool>>::iterator i=std::find_if(outputs.begin(), outputs.end(), [output](std::pair<std::string, bool> p){return p.first==output;});
	if(i==outputs.end()) {
		return false;
	}
	*v=i->second;
	return true;
}
