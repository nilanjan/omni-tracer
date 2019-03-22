#include <iostream>
#include "omni_gen/src/generator.hpp"

int main(int argc, char* argv[]) 
{
	ns_omni_gen::Generator og = new ns_omni_gen::Generator();

	if(og.Test()) {
		std::cout<<"Test failed!"<<std::endl;
	}

	return 0;
}

