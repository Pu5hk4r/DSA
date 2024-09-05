#include <iostream>
#include <vector>
#include <algorithm>


bool compare(std::string a, std::string b)
{
	if(a.length() == b.length()){

		return a < b;  //lexicographic
	}

	return a.length() < b.length();
}

void findsubsets(char *input,char *output,int i,int j,std::vector<std::string> &vec)
{

	//base case

	if(input[i] == '\0'){

		output[j] = '\0';

		std::string temp (output);

		vec.push_back(temp);

		return;
	}


	//rec case
	//include ith letter

	output[j] = input[i];

	findsubsets(input,output ,i+1,j+1,vec);

	//exclude ith letter

	findsubsets(input,output,i+1,j,vec);

}


int main()
{
	char input[100];

	char output[100];

	std::cout<<"enter the string "<<"\n";

	std::cin>> input;

	std::vector<std::string> vec ;

	findsubsets(input,output,0,0,vec);

	std::sort(vec.begin(),vec.end(),compare);

    for(const auto &p : vec)

    	std::cout<<p<<" ";

	return 0;
}