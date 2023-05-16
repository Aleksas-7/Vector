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
<summary> push_back spartos analizė </summary>
</details>

<details>
<summary> atminties perskirstymas </summary>
  
  20 su 1_000_000
  17 su 100_000
  14 su 10_000
  
</details>

<details>
<summary> std::vector ir Vector palyginimas v2.0 versijoje </summary>
</details>
