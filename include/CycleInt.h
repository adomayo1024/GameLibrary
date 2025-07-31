#pragma once


namespace myGE {
    class CycleInt {
        public:
            /**
             * Konstruktor, um ein CycleInt zu initialisieren
             * @param max die Zahl nach der wieder auf 0 zurückgegangen werden soll. Der Bound ist dann 0 bis max - 1
             */
            CycleInt(int max);

            CycleInt operator++(int);

            CycleInt operator--(int);

            int operator-(int);

            operator int() const;

            bool operator==(int);

        private:
            int i;
            int max;
    };
}
