#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "student.h"
#include "human.h"
#include "manolib.h"


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