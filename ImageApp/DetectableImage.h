#pragma once
#include "StatusImageI.h"
class DetectableImage :
    public StatusImageI
{
public:
    enum class Status {UNDEFINED, POSITIVE, NEGATIVE};

private:
    Status status;

public:
    DetectableImage(string ID, LoggerI* lg, Image* image, string info);

    void set_path(string path);
    void PerformImageLoad();
    void Show();
    string GetInfoStr();
    void SetInfo(string i_args);

};

