#include <iostream>
#include <vector>
using namespace std;

namespace ariel{

    class MagicalContainer{
        private:
            vector <int> elements; //vector that contains the numbers
            vector <int*> primeElements; //vector that contains pointers of prime numbers
            
        public:
            MagicalContainer(); // Default constructor
            void addElement(int); // Adding element to the container
            size_t size() const { return elements.size();}; // Return the size of the container
            void removeElement(int); // Removing element from the container
            vector<int> getElements() const { return elements;} // return the vector of numbers
            vector<int*> getPrimeElements() const { return primeElements;} // return the vector of prime numbers

            class Iterator{
                private:
                    MagicalContainer& container;
                    size_t currentIndex;

                public:
                    // to run the (make tidy)
                    Iterator() = delete; 
                    Iterator(Iterator&&) = delete;
                    Iterator& operator=(Iterator&&) = delete;  
                    // Iterator& operator=(const Iterator& other) = delete;  

                    // constructors    
                    Iterator(MagicalContainer& magicalContainer): container(magicalContainer), currentIndex(0){}
                    Iterator(MagicalContainer& magicalContainer, size_t index): container(magicalContainer), currentIndex(index){}
                    Iterator(const Iterator& other):container(other.container), currentIndex(other.currentIndex){}

                    // setters
                    void setContainer(MagicalContainer& cont){ container = cont;}
                    void setIndex(size_t num){ currentIndex = num;}

                    // method to increase currentIndex 
                    void increase(size_t num){ currentIndex += num;}

                    // getters
                    MagicalContainer& getContainer() const{return container;}
                    size_t getIndex() const{return currentIndex;}

                    // comparison functions
                    virtual bool operator==(const Iterator& other) const{return &container == &other.container && currentIndex == other.currentIndex;} // Equality comparison  
                    virtual bool operator!=(const Iterator& other) const{return !(*this == other);} // Inequality comparison   
                    virtual bool operator>(const Iterator& other) const{return currentIndex > other.currentIndex;} // Greater than comparison  
                    virtual bool operator<(const Iterator& other) const{return currentIndex < other.currentIndex;} // Less than comparison  
                    virtual int operator*() const { return getContainer().getElements().at(getIndex()); };

                    Iterator& operator=(const Iterator& other);

                    // destructor
                    virtual ~Iterator();
            };


        class AscendingIterator: public Iterator{

            public:
            // constructors
            AscendingIterator( MagicalContainer &, size_t);
            AscendingIterator( MagicalContainer& magicalContainer);
            AscendingIterator(const AscendingIterator& other);// Copy constructor      

            // to run (make tidy)
            AscendingIterator() = delete; 
            AscendingIterator(AscendingIterator&&) = delete;
            AscendingIterator& operator=(AscendingIterator&&) = delete;
            AscendingIterator& operator=(const AscendingIterator& other) = default; // Assignment operator   
              
            AscendingIterator& operator++(); // Pre-increment operator

            AscendingIterator begin()const ;
            AscendingIterator end()const ;
            
            ~AscendingIterator() override; // destructor  
        };

        class SideCrossIterator : public Iterator{

            public:
                // to run (make tidy)
                SideCrossIterator() = delete; 
                SideCrossIterator(SideCrossIterator&&) = delete;
                SideCrossIterator& operator=(SideCrossIterator&&) = delete;
                SideCrossIterator& operator=(const SideCrossIterator& other) = default;// Assignment operator      

                // constructors
                SideCrossIterator( MagicalContainer &, size_t);
                SideCrossIterator( MagicalContainer& magicalContainer) ;                
                SideCrossIterator(const SideCrossIterator& other) ;// Copy constructor              
                          
                int operator*() const override; // Dereference operator                
                SideCrossIterator& operator++() ; // Pre-increment operator

                SideCrossIterator begin()const;
                SideCrossIterator end()const;
                
                ~SideCrossIterator() override;// Destructor    
        };

        class PrimeIterator : public Iterator{

            public:
                // to run (make tidy)
                PrimeIterator() = delete; 
                PrimeIterator(PrimeIterator&&) = delete;
                PrimeIterator& operator=(PrimeIterator&&) = delete;
                PrimeIterator& operator=(const PrimeIterator& other) = default;// Assignment operator

                // constructors
                PrimeIterator( MagicalContainer &, size_t);
                PrimeIterator( MagicalContainer& magicalContainer);
                PrimeIterator(const PrimeIterator& other);// Copy constructor

                PrimeIterator& operator++() ;// Pre-increment operator
                int operator*() const override;// Dereference operator

                PrimeIterator begin()const ;
                PrimeIterator end() const ;
                
                ~PrimeIterator() override;// Destructor 
        };
    };
}