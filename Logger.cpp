//
// Created by Ali Mirlou on 10/15/2018.
//

#include "Logger.h"

#include <unistd.h>
#include <cstdarg>
#include <memory>

using namespace std;

string fstring(const string zcFormat, ...) {
	va_list vaArgs;
	va_start(vaArgs, zcFormat);
	char *fp = nullptr;
	__mingw_vasprintf(&fp, zcFormat.c_str(), vaArgs);
	va_end(vaArgs);
	unique_ptr<char[]> formatted(fp);
	return string(formatted.get());
}

function<void(int, string)> Logger(string name_space) {
	return [name_space_length = name_space.length(), name_space{move(name_space)}](int tabs, string s) {
		unsigned long long length = s.length();

		write(1, "[", 1);
		write(1, name_space.c_str(), static_cast<unsigned int>(name_space_length));
		write(1, "] ", 2);
		for (; tabs > 0; --tabs) write(1, "\t", 1);
		write(1, s.c_str(), static_cast<unsigned int>(length));
		write(1, "\n", 1);
	};
}
