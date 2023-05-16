#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <iostream>


#include "Vector.h"
#include "../include/RandInt.h"


using std::string;
using std::vector;
using std::sort;
using std::stringstream;
using std::setw;
using std::left;
using std::move;

class Zmogus {

protected:

    string vardas;
    string pavarde;

    Zmogus(){
        vardas = "";
        pavarde = "";
    }

    ~Zmogus(){vardas.clear();pavarde.clear();}

public:
    
    virtual string duok_var () const {return vardas;}
    virtual string duok_pav () const {return pavarde;}

};

class Studentas : Zmogus {

private:

    string vardas;
    int egz;
    double galutinis_vid;
    double galutine_med;
    vector<int> paz;

public:
    Studentas(){
        vardas = "";
        pavarde = "";
        egz = 0;
        paz.resize(1);
        paz.at(0) = 0;
    }
    
    Studentas(string v, string p, vector<int> &pa, int e){
        vardas = v;
        pavarde = p;
        egz = e;
        copy(pa.begin(), pa.end(), std::back_inserter(paz));
    }

    // Copy constructor
    Studentas(const Studentas& k){
        vardas = k.vardas;
        pavarde = k.pavarde;
        egz = k.egz;
        galutinis_vid = k.galutinis_vid;
        galutine_med = k.galutine_med;
        paz = k.paz;
    }

    // Copy assignment operator
    Studentas& operator=(const Studentas& k){
        if (this != &k){
            vardas = k.vardas;
            pavarde = k.pavarde;
            egz = k.egz;
            galutinis_vid = k.galutinis_vid;
            galutine_med = k.galutine_med;
            paz = k.paz;
        }
        return *this;
    }

    // Move constructor
    Studentas(Studentas&& k){
        vardas = move(k.vardas);
        pavarde = move(k.pavarde);
        egz = move(k.egz);
        galutinis_vid = move(k.galutinis_vid);
        galutine_med = move(k.galutine_med);
        paz = move(k.paz);
    }

    // Move assignment operator
    Studentas& operator=(Studentas&& k){
        if (this != &k){
            vardas = move(k.vardas);
            pavarde = move(k.pavarde);
            egz = move(k.egz);
            galutinis_vid = move(k.galutinis_vid);
            galutine_med = move(k.galutine_med);
            paz = move(k.paz);
        }
        return *this;
    }

    inline std::string duok_var () const {return vardas;}
    inline std::string duok_pav () const {return pavarde;}

    inline double duok_vid() const {return galutinis_vid;}
    inline double duok_med() const {return galutine_med;}

    void rask_galutinis_vid(){
        double vidurkis = std::accumulate(paz.begin(), paz.end(), 0);
        vidurkis /= paz.size();
        galutinis_vid = (0.4 * vidurkis) + (0.6 * egz);
    }

    void rask_galutine_med(){
        double g;
        std::sort(paz.begin(), paz.end());

        if (paz.size() % 2 == 0) {
            // Lyginio sk mediana
            g = (1.0 * paz.at(paz.size() / 2) + paz.at((paz.size() / 2) - 1)) / 2.0;
        } 
        else {
            // Nelyginio sk mediana
            g = paz.at((paz.size() - 1) / 2);
        }
        galutine_med = (0.4 * g) + (0.6 * egz);
    }

    stringstream duok_info_line (){
        stringstream ss;
        ss << "\n" << left << setw(15) << duok_var() << setw(15) << duok_pav();
        for (auto &p : paz){
            ss << left << setw(5) << p;
        }
        ss << left << setw(5) << egz;
        return ss;
    }

    stringstream duok_galut_line (){
        stringstream ss;
        ss << "\n" << left << setw(15) << duok_var() << setw(15) << duok_pav();

        ss << left << setw(5) << duok_vid();
        return ss;
    }

    void stud_clear(){
        paz.clear(); 
        vardas.clear();
        pavarde.clear();
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Studentas& s){
        out << "\n" << left << setw(15) << s.vardas << setw(15) << s.pavarde << left << setw(5) << s.galutinis_vid;
        return out;
    }
    
    // Destructor
    ~Studentas(){stud_clear();}

};
