#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "student.h"
#include "human.h"
#include "manolib.h"
#include "functions.h"
#include "vector.h"


TEST_CASE("Studentu klases penkiu pirstu taisykles testas")
{
    Stud student1("Jonas", "Jonaitis", {10, 10, 5, 6, 2, 8}, 7, 'a', 7.0);

    SECTION("Copy konstruktorius")
    {
        Stud student2(student1);
        REQUIRE(student1.getVardas() == student2.getVardas());
        REQUIRE(student1.getPavarde() == student2.getPavarde());
        REQUIRE(student1.getEgz() == student2.getEgz());
        REQUIRE(student1.getVm() == student2.getVm());
        REQUIRE(student1.getGalutinis() == student2.getGalutinis());
    }

    SECTION("Copy priskyrimo operatorius")
    {
        Stud student3 = student1;

        REQUIRE(student1.getVardas() == student3.getVardas());
        REQUIRE(student1.getPavarde() == student3.getPavarde());
        REQUIRE(student1.getEgz() == student3.getEgz());
        REQUIRE(student1.getVm() == student3.getVm());
        REQUIRE(student1.getGalutinis() == student3.getGalutinis());
    }

    SECTION("Move konstruktorius")
    {
        Stud student4(std::move(student1));
        REQUIRE(student4.getVardas() == "Jonas");
        REQUIRE(student4.getPavarde() == "Jonaitis");
        REQUIRE(student4.getEgz() == 7);
        REQUIRE(student4.getVm() == 'a');
        REQUIRE(student4.getGalutinis() == 7.0);
    }

    SECTION("Move priskyrimo operatorius")
    {
        Stud student5;
        student5 = std::move(student1);
        REQUIRE(student5.getVardas() == "Jonas");
        REQUIRE(student5.getPavarde() == "Jonaitis");
        REQUIRE(student5.getEgz() == 7);
        REQUIRE(student5.getVm() == 'a');
        REQUIRE(student5.getGalutinis() == 7.0);
    }
    SECTION("Input operatorius")
    {
        std::istringstream input("Petras Petraitis 10 3 8 7 6 5 10 3 5 1 7 8 a");
        Stud student6;
        input >> student6;

        REQUIRE(student6.getVardas() == "Petras");
        REQUIRE(student6.getPavarde() == "Petraitis");
        REQUIRE(student6.getEgz() == 8);
        REQUIRE(student6.getVm() == 'a');
    }

    
}
TEST_CASE("Kitu programos funkciju testai")
{
    Stud student7("Petras", "Petraitis", {10, 9, 8}, 7, 'a', 0.0);
    Stud student8("Petras", "Petraitis", {7, 6, 5}, 7, 'm', 0.0);
    
    SECTION("FinalScore() testas")
    {
        student7.FinalScore();
        REQUIRE(student7.getGalutinis() == Approx(7.8));
        
        student8.FinalScore();
        REQUIRE(student8.getGalutinis() == Approx(6.6));
    }
}
TEST_CASE("Vektoriaus klasės testai")
{
    Vektor<Stud> vektorius;
    vektorius.push_back(Stud("Jonas", "Jonaitis", {10, 9, 8}, 7, 'a', 0.0));
    vektorius.push_back(Stud("Petras", "Petraitis", {7, 6, 5}, 7, 'm', 0.0));

    SECTION("Vektoriaus dydis")
    {
        REQUIRE(vektorius.size() == 2);
    }

    SECTION("Vektoriaus indeksavimas []")
    {
        REQUIRE(vektorius[0].getVardas() == "Jonas");
        REQUIRE(vektorius[1].getPavarde() == "Petraitis");
    }
    Vektor<int>test;
    test.push_back(1);
    test.push_back(2);
    
    SECTION("pop_back() testas")
    {
        test.pop_back();
        REQUIRE(test.size() == 1);
        REQUIRE(test[0] == 1);
    }
    SECTION("reserve() testas")
    {
        test.reserve(25);
        REQUIRE(test.capacity() == 25);
    }
    SECTION("shrink_to_fit() testas")
    {   
        test.reserve(25);
        test.shrink_to_fit();
        REQUIRE(test.capacity() == 2);
    }
    SECTION("swap() testas")
    {
        Vektor<int>test2;
        test2.push_back(3);
        test2.push_back(4);
        test.swap(test2);
        REQUIRE(test.size() == 2);
        REQUIRE(test[0] == 3);
        REQUIRE(test2.size() == 2);
        REQUIRE(test2[0] == 1);
    }
}