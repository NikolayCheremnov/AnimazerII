#include "PatternLogger.h"

// log format:
// pattern:class:method:object_id:msg
void PatternLogger::log(int l_type, string l_args)
{
	if (l_type == pl_type) {
		ofstream pl_out;
		pl_out.open(logs_path + "\\PATTERNLOGS.log", ios::app);
		vector<string> args = get_tokens(l_args, ":");
		if (args.size() == 5)
			pl_out << get_time() << "pl> " << "patt: " << args[0] <<
			" class: " << args[1] << " meth: " << args[2] <<
			" obj_id: " << args[3] << " msg: " << args[4] << endl;
		else
			pl_out << get_time() << "broken_pl> " << l_args << endl;
		pl_out.close();
	}
	else if (nextLogger != nullptr)
		nextLogger->log(l_type, l_args);
	else
		unhandled_log(l_args);
}
