#include "../include/Mylib.h"



void nuskaityk(Vector<Studentas> &st, string f_pav){

  std::stringstream buffer;
  ifstream fin (f_pav);
  if (!fin.is_open()){
    throw std::runtime_error("Tokio failo neradau.");
  }
  buffer << fin.rdbuf();
  fin.close();

  string line;
  int nd_sk = 0;

  getline(buffer, line);

  stringstream ss (line);
  string part;

  while (ss >> part){
    nd_sk++;
  }
  nd_sk -= 3;
  if (nd_sk == 0){
    throw std::runtime_error("Studentai irase neturi namu darbu informacijos.");
  }
  // Susiskaiciavome namu darbu sk is pirmines eil.
  
  string v, p;
  vector<int> pa;
  pa.reserve(nd_sk);
  int e;


  // capacity sz count
  int cap_count = 0;
  int cur_sz = st.capacity();
  cout << "initial cap: " << cur_sz << endl;
  //

  while(buffer){
    if(!buffer.eof()){

      getline(buffer, line);
      stringstream ss (line);
      ss >> v;
      ss >> p;

      int t;
      for (int i = 0 ; i < nd_sk ; i++){
        ss >> t;
        pa.push_back(t);
      }
      ss >> e;
      Studentas temp(v, p, pa, e);
      pa.clear();
      temp.rask_galutinis_vid();
      temp.rask_galutine_med();
      st.push_back(temp);
      if (cur_sz != st.capacity()){
        cur_sz = st.capacity();
        cap_count++;
      }
      pa.clear();
    }
    else {break;}
  }
  cout << "capacity was changed: " << cap_count << " times" << endl;
}

void spausd_v0_2(Vector<Studentas> &st){

  std::ostringstream ss;

  ofstream fout("out.txt");
  
  fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis(Vid.) / " << setw(25) << "Galutine(Med.)" << "\n";
  fout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
  string outputas;
  for (auto &s : st){
    ss << left << setw(15) << s.duok_var()  << setw(15) << s.duok_pav();
    ss << left << setw(20) << setprecision(3) << s.duok_vid();
    ss << left << setw(20) << setprecision(3) << s.duok_med();
    ss << " \n";
    outputas += ss.str();
    ss.str("");
  }
  fout << outputas;
  fout.close();
}

void spausd_v0_1(Vector<Studentas> &st) 
{
  cout << " | Jei norite matyti" << endl;
  cout << "vidurkius, iveskite v" << endl;
  cout << "medianas, iveskite m" << endl;
  char pasirinkimas = duok_man_char('v', 'm', '.');

  cout << endl << "Pavardė" << setw(10) << "Vardas";
  if (pasirinkimas == 'v') {
    cout << setw(20) << "Galutinis(Vid.)" << endl;
  } else {
    cout << setw(20) << "Galutinis(Med.)" << endl;
  }

  cout << "--------------------------------------" << endl;
  // Skaičiuojama studentu info
  double galutinis;

  // Eiti per visus studentus:
  for (auto &nr : st) {

    // Susirandu Galutini vidurki rez: (jei pasi == 'v')
    if (pasirinkimas == 'v') {
      galutinis = nr.duok_vid();
    }
    else {
      galutinis = nr.duok_med();
    }

    cout << nr.duok_pav() << setw(10) << nr.duok_var();
    cout << setw(18) << setprecision(3) << galutinis << endl;
  }
}

void sukurk_v0_4(int dydis, int kiek_nd){

  std::ostringstream ss;
  std::ostringstream nss;
  ss << dydis;
  string f_name = "studentai" + ss.str() + ".txt";
  ss.str("");

  ss << left << setw(15) << "Vardas"  << setw(15) << "Pavarde";
  for (int i = 1 ; i < kiek_nd+1 ; i++){
    nss << i;
    string n_s = "ND" + nss.str();
    ss << left << setw(5) << n_s;
    nss.str("");
  }
  ss << left << setw(5) << "Egzaminas";

  Vector<Studentas> temp(dydis);
  prikurk_studentu(temp, dydis, kiek_nd);

  string outputas = ss.str();
  ss.str("");

  ofstream fout (f_name);
  int del = 0;
  for (auto &s : temp){
    if (del == 100000){
      fout << outputas;
      outputas = "";
      del = 0;
    }
    del++;
    outputas += s.duok_info_line().str();
  }

  fout << outputas;

  fout.close();
}

void studentu_padalinimas(Vector<Studentas> &nusk, Vector<Studentas> &galv, int dydis)
{

  std::ostringstream ss;
  ss << dydis;
  string f_name_g = "galvociai" + ss.str() + ".txt";
  string f_name_n = "nuskriaustukai" + ss.str() + ".txt";

  ss.str("");
  //cout << nusk.at(0).duok_info_line().str() << endl;
  //cout << galv.at(0).duok_info_line().str() << endl;

  ofstream fout(f_name_g);
  fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis\n";
  fout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";
  ofstream foutn(f_name_n);
  foutn << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis\n";
  foutn << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";

  int count = 0;
  string outputas;

  for (auto &s : nusk){
    
    if (count == 10000){
      foutn << outputas;
      outputas = "";
      count = 0;
    }
    count++;
    outputas += s.duok_galut_line().str();
  }
  foutn << outputas;
  foutn.close();

  count = 0;
  outputas = "";

  for (auto &s : galv){
    if (count == 10000){
      fout << outputas;
      outputas = "";
      count = 0;
    }
    count++;
    outputas += s.duok_galut_line().str();
  }
  fout << outputas;
  fout.close();
}














