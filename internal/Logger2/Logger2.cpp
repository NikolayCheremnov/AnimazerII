#include "Logger2.h"

// need ':' in string end
vector<string> Logger2::get_tokens(string l_args, string delimiter)
{
    vector<string> tokens;
    size_t prev = 0;
    size_t next;
    size_t delta = delimiter.length();

    while ((next = l_args.find(delimiter, prev)) != string::npos) {
        tokens.push_back(l_args.substr(prev, next - prev));
        prev = next + delta;
    }

    return tokens;
}

string Logger2::get_time()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return "<" + string(buf) + ">";
}

void Logger2::unhandled_log(string l_args)
{
    ofstream ul_out;
    ul_out.open(logs_path + "\\UNHANDLEDLOGS.log", ios::app);
    ul_out << get_time() << " ul> " << l_args << endl;
    ul_out.close();
}

Logger2::Logger2(string ID)
{
    this->ID = ID;
    logs_path = "";
    nextLogger = nullptr;
}

Logger2::~Logger2()
{
    if (nextLogger != nullptr)
        delete nextLogger;
}

bool Logger2::set_logs_path(string path)
{
    logs_path = path;
    return true;
    // later was add dir check
}
