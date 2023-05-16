#include "../include/Mylib.h"

int duok_man_int(int from, int to)
{
  int ats;
  while (true) {
    if (cin >> ats) {
      if (ats >= from && ats <= to) {
        return ats;
      }
      cout << "Iveskite skaičių nuo ";
      cout << from << " iki " << to << endl;
    } else {
      cout << "Iveskite skaičių nuo ";
      cout << from << " iki " << to << endl;
      cin.clear();
      cin.ignore(50, '\n');
    }
  }
}

char duok_man_chara() 
{
  char ats;
  while (true) {
    if (cin >> ats) {
      cin.clear();
      cin.ignore(50, '\n');
      return ats;
    } else {
      cout << "Ivestis neteisinga. " << endl;
      cin.clear();
      cin.ignore(50, '\n');
    }
  }
}

char duok_man_char(char a = '.', char b = '.', char c = '.') 
{
  char ats;
  while (true) {
    if (cin >> ats) {
      if ((ats == a || ats == b || ats == c) && (ats != '.')) {
        return ats;
      }
      cout << "Ivestis turi būti " << a << " " << b << " " << c << endl;
    } else {
      cout << "Ivestis turi būti " << a << " " << b << " " << c << endl;
      cin.clear();
      cin.ignore(50, '\n');
    }
  }
  return ats;
}





// ========================================================================= Studentai

bool findGalvocius (Studentas &t)
{
  return t.duok_vid() >= 5;
}

bool compareByGalutinis(const Studentas &a, const Studentas &b)
{
    return a.duok_vid() < b.duok_vid();
}

void prikurk_studentu (Vector<Studentas> &st, int kiek, int nd_sk) {

    const int vardu_kiekis = 3;
    string vardai_m[3] = {"Singailas", "Odisejas", "Algintas"};
    string vardai_f[3] = {"Asta", "Alfreda", "Airine"};

    string pav_m[3] = {"Alton", "Alsenas", "Jakaitis"};
    string pav_f[3] = {"Joteika", "Sousa", "Tenorio"};

    
    RandInt rnd_name{0, vardu_kiekis-1};
    RandInt rnd_mark{0, 10};
    RandInt rnd_bool{0, 1};

    string v, p;
    vector<int> pa;
    int e;

    for (int s = 0 ; s < kiek ; s++){
        if (rnd_bool()){
            v = vardai_m[rnd_name()];
            p = pav_m[rnd_name()];

            for (int i = 0; i < nd_sk; i++){
                pa.push_back(rnd_mark());
            }
            e = rnd_mark();
        }
        else{
            v = vardai_f[rnd_name()];
            p = pav_f[rnd_name()];

            for (int i = 0; i < nd_sk; i++){
                pa.push_back(rnd_mark());
            }
            e = rnd_mark();
        }
        Studentas temp(v, p, pa, e);
        temp.rask_galutinis_vid();
        temp.rask_galutine_med();
        st.push_back(temp);
        pa.clear();
        temp.stud_clear();
    }
}






