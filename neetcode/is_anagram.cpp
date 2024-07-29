#include <iostream>
#include <string>
#include <algorithm>

bool is_anagram(std::string s, std::string t){
	// Check character exists
	if (s.size() == 0 || t.size() == 0){
		return false;
	}
	// check same number of characters
	if (s.size() != t.size()){
		return false;
	}
	// easy method
	// sort string, then compare letter by letter
	
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	std::transform(t.begin(), t.end(), t.begin(), ::tolower);
	std::cout << "s : " << s << std::endl;
	std::cout << "t : " << t << std::endl;
	
	// Sorting the string
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());	
	std::cout << "s : " << s << std::endl;
	std::cout << "t : " << t << std::endl;
	
	auto second_it = t.begin();
	for (auto it=s.begin(); it != s.end(); ++ it){
		// auto second_it = t.begin();
		std::cout << *it << ", " << *second_it << std::endl;
		if (*it != *second_it){
			return false;
		}
		++second_it;
	}	
	return true;
}
int main(){
	std::string s {"carrot"}, t {"ratata"};
	bool anagram_check = is_anagram(s,t);
	if (anagram_check) {
		std::cout << "Strings are anagrams" << std::endl;
	}
	else {
		std::cout << "Strings are not anagrams" << std::endl;
	}
	
	s = "racecar";
	t = "carrace";

	anagram_check = is_anagram(s,t);
	if (anagram_check) {
		std::cout << "Strings are anagrams" << std::endl;
	}
	else {
		std::cout << "Strings are not anagrams" << std::endl;
	}
	return 0;
}
