# Vector

<details>
<summary> 5 Vector clasės funkcijos </summary>
  
  1.
  ```c++
  T& operator[](size_t index){return el[index];}
  const T& operator[](size_t index)const {return el[index];}
  ```
  
  2.
  ```c++
void reserve(size_t new_cap)
{
  if (new_cap > max_size()) {throw std::length_error("length_error");}
  if (new_cap <= cap){return;}

  T* temp = new T[s];
  for (size_t i = 0 ; i < s ; ++i){temp[i] = el[i];}
  delete[] el;
  el = new T[new_cap];
  for (size_t i = 0 ; i < s ; ++i){el[i] = temp[i];}
  cap = new_cap;        
}
  ```
  
  3.
  ```c++
void push_back (const T& element) 
{
  if (s == cap){resize(cap * 2);}
                           
  if (s < cap){
    el[s] = element;
    s++;
  }
}

  ```
  
  4.
  ```c++
void pop_back() {
  if (s != 0){s--;}
}
  ```
  
  5.
  ```c++
bool empty () {return s == 0;}

void clear () {s = 0;}
  ```
  
</details>

<details>
<summary> Push_back spartos analizė </summary>
  
| push_back() | 10_000 | 100_000 | 1_000_000 | 10_000_000 |
|-------------|--------|---------|-----------|------------|
| std::vector | 0      | 0,001   | 0,013     | 0,133      |
| Vector      | 0      | 0       | 0,01      | 0,139      |
  
</details>

<details>
<summary> Atminties perskirstymas </summary>
  
  Atminties perskirtymas vyksta 20 kai failo dydis: 1_000_000
  Atminties perskirtymas vyksta 17 kai failo dydis: 100_000
  Atminties perskirtymas vyksta 14 kai failo dydis: 10_000
  
</details>

<details>
<summary> std::vector ir Vector palyginimas v2.0 versijoje </summary>
  
| Failo dydis 100_000     | std::vector | Vector |
|-------------------------|-------------|--------|
| failo sukurimas         | 0.333       | 0.351  |
| failo nuskaitymas       | 0.398       | 0.541  |
| rikiavimas              | 0.107       | 0.107  |
| konteinerio padalinimas | 0.037       | 0.063  |
| konteinerių išrašymas   | 1.484       | 1.489  |
| Visa programa           | 2.033       | 2.208  |
  
</details>
