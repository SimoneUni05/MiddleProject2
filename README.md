# MiddleProject

## Creazione struttura

- creazione cartella del progetto "InertialDriver" con suddivisione in sotto cartelle di file .h e file .cpp
- indviduazione classi da progettore e creazione di uno schema rappresentante il progetto
- suddivisione del carico di lavoro

### Struttura:
- Classe Lettura con 6 parametri double (yaw_v,yaw_a, pitch_v, pitch_a, roll_v, roll_a) che incpsula la lettura di un sensore
- Classe IntertialDriver che gestisce la lettura dai 17 sensori tramite un array circolare di dimensione stabilita BUFFER_DIM, implementato tramite la classe MyVector<Lettura>
- Classe main che simula la lettura di 17 sensori e che utilizza InertialDriver per organizzarli e leggerli
## Scrittura codice
  
## Test
- Vengono effettuatti test di ognuna delle classi scritte
## Problematiche affrontate

