#pragma once

#ifndef MYLIB_H
#define MYLIB_H

#include "../include/Studentas.h"

#include <algorithm>
#include <iomanip>

#include <string>
#include <vector>
#include <numeric>

#include <sstream>
#include <chrono>

using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::left;
using std::setprecision;
using std::setw;
using std::string;
using std::vector;
using std::sort;
using std::accumulate;
using std::ifstream;
using std::stringstream;
using std::swap;
using std::ofstream;

// In failai.cpp
void nuskaityk(Vector<Studentas> &st, string f_pav);

void sukurk_v0_4(int dydis, int kiek_nd);
void spausd_v0_2(Vector<Studentas> &st);
void spausd_v0_1(Vector<Studentas> &st);

void studentu_padalinimas(Vector<Studentas> &nusk, Vector<Studentas> &galv, int dydis);

// In func.cpp
int duok_man_int(int from, int to);
char duok_man_chara();
char duok_man_char(char, char, char);
// ==== stud
bool findGalvocius (Studentas &t);
bool compareByGalutinis(const Studentas &a, const Studentas &b);
void prikurk_studentu (Vector<Studentas> &st, int kiek, int nd_sk);

#endif