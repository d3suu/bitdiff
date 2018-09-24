#include <exception>

namespace exceptions{
	struct ERR_SIZE : public std::exception {
		const char * what() const throw(){
			return "Files size are different";
		}
	};
}
