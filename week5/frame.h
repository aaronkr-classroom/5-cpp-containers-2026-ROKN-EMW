#pragma once

#ifndef GURAD_fram_h
#define GURAD_frame_h

#include <vector>
#include <string>

using std::vector; using std::string;

string::size_type width(const vector<string>&);
vector<string> frame(const vector<string>&);

#endif
