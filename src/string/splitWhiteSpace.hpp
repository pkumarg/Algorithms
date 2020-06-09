#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define SKIP_WHITE_SPACE(srcStr, iter)\
{\
    while(srcStr[iter] && isspace(srcStr[iter]))\
    {\
	iter++;\
    }\
}

void splitWhiteSpace(string srcStr,
	vector<string> &destList)
{
    int iter = 0;
    int startIdx = 0;

    // Skipp whitespaces in start first
    SKIP_WHITE_SPACE(srcStr, iter);

    startIdx = iter;

    while(srcStr[iter])
    {
	if(isspace(srcStr[iter]))
	{
	    destList.push_back(srcStr.substr(startIdx, (iter - startIdx)));

	    // Skip further whitesapces
	    SKIP_WHITE_SPACE(srcStr, iter);

	    startIdx = iter;
	}

	if(!srcStr[iter])
	    return;

	iter++;
    }

    // Add last remaining token here
    if(startIdx != iter)
	destList.push_back(srcStr.substr(startIdx, (iter - startIdx)));
}
