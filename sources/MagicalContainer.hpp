#include <iostream>
#include <vector>
using namespace std;

namespace ariel{

    class MagicalContainer{
        private:
            vector<int> elements;

        public:
            MagicalContainer(); // Default constructor
            void addElement(int); // Adding elements to the container
            int size()const; // Return the size of the container
            void removeElement(int); // Removing elemnt fron the container
            vector<int> getElements() const; // return the container


        class AscendingIterator{
            private:
                MagicalContainer& container;
                int currentIndex;

            public:


            AscendingIterator( MagicalContainer &, int);
            AscendingIterator( MagicalContainer& magicalContainer);
            AscendingIterator(const AscendingIterator& other);// Copy constructor      

            AscendingIterator() = delete; 
            AscendingIterator(AscendingIterator&&) = delete;
            AscendingIterator& operator=(AscendingIterator&&) = delete;

            ~AscendingIterator() ;// Destructor    
            AscendingIterator& operator=(const AscendingIterator& other);// Assignment operator   
            bool operator==(const AscendingIterator& other) const;// Equality comparison  
            bool operator!=(const AscendingIterator& other) const;// Inequality comparison   
            bool operator>(const AscendingIterator& other) const;// Greater than comparison  
            bool operator<(const AscendingIterator& other) const;// Less than comparison  
            int operator*() const ;// Dereference operator   
            AscendingIterator& operator++(); // Pre-increment operator
            AscendingIterator begin()const;
            AscendingIterator end()const;
        };

        class SideCrossIterator{
            private:
                MagicalContainer& container;
                int currentIndex;
                // bool fromStart;

            public:
                SideCrossIterator() = delete; 
                SideCrossIterator(SideCrossIterator&&) = delete;
                SideCrossIterator& operator=(SideCrossIterator&&) = delete;

                SideCrossIterator( MagicalContainer &, int);
                SideCrossIterator( MagicalContainer& magicalContainer) ;                
                SideCrossIterator(const SideCrossIterator& other) ;// Copy constructor       
                ~SideCrossIterator() ;// Destructor              
                SideCrossIterator& operator=(const SideCrossIterator& other);// Assignment operator       
                bool operator==(const SideCrossIterator& other) const ;// Equality comparison               
                bool operator!=(const SideCrossIterator& other) const ;// Inequality comparison               
                bool operator>(const SideCrossIterator& other) const ;// Greater than comparison               
                bool operator<(const SideCrossIterator& other)const;// Less than comparison               
                int operator*() const ; // Dereference operator                
                SideCrossIterator& operator++() ; // Pre-increment operator
                SideCrossIterator begin()const;
                SideCrossIterator end()const;
        };

        class PrimeIterator{
            private:
                MagicalContainer& container;
                int currentIndex;
            public:
                PrimeIterator() = delete; 
                PrimeIterator(PrimeIterator&&) = delete;
                PrimeIterator& operator=(PrimeIterator&&) = delete;

                PrimeIterator( MagicalContainer &, int);
                PrimeIterator( MagicalContainer& magicalContainer);
                PrimeIterator(const PrimeIterator& other);// Copy constructor
                ~PrimeIterator();// Destructor 
                PrimeIterator& operator=(const PrimeIterator& other);// Assignment operator
                bool operator==(const PrimeIterator& other) const ;// Equality comparison 
                bool operator!=(const PrimeIterator& other) const ;// Inequality comparison
                bool operator>(const PrimeIterator& other) const ;// Greater than comparison   
                bool operator<(const PrimeIterator& other) const ;// Less than comparison  
                int operator*() const ;// Dereference operator
                PrimeIterator& operator++() ;// Pre-increment operator
                PrimeIterator begin()const;
                PrimeIterator end()const;

        };
    };
}