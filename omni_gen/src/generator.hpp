#include <iostream>
#include <string>
#include <list>

namespace ns_omni_gen {
class Generator {
private:

public:
	Generator();
	virtual ~Generator() {}

	void Put(std::list<std::string>& fn_info) {
		//
		// return_type->func_name->arg1_type->arg1_val->arg2_type->arg2_val...
		//
	}

	bool Test() {}
};

}

