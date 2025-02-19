#pragma once

#include <stack>

class clsMyString {

private:
  std::stackstd::string value;
  std::stackstd::string Temp;

public:
  clsMyString() { value.push(""); }

  void SetValue(std::string value) { this->value.push(value); }

  std::string Value() { return value.top(); }

  void Undo() {
    Temp.push(value.top());
    value.pop();
  }

  void Redo() {
    value.push(Temp.top());
    Temp.pop();
  }
};
