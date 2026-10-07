// COMP 2450 — Floor 6 starter
// hero/Lint.cpp — body of isBalanced.  THE WORK IS HERE (Wednesday).

#include "Lint.h"

#include "Stack.h"

namespace dungeon {

	bool isBalanced(const std::string& input) {
		Stack<char> s;
		for (char c : input) {
			switch (c) {
			case '(':
			case '[': 
			case '{':
				s.push(c); 
				break;
			case ')':
				if (s.empty() || s.top() != '(') return false;
				s.pop(); 
				break;
			case ']':
				if (s.empty() || s.top() != '[') return false;
				s.pop(); 
				break;
			case '}':
				if (s.empty() || s.top() != '{') return false;
				s.pop();
				break;
			default:
				break;
			}
		}
		return s.empty();
	}

}  // namespace dungeon
