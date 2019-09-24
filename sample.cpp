	//Requires: String of keywords
	//Modifies: last_search Vector
	//Effects: returns the number of logs found with all keywords
int keyWordSearch(std::string& keyword) {
	last_search.clear();
	lastCategory = category_log.end();
	lastTS.first = logs.end();
	lastTS.second = logs.end();
	lastSearch = true;
	std::vector<std::string> check;
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
	auto it = keyword.begin();
	std::string dummy = "";
	while (it != keyword.end()) {
		if (isalnum(*it)) dummy += *it;
		else {
			if (dummy != "") {
				check.push_back(dummy);
				dummy = "";
			}
		}
		++it;
	}
	if (dummy != "") {
		check.push_back(dummy);
	}
	auto last = std::unique(check.begin(), check.end());
	check.erase(last, check.end());
	if (check.empty()) {
		return 0;
	}
	auto itr = keywords.find(check[0]);
	if (itr == keywords.end()) {
		return 0;
	}
	auto remove = std::unique(itr->second.begin(), itr->second.end());
	itr->second.erase(remove, itr->second.end());
	std::vector<int> ins(itr->second);
	for (int i = 1; i < int(check.size()); ++i) {
		itr = keywords.find(check[i]);
		if (itr == keywords.end()) {
			return 0;
		}
		remove = std::unique(itr->second.begin(), itr->second.end());
		itr->second.erase(remove, itr->second.end());
		auto end = std::set_intersection(ins.begin(), ins.end(), itr->second.begin(),
			itr->second.end(), ins.begin());
		ins.resize(end - ins.begin());
	}
	for (int i = 0; i < int(ins.size()); ++i) {
		last_search.push_back(ins[i]);
	}

	return int(ins.size());
}