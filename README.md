# MiddleProject

## Creazione struttura

- creazione cartella del progetto "InertialDriver" con suddivisione in sotto cartelle di file .h e file .cpp
- indviduazione classi da progettore e creazione di uno schema rappresentante il progetto
- suddivisione del carico di lavoro

### Struttura:
- Classe Misure con 6 parametri double (yaw_v,yaw_a, pitch_v, pitch_a, roll_v, roll_a) che incpsula la lettura di un sensore
  1.private:
    
- Classe IntertialDriver che gestisce la lettura dai 17 sensori tramite un array circolare di dimensione stabilita BUFFER_DIM, implementato tramite la classe MyVector di Misure:
  1. private:
     * const int BUFFER_DIM_
     * MyVector<Misure>
  2. public:
     * void push_back(array<Misure> array) (controllo della lunghezza = 17)
     * void clear_buffer();
     * Misura get_reading(int index) (controllo della lunghezza da 0 a 16)

  
- Classe main che simula la lettura di 17 sensori e che utilizza InertialDriver per organizzarli e leggerli
## Scrittura codice
  
## Test
- Vengono effettuatti test di ognuna delle classi scritte
## Problematiche affrontate

