#include "StandardLogger2Builder.h"

void StandardLogger2Builder::MakeLoggersChain()
{
	string path = "D:\\CherepNick\\ASTU\\4_course\\7_semester\\APIPP\\AnimazerII\\AnimazerII\\logs"; // do relative path later
	pl = new PatternLogger("sl2b_builded_pl");
	pl->set_logs_path(path);
	ErrorLogger* el = new ErrorLogger("sl2b_builded_el");
	el->set_logs_path(path);
	pl->set_nextLogger(el);
	InfoLogger* il = new InfoLogger("sl2b_builded_il");
	il->set_logs_path(path);
	el->set_nextLogger(il);
}
