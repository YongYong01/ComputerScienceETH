1. `plain|`
  
    1. Type: `cpp|double` / Value: `cpp|1.5`
    2. Type: `cpp|bool` / Value: `cpp|1.5 == 1 (false)`
    3. Type: `cpp|doule` / Value: `cpp|0.75`
    4. Type: `cpp|int` / Value: `cpp|1/2=0`
    5. Type: `cpp|double` / Value: `cpp|-1.0`


2. ```c++ 
    // PRE: Der Wert c muss im Bereich 0 - 127 sein
    // POST: Inkrementiert den Wert auf den Index c im Vektor vec
    void add(const char c);

    // PRE: Der Wert muss im Bereich zwischen 0 - 127 sein.
    // POST: Gibt den Wert im Index c vom Vektor vec zurück
    int get(const char c) const;
    
    ```