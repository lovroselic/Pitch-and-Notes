// https://www.codeabbey.com/index/task_view/pitch-and-notes
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <chrono>
#include <cmath>
#include <cassert>
#include <limits>
#include <numeric>
#include <tuple>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "1.0"

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

tuple<string, int> parseNote(string note);
int NoteToPitch(string rawNote, vector<float> Octave, vector<double> Ratio, vector<string> Notes);

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "Pitch and Notes v" << VERSION << "!\n\n";
	//string path = "Test.txt";
	string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	vector<string> data = splitString(raw_data[1], " ");
	//printVector(data);
	vector<int> solution;

	vector<string> Notes = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
	vector<double> Ratio(12);

	for (int i = 0; i < 12; i++) {
		Ratio.at(i) = pow(2, (i / 12.0));
	}

	vector<float> Octave(7);
	Octave.at(0) = 27.5;
	Octave.at(1) = 55;

	for (int i = 2; i < 7; i++) {
		Octave.at(i) = Octave.at(i - 1) * 2;
	}

	for (auto note : data) {
		int pitch = NoteToPitch(note, Octave, Ratio, Notes);
		solution.push_back(pitch);
	}

	cout << "\nSolution: " << joinVector(solution, " ") << endl;

	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
}

tuple<string, int> parseNote(string rawNote) {
	int octave = static_cast<int>(rawNote.back()) - 48;
	string note = rawNote.substr(0, rawNote.size() - 1);
	return make_tuple(note, octave);
}

int NoteToPitch(string rawNote, vector<float> Octave, vector<double> Ratio, vector<string> Notes) {
	vector<string> REF = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
	string note;
	int octave;
	tie(note, octave) = parseNote(rawNote);
	int notePos = find(Notes.begin(), Notes.end(), note) - Notes.begin();
	int refPos = find(REF.begin(), REF.end(), note) - REF.begin();
	if (refPos < 9) octave--;

	return round(Octave[octave] * Ratio[notePos]);
}