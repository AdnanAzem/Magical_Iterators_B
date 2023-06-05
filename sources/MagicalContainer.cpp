#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

namespace ariel{

    // Helper function to check if a number is prime
    bool isPrime(int num) {
        if (num <= 1)
            return false;
        for (int i = 2; i <= std::sqrt(num); i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    //=========================== MagicalContainer Class ===========================

    MagicalContainer::MagicalContainer() {}

    // Method to add an element to the container
    void MagicalContainer::addElement(int element) {
        elements.push_back(element); // add the element to the vector elements
        std::sort(elements.begin(), elements.end()); // sort the elements

        // add a pointer to the vector primeElements if the element is a prime number
        primeElements.clear();
        for(size_t i = 0; i < elements.size(); i++)
        if(isPrime(elements.at(i))){
            primeElements.push_back(&elements.at(i));
        }
    }

    // Method to remove an element from the container
    void MagicalContainer::removeElement(int element) {
  
        bool flag = false;// to tell us if the element was in the container
        if (isPrime(element)) { // If the number is prime, remove from the prime container.
            for (auto item = primeElements.begin(); item != primeElements.end(); ++item) {
                if (**item == element) {// remove the element if we found it
                    primeElements.erase(item);
                    break;
                }
            }
        }
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) { // remove the element if we found it
                elements.erase(it);
                flag = true;
                break;
            }
        }
        if(!flag) // if the element doesn't exist throw error
            throw std::runtime_error("Error: The element doesn't exist");
    }

    //=========================== Iterator Class ===========================

    // Assignment operator
    MagicalContainer::Iterator& MagicalContainer::Iterator::operator=(const Iterator& other) {
        if(&getContainer() != &other.getContainer()){ // throw error if we try to assign different containers
            throw runtime_error("Error: Iterators cannot be assigned if they belong to different containers.");
        }
        if (this != &other) {
            setContainer(other.getContainer());
            setIndex(other.getIndex());

        }
        return *this;
    }

    MagicalContainer::Iterator::~Iterator() {}

    //=========================== End Iterator Class ===========================

    //=========================== AscendingIterator Class ===========================

    MagicalContainer::AscendingIterator::AscendingIterator( MagicalContainer &cont, size_t index)
        : Iterator(cont,index){}

    // Default constructor
    MagicalContainer::AscendingIterator::AscendingIterator( MagicalContainer& magicalContainer)
        : Iterator(magicalContainer){} 

    // Copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
        :Iterator(other.getContainer(),other.getIndex()){}

    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // Pre-increment operator
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        if(getIndex() >= getContainer().getElements().size() || *this == end()){ // throw error when try to increase while we at the end
            throw runtime_error("Error: Iterator out of bounds!!!");
        }
        increase(1); // increase currentIndex by 1.
        return *this;
    }

    // Method to get an AscendingIterator pointing to the first element
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
        return AscendingIterator(getContainer(),0); 
    }

    // Method to get an AscendingIterator pointing one position past the last element
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
        return AscendingIterator(getContainer(),getContainer().size());
    }
    //=========================== End AscendingIterator Class ===========================


    //=========================== SideCrossIterator Class ===========================
  
    MagicalContainer::SideCrossIterator::SideCrossIterator( MagicalContainer &cont, size_t index)
        : Iterator(cont,index){}

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& magicalContainer) 
        : Iterator(magicalContainer,0){}

    // Copy constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) 
        : Iterator(other.getContainer(), other.getIndex()){}
        
    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    // Dereference operator
    int MagicalContainer::SideCrossIterator::operator*() const { 
        if (!(getIndex() % 2)) { // if the index is even return the value from start
            return getContainer().elements.at((getIndex() / 2));
        }
        else { // if the index is odd return the value from the end
            return getContainer().elements.at((getContainer().size() - 1 - (getIndex() - 1 ) / 2));
        }
    }

    // Pre-increment operator
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if(getIndex() >= getContainer().getElements().size() || *this == end()){ // throw error when try to increase while we at the end
            throw runtime_error("Error: Iterator out of bounds!!!");
        }
        increase(1); // increase the currentIndex by 1.
        return *this;
    }

    // Method to get a SideCrossIterator pointing to the first element
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
        return SideCrossIterator(getContainer(),0); 
    }

    // Method to get a SideCrossIterator pointing one position past the last element
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
        return SideCrossIterator(getContainer(),getContainer().size());
    }

    //=========================== End SideCrossIterator Class ===========================


    //=========================== PrimeIterator Class ===========================

    MagicalContainer::PrimeIterator::PrimeIterator( MagicalContainer &cont, size_t index) 
        : Iterator(cont,index){}

    // Default constructor
    MagicalContainer::PrimeIterator::PrimeIterator( MagicalContainer& magicalContainer) 
        : Iterator(magicalContainer, 0){
    }

    // Copy constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) 
        : Iterator(other.getContainer(), other.getIndex()){}
    

    // Destructor
    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    // Dereference operator
    int MagicalContainer::PrimeIterator::operator*() const {
        return *getContainer().getPrimeElements().at(getIndex());
    }

    // Pre-increment operator
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        if(getIndex() >= getContainer().getPrimeElements().size() || *this == end()){// throw error when try to increase while we at the end
            throw runtime_error("Error: Iterator out of bounds!!!");
        }
        increase(1); // increase the currentIndex by 1.
        return *this;
    }

    // Method to get a PrimeIterator pointing to the first prime element
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
        return PrimeIterator(getContainer(),0);
    }

    // Method to get a PrimeIterator pointing one position past the last prime element
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
        return PrimeIterator(getContainer(),getContainer().getPrimeElements().size());
    }

    //=========================== End PrimeIterator Class ===========================

    //=========================== End MagicalContainer Class ===========================
}






    