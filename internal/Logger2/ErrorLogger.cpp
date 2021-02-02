#include "ErrorLogger.h"

// log format:
// class:method:obj_id:error_msg
void ErrorLogger::log(int l_type, string l_args)
{
	if (l_type == el_type) {
		ofstream el_out;
		el_out.open(logs_path + "\\ERRORLOGS.log", ios::app);
		vector<string> args = get_tokens(l_args, ":");
		if (args.size() == 4)
			el_out << get_time() << "el> " << "class: " << args[0] <<
			" meth: " << args[1] << " obj_id: " << args[2] <<
			" msg: " << args[3] << endl;
		else
			el_out << get_time() << "broken_el> " << l_args << endl;
		el_out.close();
	}
	else if (nextLogger != nullptr)
		nextLogger->log(l_type, l_args);
	else
		unhandled_log(l_args);
}
