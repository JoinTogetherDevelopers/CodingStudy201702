// author : huklee

vector<int> slice(const vector<int> &c_input, int a, int b){
	return vector<int>(c_input.begin() + a, c_input.begin() + b);
}

int vec2int(const vector<int> &c_input, int pos){
	int sum=0;
	for (int i : slice(c_input, 0, c_input.size() - pos))
		sum = i + sum*10;
	return sum;
}

int pos_count(const vector<int> &c_input, int pos, unordered_map<int, int> &ht){
	// 01. base case : size <= 1
	if (pos >= c_input.size() - 1)
		return 1;

	// 02. memoization
	if (ht.find(vec2int(c_input, pos)) != ht.end())
		return ht[vec2int(c_input, pos)];

	// 03. recursive
	if (c_input[pos] == 1){
		ht[vec2int(c_input, pos)] = pos_count(c_input, pos + 1, ht) + pos_count(c_input, pos + 2, ht);
		return ht[vec2int(c_input, pos)];
	}
	else{
		ht[vec2int(c_input, pos)] = pos_count(c_input, pos + 1, ht);
		return ht[vec2int(c_input, pos)];
	}
}

int solve(const vector<int> &input){
	// 01. convert the table
	vector<int> c_input;
	for (int i=0; i < input.size() - 1; i++)
		c_input.push_back((input[i]*10 + input[i+1] <= 34) ? 1 : 0);
	c_input.push_back(0);

	// 02. recursive call 
	unordered_map<int, int> ht;
	return pos_count(c_input, 0, ht);
}
