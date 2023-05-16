#include "../include/Mylib.h"


int main(){

    char pasirinkimas;

    Vector<Studentas> st;

    do {

        cout << "\nJei norite: " << endl;
        cout << "  suvesti studentus iš duomenų failo: iveskite f" << endl;
        cout << "  išvesti studentus i out.txt faila: iveskite i" << endl;
        cout << "  sukurti atsitiktini studentu kieki: iveskite a" << endl;

        cout << "Versijos v0_4 func: " << endl;
        cout << "  sukurti atsitiktinių studentų failą, iveskite s" << endl;
        cout << "  padalinti studentu failą į galvočiu ir nuskriaustuku failus, iveskite p" << endl;

        cout << endl;
        cout << "  išeiti iš programos, iveskite n" << endl;

        pasirinkimas = duok_man_chara();

        if (pasirinkimas == 'f')
        {
            cout << "Iveskite failo pavadinima: " << endl;
            string failo_pav;
            cin >> failo_pav;

            try{
            nuskaityk(st, failo_pav);
            sort(st.begin(), (st.end()), compareByGalutinis);
            }
            catch (std::exception &e){cout << "Atsitiko problema su failo nuskaitymu: " << e.what() << endl;}
        }


        else if (pasirinkimas == 'i')
        {
            spausd_v0_2(st);
            cout << "studentai atspausdinti i faila out.txt" << endl;
        }

        else if (pasirinkimas == 'a')
        {
            cout << "Kiek namų darbų turės studentai: " << endl;
            int kiek_nd = duok_man_int(1, 20);

            cout << "Kiek atsitiktinių studentu norite sukurti?" << endl;
            int kiek = duok_man_int(1, 10000);
            prikurk_studentu(st, kiek, kiek_nd);
            //spausd_v0_1(st);
        }

        else if (pasirinkimas == 's')
        {
            cout << "Kiek namų darbų turės studentai: " << endl;
            int kiek_nd = duok_man_int(1, 20);

            cout << "Kiek studentu turėtu būti šiame faile?: " << endl;
            int kiek_st = duok_man_int(1, 10000000);

            auto p1 = std::chrono::high_resolution_clock::now();;
            sukurk_v0_4(kiek_st, kiek_nd);
            auto p2 = std::chrono::high_resolution_clock::now();;
            cout << "Failo, dydzio: " << kiek_st << " kurimas, užtruko " 
            << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(p2-p1).count() << " seconds\n";
        }

        else if (pasirinkimas == 'p')
        {
            try {

                string f_name, t;

                cout << "Iveskite studentų failo pavadinimą: " << endl;
                cin >> f_name;
                t = f_name;
                t.erase(0, 9);
                int stud_kiek = std::stoi(t);

                auto a1 = std::chrono::high_resolution_clock::now();
                nuskaityk(st, f_name);
                auto t2 = std::chrono::high_resolution_clock::now();
                cout << "!!!: Failo nuskaitytas per " << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(t2-a1).count() << " seconds\n";

                auto t11 = std::chrono::high_resolution_clock::now();
                sort(st.begin(), st.end(), compareByGalutinis);
                auto t12 = std::chrono::high_resolution_clock::now();
                cout << "!!!: Failo surikiuotas per " << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(t12-t11).count() << " seconds\n";

                auto dal1 = std::chrono::high_resolution_clock::now();
                Vector<Studentas> galvociai;
                galvociai.reserve(stud_kiek);
                Vector<Studentas>::iterator it;
                it = std::find_if(st.begin(), st.end(),  findGalvocius);
                int pr = it - st.begin() - 1;
                for (Vector<Studentas>::iterator ter = it ; ter < st.end() ; ter++){galvociai.push_back(*ter);}
                st.resize(pr);
                auto dal2 = std::chrono::high_resolution_clock::now();
                cout << "!!!: Studentai padalinti per " << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(dal2-dal1).count() << " seconds\n";

                auto t21 = std::chrono::high_resolution_clock::now();
                studentu_padalinimas(st, galvociai, stud_kiek);
                auto t22 = std::chrono::high_resolution_clock::now();
                cout << "Pdalinti studentai israsyti per " << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(t22-t21).count() << " seconds\n";

                auto a2 = std::chrono::high_resolution_clock::now();
                cout << "Visas studentu skirstymas užtruko " << 0.001 * std::chrono::duration_cast<std::chrono::milliseconds>(a2-a1).count() << " seconds\n";
            }
            catch (std::exception &e){cout << "atsitiko problema su failo nuskaitymu: " << e.what() << endl;}
        } // ~st() and ~galvociai()

        else if (pasirinkimas == 'n'){}

        else {cout << "Netaisyklinga įvestis." << endl;}


    } while (pasirinkimas != 'n');

}
