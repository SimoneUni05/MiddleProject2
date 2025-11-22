# MiddleProject

## Progettazione
- creazione cartella del progetto "InertialDriver" con suddivisione in sotto cartelle di file .h e file .cpp
- indviduazione classi da progettore e creazione di uno schema rappresentante il progetto
- suddivisione del carico di lavoro

### Struttura:
- Classe Misure costituita da un array con le letture di tutti i sensori, ogni lettura è organizza tramite la structure Lettura (array di lunghezza fissa uguale in numero ai 17 sensori)
  2. public:
    * Lettura& operator\[](int index);
    * const Lettura& operator[](int index) const;
    * std::ostream& operator<<(std::ostream& os, const Misura& m);
- Structure Lettura con 6 parametri double (yaw_v,yaw_a, pitch_v, pitch_a, roll_v, roll_a) che incpsula la lettura di un sensore
     * std::ostream& operator<<(std::ostream& os, const Lettura& l)
- Classe IntertialDriver che gestisce la lettura dai 17 sensori tramite un array circolare di dimensione stabilita BUFFER_DIM, implementato tramite la classe MyVector di Misure:
  1. private:
     * const int BUFFER_DIM_
     * MyVector<Misure>
  2. public:
     * IntertialDriver();
     * void push_back(array<Misure> array); (controllo della lunghezza = 17)
     * Measure pop_front();
     * void clear_buffer();
     * Misura get_reading(int index); (controllo dell'indice da 0 a 16)
     * std::ostream& operator<<(std::ostream& os, const InertialDriver& v);
     
- Classe main che simula la lettura di 17 sensori e che utilizza InertialDriver per organizzarli e leggerli
## Scrittura codice
  
## Test
- Vengono effettuatti test di ognuna delle classi scritte
## Problematiche affrontate
