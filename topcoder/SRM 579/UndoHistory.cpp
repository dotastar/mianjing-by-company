#line 5 "UndoHistory.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

class UndoHistory {
public:
	// 0 = not find, other is match length
	int maxHistoryPrefix(set<string>& history, string& line, int start) {
		int end = start;
		while(end < line.size() && history.count(line.substr(start, end-start+1)) == 1) end++;
		return end-start;
	}
	int minPresses(vector <string> lines) {
		int n = 0;
		set<string> history;
		string text;		
		for(int i = 0; i < lines.size(); ++i) {
			string& line = lines[i];
			int j = 0;
			int jump = 0;
			if(line.substr(0, text.size()) == text) jump += text.size();
			int matchLengthBegin = maxHistoryPrefix(history, line, 0);
			if(jump > 0 && jump > matchLengthBegin - 2 )j = jump;
			else {
				text = line.substr(0, matchLengthBegin);
				j += matchLengthBegin;
				if(i != 0) n += 2;
			} 
			while(j < line.size()) {
				int matchLength = maxHistoryPrefix(history, line, j);
				if(matchLength <= 1) {
					n++;
					text.append(1, line[j]);
					j++;
				} else {
					n += 2;
					text.append(line, j, matchLength);
					j += matchLength;
				}
				history.insert(text);		
			}
			n++;//enter
		}
		return n;
	}
	

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
