#pragma once


namespace myGE {
    class CycleInt {
        public:
            /**
             * Konstruktor, um ein CycleInt zu initialisieren
             * @param max die Zahl nach der wieder auf 0 zurückgegangen werden soll. Der Bound ist dann 0 bis max - 1
             */
            explicit CycleInt(int max);

            /**
             * Der ++ Operator für ein Cycle Int, wodurch der Wert um 1 erhöht wird und bei max wieder bei 0 beginnt
             * @return CycleInt mit dem Wert bevor der Inkrementierung
             */
            CycleInt operator++(int);

            /**
             * Der -- Operator für ein Cycle Int, wodurch der Wert um 1 verringert wird und nach 0 bei max-1 wieder beginnt
             * @return CycleInt mit dem Wert bevor der Dekrementierung
             */
            CycleInt operator--(int);

            /**
             * Der - Operator mit Int, wobei der Wert vom Cycle Int nicht verändert wird, aber der Bound berücksichtigt wird.
             * @return Differenz vom Cycle Int und int mit Berücksichtigung des Bounds des Cycle Ints
             * @note
             * Beispiel:
             * max = 5.  dann ist 3-4 = 4.
             *
             */
            int operator-(int);

            /**
             * Der + Operator mit Int, wobei der Wert vom Cycle Int nicht verändert wird, aber der Bound berücksichtigt wird.
             * @return
             */
            int operator+(int);

            /**
             * Konveniert einen CycleInt in einen Int.
             */
            operator int() const;

            /**
             * Gleichheitsoperator, wenn bei ints gleich sind liefert er true.
             * @return true, wenn beide gleich sind.
             */
            bool operator==(int);

            /**
             * Zuweisungsoperator, womit man Int einen CycleInt zuweisen kann.
             * Wenn der Int, der zugewiesen werden soll, entweder kleiner als 0 oder größer gleich des max Values ist.
             * Wird der Wert des CycleInts nicht verändert.
             * @return
             */
            CycleInt &operator=(const int &);

        private:
            /**
             * Der Wert des Cycle Ints
             */
            int i;
            /**
             * Der Bound des Cycle Ints, wenn max erreicht ist, wird wieder auf 0 gesetzt.
             */
            int max;
    };
}
