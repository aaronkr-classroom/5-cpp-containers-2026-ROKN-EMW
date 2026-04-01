#pragma once
//grade.h

#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"
#include <list>

using std::vector; // 추가

double grade(double, double, const vector<double>&); // &(참조) 사용하면 const
double grade(double, double, double);
double grade(const Student_info&);

bool fgrade(const Student_info&);
vector<Student_info> extract_fails(vector<Student_info>&);
list<Student_info> extract_fails(list<Student_info>&);

#endif
