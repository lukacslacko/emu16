#include <vector>
#include <string>

// Usage:
//
// Parse* p = parse(tokenize("..."));
// if (!p->ok()) { handle error }

enum Kind {
  PROGRAM, STATEMENT, INCLUDE, STRING, UNIT, SIM, DECL, USE, CONN, WIRE, D, F
};

class Parse {
 public:
  Parse(Kind kind) : kind_(kind), error_(false) {}
  Parse(std::string s) : kind_(STRING), payload_(s) {}
  Kind kind() const { return kind_; }

  void add(Parse* parse) { children_.push_back(parse); }
  std::vector<Parse*>& children() { return children_; }

  void set_end(int end) { end_ = end; }
  int end() const { return end_; }
  
  void set_payload(std::string payload) { payload_ = payload; }
  std::string payload() const { return payload_; }
  
  void error(std::string message, int offset) {
    error_ = true;
    error_message_ = message;
    error_offset_ = offset;
  }
  
  bool ok() const { return !error_; }
  std::string error_message() const { return error_message_; }
  int error_offset() const { return error_offset_; }

 private:
  Kind kind_;
  std::vector<Parse*> children_;
  int end_;
  std::string payload_;
  bool error_;
  std::string error_message_;
  int error_offset_;
};

std::vector<std::string> tokenize(std::string s) {
  std::vector<std::string> v;
  std::string curr;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ' ' || s[i] == '\t') {
      if (curr.size() > 0) v.push_back(curr);
      curr = "";
      continue;
    }
    if (s[i] == ',' || s[i] == ';' || s[i] == '(' || s[i] == '{' || s[i] == ')' || s[i] == '}' || s[i] == ':') {
      if (curr.size() > 0) v.push_back(curr);
      v.push_back(std::string(1, s[i]));
      curr = "";
      continue;
    }
    curr += s[i];
  }
  if (curr.size() > 0) v.push_back(curr);
  return v;
}

Parse* parse(std::vector<std::string> tokens, int offset = 0, Kind kind = PROGRAM) {
  Parse* result = new Parse(kind);
  if (kind == PROGRAM) {
    while (offset < tokens.size()) {
      if (tokens[offset] == "include") {
        Parse* p = parse(tokens, offset+1, INCLUDE);
        if (!p->ok()) return p;
        result->add(p);
        offset += p->end();
        continue;
      }
      result->error("Bad token in PROGRAM", offset);
      return result;
    }
    result->set_end(offset);
    return result;
  }
  if (kind == INCLUDE) {
    if (tokens[offset+1] != ";") {
      result->error("Missing semicolon in INCLUDE", offset+1);
      return result;
    }
    result->add(new Parse(tokens[offset]));
    return result;
  }
}
