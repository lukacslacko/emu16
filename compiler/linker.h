#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
std::vector<uint8_t> link(std::vector<uint8_t> input) {
	std::vector<uint8_t> output;
	struct Function {
		std::vector<uint8_t> code;
		uint16_t addr;
		uint16_t cl;
		std::string name;
		std::vector<std::pair<uint16_t,std::string>> calls;
	};
	std::vector<Function> functions;
	auto it = input.begin();
	auto end = input.end();
	bool hasmain=false;
	while (it!=end) {
		uint16_t ns;
		ns = *it++<<8;
		if(it==end){return output;}
		ns |= *it++;
		if(it==end){return output;}
		uint16_t nf;
		nf = *it++<<8;
		if(it==end){return output;}
		nf |= *it++;
		if(it==end){return output;}
		std::vector<std::string> strings;
		for (int i = 0;i<ns;++i) {
			std::string cs;
			char c;
			for(;;){
				c=*it++;
				if(it==end){return output;}
				if((int)c){cs+=c;}else{break;}
			}
			strings.push_back(cs);
		}
		for (int i = 0;i<nf;++i) {
			uint16_t n;
			n = *it++<<8;
			if(it==end){return output;}
			n |= *it++;
			if(it==end){return output;}
			if(n>ns){return output;}
			if(std::find_if(functions.begin(),functions.end(),[&](Function f){return f.name==strings[n];})!=functions.end()) {
				return output;
			}
			uint16_t cl;
			cl = *it++<<8;
			if(it==end){return output;}
			cl |= *it++;
			if(it==end){return output;}
			if(strings[n]=="main"){
				hasmain=true;
			}
			Function cf;
			cf.cl=cl;
			cf.code.resize(cl);
			for (int i=0;i<cl;++i){
				uint8_t b;
				b=*it++;
				if(it==end){return output;}
				cf.code[i]=b;
			}
			cf.name=strings[n];
			uint16_t nc;
			nc = *it++<<8;
			if(it==end){return output;}
			nc |= *it++;
			for(int j=0;j<nc;++j){
				if(it==end){return output;}
				uint16_t cn;
				cn = *it++<<8;
				if(it==end){return output;}
				cn |= *it++;
				if(cn>ns){return output;}
				if(it==end){return output;}
				uint16_t a;
				a = *it++<<8;
				if(it==end){return output;}
				a |= *it++;
				if(a>=(cl-1)){return output;}
				cf.calls.push_back(std::pair<uint16_t,std::string>(a,strings[cn]));
			}
			functions.push_back(cf);
		}
	}
	if(!hasmain){
		return output;
	}
	std::vector<std::string> usedfunctions = {"main"};
	std::vector<std::string> nr = {"main"};
	std::vector<std::string> cr;
	while (!nr.empty()) {
		cr=nr;
		nr.clear();
		for (auto cf : cr) {
			for (auto cc : (*std::find_if(functions.begin(),functions.end(),[&](Function f){return f.name==cf;})).calls) {
				if(std::find(usedfunctions.begin(),usedfunctions.end(),cc.second)==usedfunctions.end()) {
					usedfunctions.push_back(cc.second);
					nr.push_back(cc.second);
				}
			}
		}
	}
	uint16_t ca = 0;
	for (auto p : usedfunctions) {
		Function& cf = *std::find_if(functions.begin(),functions.end(),[&](Function f){return f.name==p;});
		cf.addr=ca;
		ca+=cf.cl;
	}
	for (auto p : usedfunctions) {
		Function& cf = *std::find_if(functions.begin(),functions.end(),[&](Function f){return f.name==p;});
		for (std::pair<uint16_t, std::string> cc : cf.calls) {
			uint16_t addr = (*std::find_if(functions.begin(),functions.end(),[&](Function f){return f.name==cc.second;})).addr-cc.first-(uint16_t)2-cf.addr;
			cf.code[cc.first]=addr>>8;
			cf.code[cc.first+1]=addr;
		}
	}
	output.resize(ca);
	ca=0;
	for (auto p : usedfunctions) {
		Function& cf = *std::find_if(functions.begin(),functions.end(),[&](Function f){return f.name==p;});
		for (int i = 0;i<cf.cl;++i) {
			output[ca+i]=cf.code[i];
		}
		ca+=cf.cl;
	}
	return output;
}
