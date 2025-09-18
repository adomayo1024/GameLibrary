#include <gtest/gtest.h>

#include "CycleInt.h"

namespace myGE {

    class CycleIntTest: public ::testing::Test {
        protected:
            CycleInt test{10};

            void TearDown() override {

            }
    };

    /**
     * Testet, ob bei der Initialisierung der Wert 0 ist.
     */
    TEST_F(CycleIntTest, initialize) {
        EXPECT_EQ(0, test);
    }

    /**
     * Testet, ob nach der Zuweisung eines Cycle Ints mit einem Int der Cycle Int auch wirklich den Wert des Ints hat.
     * Zudem noch, dass es immer noch derselbe Cycle Int ist und nicht ein neues Objekt.
     */
    TEST_F(CycleIntTest, assigmentOperatorInt) {
        auto adresse = &test;
        test = 7;
        EXPECT_EQ(7, test);
        EXPECT_EQ(&test, adresse);
    }

    /**
     * Testet, ob nach "falscher" Zuweisung (außerhalb des Bounds) mit einem Int der Wert unverändert bleibt.
     */
    TEST_F(CycleIntTest, assigmentOperatorIntWrongAssigment) {
        test = 12;
        EXPECT_EQ(0, test);
        test = 5;
        test = -34;
        EXPECT_EQ(5, test);
    }

    /**
     * Testet, ob der ++ Operator funktioniert und nach Aufruf der Wert um 1 erhöht wurde.
     */
    TEST_F(CycleIntTest, plusPlusOperator) {
        test++;
        EXPECT_EQ(1, test);
    }

    /**
     * Testet, ob der Wert, der vom ++ Operator zurückgeliefert wird, noch nicht der inkrementierende Wert ist,
     * sondern der vorherige Wert.
     */
    TEST_F(CycleIntTest, plusPlusOperatorIncrementAfter) {
        int temp = test++;
        EXPECT_EQ(0, temp);
        EXPECT_EQ(1, test);
    }

    /**
     * Testet, ob beim Aufruf des ++ Operators, wenn der Wert beim Maximum ist, der Wert auf 0 zurückgeht.
     */
    TEST_F(CycleIntTest, plusPlusOperatorOverflow) {
        test = 9;
        test++;
        EXPECT_EQ(0, test);
    }

    /**
     * Testet, ob der + Operator richtig funktioniert und das richtige Ergebnis geliefert.
     */
    TEST_F(CycleIntTest, plusOperatorWithInt) {
        test = 3;
        EXPECT_EQ(9, test + 6);
    }

    /**
     * Testet, ob der + Operator das richtige Ergebnis liefert, wenn es zu einem Overflow (über max) kommen würde.
     */
    TEST_F(CycleIntTest, plusOperatorWithIntOverflow) {
        test = 7;
        EXPECT_EQ(3, test + 6);
    }

    /**
     * Testet, ob der + Operator das richtige Ergebnis liefert, wenn es zu einem Underflow (unter 0) kommen würde.
     */
    TEST_F(CycleIntTest, plusOperatorWithIntUnderFlow) {
        test = 2;
        EXPECT_EQ(8, test + -4);
    }

    /**
     * Testet, ob der -- Operator funktioniert, nachdem Aufruf der Wert um 1 verringert wurde.
     */
    TEST_F(CycleIntTest, minusMinusOperator) {
        test++;
        test--;
        EXPECT_EQ(0, test);
    }

    /**
     * Testet, ob der Wert, der vom ++ Operator zurückgeliefert wird, noch nicht der dekrementierende Wert ist,
     * sondern der vorherige Wert.
     */
    TEST_F(CycleIntTest, minusMinusOperatorDecrementAfter) {
        int temp = test--;
        EXPECT_EQ(0, temp);
        EXPECT_EQ(9, test);
    }

    /**
     * Testet, ob der -- Operator funktioniert, wenn der Wert vorher 0 war und nach dem Aufruf der Wert bei max - 1 liegt.
     */
    TEST_F(CycleIntTest, minusMinusOperatorOverflow) {
        test--;
        EXPECT_EQ(9, test);
    }

    /**
     * Testet, ob der - Operator richtig funktioniert und das korrekte Ergebnis liefert.
     */
    TEST_F(CycleIntTest, minusOperatorWithInt) {
        test++;
        EXPECT_EQ(0, 1 - test);
    }

    /**
     * Testet, ob der - Operator das richtige Ergebnis liefert, wenn es zu einem Underflow (unter 0) kommen würde.
     */
    TEST_F(CycleIntTest, minusOperatorWithIntUnderflow) {
        test = 5;
        EXPECT_EQ(8, test - 7);
    }

    /**
     * Testet, ob der - Operator das richtige Ergebnis liefert, wenn es zu einem Overflow (über 0) kommen würde.
     */
    TEST_F(CycleIntTest, minusOperatorWhithIntOverflow) {
        test = 8;
        EXPECT_EQ(1, test - -3);
    }

    /**
     * Testet, ob die Konvertierung zu einem Int richtig funktioniert, und der Int danach denselben Wert hält.
     */
    TEST_F(CycleIntTest, intConversion) {
        int zahl = test;

        EXPECT_EQ(0, zahl);
        EXPECT_EQ(test, zahl);
    }

}
