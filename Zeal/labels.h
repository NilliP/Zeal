#pragma once
#include "hook_wrapper.h"
#include "memory.h"
#include <string>

class labels
{
public:
    std::string debug_info;
    int target_label_case = 600;  // Default to 600 (off)

    void print_debug_info(std::string);
    void print_debug_info(const char* format, ...);
    bool GetLabel(int EqType, std::string& str);
    int GetGauge(int EqType, std::string& str);
    labels(class ZealService* zeal);
    ~labels();
    void callback_main();

private:
    // Any private members you might want to add
};