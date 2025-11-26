# MiddleProject
## Divisione Lavoro
- push_back: Simone Piccinini
- pop_front: Simone Piccinini
- operator<<: Manuel Carelli
- testing: Manuel Carelli
- clear_buffer: Emanuel Huber
- get_reading: Emanuel Huber

## Progettazione
- creazione cartella del progetto "InertialDriver" con suddivisione in sotto cartelle di file .h e file .cpp
- indviduazione classi da progettore e creazione di uno schema rappresentante il progetto
- suddivisione del carico di lavoro

### Struttura:
- Classe Misure costituita da un array con le letture di tutti i sensori, ogni lettura è organizza tramite la structure Lettura (array di lunghezza fissa uguale in numero ai 17 sensori)
    * Lettura& operator\[](int index);
    * const Lettura& operator[](int index) const;
    * std::ostream& operator<<(std::ostream& os, const Misura& m);
- Structure Lettura con 6 parametri double (yaw_v,yaw_a, pitch_v, pitch_a, roll_v, roll_a) che incpsula la lettura di un sensore
     * std::ostream& operator<<(std::ostream& os, const Lettura& l)
- Classe IntertialDriver che gestisce la lettura dai 17 sensori tramite un array circolare di dimensione stabilita BUFFER_DIM, implementato tramite la classe MyVector di Misure:
  1. private:
     * const int BUFFER_DIM_
     * MyVector\<Misure> buffer
  2. public:
     * IntertialDriver();
     * void push_back(array<Misure> array); (controllo della lunghezza = 17)
     * Measure pop_front();
     * void clear_buffer();
     * Misura get_reading(int index); (controllo dell'indice da 0 a 16)
     * std::ostream& operator<<(std::ostream& os, const InertialDriver& v);
     
- Classe test.cpp che simula la lettura di 17 sensori e che utilizza InertialDriver per organizzarli e leggerli
  
## Schema Logico
<img width="1948" height="1641" alt="Blank diagram - Page 1" src="https://github.com/user-attachments/assets/e2f1d10b-09b0-4aba-9450-1cdbdad3b705" />


