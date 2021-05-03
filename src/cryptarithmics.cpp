#include <bits/stdc++.h>

const std::vector<std::string> summands {"CP", "IS", "FUN"};
const std::string solution = "TRUE";
/* Another example could be:
* {"POCO", "POCO", "POCO", "POCO", "POCO", "POCO", "POCO", "POCO", "POCO",
* "POCO", "POCO", "POCO", "POCO", "POCO", "POCO"} => "MUCHO"
*/
std::vector<std::pair<char, int>> lettersDic;

std::pair<char, int> find_el(char a){
	for(auto i : lettersDic){
		if(i.first == a){
			return i;
		}
	}
	return std::pair<char, int>('+', -7);
}

std::pair<char, int> find_el(int a){
	for(auto i : lettersDic){
		if(i.second == a){
			return i;
		}
	}
	return std::pair<char, int>('+', -1);
}

bool check_solution(){
	int sol = 0, sum = 0, tmp = 0;
	for(auto i : summands){
		for(auto j : i){
			tmp*=10;
			tmp+=find_el(j).second;
		}
		sum +=tmp;
		tmp = 0;
	}
	for(auto i : solution){
		sol*=10;
		sol+=find_el(i).second;
	}
	if(sum == sol){
		return true;
	}
	return false;
}

void printlettersDic(){
	for(auto i : lettersDic){
		std::cout << i.first <<"=" <<i.second <<" ";
	}
	std::cout << "\n";
}

bool allDefined(){
	if(find_el(-1).first == '+') return true;
	return false;
}

bool recurse(int j) {
	if(allDefined() && check_solution()){
		std::cout << "Solution found! ";
		printlettersDic();
		return true;
	}
	else if(j == lettersDic.size()){
		return false;
	}
	for(int i=0; i<10; ++i){
		if(find_el(i).first != '+') continue;
		lettersDic[j].second = i;
		recurse(j+1);
		lettersDic[j].second = -1;
	}
	return false;
}

int main(void) {
	for(auto i : summands){
		for(auto j : i){
			if (std::find(lettersDic.begin(), lettersDic.end(), std::pair<char, int>(j, -1)) == lettersDic.end())
					lettersDic.push_back(std::pair<char, int>(j, -1));
		}
	}
	for(auto i : solution){
		if (std::find(lettersDic.begin(), lettersDic.end(), std::pair<char, int>(i, -1)) == lettersDic.end())
				lettersDic.push_back(std::pair<char, int>(i, -1));
	}
	if(lettersDic.size() > 10){
		std::cout<<"Problem parameters invalid: more than 10 unknowns\n";
		return 1;
	}
	recurse(0);
	return 0;
}
