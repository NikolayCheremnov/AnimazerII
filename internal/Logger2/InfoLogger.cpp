#include "InfoLogger.h"

// log format:
// info
void InfoLogger::log(int l_type, string l_args)
{
	if (l_type == il_type) {
		ofstream il_out;
		il_out.open(logs_path + "\\INFOLOGS.log", ios::app);
		il_out << get_time() << " il> " << l_args << endl;
		il_out.close();
	}
	else if (nextLogger != nullptr)
		nextLogger->log(l_type, l_args);
	else
		unhandled_log(l_args);
}