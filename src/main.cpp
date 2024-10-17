#include <iostream>
#include <gtest/gtest.h>
#include "unique_ptr.h"
#include "shared_ptr.h"

int main(int argc, char **argv) {
    if (false) // make false to run unit-tests
    {
        // debug section
        // --------------------- unique_ptr ---------------------
        // const UniquePtr<int> ptr_int = make_unique<int>(10);
        // const UniquePtr ptr_str = {make_unique<std::string>("hello world!")};
        // std::cout << "ptr_int.get(): " << ptr_int.get() << std::endl;
        // std::cout << "ptr_str.get(): " << ptr_str.get() << std::endl;
        // std::cout << "*ptr_int: " << *ptr_int << std::endl;
        // std::cout << "*ptr_str: " << *ptr_str << std::endl;
        // std::cout << "ptr_str->length(): " << ptr_str->length() << std::endl;
        //
        // UniquePtr<std::string> ptr{new std::string{"hello"}};
        // ptr.reset(new std::string{"nice"});
        // std::cout << *ptr << std::endl; // output: nice
        //
        // UniquePtr<double> ptr3{new double{1.567}};
        // const double *tmp{ptr3.release()};
        // std::cout << *tmp << std::endl; // output: 1.567
        // delete tmp; // manual deletion
        //
        // // can not be copied
        // // const UniquePtr<int> ptr1{new int{10}};
        // // UniquePtr<int> ptr2{ptr1};
        //
        // // can not be copied
        // // UniquePtr<int> ptr1{new int{10}};
        // // UniquePtr<int> ptr2{new int{11}};
        // // ptr2 = ptr1;
        //
        //
        // //--------------------- shared_ptr ---------------------
        // SharedPtr<int> shared_ptr1{new int{10}};
        // SharedPtr<int> shared_ptr2{make_shared<int>(10)};
        //
        // SharedPtr<int> shared_ptr3{new int{10}};
        // SharedPtr<int> shared_ptr4{shared_ptr3};
        //
        // SharedPtr<int> shared_ptr6{new int{10}};
        // SharedPtr<int> shared_ptr7{new int{11}};
        // shared_ptr6 = shared_ptr7;


        // SharedPtr<int> ptr1{make_shared<int>(10)};
        // std::cout << ptr1.use_count() << std::endl; // output: 1
        // SharedPtr<int> ptr2{ptr1};
        // std::cout << ptr1.use_count() << std::endl; // output: 2
        // std::cout << ptr2.use_count() << std::endl; // output: 2

        // SharedPtr<int> ptr{new int{10}};
        // std::cout << ptr.get() << std::endl; // output: raw pointer of the class
        // std::cout << *ptr << std::endl; // output: 10

        // SharedPtr<std::string> ptr{new std::string{"hello"}};
        // std::cout << ptr->length() << std::endl; // output: 5

        SharedPtr<std::string> ptr{new std::string{"hello"}};
        ptr.reset(new std::string{"nice"});
        std::cout << *ptr << std::endl; // output: nice

    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}
