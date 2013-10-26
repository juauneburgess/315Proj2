#include <stdio.h>   
#include <stdlib.h>    
#include <time.h> 
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class AIEngine{
private:
	
	string difficulty;
	
public:

	AIEngine();
	
	vector<int> MakeMove(vector<int> possible_moves);

};