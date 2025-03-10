#include "ladder.h"
using namespace std;

void error(string word1, string word2, string msg){
	cerr << "Error on " << word1 << ", " << word2 << ": " << msg << endl;
}
bool off_by_one(const string& longer, const string& shorter){
	int short_len = shorter.length();
	int found_diff = 0;
	for(int i=0; i<short_len; ++i)
		if(shorter[i] != longer[i+found_diff]){
			++found_diff;
			--i;
			if(found_diff > 1)
				return false;
		}
	return true;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
	int diff = str1.length() - str2.length();
	if(diff == 0){
		int len = str1.length();
		bool same = true;
		for(int i=0; i<len; ++i)
			if(str1[i] != str2[i]){
				if(same)
					same = false;
				else
					return false;
			}
		return true;
	}else if(diff == d)
		return off_by_one(str1, str2);
	else if(diff == -d)
		return off_by_one(str2, str1);
	return false;
}
bool is_adjacent(const string& word1, const string& word2){
	return edit_distance_within(word1, word2, 1);
}
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
	// Follows pseudocode, may have errors
	queue<vector<string>> ladder_queue;
	ladder_queue.push(vector<string>(1, begin_word));
	set<string> visited;
	visited.insert(begin_word);
	while(!ladder_queue.empty()){
		vector<string> ladder = ladder_queue.front();
		ladder_queue.pop();
		string last_word = ladder[ladder.size()-1];
		for(string word: word_list){
			if(is_adjacent(last_word, word) && !visited.count(word)){
				visited.insert(word);
				vector<string> new_ladder = ladder;
				new_ladder.push_back(word);
				if(word == end_word)
					return new_ladder;
				ladder_queue.push(new_ladder);
			}
		}
	}
	// return ???
	return vector<string>(0);
}
void load_words(set<string> & word_list, const string& file_name){
	ifstream infile(file_name);
	string word;
	while(infile >> word)
		word_list.insert(word);
}
void print_word_ladder(const vector<string>& ladder){
	if(ladder.size() == 0)
		cout << "No word ladder found.";
	else
		for(string word: ladder)
			cout << word << " ";
	cout << endl;
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    // my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    // my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    // my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    // my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    // my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    // my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
	vector<string> ladder1 = generate_word_ladder("cat", "dog", word_list);
	print_word_ladder(ladder1); cout << endl;
	my_assert(ladder1.size() == 4);
	vector<string> ladder2 = generate_word_ladder("marty", "curls", word_list);
	print_word_ladder(ladder2); cout << endl;
	my_assert(ladder2.size() == 6);
	vector<string> ladder3 = generate_word_ladder("code", "data", word_list);
	print_word_ladder(ladder3); cout << endl;
	my_assert(ladder3.size() == 6);
	vector<string> ladder4 = generate_word_ladder("work", "play", word_list);
	print_word_ladder(ladder4); cout << endl;
	my_assert(ladder4.size() == 6);
	vector<string> ladder5 = generate_word_ladder("sleep", "awake", word_list);
	print_word_ladder(ladder5); cout << endl;
	my_assert(ladder5.size() == 8);
	vector<string> ladder6 = generate_word_ladder("car", "cheat", word_list);
	print_word_ladder(ladder6); cout << endl;
	my_assert(ladder6.size() == 4);
}